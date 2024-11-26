#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int p = 0; p < t; p++){
        int n; cin >> n;
        int a = 0; // i
        int b = 0; // i
        int c = 0; // i
        int d = 0; // p
        int e = 0; // p
        int x = 0;
        int y = 0;
        for (int u = 1; u <= n; u++){ // necesito cualquiera de las siguientes combinaciones (p,p,i), (i,i,i)
            int m; cin >> m;
            if (x || y){
                continue;
            }
            else{
                if (m % 2 == 1){
                    if (!a){
                        a = u;
                    }
                    else if (!b){
                        b = u;
                    } 
                    else if (!c){
                        c = u;
                    }
                    if (a && b && c){
                        x = 1;
                    }
                    else if (a && d && e){
                        y = 1;
                    }          
                }
                else{
                    if (!d){
                        d = u;
                    }
                    else if (!e){
                        e = u;
                    }
                    if (a && d && e){
                        y = 1;
                    }                     
                }
            }
        }
        if (x){
            cout << "YES" << endl;
            cout << a << " ";
            cout << b << " ";
            cout << c << endl;
        }
        else if (y){
            cout << "YES" << endl;
            cout << a << " ";
            cout << d << " ";
            cout << e << endl;            
        }
        else{
            cout << "NO" << endl;
        }
    }
}