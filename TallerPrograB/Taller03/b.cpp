#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        string s; cin >> s;
        int tamano = s.size();
        vector <int> presente(tamano, 1);
        stack <int> minus;
        stack <int> mayus;
        for (int j = 0; j < tamano; j++){
            char letra = s[j];
            if (letra != 'b' && letra != 'B'){
                if (isupper(letra)){
                    mayus.push(j);
                }
                else {
                    minus.push(j);
                }
            }
            else if (letra == 'b'){
                presente[j] = 0;
                if (!minus.empty()){
                    int pos_minus = minus.top();
                    minus.pop();
                    presente[pos_minus] = 0;                   
                }
            }
            else{
                presente[j] = 0;
                if (!mayus.empty()){
                    int pos_mayus = mayus.top();
                    mayus.pop();
                    presente[pos_mayus] = 0;
                }
            }
        }
        for (int j = 0; j < tamano; j++){
            if (presente[j]){
                cout << s[j];
            }
        }
        cout << endl;
    }
}