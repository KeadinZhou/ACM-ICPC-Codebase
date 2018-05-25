#include<bits/stdc++.h>
#define MAXN (1000+100)
#define INF (1000000000)
using namespace std;

struct Te
{
    int a,b,v;
    bool operator<(const Te&tmp) const {return v>tmp.v;}
}MIN;

priority_queue<Te>q;
vector<Te>es[MAXN];

int n,m;
bool used[MAXN];

inline void first()
{
    MIN.v=INF;
    while(!q.empty()) q.pop();
    memset(used,0,sizeof used);
}

void push(int x)
{
    used[x]=1;
    int cnt=es[x].size();
    for(int i=0;i<cnt;i++)
    {
        if(used[es[x][i].a]^used[es[x][i].b])
        {
            q.push(es[x][i]);
        }
    }
}

int Prim(int x)
{
    push(x);
    int ans=0,num=0;
    while(num<n-1)
    {
        if(q.empty()) return -1;
        Te now=q.top();q.pop();
        if(!(used[now.a]^used[now.b])) continue;
        ans+=now.v;num++;
        if(!used[now.a]) push(now.a);else push(now.b);
    }
    return ans;
}

int main()
{
    //Kealine

    first();
    cin>>n>>m;
    while(m--)
    {
        int x,y,z;cin>>x>>y>>z;
        Te tmp=Te{x,y,z};
        if(tmp.v<MIN.v) MIN=tmp;
        es[x].push_back(tmp);
        es[y].push_back(tmp);
    }
    cout<<Prim(MIN.a)<<endl;

    return 0;
}
/*
5 8
1 2 6
1 3 3
1 4 2
1 5 1
2 3 10
3 4 8
3 5 7
4 5 5
*/
