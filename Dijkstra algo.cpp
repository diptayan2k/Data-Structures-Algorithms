#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define INF 1000000000000000000
using namespace std;


vector<pair<ll,ll> > v[200001];
ll n,m;
ll dis[200001];

void dijkstra(ll src)
{
    for(ll i=1;i<=n;i++) dis[i]=INF;
    dis[src]=0;
    set<pair<ll,ll> > st;
    st.insert({0,src});

    while(!st.empty())
    {
        pair<ll,ll> tmp=*(st.begin());
        ll p=tmp.S;
        st.erase(st.begin());
        for(auto i:v[tmp.S])
        {
            ll u=i.F;
            ll wt=i.S;
            if(dis[u]>dis[p]+wt)
            {
                if(dis[u]!=INF)
                {
                    st.erase(st.find({dis[u],u}));
                }
                dis[u]=dis[p]+wt;
                st.insert({dis[u],u});


            }

        }
    }
}



int main()
{
    cin>>n>>m;

    for(ll i=0;i<m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        v[x].pb({y,w});
        v[y].pb({x,w});
    }
    ll src;
    cin>>src;
    dijkstra(src);
    for(ll i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;


}
