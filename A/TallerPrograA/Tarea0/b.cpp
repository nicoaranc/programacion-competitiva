#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        int m; cin >> m;
        if (n > m){
            cout << n << endl;
        }
        else{
            cout << m << endl;
        }
    }
}