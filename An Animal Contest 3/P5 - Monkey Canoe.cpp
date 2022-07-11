#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi; 
 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
 
const int MM = (int)2e3+1; 
const int mod = 1e9+7; 
int dy []= {1,0,-1,0}, dx[] = {0,1,0,-1}; 
int n, m;  
map<int, int> adj[(int)2e6+1];
char grid[MM][MM]; 
int id[MM][MM], cnt = 1;
bool inq[(int)2e6+1];  
int dis[(int)2e6+1]; 
queue<pi> q; 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i =0; i < n; i++) {
		for (int j= 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i =0; i < n; i++) {
		for (int j= 0; j < m; j++) {
			if (grid[i][j] == '#' && id[i][j] == 0) {
				q.push({i,j}); 
				id[i][j] = cnt; 
				while (!q.empty()) {
					int y = q.front().f, x = q.front().s; q.pop();  
					for (int k = 0; k < 4; k++) {
						int ny = y+dy[k], nx = x+dx[k];
						if (ny >= 0 && ny < n && nx >= 0 && nx < m && id[ny][nx] == 0 && grid[ny][nx] =='#') {
							id[ny][nx] = cnt; 
							q.push({ny,nx}); 
						}
					}
				}
				cnt++; 
			}		
		}
	}
	for (int i =0; i < m; i++) {
		int pre = -1; 
		for (int j= 0; j < n; j++) {
			if (grid[j][i] == '#') {
				if (pre != -1 && id[pre][i] != id[j][i]) {
					int pre_id = id[pre][i], cur_id = id[j][i]; 
					if (adj[cur_id].count(pre_id) == 0) {
						adj[cur_id].insert({pre_id, j - pre-1}); 
						adj[pre_id].insert({cur_id, j - pre-1}); 
					}
					else {
						int dis = max( j - pre-1, adj[cur_id][pre_id]);
						adj[cur_id].erase(pre_id);
						adj[pre_id].erase(cur_id);
						adj[cur_id].insert({pre_id, dis}); 
						adj[pre_id].insert({cur_id, dis}); 

					}
				}
				pre = j; 
			}
		}
	}
	for (int i =0; i < n; i++) {
		int pre = -1; 
		for (int j= 0; j < m; j++) {
			if (grid[i][j] == '#') {
				if (pre != -1 && id[i][j] != id[i][pre]) {
					int pre_id = id[i][pre], cur_id = id[i][j]; 
					if (adj[cur_id].count(pre_id) == 0) {
						adj[cur_id].insert({pre_id, j - pre-1}); 
						adj[pre_id].insert({cur_id, j - pre-1}); 
					}
					else {
						int dis = max(j - pre-1, adj[cur_id][pre_id]);
						adj[cur_id].erase(pre_id);
						adj[pre_id].erase(cur_id);
						adj[cur_id].insert({pre_id, dis}); 
						adj[pre_id].insert({cur_id, dis}); 
					}
				}
			pre = j; 
			}
		}
	}
	priority_queue<pi> pq;
	cnt = 0;
	for (int i = 0; i < m; i++) {
		if (id[0][i] > cnt) {
			cnt++;
			for (pi v : adj[id[0][i]]) {
				if (v.s > dis[v.f]) {
					dis[v.f] = v.s; 
					pq.push({dis[v.f],v.f}); 
					inq[v.f] = true; 
				}
			}
			while (!pq.empty()) {
				pi u = pq.top(); pq.pop();
				inq[u.s] = false; 
				for (pi v : adj[u.s]) {
					if (dis[v.f] == 0 || dis[v.f] < min(v.s, dis[u.s])) { 
						dis[v.f] = min(v.s, dis[u.s]);
						if (!inq[v.f]) {
							pq.push({dis[v.f],v.f});  
							inq[v.f] = true; 
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (grid[n-1][i] == '#' && id[n-1][i] <= cnt) cout << 0;
		else if (grid[n-1][i] == '.' || dis[id[n-1][i]] == 0) cout << -1;
		else cout << dis[id[n-1][i]];
		if (i == m-1) cout << endl;
		else cout << " "; 
	}

}