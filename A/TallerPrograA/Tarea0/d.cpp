#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> valores;
    vector <int> prueba;
    prueba.assign(n,0);
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        valores.push_back(a);
    }
    int respuesta = 0;
    for (int i = 0; i < n; i++){
        if (valores[i] > n){
            respuesta++;
        }
        else{
            int x = valores[i];
            if (prueba[x-1] != 0){
                respuesta++;
            }
            else{
                prueba[x-1] = 1;
            }
        }
    }
    cout << respuesta << endl;
}