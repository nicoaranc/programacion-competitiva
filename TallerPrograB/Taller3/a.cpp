#include <bits/stdc++.h>
using namespace std;

int main(){
    int c; cin >> c;
    for (int t = 0; t < c; t++){
        int n; cin >> n;
        vector <int> etiquetas;
        for (int r = 0; r < n; r++){
            int e; cin >> e;
            etiquetas.push_back(e);
        }
        int m; cin >> m;
        for (int r = 0; r < m; r++){
            string s; cin >> s;
            // condicion 1
            if (s.size() != n){
                cout << "NO" << endl;
                continue;
            }
            // condicion 2
            int cond2 = 1;
            map <char, int> mapa1;
            for (int i = 0; i < n; i++){
                char letra = s[i];
                if (mapa1.find(letra) == mapa1.end()){
                    int valor = etiquetas[i];
                    mapa1[letra] = valor;
                }
                else{
                    int valor = mapa1[letra];
                    if (valor != etiquetas[i]){
                        cond2 = 0;
                        break;
                    }
                }
            }
            if (!cond2){
                cout << "NO" << endl;
                continue;
            }
            // condicion 3
            int cond3 = 1;
            map <int, char> mapa2;
            for (int i = 0; i < n; i++){
                int valor = etiquetas[i];
                if (mapa2.find(valor) == mapa2.end()){
                    char letra = s[i];
                    mapa2[valor] = letra;
                }
                else{
                    char letra = mapa2[valor];
                    if (letra != s[i]){
                        cond3 = 0;
                        break;
                    }
                }
            }
            if (!cond3){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
        }
    }
}