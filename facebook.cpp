#include <iostream>
#define MAX 100
using namespace std;
struct node
{
    int vertex,comments,month,friends;
    node *next;

};
class graph
{
    int visited[MAX],n,edges;
    node *g[MAX];
    node v[MAX];
    public: graph(){}
    void ins(int vi,int vj);
    void read();
    void bday();
    void max_f();
    void max_c();
    void dfs();
    void dfs1(int);
    void bfs();

};
void graph::read()
{
    int vi,vj,i;
    cout<<"Enter No of Users";
    cin>>n;
    for(i=0;i<n;i++)
    {
        g[i]=NULL;
        v[i].friends=0;
        cout<<"\n Enter Data For User"<<i<<"\n Enter Month Of Birth\n";
        cin>>v[i].month;
        cout<<"Enter No of comments\n";
        cin>>v[i].comments;
    }
    cout<<"\nEnter No Of edges\n";
    cin>>edges;
    for(i=0;i<edges;i++)
    {
        cout<<"\n Enter Edge";
        cin>>vi>>vj;
        ins(vi,vj);
        ins(vj,vi);
    v[vi].friends=v[vi].friends+1;
    //v[vj].friends=v[vj].friends+1;
    v[vj];
    }
}

void graph::ins(int vi,int vj)
{
    node *p,*q;
    q=new node;
    q->vertex=vj;
    q->next=NULL;
    if(g[vi]==NULL)
    {
        g[vi]=q;
    }
    else
    {
        p=g[vi];
        while(p->next!=NULL)
        {
            p=p->next;

        }
        p->next=q;

    }
    }
void graph ::dfs()
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    dfs1(0);
}

void graph::dfs1(int i)
{
        node *p;
        cout<<"\nI::"<<i;
        p=g[i];
        visited[i]=1;
        while(p!=NULL)
        {
         i=p->vertex;
         if(!p->vertex)
         {
            dfs1(i);
         }
         p=p->next;
        }
}

int main()
{
   graph g1;
   g1.read();
   g1.dfs();
}

