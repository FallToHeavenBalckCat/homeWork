// 有向图的拓扑序列（拓扑序列的必是有向无环图)
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
int e[N],ne[N],h[N],idx;
int d[N];//保存每个点的入度
int q[N],hh,tt;//使用模拟对立来写，
int n,m;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool topolSort()
{
    hh=0,tt=-1;
    
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0) q[++tt]=i;
    }

    while(hh<=tt)
    {
        int t=q[hh++];

        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            d[j]--;
            if(d[j]==0) q[++tt]=j; 
        }
    }

    return tt==n-1;
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
        d[b]++;
    }
    if(!topolSort()) puts("-1");
    else
    {
        for(int i=0;i<n;i++)
        {
            cout<<q[i]<<" ";
        }
    }

    return 0;

}
