#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n, split; 
ll l= 0, r, MIN = 10e15; 
int main(){
 	ios::sync_with_stdio(0); cin.tie(0);
 	cin >> n;
 	int a [n*2+1]; 
 	for (int i = 0; i < n; i++) {
 		cin >> a[i] ;
 		a[i+n] = a[i];
 		r += a[i]; 
 		
 	}

 	for (int i = 0; i < n; i++ ) {
 		if (abs(l+a[i]-(r-a[i])) < MIN) {
 			l += a[i]; r -= a[i]; 
 			MIN = abs(l-r);
 			split = i+1;
 		} 
 		else break; 
 	}
 	cout << MIN << " "; 
 	for (int i = 0 ; i< n-1; i++) {
 		l -= a[i], r += a[i];
 		MIN = abs(l-r); 
 		while (true) {
 			if (abs (l+a[split]-(r-a[split])) < MIN) {
 				l+= a[split];
 				r-=a[split]; 
 				MIN = abs (l-r); 
 				split++;
 			}
 			else break; 
 		}
 		cout << MIN; 
 		if (i != n-2) cout << " ";  
 	}
 	cout << endl; 
}
 	