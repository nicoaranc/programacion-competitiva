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

ll coefBinMod(ll a, ll b, ll p){
    ll res;
    if (a == 0 || a == 1 || b == 0 || a == b){
        res = 1;
    }
    else{
        ll sup = factoriales[a] % MOD;
        ll inf = ((factoriales[b] % MOD)*(factoriales[a-b] % MOD)) % MOD;
        inf = invmod(inf, MOD);
        res = (sup*inf) % MOD;        
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    factoriales.resize((1e6)+1, 0);
    factoriales[0] = factoriales[1] = 1;
    for (int i = 2; i <= 1e6; i++){
        factoriales[i] = ((i%MOD) * (factoriales[i-1]%MOD))%MOD;
    }
    ll N, A, I, G;
    while (cin >> N >> A >> I >> G){
        ll res;
        ll combPorGrupo = coefBinMod(I,G,MOD);
        ll x = binpow(combPorGrupo,A,MOD);
        ll combDeGrupos = coefBinMod(N,A,MOD);
        ll y = ((x%MOD)*(combDeGrupos%MOD))%MOD;
        res = y;
        cout << res << endl;
        res = 0;
    }
}