#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> mem;
    int n; cin >> n;
    int x; cin >> x;
    vector <int> alturas;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        alturas.push_back(a);
    }
    mem.resize(n,1);
    long long maximo = 1;
    for (int i = 0; i < alturas.size(); i++){
        long long contador = 0;
        for (int j = i + 1; j < alturas.size(); j++){
            if (i == 0){
                if (alturas[j] - alturas[j-1] > x){
                    mem[i] = contador + 1;
                    if (contador + 1 > maximo){
                        maximo = contador + 1;
                    }
                    break;
                }
                else{
                    contador += 1;
                    if (j == alturas.size() - 1){
                        mem[i] = contador + 1;
                        if (contador + 1 > maximo){
                            maximo = contador + 1;
                        }
                        break;
                    }
                }
            }
            else{
                if (mem[i-1] > 1){
                    mem[i] = mem[i-1] - 1;
                    break;
                }
                if (alturas[j] - alturas[j-1] > x){
                    mem[i] = contador + 1;
                    if (contador + 1 > maximo){
                        maximo = contador + 1;
                    }
                    break;
                }
                else{
                    contador += 1;
                    if (j == alturas.size() - 1){
                        mem[i] = contador + 1;
                        if (contador + 1 > maximo){
                            maximo = contador + 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    cout << maximo << endl;
}