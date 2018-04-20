/*#3. Create Binary tree and perform following operations:
a. Insert
b. Display
c. Depth of a tree
d. Display leaf-nodes
e. Create a copy of a tree*/
//________________________________________________________________________________________________________
#include<iostream>
using namespace std;
//________________________________________________________________________________________________________
typedef struct node
{
  	int data;
  	node *left,*right;
}node;
//________________________________________________________________________________________________________
class bt
{
      node *root;
      
 public:
      bt()
      	{
       	 	root=NULL;
     	}

	  node* getroot()//will give the value of the current root
        {
        	return root;
     	}

	  void create(int );
      void insert(int ,int );
      node *search(node *,int );
      void rpreorder(node *root);
      void rpostorder(node *root);
      void rinorder(node *root);
      void preorder();
      void postorder();
      void inorder();
      
      int height(node *root);
      int display_leaf(node *root);
      node *copyt(node *root);
	  bt(const bt &bt)//copy constructor syntax =>"class_name(const class_name &old_obj)"
		{
			node *copyt(node *root);
		}
};
//________________________________________________________________________________________________________
class stack
{
  
  node *array[90];
  int top;
  public:
  stack()
  {
   top=-1;
  }
  bool empty()
  {
   if(top==-1)
   return true;
   else
   return false;
  }
  void push(node *p)
  {
   array[++top]=p;
  }
  node* pop()
  {
   return array[top--];
  }
};
//________________________________________________________________________________________________________
void bt::create(int root_val)
{
  	if(root==NULL)
 	 {
  	 	 root=new node;
   		 root->data=root_val;
   		 root->left=root->right=NULL;
  	 }
}

//________________________________________________________________________________________________________
node* bt::search(node *root,int key)
{
  if(root!=NULL)
  {
     if(root->data==key)
     {
       return root;
     }
     else
     {
       node *a,*b;
       a=search(root->left,key);
       b=search(root->right,key);
       if(a!=NULL)
        return a;
       else
        return b; 
      
     }
  }
return NULL;
}
//________________________________________________________________________________________________________
void bt::insert(int value,int key)
{
  char ch;
  
  node* temp=search(root,key);
  if(temp!=NULL)
  	{
  	  node *n=new node;
  	  n->data=value;
   
  	  cout<<"where to insert..(l/r) : ";
  	  cin>>ch;
  	  if(temp->left==NULL && (ch=='l' || ch=='L') )
  	   {
  	     temp->left=n;
  	   }
  	  else if(temp->right==NULL && (ch=='r' || ch=='R') )
  	   {
  	     temp->right=n;
  	   }
  	  else 
  	  {
  	    cout<<"\nlocation full..\n";
  	  }
  	}
  else
  {
    cout<<"\nKEY NOT FOUND...\n";
  }
}
//________________________________________________________________________________________________________
void bt::rpreorder(node *root)						//root-left-right
{
  	if(root!= NULL)
 	 {	
  		cout<<root->data<<"\t";
  		
  		rpreorder(root->left);
  		rpreorder(root->right);	
 	 }
}
//________________________________________________________________________________________________________
void bt::rpostorder(node *root)						//left-right-root
{
  	if(root!= NULL)
 	 {	
  		rpostorder(root->left);
  		rpostorder(root->right);	
 	    cout<<root->data<<"\t";
     }
}
//________________________________________________________________________________________________________
void bt::rinorder(node *root)						//left-root-right
{
  	if(root!= NULL)
 	 {	
  		rinorder(root->left);
  		cout<<root->data<<"\t";  		
		rinorder(root->right);	
 	 }
}
//________________________________________________________________________________________________________

void bt::preorder()
{
  node *temp=root;
  stack s1;
  while(1)
  {
    while(temp!=NULL)
     {
       cout<<temp->data<<"\t";
       s1.push(temp);
       temp=temp->left;	
     }
    if(!s1.empty())
     {
 	temp=s1.pop();
	temp=temp->right;
     }
    else
	break;
  }
}

//________________________________________________________________________________________________________

void bt::inorder()
{
  node *temp=root;
  stack s2;
  while(1)
  {
    while(temp!=NULL)
     {

       s2.push(temp);
       temp=temp->left;	
     }
    if(!s2.empty())
     {
 	temp=s2.pop();
        cout<<temp->data<<"\t";
	temp=temp->right;
     }
    else
	break;
  }
}
//________________________________________________________________________________________________________

void bt::postorder()
{  
node *temp=root;
 stack s3,s4;
 s3.push(temp); 
 while(!s3.empty())
   {
	temp=s3.pop();
	s4.push(temp);
    if(temp->left != NULL)
 	s3.push(temp->left);
    if(temp->right != NULL)
	s3.push(temp->right);
   }
  while(!s4.empty())
   {
      temp=s4.pop();
      cout<<temp->data<<"\t";  
   }
}

//________________________________________________________________________________________________________

int bt::height(node *root)
{
  if (root==NULL)
  return -1;
  else
  return 1+max(height(root->left),height(root->right));
}
//________________________________________________________________________________________________________

int bt::display_leaf(node *root)
{
  if(root==NULL)
  return 0;
  else if(root->left==NULL && root->right==NULL)
	{
	  cout<<"\t";
	  cout<<root->data;
	  return 100;
	} 
  else
  {
  	display_leaf(root->left);
  	display_leaf(root->right);
  }
}
//________________________________________________________________________________________________________
node* bt::copyt(node *root)
{
  node *t=root;
  if(root!=NULL)
   {
		t->data=root->data;
		t->left=copyt(root->left);
		t->right=copyt(root->right);   
   }
  return t;
}
//_______________________________________________________________________________________________________
int main()
{
 bt b;
 bt cb=b;//for copy of tree2
 node *root2;
 
 char exit;
 int root_val,value,key,choice,choice1,ch,ch1,h;
 cout<<"\nROOT VALUE : ";
 cin>>root_val;
 b.create(root_val);

 do
  {
   cout<<"\n*********MENU*********\n1.INSERT\n2.DISPLAY\n3.DEPTH OF TREE\n4.DISPLAY LEAF NODES\n5.CREATE A COPY OF TREE\n6.EXIT";
   cout<<"\nENTER YOUR CHOICE : ";
   cin>>choice;
   switch(choice)
    {
	case 1://insert
		do
 		{
		 cout<<"\n----------------------------------";
		 cout<<"\nENTER THE VALUE TO BE INSERTED : ";
	 	 cin>>value;
	 	 cout<<"VALUE TO BE INSERTED AFTER : ";
	 	 cin>>key;
     	         b.insert(value,key); 
    		 cout<<"\ncontinue inserting...(y/n) : ";
     		 cin>>exit; 
 		}while(exit!='n');	
		break;				

	case 2://display
	       do
	       {
		cout<<"\n1.RECURSIVE\n2.NON-RECURSIVE\n3.BACK TO MENU\nCHOICE: ";
		cin>>choice1;
		switch(choice1)
		 {
		  case 1://recursive
			do
			{
			  cout<<"\n\n1.PREORDER\n2.POSTORDER\n3.INORDER\n4.DISPLAY ALL\n5.BACK..\nCHOICE: ";
			  cin>>ch;
			  switch(ch)
			  {
				case 1://preorder
				cout<<"\n**PREORDER**\n";
				b.rpreorder(b.getroot());
				break;

			        case 2://postorder
				cout<<"\n**POSTORDER**\n";
				b.rpostorder(b.getroot());
				break;
	
				case 3://inorder
				cout<<"\n**INORDER**\n";
				b.rinorder(b.getroot());
				break;

				case 4://display all
				cout<<"\n----------------------------------------";
				cout<<"\n**PREORDER**\n";
				b.rpreorder(b.getroot());
				cout<<"\n**POSTORDER**\n";
				b.rpostorder(b.getroot());
				cout<<"\n**INORDER**\n";
				b.rinorder(b.getroot());
				cout<<"\n----------------------------------------";
				break;	

				case 5://back ..
				break;	

				default: cout<<"\nINVALID CHOICE....\n";
			  }
		        }while(ch!=5);
		        break;

		case 2://nonrecursive
			do
			{
			  cout<<"\n\n1.PREORDER\n2.POSTORDER\n3.INORDER\n4.DISPLAY ALL\n5.BACK..\nCHOICE: ";
			  cin>>ch1;
			  switch(ch1)
			  {
				case 1://preorder
				cout<<"\n**PREORDER**\n";
				b.preorder();
				break;

			        case 2://postorder
				cout<<"\n**POSTORDER**\n";
				b.postorder();
				break;
	
				case 3://inorder
				cout<<"\n**INORDER**\n";
				b.inorder();
				break;

				case 4://display all
				cout<<"\n----------------------------------------";
				cout<<"\n**PREORDER**\n";
				b.preorder();
				cout<<"\n**POSTORDER**\n";
				b.postorder();
				cout<<"\n**INORDER**\n";
				b.inorder();
				cout<<"\n----------------------------------------";
				break;	

				case 5://back..
				break;	

				default: cout<<"\nINVALID CHOICE....\n";

			  }
		       }while(ch1!=5);
		       break;
			 
		case 3://back to menu..
			break;	

		default: cout<<"\nINVALID CHOICE....\n";
                }
	       }while(choice1!=3);				
	       break;									

	case 3://depth of tree
		h=b.height(b.getroot());
                cout<<"\nHEIGHT : "<<h<<"\n";
		break;

	case 4://display leaf nodes
		cout<<"\nLEAF NODES :- ";
		b.display_leaf(b.getroot());
		cout<<"\n";
		break;

	case 5://create a copy of tree
		root2=b.copyt(b.getroot());
		cout<<"\n----------------------------------------";
		cout<<"\n*******PREORDER(COPY OF TREE)*******\n";
		cb.rpreorder(root2);
		cout<<"\n*******PREORDER(MAIN TREE)*********\n";
		b.rpreorder(b.getroot());
		cout<<"\n\n*******POSTORDER(COPY OF TREE)*******\n";
		cb.rpostorder(root2);
		cout<<"\n*******POSTORDER(MAIN TREE)*********\n";
		b.rpostorder(b.getroot());
		cout<<"\n\n*******INORDER(COPY OF TREE)*******\n";
		cb.rinorder(root2);
		cout<<"\n*******INORDER(MAIN TREE)*********\n";
		b.rinorder(b.getroot());
		cout<<"\n----------------------------------------\n";
		break;

	case 6://exit
		break;

		default:cout<<"\nINVALID CHOICE.....\n";
	}

}while(choice!=6);

return 0;
} 
//________________________________________________________________________________________________________

