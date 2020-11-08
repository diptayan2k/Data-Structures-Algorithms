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

ll n;
vector<vector<ll> > par(200001, vector<ll>(21, -1));
vector<ll> v[200001];
ll lev[200001];

void dfs(ll u, ll p)
{
	lev[u] = lev[p] + 1;
	par[u][0] = p;

	for (auto i : v[u])
	{
		if (i == p) continue;
		dfs(i, u);
	}
}

ll kthanc(ll x, ll k)
{
	for (int i = 20; i >= 0; i--)
	{
		if (((1ll << i)&k) != 0) x = par[x][i];
	}

	return x;
}

ll lca(ll x, ll y)
{
	if (lev[y] > lev[x]) swap(x, y);
	x = kthanc(x, lev[x] - lev[y]);

	if (x == y) return x;

	for (int i = 20; i >= 0; i--)
	{
		if (par[x][i] != 0 and par[x][i] != par[y][i])
		{
			x = par[x][i];
			y = par[y][i];
		}
	}

	return par[x][0];

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
    
    lev[0] = -1;
	dfs(1, 0);
	par[1][0] = -1;

	for (int j = 1; j <= 20; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			ll u = par[i][j - 1];
			if (u != -1)
			{
				par[i][j] = par[u][j - 1];
			}
		}
	}

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


