#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair< ll ,ll > pi; 
const int MM = 2e5+5;  
const ll mod = 1e10+7; 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
#define nl "\n"

int n,q;
ll a[MM], psa[MM]; 
ll gcd (ll a, ll b) {
	if (b == 0LL) return a;
	return gcd(b,a%b); 
} 
ll lcm (ll a, ll b) {
	return ((a%mod/gcd(a,b)) * b%mod)%mod; 
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) psa[i] = (lcm(psa[i-1], a[i]))%mod; 
		else psa[0] = a[i]; 	
	}
	for (int i = 0; i < q; i++) {
		ll t; 
		cin >> t;
		int l = 0, r= n-1, ans = -1; 
		while (l <= r) {
			int mid = (l+r)/2;
			if (t % psa[mid] != 0) {
				ans = mid+1;
				r = mid-1;
			}
			else l = mid+1; 
		}
		cout << ans << nl; 
	
	}
}
