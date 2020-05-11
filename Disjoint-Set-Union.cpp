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

ll size[1000001];
ll a[1000001];


void intialise(ll n)
{
    f(i,0,n)
    {
        a[i]=i;
        size[i]=1;
    }

}

ll root(ll i)
{
    while (a[i] != i)
	{
		a[i]=a[a[i]] ;
		i = a[ i ];
	}
    return i;
}

void union_(ll x, ll y)
{
   ll rootx=root(x);
   ll rooty=root(y);
    if(size[rooty]>size[rootx]) swap(x,y);
    a[rooty]=rootx;
    size[rootx]+=size[rooty];

}

bool check_connection(ll x, ll y)
{
   ll rootx=root(x);
   ll rooty=root(y);

    if(rootx==rooty) return true;
    else return false;

}


int main()
{
    intialise(5);
    if(check_connection(2,3)) cout<<"2 and 3 are connected before union"<<endl;
    else cout<<"2 and 3 are not connected before union"<<endl;
    union_(2,3);
    if(check_connection(2,3)) cout<<"2 and 3 are connected after union"<<endl;
    else cout<<"2 and 3 are not connected after union"<<endl;

}



















