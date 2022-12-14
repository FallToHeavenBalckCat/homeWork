//图中点的层次
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N=100010;
int e[N],ne[N],h[N],idx;
int n,m;
int d[N];
queue<int> q;


void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int bfs()
{
    memset(d,-1,sizeof d);
    d[1]=0;
    q.push(1);
    while(q.size())
    {
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(d[j]==-1)
            {
                d[j]=d[t]+1;
                q.push(j);
            }
        }
    }

    return d[n];
       
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}
