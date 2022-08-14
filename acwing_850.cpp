//Dijkstra的堆优化写法
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N=150010;
int h[N],e[N],ne[N],w[N],idx;
bool st[N];
int dist[N];
int n,m;
typedef pair<int,int> PII;


void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    priority_queue<PII,vector<PII>,greater<PII>> q;
    //pair第一个参数表示距离，第二个参数表示序号
    q.push({0,1});
    
    while(q.size())
    {
        auto t=q.top();
        q.pop();
        
        int distance=t.first;
        int ver=t.second;

        if(st[ver]) continue;
        st[ver]=true;

        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[ver]+w[i])
            {
                dist[j]=dist[ver]+w[i];
                q.push({dist[j],j});
            }
        }
    }

    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];

}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,x;
        scanf("%d%d%d",&a,&b,&x);
        add(a,b,x);
    }
    cout<<dijkstra()<<endl;
    return 0;
}
