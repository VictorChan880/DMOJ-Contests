#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair 
#define pb push_back
typedef pair<int, int> pi; 
const int MM = 3e5+1; 
const int mod = 1e9+7; 
int n, m; 
vector <int> adj[MM];
int dp[MM]; bool vis[MM]; 
void dfs (int v) {
	vis[v] = true;
	for (int u : adj[v]) {
		if (v > u) dp[u] = max(dp[u],v);
		if (dp[v] > u) dp[u] = max(dp[v], dp[u]);
		if (!vis[u]) {dfs(u);} 
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) { 
	 	int u, v;
	 	cin >> u >> v;
	 	adj[v].pb(u);
	}
	for (int i = n; i >= 1; i--) {
		if (!vis[i]) dfs(i);
	}
	for (int i = n; i >= 1; i--) {
		if (dp[i] != 0 ) {
			cout << i << " " << dp[i] << endl;
			return 0;  
		}
	}
	cout << -1 << endl; 	
}