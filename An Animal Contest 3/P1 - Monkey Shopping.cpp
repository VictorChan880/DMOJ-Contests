#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi; 

#define mp make_pair
#define pb push_back 
const int MM = 2e5; 
const int mod = 1e9+7; 

int a,b,c,d; 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> c >> d;
	if (a < b && c < d) {
		cout << "Go to the department store" << endl;
	}
	else if (a < b && c >= d) {
		cout << "Go to the grocery store" << endl;
	}
	else if (a >= b && c < d) {
		cout << "Go to the pharmacy" << endl;
	}
	else cout << "Stay home" << endl;
}