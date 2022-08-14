//Dijkstra的朴素做法
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510;
int g[N][N];
int dist[N];
bool st[N];
int n,m;


int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    //外层循环表示做n次处理，每次处理可以得到一个点的最短路径
    for (int i=0;i<n;i++)
    {
        int t=-1; 
        //这个过程中就是在寻找不在S集合中并且距离最近的点
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1 ||  dist[t] > dist[j])) t=j;   
        }

        //这个过程是在对最短路径进行更新。
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }

        //用t更新完最短路径之后，将t加入到最短路径之中。
        st[t]=true;
    }

    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
    
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int a,b,x;
        scanf("%d%d%d",&a,&b,&x);
        g[a][b]=min(g[a][b],x);
    }
    
    cout<<dijkstra()<<endl;
    return 0;

}
