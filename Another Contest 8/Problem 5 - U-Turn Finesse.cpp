#pragma GCC optimize("Ofast", "unroll-loops")
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi; 
 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
 
const int MM = 1e6+5; 
const int mod = 998244353 ;  

int n,t ; 
ll bit[MM], dp_right[MM], dp_left[MM], a[MM], b[MM]; map<int, int> _map;  
void update (int idx, ll val) {
	while (idx <= n) {
		bit[idx] = (bit[idx] + val)%mod; 
		idx += idx & -idx; 
	}
}
ll query (int idx) {
	ll ret = 0;
	while (idx > 0) {
		ret = (ret + bit[idx])%mod;
		idx -= idx & -idx; 
	}
	return ret; 
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> t; 
	while (t--) {
		scan(n); 
		for (int i = 0; i < n; i++) {
			bit[i+1] = 0; 
			scan(a[i]); 
		}
		for (int i = 0; i < n; i++) {
			dp_left[i] = (1 + query(a[i]-1))%mod; 
			update(a[i], dp_left[i]); 
		}
		for (int i =0; i <= n; i++) bit[i] = 0; 
		ll ans = 0; 
		for (int i = n-1; i >= 0; i--) {
			dp_right[i] = (1 + query(a[i]-1))%mod; 
			ans = (ans + dp_right[i] * dp_left[i])%mod; 
			update (a[i], dp_right[i]); 
		}
		cout << ans << "\n"; 
	}
}