#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll p[100001][20];
vector<ll> v[100001];
ll lev[100001];
bool vis[100001];
ll n;

void dfs(ll u)
{
    vis[u]=true;

    for(auto i: v[u])
    {
        if(!vis[i])
        {
            lev[i]=lev[u]+1;
            p[i][0]=u;
            dfs(i);
        }
    }

}

void setval()
{
    init(p,-1);
    init(lev,0);
    init(vis,false);
    dfs(1);


    f(i,1,19)
    {
        f(j,1,n)
        {
            if(p[j][i-1]!=-1)
            {
                p[j][i]=p[p[j][i-1]][i-1];
            }
        }

    }





}

ll lca(ll u, ll v)
{
    if(lev[u]<lev[v]) swap(u,v);
    ll i,lg;
    for(lg=0;(1<<lg)<=lev[u]; lg++);
    lg--;



    for(i=lg;i>=0;i--)
    {
        if((lev[u]-(1<<i))>=lev[v])
            u=p[u][i];

    }


    if(u==v) return u;



    for(i=lg;i>=0;i--)
    {
        if(p[u][i]!=-1 and p[u][i]!=p[v][i])
        {
            u=p[u][i];
            v=p[u][v];
        }
    }

    return p[u][0];


}



int main()
{

    cin>>n;

    f(i,1,n-1)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    setval();

    cout<<lca(3,7);


}

/*
8
1 2
1 8
2 3
2 4
4 5
5 6
6 7
*/


