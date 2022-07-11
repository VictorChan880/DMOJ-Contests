#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi; 

#define mp make_pair
#define pb push_back 
const int MM = 1e6; 
const int mod = 1e9+7; 

int n,m; map<int,int> aset, bset;  
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n>> m; 
	for (int i = 1; i <= n; i++) {
		int x;
		cin >>x;
		if (x != -1){
			if (aset.count(i-x-1) == 0) aset.insert(mp(i-x-1, 0)); 
			int tmp = aset.at(i-x-1);
			aset.erase(i-x-1);  
			aset.insert(mp(i-x-1, tmp+1)); 
			
		}
		
	}
	for (int i = 1; i <= m; i++) {
		int x; 
		cin >> x; 
		if (x != -1){
			if (bset.count(i-x-1) == 0) bset.insert(mp(i-x-1, 0)); 
			int tmp = bset.at(i-x-1);
			bset.erase(i-x-1);  
			bset.insert(mp(i-x-1, tmp+1)); 
			
		}
	}
	int ans = 0; 
	for (pi x : aset) {
		if (bset.count(x.first) != 0) {
			ans+= min(x.second, bset.at(x.first)); 
			bset.erase(x.first); 
		}
	}
	cout << ans << endl; 
}