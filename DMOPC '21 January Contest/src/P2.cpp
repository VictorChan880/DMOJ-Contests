#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair< char, int > pi; 
const int MM = 1e5 + 5;  
const int mod = 998244353 ; 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
#define nl "\n"
int m, n; 
 	

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<int> a;
	if (n == 1) {
		cout << 1 << nl; return 0;
	}
	if (n == 2) {
		cout << -1 << nl; return 0;
	}
	a.pb(1); a.pb(3); a.pb(2);
	ll sum = 6; 
	for (int i = 4; i <= n; i++) {
		a.pb(i); sum = sum + i; 
	}
	for (int i = 1; i * i <= sum; i++) {
		if (sum % i == 0) {
			for (int j = 0; j < a.size(); j++) {
				cout << a[j] <<(j == a.size()-1 ? nl : " ");
			}
			return 0; 
		}
	}
	cout << -1 << nl; 
	
}