#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TC int t; cin >> t; while(t--)
#define rep(i,j,k) for(int i=j; i<k; i++)
#define endl '\n'
#define pb push_back

const int MAX = 1e6+6;
const int MOD = (int) 1e9+7;

ll modmul(ll a,ll b){ll res=0;a%=MOD;while(b){if(b&1)res=(res+a)%MOD;a=(a<<1)%MOD;b>>=1;}return res;}
ll modexp(ll a,ll b){ll res=1;a%=MOD;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}

vector<int> G[MAX],child;
int sum=0;
int dfs(int u,int par,int sum=0)
{	
	child[u] = u;
	for(auto x : G[u])
	{
		if(x == par)continue;
		dfs(x,u,0);
		sum += child[x]; 
	}
	child[u] += sum;
	return 0;
}
int32_t main() {
    IOS;
    int n,m,u,v;
    cin >> n >> m;
    rep(i,0,m)
    {
    	cin >> u >> v;
    	G[u].pb(v);G[v].pb(u);
    }
    child.resize(n+1);
    dfs(1,0);
    rep(i,1,n+1)cout << child[i] << ' ';
    return 0;
}


//	  		1
//	 	   / \
//		  2   3
//		 / \ 
//		4   5


// 15 11 3 4 5
