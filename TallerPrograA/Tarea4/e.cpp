#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    ll n, c, g;
    cin >> n >> c >> g;
    ll m = gcd(c, g);
    if (m == 1){ // Si uno de los pesos es primo
        if (c <= n && g <= n){
            cout << "SI" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else{
        ll x = c / m;
        ll y = g / m;
        if (x <= n && y <= n){
            cout << "SI" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}