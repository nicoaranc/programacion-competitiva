#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    long long k; cin >> k;
    multiset <long long> tiempos;
    long long maximo = 0;
    for (long long i = 0; i < n; i++){
        long long t; cin >> t;
        tiempos.insert(t);
        maximo = max(maximo, t);
    }
    long long i = 0;
    long long j = maximo * k;
    long long res = j;
    while (i < j){
        long long medio = i + ((j - i) / 2);
        long long figuras = 0;
        for (auto itr = tiempos.begin(); itr != tiempos.end(); itr++){
            long long tiempo = *itr;
            figuras += medio/tiempo;
            if (figuras >= k){
                break;
            }
        }
        if (figuras >= k){
            j = medio;
            res = medio;
        }
        else{
            i = medio + 1;
        }
    }
    cout << res << endl;
}
