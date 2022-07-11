#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair< ll,ll > pi; 
const int MM = 1e3+5;  
const int mod = 998244353 ; 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
#define nl "\n"
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; 
	cin >> n; 
	
	while (n--) {
		ll a,b;
		cin >> a >> b;
		int l = 0, r = 55, mid,ans; 
		while (l <= r) {
			mid = (l+r)/2; 
			map<ll, int> _map; 
			queue<ll> q; q.push(a);
			while (!q.empty()) {
				ll u =q.front(); q.pop();
				if (_map[u] + 1 > mid) continue; 
				if (2 * u >= 0 && _map.count(2*u) == 0 ){
					q.push(2*u); _map[2*u] = _map[u] + 1;
					if (2*u == b) break; 
				}
				if (u%2 == 0 && _map.count(u/2) == 0) {
					q.push(u/2); _map[u/2] = _map[u] + 1; 
					if (u/2 == b) break; 
	
				}
				if (2 * u >= 0 && _map.count(u+1) == 0){
					q.push(u+1); _map[u+1] = _map[u] + 1; 
					if (u+1 == b) break; 
				}
			}
			if (_map.count(b) == 0) l = mid+1;
			else {
				ans =  mid;
				r = mid-1;
			}
		}
		cout << ans << nl; 
	}
}