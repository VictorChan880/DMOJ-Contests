#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair 
typedef pair<int, int> pi; 
const int MM = 1e6; 
const int mod = 1e9+7; 
int t;
ll gcd (ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b,a%b); 
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		ll a,b; 
		cin >> a >> b;
		ll GCD = gcd(a,b); 
		a/= GCD;
		b/=GCD;
		ll tmp = b; 
		int cnt_2 = 0; 
		int cnt_5 = 0; 
		while (tmp>0) {
			if (tmp%2 != 0) break;
			tmp/=2;
			cnt_2++; 
		}
		while (tmp>0) {
			if (tmp%5 != 0) break;
			tmp/=5;
			cnt_5++; 
		}
		cout << (tmp == 1? max(cnt_5, cnt_2) : -1) << endl; 
	}
}
