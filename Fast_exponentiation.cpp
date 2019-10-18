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

ll m=1000000007;
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % m;
    p = (p%m * p%m) % m;

    return (y%2 == 0)? p%m : (x%m * p%m) % m;
}

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
ll t;
cin>>t;
while(t--)
{

    ll x,y;
    cin>>x>>y;
    cout<<power(x,y);



}

}
