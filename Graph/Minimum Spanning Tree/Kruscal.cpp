#include<bits/stdc++.h>
#define MAXN (1000+100)
using namespace std;

struct Te
{
    int a,b,v;
    bool operator<(const Te&tmp) const {return v>tmp.v;}
};

priority_queue<Te>q;

int n,m,fa[MAXN];

inline void first()
{
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) fa[i]=i;
}

int getFa(int x)
{
    return (x==fa[x]?x:(fa[x]=getFa(fa[x])));
}

int Kruscal()
{
    int ans=0,num=0;
    while(num<n-1)
    {
        if(q.empty()) return -1;
        Te now=q.top();q.pop();
        int xx=getFa(now.a),yy=getFa(now.b);
        if(xx==yy) continue;
        ans+=now.v;
        fa[xx]=fa[yy];
        num++;
    }
    return ans;
}

int main()
{
    //Kealine

    cin>>n>>m;
    first();
    while(m--)
    {
        int x,y,z;cin>>x>>y>>z;
        q.push(Te{x,y,z});
    }
    cout<<Kruscal()<<endl;

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
