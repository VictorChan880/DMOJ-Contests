#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair< int ,int > pi; 
const int MM = 1e6+5;  
const int mod = 998244353 ; 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
#define nl "\n"
struct cmp {
	bool operator () (pi x, pi y) {
		if (x.f == y.f) return x.s > y.s; 
		else return x.f > y.f; 
	}
};
int n,m; 
string str; 
pi a[MM]; 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	cin >> str;
	for (int i =0 ; i < m ;i++) {
		cin >> a[i].f;
	}
	int idx = 0; 
	for (int i =0 ; i < n ;i++) {
		if (str[i] == '0') {
			a[idx++].s = i; 
		}
	}
	sort(a,a+m,cmp());
	int x = a[0].s;
	//cerr << x << nl; 
	for (int i = x+1; i < n; i++) {
		if (str[i] == '0') continue;
		cout << str[i]; 
	}
	for (int i = 0; i < x; i++) {
		if (str[i] == '0') continue;
		cout << str[i]; 
	}
	cout << nl; 
}