#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    vector <long long> empanadas;
    for (long long i = 0; i < n; i++){
        long long a; cin >> a;
        empanadas.push_back(a);
    }
    sort(empanadas.begin(), empanadas.end());
    long long maximo = n/2;
    if (n%2 == 0){
        maximo--;
    }
    long long i = 0;
    long long j = maximo;
    vector <long long> baratos;
    vector <long long> caros;
    vector <long long> respuesta;
    vector <long long> respuesta_final;
    long long res = 0;
    while (i <= j){
        respuesta.clear();
        baratos.clear();
        caros.clear();
        long long medio = i + ((j - i) / 2);
        for (int k = 0; k < n; k++){
            long long empanada = empanadas[k];
            if (k < medio){
                baratos.push_back(empanada);
            }
            else{
                caros.push_back(empanada);
            }
        }
        long long caro = 1;
        long long barato = 0;
        if (!caros.empty()){
            respuesta.push_back(caros[0]);
        }
        while (caro < caros.size()){
            if (barato < baratos.size()){
                if (baratos[barato] < caros[caro] && baratos[barato] < caros[caro-1]){
                    respuesta.push_back(baratos[barato]);
                    barato++;
                }
            }
            respuesta.push_back(caros[caro]);
            caro++;
        }
        if (caro == caros.size() && barato == baratos.size()){
            respuesta_final = respuesta;
            i = medio + 1;
            res = i;
        }
        else{
            j = medio - 1;
        }
    }
    res--;
    cout << res << endl;
    if (res != 0){
        for (long long k = 0; k < n; k++){
            cout << respuesta_final[k] << " ";
        }
    }
    else {
        for (long long k = 0; k < n; k++){
            cout << empanadas[k] << " ";
        }
    }
    cout << endl;
}