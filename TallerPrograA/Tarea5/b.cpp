#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    ll n; cin >> n;
    ll a;
    ll res;
    if (n % 3 == 0){
        if (n % 2 == 0){
            a = n - 4;
            a /= 2;
            res = a*n + (n/3);
        }
        else{
            a = n - 3;
            a /= 2;
            res = a*n + (n/3);            
        }
    }
    else{
        a = n - 1;
        a /= 2;
        res = n * a;   
    }
    cout << res << endl;
}