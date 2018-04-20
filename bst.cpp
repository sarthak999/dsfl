/*
5. Implement binary search tree and perform following operations:
a. Insert
b. Delete
c. Search
d. Mirror image
e. Display
f. Display level wise
*/
//____________________________________________________________________________________________________
#include<iostream>
using namespace std;

class bst;
class stack;
class queue;

class node
{
	friend class bst; 
	friend class stack;
	friend class queue;
	node *left;
	node *right;
	public:
	int data;
	
};
//____________________________________________________________________________________________________
class stack
{
	node *array[20];
	int top;

	public:	//vimp to make public

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
	void push(node *data)
	{
		array[++top]=data;
	}
	node *pop()
	{
		return array[top--];
	}
};
//____________________________________________________________________________________________________
class queue
{
	node *array[20];
	int front;
	int rear;

	public:		//vimp to make public
	queue()
	{
		front=-1;
		rear=-1;
	}
	void enqueue(node *m)
	{
		if(rear==-1)
		{
			rear=front=0;
			array[rear]=m;				
		}
		else
		{
			array[++rear]=m;
		}
	}
	node* dequeue()
	{
		return array[front++];
	}

	bool emptyq()
	{
		if(front>rear || front<0)
		return true;
		else
		return false;
	}

};
//____________________________________________________________________________________________________
class bst
{
 	node *root;
	node *parent;
 	public:
		bst()
		{
			root=NULL;
		}		
		node* getroot()//will give the value of the current root_used here only for r_display
		{
			return root;
		}		
		
		void insert(node* ,int );
		void create();
		node* delete_node(node* ,int );
		node* search(int );
		void mirror_image();
		void indisplay();
		void rindisplay(node* );
		void lwdisplay1(); 
		void mirror(node *);
};
//____________________________________________________________________________________________________
void bst::insert(node* root,int key)
{
	node *temp=new node;
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	
	if(key < root->data)
	{
		if(root->left==NULL)
		root->left=temp;
		else
		insert(root->left,key);
	}
	if(key > root->data)
	{
		if(root->right==NULL)
		root->right=temp;
		else
		insert(root->right,key);
	}

}
//____________________________________________________________________________________________________
void bst::create()
{
	int n,i,key;
	cout<<"\nEnter number of entries : ";
	cin>>n;
	node *temp=new node;
	temp->data=0;
	temp->left=NULL;
	temp->right=NULL;

	for(i=1;i<=n;i++)
	{
		cout<<"Entry "<<i<<": ";
		cin>>key;
		if(i==1)
		{
			temp->data=key;
			root=temp;
		}
		else
			insert(root,key);
	}
}
//____________________________________________________________________________________________________
void bst::lwdisplay1()
{
	queue q;
	node *temp=root;
	q.enqueue(temp);
	while(q.emptyq()==false)
	{		
		temp=q.dequeue();
		cout<<"\t"<<temp->data;
		if(temp->left!=NULL)
		q.enqueue(temp->left);
		if(temp->right!=NULL)
		q.enqueue(temp->right);			
	}
}
//____________________________________________________________________________________________________
void bst::rindisplay(node *root)
{
	if(root != NULL)
	{
		rindisplay(root->left);
		cout<<"\t"<<root->data;
		rindisplay(root->right);	
	}
}
//____________________________________________________________________________________________________
void bst::indisplay()
{
	stack s;
	node*temp=root;
	while(1)
	{	
	while(temp != NULL)
	{
		s.push(temp);
		temp=temp->left;
	}
	if(!s.empty())
	{
		temp=s.pop();
		cout<<"\t"<<temp->data;
		temp=temp->right;
	}
	else
	break;
	}
}
//____________________________________________________________________________________________________
node* bst::search(int key)
{
	node *temp=root;
	while(temp!=NULL)
	{	
		if(temp->data==key)
		return temp;		
		parent=temp;
		if(temp->data > key)
		temp=temp->left;
		else
		temp=temp->right;	
	}

}
//____________________________________________________________________________________________________
node* bst::delete_node(node* root,int key)
{
	node* value=search(key); 
	node* temp;
	node* ptr;

	if(value->right==NULL && value->left==NULL)
	 {
		if(parent->left==value)
		parent->left=NULL;
		else
		parent->right=NULL;
		return NULL;
	 }

	if(value->left==NULL && value->right!=NULL)
 	 {
		parent->right=value->right;	
		delete value;
		return NULL;
	 }

	 if(value->right==NULL && value->left!=NULL)
	 {
		parent->left=value->left;
		delete value;
		return NULL;
	 }
	 
	else
	{
		temp=value;
		temp=temp->left;
		if(temp->right==NULL)
		{			
			value->data=temp->data;
			value->left=temp->left;
			delete temp;
			return NULL;			
		}		
		else
		{		
			while(temp->right != NULL)
			{		
				ptr=temp;
				temp=temp->right;
			}	
			value->data=temp->data;
			ptr->right=temp->left;
			delete temp;		
			return NULL;			
		}
	}
}
//____________________________________________________________________________________________________
void bst::mirror(node *root)
{
	node *temp;	
	if(root!=NULL)
	{
		mirror(root->left);
		mirror(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;			
	}
}
//____________________________________________________________________________________________________
int main()
{
	bst b;
	node *r;
	int choice,key;
	do
	{
		cout<<"\n\n******MENU*******\n1.CREATE\n2.DISPLAY\n3.LEVEL WISE DISPLAY\n4.DELETE\n5.MIRROR\n6.EXIT";
		cout<<"\nCHOICE : ";
		cin>>choice;
		switch(choice)
		{
			case 1://create
					b.create();
					break;

			case 2://display
					cout<<"\nNON RECURSIVE :-\n";
					b.indisplay();
					cout<<"\nRECURSIVE :-\n";
					b.rindisplay(b.getroot());
					break;

			case 3:
					cout<<"\nLEVEL WISE DISPLAY :- \n";
					b.lwdisplay1();
					break;

			case 4://delete
					cout<<"\nENTER THE ELEMENT TO BE DELETED : ";
				    cin>>key;
					r=b.delete_node(b.getroot(),key);
					if(r==NULL)
					cout<<"\n\nSuccesfully deleted!!";
					else
					cout<<"\n\nKey was not found..";				
					
					cout<<"\n\nAFTER DELETION :\n";
					b.rindisplay(b.getroot());
					break;

			case 5://mirror
					b.mirror(b.getroot());
					cout<<"\nInorder Display..\n";
					b.rindisplay(b.getroot());
					break;

			case 6://exit
					break;

			default:cout<<"\ninvalid choice\n";
					
		}

	}while(choice!=6);
}
//____________________________________________________________________________________________________

