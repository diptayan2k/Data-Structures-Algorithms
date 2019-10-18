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

ll BIT[1000], a[1000];
void update(ll x, ll delta, ll n)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
ll query(ll x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

ll n;
cin>>n;
f(i,1,n) {cin>>a[i]; update(i,a[i],n);}
ll q;
cin>>q;
while(q--)
{
    //cout<<"Enter the range: ";
    ll l,r;
    cin>>l>>r;
    cout<<"Sum :"<<query(r)-query(l-1)<<endl;
}

}





