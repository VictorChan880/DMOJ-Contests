#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi; 

#define mp make_pair
#define pb push_back 
const int MM = 11; 
const int mod = 1e9+7; 

int k,d, a[MM]; 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> k >> d;
	for (int i = 0; i < d; i++) {
		cin >> a[i];
	}
	sort(a,a+d);
	if (a[0] == 0) {
		if (d == 1)cout << -1 << endl;
		else {
			cout << a[1]; 
			for (int i =0; i < k-2; i++) {
				cout << 0;
			}
			if (k > 1)cout << a[1];
			cout << endl;  
		}
	}
	else {
		for (int i =0; i < k; i++) {
			cout << a[0];
		}
		cout << endl; 
	}
}