#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair 
typedef pair<int, int> pi; 
const int MM = 1e6; 
const int mod = 1e9+7; 
double t, r1, r2, r3; 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r1 >> r2 >> r3; 
		double good = 0;
		double total = (r2 - r3)*(r2-r3); 
		if (r3 < r1) good += (r1-r3) * (r1-r3); 
		if ( (r1 + r3)*(r1+r3) < total ) good += total - (r1+r3) * (r1+r3);
		if (r3 > r1) good += min (r3-r1, r2-r3) * min (r3-r1, r2-r3); 
		cout << (double)good / total << endl;  
	}
}
