 #include<iostream>
 #include<string.h>
 using namespace std;
 #define MAX1 15
 #define INFINITY 999
 
 class Graph
 {
 
 int n,sum,i,j,k,e,wt,m,l,min,temp;
 int g[MAX1][MAX1],visited[MAX1];

 public:  
  Graph()
  {
  sum=0;
  }
 
  void readGraph()
  {
   cout<<"Emter the value of n: ";
   cin>>n;
   
   for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
    {
     if(i==j)
     g[i][j]=0;
     else
     g[i][j]=INFINITY;
    }
   }
   
   cout<<"Enter the no of edges: ";
   cin>>e;
   
   for(k=0;k<e;k++)
    {
     cout<<"Enter i and j: ";
     cin>>i>>j;
     
     //cout<<"Enter j: ";
     //cin>>j;  
    
     if(i==j)
     k--;
     else
     {
       cout<<"Enter weight: ";
       cin>>wt;
       g[i][j]=wt;
       g[j][i]=wt;
     }
    }
  }
  
  void display()
  {
  
  }
  
  void prims()
  {
  for(i=0;i<n;i++)
  {
   visited[i]=0;   
  }
  visited[0]=1;
  
  for(int pass=0;pass<n-1;pass++)
  {
      min=99;
      
        for(i=0;i<n;i++)
 	{
     		temp=99;
     		if(visited[i]==1)
     		{
     		 for(j=0;j<n;j++)
  		{
   		     if(g[i][j]<temp && visited[j]==0)
   		     {
   		     temp=g[i][j];
   		     k=j;
   		     }
  		}
  		if(min>temp)
  		{
  		min=temp;
  		l=i;
  		m=k;  		  		
     		}
     		}   
  	}
	sum=sum+min;
	visited[m]=1;
	cout<<"\nFrom node "<<l<<"-"<<m<<" ";  	
  }
  cout<<"\nmin cost of spanning tree is: "<<sum<<"\t";
  }
};
 
int main()
{
 Graph g;
 g.readGraph();
 g.prims();
 return 0;
}
