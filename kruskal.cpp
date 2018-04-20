//7. Represent any real world graph using adjacency list /adjacency matrix find minimum spanning tree using Kruskal’s algorithm.

#include<iostream>
#define MAX 20
using namespace std;

typedef struct node
{
	int v1,v2,weight;
}node;

node path[MAX],source[MAX];
int component[MAX];
int e,v;

class kruskal
{
	public:
		kruskal()
		{
			for(int i=0;i<MAX;i++)
			component[i]=i;
		}
		void create();
		void sort();
		void algo();
		int find(int );
		void unite(int ,int );
		void display( );
};

void kruskal::create()
{
	cout<<"\nNo. Of Edges : ";
	cin>>e;
	cout<<"\nNo. Of Vertices : ";
	cin>>v;
	for(int i=0;i<e;i++)
	{
		cout<<"\n_______________________";
		cout<<"\nEDGE :";
		cout<<"\nVertex 1 : ";
		cin>>source[i].v1;		
		cout<<"Vertex 2 : ";
		cin>>source[i].v2;		
		cout<<"WEIGHT : ";
		cin>>source[i].weight;		
	}
	
}

void kruskal::sort()
{
	node temp;
	for(int i=0;i<e-1;i++)
	{
		for(int j=0;j<e-i-1;j++)
		{	
			if(source[j].weight > source[j+1].weight)
				{
					temp=source[j];
					source[j]=source[j+1];
					source[j+1]=temp;	
				}
		}
	}
}
void kruskal::algo()
{
   /* cout<<"\nCOMPONENT ..............\n";
	for(int i=0;i<e;i++)
	{		
		cout<<"\n"<<component[i];
	}*/

	int p=0; //pointer to path array
	int	x=0; //pointer to store array
    
	while(p < v-1) //as the final path will have (no. of vertex) - 1 edges.......so if vertex =5 then path=4 hence pn will pt 0 to 3
	{
		int a=find(source[x].v1);//it will return the component of a..
		int b=find(source[x].v2);//it will return the component of b..	
		//cout<<"\na:"<<a<<"\nb:"<<b;
		if(a != b)	//if the selected points are from diffrent components then add them in path
		{
			path[p++]=source[x]; // path created..
			unite(a,b);			// unite path by nameing both the component wiht same name..

		}
		x++;	
	}
}

int kruskal::find(int z)
{
	return component[z];
}

void kruskal::unite(int a,int b)
{
	for(int i=1;i<=v;i++)
	{
		if(component[i]==b)
		component[i]=a;
	}
  	/* cout<<"\nupdated COMPONENT ..............\n";
	for(int i=0;i<e;i++)
	{		
		cout<<"\n"<<component[i];
	}*/

}

void kruskal::display()
{
	int cost=0;
	for(int i=0;i<v-1;i++)
	{		
		cout<<"\nEDGE : "<<path[i].v1<<" "<<path[i].v2<<"\t"<<"WEIGHT : "<<path[i].weight;
		cost=cost+path[i].weight;
	}
	cout<<"\n\nTOTAL COST : "<<cost<<"\n\n";
}


int main()
{
	kruskal k;
	cout<<"\n\n***********IP DATA FOR KRUSKALS SHORTEST PATH**********\n\n";
	k.create();
	cout<<"\n\n***********KRUSKALS SHORTEST PATH**********\n\n";
	k.algo();	
	k.display();
}


