#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> canciones;
    for (int i = 0; i < n; i++){
        int s; cin >> s;
        canciones.push_back(s);
    }
    int res = 0;
    int aux = 0;
    int desc = 0;
    map <int, int> mapa;
    vector <int> largo;
    for (int i = 0; i < n; i++){
        int cancion = canciones[i];
        if (mapa.find(cancion) == mapa.end()){
            aux++;
            res = max(res, aux);
            largo.push_back(aux);
            mapa[cancion] = i + 1;
        }
        else {
            int pos = mapa[cancion];
            desc = max(pos, desc);
            aux = i + 1 - desc;
            res = max(res, aux);
            largo.push_back(aux);
            mapa[cancion] = i + 1;
        }
    }
    cout << res << endl;
}