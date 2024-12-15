#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    long long k; cin >> k;
    vector <long long> numeros;
    long long maximo = 0;
    long long max_sum = 0;
    for (long long i = 0; i < n; i++){
        long long a; cin >> a;
        numeros.push_back(a);
        maximo += a;
        max_sum = max(max_sum, a);
    }
    long long i = max_sum;
    long long j = maximo;
    long long res = j;
    while (i < j){;
        long long medio = i + ((j - i) / 2);
        long long contador = 0;
        long long suma = 0;
        for (long long k = 0; k < n; k++){
            long long numero = numeros[k];
            if (suma + numero <= medio){
                suma += numero;
            }
            else{
                contador++;
                suma = numero;
            }
            if (k == n - 1){
                contador++;
            }
        }
        if (contador > k){
            i = medio + 1;
        }
        else{
            j = medio;
            res = j;
        }
    }
    cout << res;

}