#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

const int N=300010;
typedef long long ll;
//哈希表的s[0]表示偶数的下标为偶数的哈希表，s[1]表示下标为奇数的哈希表，第二维存储前缀和，
//比如s[0][sum]表示下标为偶数的并且异或前缀和为sum的个数。
unordered_map<int,int> s[2];
int sum=0,q[N];
ll res;//存储答案

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&q[i]);
    }

    s[0][sum]++;
    //对于区间[i,j]有Sj=Si-1
    for(int t=1;t<=n;t++){
        //计算当前的前缀和，
        sum^=q[t];

        //将之前的异或前缀和为sum的次数加入答案，
        res+=s[t&1][sum];

        //前两行的意思就是我求出来了一个当j=当前正在枚举的下标(t)的前缀和，
        //然后第二行就是把前边前缀和也为当前Sum的次数加入到答案中，
        //然后第三行是对前缀和为Sum的次数进行+1(因为这次又求出了前缀和为当前sum)
        s[t&1][sum]++;
    }
    
    cout<<res<<endl;
    return 0;

}
