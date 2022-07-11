#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair 
typedef pair<int, int> pi; 
const int MM = 1e6; 
const int mod = 1e9+7; 
string s; 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for (int i = 0; i < 27; i++) {
		if (s.find((char)('a' + i)) == string::npos) {
			cout << (char)('a' + i) << endl;
			break;
		}
	}
	
	
}