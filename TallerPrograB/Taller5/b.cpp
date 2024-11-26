#include <bits/stdc++.h>
using namespace std;
long long maximo = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int y = 0; y < t; y++){
        int n; cin >> n;
        int m; cin >> m;
        vector <int> alturas;
        for (int j = 0; j < n; j++){
            int a; cin >> a;
            alturas.push_back(a);
        }
        long long i = 0;
        long long j = maximo;
        long long res = 1;
        while (i < j){
            long long medio = i + ((j - i) / 2);
            long long agua = 0;
            for (int k = 0; k < n; k++){
                int alt = alturas[k];
                if (alt < medio){
                    agua += medio - alt;
                }
                if (agua > m){
                    break;
                }
            }
            if (agua <= m){
                res = max(res, medio);
                i = medio + 1;
            }
            else{
                j = medio ;
            }
        }
        cout << res << endl;
    }
}