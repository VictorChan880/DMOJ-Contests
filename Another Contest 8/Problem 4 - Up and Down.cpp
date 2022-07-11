#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pi; 
 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
 
const int MM = 1e4+1; 
const int mod = 1e9+7;  

int n,q ; vector<int> adj[MM]; 
int grid[MM][MM]; 
vector< pair<pair<int,int>, int>> _dis[MM]; 
void dfs (int u) {
	for (int v: adj[u]) {
		if (_dis[v].size() == 1) {
			for (pair<pair<int,int>, int> dis : _dis[u]) {
				int up = dis.f.f, down = dis.f.s; 
				if (dis.s != u){
					_dis[dis.s].pb({{down, up+1}, v}); 
					grid[down][up+1]++; 
				}
				_dis[v].pb({{up+1, down} , dis.s});
				grid[up+1][down]++; 
			}
			_dis[u].pb({{0,1},v}); 
			grid[0][1]++; 
			dfs(v); 
		}
	}
}
int main() {
	cin >> n;
	grid[0][0] = n;
	for (int i =1; i <= n; i++) {
		_dis[i].pb({{0,0},i});
	}
	for (int i =0; i < n-1; i++) {
		int u, v; 
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);

	}
	dfs(1); 
	cin >> q; 
	for (int i = 0; i < q; i++) {
		int up, down; 
		cin >> up >> down;
		cout << grid[up][down] << endl; 
	}
}