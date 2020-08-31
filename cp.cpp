#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define lld long double
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<=b;i++)
#define g(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
#define bits(x) __builtin_popcountll(x)
#define op(x) cout<<"Case #"<<x<<": "
#define op1(x) cout<<"Scenario #"<<x<<": "
#define endl "\n"
using namespace std;
const ll mod = 1000000007;
const ll INF = LLONG_MAX;
const ll NEGINF = LLONG_MIN;
const int N = 18;
const ll MAXN = 1000001;


struct trie
{
	struct trie *children[26];
	bool isEndOfWord;
	ll count = 0;
};


struct trie *getNode(void)
{
	struct trie *pNode =  new trie;

	pNode->isEndOfWord = false;
	pNode->count = 0;


	for (int i = 0; i < 26; i++)
		pNode->children[i] = NULL;

	return pNode;
}


void insert(struct trie *root, string & key)
{
	struct trie *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (pCrawl->children[index] == NULL)
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
	pCrawl->count++;
}


bool search(struct trie *root, string key)
{
	struct trie *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL and pCrawl->isEndOfWord);
}

void dfs(struct trie *node)
{

	for (int i = 0; i < 26; i++)
	{
		if (node->children[i] != NULL)
		{
			dfs(node->children[i]);
		}
	}
}

void solve(int t)
{

	ll n;
	cin >> n;

	string s;

	trie *root = getNode();


	for (int i = 0; i < n; i++)
	{
		cin >> s;
		insert(root, s);
	}

	dfs(root);

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int t = 1;
	cin >> t;



	for (int i = 1; i <= t; i++)
	{
		solve(i);

	}
}