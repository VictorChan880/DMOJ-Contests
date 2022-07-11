#include <bits/stdc++.h>
using namespace std;
int ans = 0;
bool found = false; 
void make_24 (int A, int B, int c ,int d, int result) {
	int a[]={A,B,c,d}; 
	if (found) return; 
	if (result == 24) {
		cout << 24 << endl;
		found = true; 
		return; 
	} 
	ans = max(ans,result); 
	for (int i = 0; i < 4; i++) {
		if (a[i] != 0) {
			for (int j = i+1; j < 4; j++) {
				if (a[j] != 0) {
					int b[4];
					copy (a,a+4,b); 
					b[i] = b[j] = 0; 
					make_24(b[0],b[1],b[2],b[3], a[i] + a[j]);
					make_24(b[0],b[1],b[2],b[3], a[i] * a[j]);
					if (a[j] >= a[i])make_24(b[0],b[1],b[2],b[3], a[j] - a[i]);
					if (a[i] >= a[j])make_24(b[0],b[1],b[2],b[3], a[i] - a[j]);
					if (!(a[i] % a[j]))make_24(b[0],b[1],b[2],b[3], a[i] / a[j]);
					if (!(a[j]%a[i])) make_24(b[0],b[1],b[2],b[3], a[j]/ a[i]); 
				}
			}
		}
	}
}
int main(){
 	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >>n;
	for (int i = 0; i < n ; i++ ) {
		vector<int> a;  
		for (int i = 0; i < 4; i++) {
			cin  >> a[i]; 
		}
		ans = 0; 
		found = false; 
		make_24(a[0],a[1],a[2],a[3],0);
		if (!found) cout << ans << endl; 
	}
	
 	}