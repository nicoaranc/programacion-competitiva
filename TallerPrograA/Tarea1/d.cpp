#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    map <long long, int> mapa;
    int resultado = 0;
    int propuesta = 0;
    for (int i = 0; i < n; i++){
        long long a; cin >> a;
        if (mapa.find(a) == mapa.end()){
            propuesta++;
            mapa[a] = i;
            if (i == n-1){
                if (propuesta > resultado){
                    resultado = propuesta;
                }
            }
        }
        else{
            int pos = mapa[a];
            if (pos < i-propuesta){
                propuesta++;
                mapa[a] = i;
                if (i == n-1){
                    if (propuesta > resultado){
                        resultado = propuesta;
                    }
                }
            }
            else{
                if (propuesta > resultado){
                    resultado = propuesta;
                }
                propuesta = i - mapa[a];
                mapa[a] = i;                
            }

        }
    }
    cout << resultado << endl;
}