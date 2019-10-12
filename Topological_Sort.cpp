#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
using namespace std;

stack<ll> s;
vector<ll> v[100001];
bool vis[100001];
void topological_sort(ll u)
{
    vis[u]=true;
    //cout<<u<<" ";

    if(!v[u].empty())
    {
        f(i,0,v[u].size()-1)
        {
            if(!vis[v[u][i]])
            {
                topological_sort(v[u][i]);
                           }
        }
    }
     s.push(u);

}

int main()
{   memset(vis,false,sizeof(vis));
    ll n,m;
    cin>>n>>m;
    f(i,0,m-1)
    {  ll x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    f(i,1,n)
    {
        if(!vis[i]) topological_sort(i);
    }

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}



















