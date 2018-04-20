/*
Shivam Shishangia
3164117
SE-IT-B
B2
*/
#include<iostream>
#include<string.h>
using namespace std;

template <class T>
class stack
{
	typedef struct node
	{
        T data;
        struct node* next;
	}node;
	node* top;
	public:
		stack()
		{
		    top=NULL;
		}
		void push(T x);
		char pop();
		int isempty();
		int isfull();
		void display();
		int incopre(T ch);
		int instpre(T ch);
		string intopost(string str);
		char stacktop();
		string intopre(string str);
		int posteval(string str,int ispost);
		int preval(string prestr);
};

template <class T>
int stack<T>::isempty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}

template <class T>
char stack<T>::stacktop()
{
	return top->data;
}

template <class T>
int stack<T>::isfull()
{
	return 0;
}

template <class T>
void stack<T>::push(T x)
{
	if(isfull())
	{
		cout<<"The Stack is Full";
	}
	else
	{
		node* p;
		p=new node;
		if(isempty())
		{
			p->data=x;
			p->next=NULL;
			top=p;
		}
		else
		{
			p->data=x;
			p->next=top;
			top=p;
		}
	}
}	

template <class T>
char stack<T>::pop()
{
	node* p;
	if(top==NULL)
	{
	    cout<<"Stack is empty";
	}
	else
	{
        p=top;
        top=p->next;
	}
    return p->data;
}

template <class T>
void stack<T>::display()
{
	if(isempty())
	{
	    cout<<"Stack is empty";
	}
	else
	{
        node* p;
        p=top;
        cout<<"\n";
        while(p!=NULL)
        {
            cout<<p->data;
            cout<<"\n";
            p=p->next;
        }
        cout<<"\n";
	}
}

int evaluate(char ch,int op1,int op2)
{
	if(ch=='+')
	    return op1+op2;
	if(ch=='-')
	    return op1-op2;
	if(ch=='*')
	    return op1*op2;
	if(ch=='/')
	    return op2/op1;
	if(ch=='^')
	    return op1^op2;
	if(ch=='%')
	    return op2%op1;
	return -1;
}
template<class T>
int stack<T>::instpre(T ch)
{
	if(ch=='(')
		return 0;
	else if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/' || ch=='%')
		return 2;
	else if(ch=='^')
		return 3;
    return -1;
}

template<class T>
int stack<T>::incopre(T ch)
{
	if(ch=='(')
		return 5;
	else if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/' || ch=='%')
		return 2;
	else if(ch=='^')
		return 4;
    return -1;
}

template <class T>
string stack<T>::intopost(string str) // function for Infix to Postfix
{
	int i=0;
	string postr;
	char op,ch;
	stack<char> st;
	for(i=0;i<str.length();i++)  			           // read all the elements one by one from the string str
	{                                                         //for started 
        ch=str.at(i);                                            //at() function used for getting one char at a time 
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))        //if ch is a alphabet
        {                                                      //
            postr.append(1,ch);                                   //directly save it to postr string using append() function
        }                                                 
        else 
        {	
            if(ch=='(')                                      //if ch is '('
                st.push(ch);                            //push it to the stack
            else if(ch==')')                               //if ch is ')' 
                while(op=st.pop()!='(')               // the pop all the elements from the stack till we get '('
                {
                    postr.append(1,op);
                }
            while((st.isempty()==false) && incopre(ch)<=instpre(st.stacktop()))    //if ch is operator
            {                                                                     //
                op=st.pop();                                                 //icp<isp pop
                postr.append(1,op);                                         //pop
            }                                                                  //append 
            if(ch!='(' && ch!=')')                                            //if ch!= ( or ) then icp>isp then push ch to stack
                st.push(ch);                                             //push element to stack
        }                                                                       //end of else
	}                                                                      //end of for
	while(st.isempty()!=true)                                             //till the stack gets emptied pop all the elements
	{                                                                    //
		op=st.pop();                                                //poped elements
		postr.append(1,op);                                        //append to postr
	}                                                                 //end of while
	return postr;                                                    //return postr i.e postfix string
}

template <class T>
string stack<T>::intopre(string str)                        //Function for Infix to Prefix
{                                  
	int i;
	string revstr,postr,prestr;
        stack<char> st;
	char ch;
	for(i=0;i<str.length();i++)                    //Push all the elements one by one into the stack
	    st.push(str.at(i));
	while(st.isempty()==false)
	{                                            //pop the elements and then append them in revstr
        ch=st.pop();
        if(ch=='(')
        revstr.append(1,')');
        else if(ch==')')
        revstr.append(1,'(');
        else
        revstr.append(1,ch);	        
	}
	postr=intopost(revstr);                  //convert revstr to postr using intopost() function
	for(i=0;i<postr.length();i++)           //Now push all the elments of postr in stack 
	    st.push(postr.at(i));
	while(st.isempty()==false)            //now pop the elements one by one and append them in prestr
	{
        ch=st.pop();
        prestr.append(1,ch);
	}
	return prestr;                    //return the prefix expression
}

template <class T>
int stack<T>::posteval(string postr,int ispost)                   //Evaluation of POstfix Expression
{
	int i,op1,op2,val,poval;
	char ch;
	stack<int> st;
	for(i=0;i<postr.length();i++)         //select every character from expression
	{                                    //
        ch=postr.at(i);                     //select one ch at a time
        if(isalnum(ch))                    //is alphabet or num 
        {
            cout<<"Enter Value for "<<"("<<ch<<")";
            cin>>val;
            st.push(val);        //push the value on stack
        }                   //
        else               //if ch is operator + - / * etc
        {                 //
            if(ispost==1)    //if it is postfix
            {
                op2=st.pop();
                op1=st.pop();
            }
            else                               //if it is prefix
            {
                op2=st.pop();
                op1=st.pop();
            }
            poval=evaluate(ch,op1,op2);    //evaluate the first two top elements
            st.push(poval);	              //push the poval to stack	
        }
	}
	return poval;
}

template <class T>
int stack<T>::preval(string prestr)           //Evaluation of Prefix expression
{
	int i,preeval;
	string postr;
	stack<char> st;
	for(i=0;i<prestr.length();i++)     //read all the elements one by one 
	{
	    st.push(prestr.at(i));          //push ch stack to stack
	}
	while(st.isempty()==false)     //pop each ch to reverse the list
	{
	    postr.append(1,st.pop());     //pop and then append to postr
	}
	preeval=st.posteval(postr,0);   //evaluate postr and save it to preeval
	return preeval;
}	

int main()
{
    int ch,val;
    stack<char> a;
    string str,post,pre;
    char ele;
    do
    {
        cout<<"\nEnter:\n1.Infix To Postfix\n2.Infix To Prefix\n3.Postfix Evaluation\n4.Prefix Evaluation\n5.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter Infix Expression: \n";
                cin>>str;
                post=a.intopost(str);
                cout<<"\nThe Posfix Expression is "<<post<<"\n";
                break;
            case 2:
                cout<<"\nEnter Infix Expression: \n";
                cin>>str;
                pre=a.intopre(str);
                cout<<"\nThe Prefix Expression is "<<pre<<"\n";
                break;
            case 3:
                cout<<"\nEnter Infix Expression: \n";
                cin>>str;
                post=a.intopost(str);
                cout<<"\nThe Posfix Expression is "<<post<<"\n";
                val=a.posteval(post,1);
                cout<<"\nThe Evaluated Value is "<<val<<"\n";
                break;
            case 4:
                cout<<"\nEnter Infix Expression: \n";
                cin>>str;
                pre=a.intopre(str);
                cout<<"\nThe Prefix Expression is "<<pre<<"\n";
                val=a.preval(pre);
                cout<<"\nThe Evaluated Value is "<<val<<"\n";
                break;
            case 5:
                break;
            default:
                cout<<"Invalid choice:\n";	
        }
    }while(ch!=5);
    return 0;
}