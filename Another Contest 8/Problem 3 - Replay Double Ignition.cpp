#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pi; 
 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
 
const int MM = 1e6+1; 
const int mod = 1e9+7;  

ll  n, m,q; ll f[MM]; 

int main() {
	cin >> m >> q;
	f[0] = f[1] = 1; 
	string ans = "11"; 
	for (int i = 2; i < (int)1e9; i++) {
		f[i] = (f[i-1] + f[i-2])%m;
		ans += to_string(f[i]); 
		if ((f[i] + f[i-1])%m == 0 && (2*f[i] + f[i-1])%m == 1) {
			ans += "0"; 
			break;
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> n; 
		n--; 
		cout << ans[n%ans.length()] << endl; 
	}
}