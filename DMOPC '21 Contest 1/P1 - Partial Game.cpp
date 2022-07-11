#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, ll> pi; 
 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
 
const int MM = 1e6+1;  
const int mod = 998244353 ;  


int n, a[MM];
vector <int> adj[MM]; 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	ll odd = 0, even = 0; 
	for (int i = 0; i < n; i++) {
		cin>> a[i];
		if (a[i]%2 == 0) {
			even += a[i]/2; 
		}
		else odd += (a[i]+1)/2; 
	}
	cout << ((odd >= even)? "Alice" : "Duke") << endl; 
	
}
