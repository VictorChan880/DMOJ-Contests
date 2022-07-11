#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair< int ,int > pi; 
const int MM = 5e3+5;  
const int mod = 998244353 ; 
#define mp make_pair 
#define pb push_back
#define f first
#define s second
#define nl "\n"

int n,m,k, ans,a,b,c,d;  
int grid [MM][MM]; 
bool flag = false; 
bool check (int size) {
	for (int y = 1; y <= n - size + 1; y+=size) {
		for (int x = 1; x <= m - size + 1; x+= size) {
			int bit = grid[y][x]; 
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (grid[y+i][x+j] != bit) {
						return false; 	
					}
				}
			}
		}
	}
	return true; 
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); 
	cin >> n >> m >> k;
	for (int i = 0; i < k ; i++) {
		cin >> a >> b >> c >> d;
		grid[a][b]++; grid[c+1][d+1]++; 
		grid[a][d+1]--; grid[c+1][b]--; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			grid[i][j] = min(grid[i][j],1); 
		}
	}
	/*
	for (int i =1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cerr << grid[i][j] << " ";
		}
		cerr << nl; 
	}
	*/
	vector <int> size;
	for (int i = 1; i <= min(n,m); i*=2) {
		if (n%i != 0 || m%i != 0) break; 
		size.pb(i); 	
	}
	int l = 0, r = size.size()-1, ans = 0; 
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(size[mid])) {
			ans = mid; 
			l = mid+1;
		}
		else r = mid-1; 
	}
	cout << ans << nl; 
	

	
}
