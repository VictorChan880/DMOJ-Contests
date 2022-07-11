#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+1;
int outDeg [MM], p [MM]; 
vector <int> adj [MM];
bool marked[MM];   
int n, m,u,v; 
void bfs (int x) {
	queue <int> q;
	q.push(x);
	while (!q.empty()) {
		int u = q.front(); q.pop(); 
		for (int v : adj[u]) {
			outDeg[v]--;
			if (!marked[v] &&(!outDeg[v] || p[v]))  {
				q.push(v); 
				marked[v] = 1; 
			}
		}
	}
}
int main(){
 	ios::sync_with_stdio(0); cin.tie(0);
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) cin >> p[i]; 
 	for (int i = 0; i < m; i++) {
 		int a, b; 
 		cin >> a >> b;
 		adj[b].push_back(a);
 		outDeg[a]++; 
 	}
 	for (int i = 1; i <= n; i++) {
 		if (!outDeg[i] && !marked[i]) {
 			marked[i] = true;
 			bfs(i);
 		}
 	}
 	for (int i = 1; i <= n; i++) {
 		cout << (marked[i] ? 1 : 0);
 		if (i == n) cout << endl;
 		else cout << " "; 
 	}
}
 	