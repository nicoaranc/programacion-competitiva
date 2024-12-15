#include <bits/stdc++.h>
using namespace std;

vector <long long> dp;
long long minimo = -1e9;
long long n, k;
map <long long, long long> mapa;
vector <long long> diferencias;


long long func(long long x){
    if (x <= 0 || mapa[x] == 0){
        return minimo;
    }
    long long pos = mapa[x] - 1;
    if (dp[pos] != -1){
        return dp[pos];
    }
    else{
        long long maximo = 1;
        for (long long i = 0; i < k; i++){
            long long diferencia = diferencias[i];
            if (mapa[x] > mapa[x-diferencia]){
                long long a = 1 + func(x-diferencia);
                maximo = max(maximo, a);
                dp[pos] = maximo;            
            }
            
        }
        return dp[pos];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    
    for (long long i = 0; i < n; i++){
        long long s; cin >> s;
        mapa[s] = i+1;
    }
    
    for (long long i = 0; i < k; i++){
        long long d; cin >> d;
        diferencias.push_back(d);
    }

    dp.resize(n, -1);
    dp[0] = 1;

    long long res = minimo;

    for (auto it = mapa.begin(); it != mapa.end(); it++){
        long long num = it->first;
        long long a = func(num);
        res = max(res, a);
        
    }

    cout << res << endl;
}