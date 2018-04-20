#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define MAX 10

struct hash
{
	char name[20];
	long int tele;
	int chain;
};

hash rec[MAX];

class hashtable
{
	public:
		hashtable()
		{
			for(int i=0;i<MAX;i++)
			{
				rec[i].tele=0;
				strcpy(rec[i].name,"-");
				rec[i].chain=-1;
			}
		}
		
		int hashing(long int tele)
		{
			return tele%MAX;
		}
		
		void wt_rplmnt(struct hash h);
		void wtout_rplmnt(struct hash h);
		void disp();
};

void hashtable::wtout_rplmnt(struct hash h)
{
	int k=hashing(h.tele);
	int p=k;
	int i;
	if(rec[k].tele==0)
	{
		rec[k].tele=h.tele;
		strcpy(rec[k].name,h.name);
	}
	else
	{
		i=k+1;
		do
		{
			if(i>=MAX)
				i=i%MAX;
			if(hashing(rec[i].tele)==k)
				p=k;
			if(rec[i].tele==0)
			{
				rec[i].tele=h.tele;
				strcpy(rec[i].name,h.name);
				do
				{
					if(hashing(rec[p].tele)==k && rec[p].chain==-1)
					{
						rec[p].chain=i;
						break;
					}
					p++;
					p=p%MAX;
				}while(p%MAX!=i);
				break;
			}
			i++;
		}while(i%MAX!=k);
		if(i==k)
			cout<<"\n Hash Table is Full";
	}
}

void hashtable::wt_rplmnt(struct hash h)
{
	int k=hashing(h.tele);
	int p=k;
	int i,change_pos;
	if(rec[k].tele==0)
	{
		rec[k].tele=h.tele;
		strcpy(rec[k].name,h.name);
	}
	else if(hashing(rec[k].tele)==hashing(h.tele))
	{
		i=k+1;
		do
		{
			if(i>=MAX)
				i=i%MAX;
			if(hashing(rec[i].tele)==k)
				p=k;
			if(rec[i].tele==0)
			{
				rec[i].tele=h.tele;
				strcpy(rec[i].name,h.name);
				int j=k;
				do
				{
					if(hashing(rec[j].tele)==k && rec[j].chain==-1)
					{
						rec[j].chain=i;
						break;
					}
					j++;
					if(j>=MAX)
						i=j%MAX;
				}while(j%MAX!=k);
				break;
			}
			i++;
		}while(i%MAX!=k);
		if(i==k)
			cout<<"\n Hash Table is Full";
	}
	else
	{
		hash temp;
		temp.tele=rec[k].tele;
		strcpy(temp.name,rec[k].name);
		temp.chain=rec[k].chain;
		rec[k].tele=h.tele;
		strcpy(rec[k].name,h.name);
		rec[k].chain=-1;
		i=k+1;
		if(i>=MAX)
			i=i%MAX;
		do
		{
			if(rec[i].tele==0)
			{
				rec[i].tele=temp.tele;
				strcpy(rec[i].name,temp.name);
				rec[i].chain=temp.chain;
				change_pos=i;
				break;
			}
			i++;
		}while(i%MAX!=k);
		for(i=0;i<MAX;i++)
		{
			if(rec[i].chain==k)
			{
				if(change_pos>=MAX)
					change_pos-=MAX;
				rec[i].chain=change_pos;
				break;
			}
		}
	}
}

void hashtable::disp()
{	
	int i;
	cout<<"\nIndex\tTele.no.\tName\tchain";
	for(i=0;i<MAX;i++)
	{
		cout<<"\n"<<i<<"\t"<<rec[i].tele<<"\t"<<rec[i].name<<"\t"<<rec[i].chain;
	}
}

int main()
{
	hashtable ht;
	hash h;
	int ch;
	while(1)
	{
		cout<<"\n Enter your choice \n1.Insert without replacement \n2.Insert with replacement \n3.exit";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n Enter telephone number";
			 		cin>>h.tele;
			 		cout<<"\n Enter name";
			 		cin>>h.name;
			 		ht.wtout_rplmnt(h);
			 		ht.disp();
			 		break;
			case 2: cout<<"\n Enter telephone number";
			 		cin>>h.tele;
			 		cout<<"\n Enter name";
			 		cin>>h.name;
			 		ht.wt_rplmnt(h);
			 		ht.disp();
			 		break;
			case 3: exit(1);
			default:cout<<"\n Invalid choice";
		}
	}
}
