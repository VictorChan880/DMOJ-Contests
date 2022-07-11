#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair 
typedef pair<ll, int> pi; 
const int MM = 4e5+5; 
const int mod = 1e9+7; 
int n;
map<ll,int> _map1, _map2; 
ll arr[MM];  
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	ll a =0, b= 0; 
	for (int i = 0; i < 2*n+1; i++) {
		ll x;
		cin >> x;
		arr[i] = x; 
		a^= x;
	}
	for (int i = 0; i < 2*n+1; i++) {
		ll x;
		cin >> x;
		b^= x;
		if (_map1.count(x) == 0) _map1.insert(mp(x,0));
		int tmp = _map1.at(x);
		_map1.erase(x);
		_map1.insert(mp(x,tmp+1)); 
	}
	
	ll c = a^b; 
	for (int i = 0; i < 2*n+1; i++) {
		ll x = arr[i] ^ c; 
		if (_map2.count(x) == 0) _map2.insert(mp(x,0));
		int tmp = _map2.at(x);
		_map2.erase(x);
		_map2.insert(mp(x,tmp+1)); 
	}
	for (int i = 0; i < 2*n+1; i++) {
		ll x = arr[i] ^ c; 
		if (_map1.count(x) == 0 || _map1.at(x) != _map2.at(x)) {
			cout << -1 << endl;
			return 0; 
		}
	}
	cout << c << endl; 
}