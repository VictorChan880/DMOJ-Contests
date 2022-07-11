#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi; 

#define mp make_pair
#define pb push_back 
#define f first
#define s second
const int MM = 1e6; 
const int mod = 1e9+7; 

int n, a[MM]; 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a,a+n); 
	int l = 0, r = n-1, cnt = 0;  
	if (n % 2 == 1) {
		if (n == 1) {
			cout << a[0] << endl;
			cout << "E" << endl;
			return 0; 
		}
		while (l <= r-2) {
			if (cnt %2 == 0){
				cout << a[l] << " "; 
				l++; 
			}
			else {
				cout << a[r] << " "; 
				r--; 
			}
			cnt++; 
		}
		cout << a[l] <<" "<< a[r] << endl; 
		l = 0; r = n-1; cnt = 0;  
		while (l <= r-2) {
			if (cnt %2 == 0){
				cout <<"B";
				l++; 
			}
			else {
				cout <<"S"; 
				r--; 
			}
			cnt++; 
		}
		cout << "ES" << endl; 
	}
	else {
		while (l <= r) {
			if (cnt %2 == 0){
				cout << a[l] <<" ";
				l++; 
			}
			else {
				cout << a[r];
				if (cnt == n-1) cout << endl;
				else cout << " "; 
				r--; 
			}
			cnt++; 
		}
		l = 0; r = n-1; cnt = 0; 
		while (l <= r) {
			if (cnt %2 == 0){
				cout <<"B";
				l++; 
			}
			else {
				cout << "S"; 
				r--; 
			}
			cnt++; 
		}
		cout << endl; 
	}
}