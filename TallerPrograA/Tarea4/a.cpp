#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

vector <ll> factoriales;

ll binpow(ll a, ll b, ll p){
    ll ans = 1;
    ll actual = a;
    while (b > 0){
        if (b % 2 == 1){
            ans = (ans * actual) % p;
        }
        actual = (actual * actual) % p;
        b /= 2;
    }
    return ans;
}

ll invmod(ll a, ll p){
    return binpow(a, p-2, p);
}


int main(){
    ios::sync_with_stdio(0);
    factoriales.resize((1e6)+1, 0);
    factoriales[0] = factoriales[1] = 1;
    for (int j = 2; j <= 1e6; j++){
        factoriales[j] = ((j%MOD) * (factoriales[j-1]%MOD))%MOD;
    }
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        // Precomputamos los factoriales % MOD
        ll res;
        ll a, b;
        cin >> a;
        cin >> b;
        if (a == 0 || a == 1 || b == 0 || a == b){
            res = 1;
            cout << res << endl;
        }
        else{
            ll sup = factoriales[a] % MOD;
            ll inf = ((factoriales[b] % MOD)*(factoriales[a-b] % MOD)) % MOD;
            inf = invmod(inf, MOD);
            res = (sup*inf) % MOD;
            cout << res << endl;
        }

    }
}
