#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010,M=N*2;

bool st[N];
int e[M],ne[M],h[N],idx;
int n=0,ans=N;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dfs(int u)
{
    st[u]=true;
    int res=0,sum=1;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(st[j]) continue;
        int s=dfs(j);
        res=max(res,s);
        sum+=s;
    }

    res=max(res,n-sum);
    //cout<<u<<" "<<res<<endl;
    ans=min(ans,res);
    return sum;
}

int main()
{
    scanf("%d",&n);
    int m=n-1;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }

    dfs(1);

    cout<<ans<<endl;

    return 0;

}
