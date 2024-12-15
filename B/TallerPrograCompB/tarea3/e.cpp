#include <bits/stdc++.h>
using namespace std;

vector <int> mem;
int a,b,c;
int f = -1e9;

int funcion(int x){
    if (mem[x] != f){
        return mem[x];
    }
    else{
        if (x >= a){
            if (x >= b){
                if (x >= c){
                    return mem[x] = max(funcion(x-a)+1,max(funcion(x-b)+1, funcion(x-c)+1));
                }
                else{
                    return mem[x] = max(funcion(x-a)+1, funcion(x-b)+1);
                }
            }
            else{
                if (x >= c){
                    return mem[x] = max(funcion(x-a)+1, funcion(x-c)+1);
                }
                else{
                    return mem[x] = funcion(x-a)+1;
                }
            }
        }
        else if (x >= b){
            if (x >= c){
                return mem[x] = max(funcion(x-b)+1, funcion(x-c)+1);
            }
            else{
                return mem[x] = funcion(x-b)+1;
            }
        }
        else if (x >= c){
            return mem[x] = funcion(x-c)+1;
        }
        else{
            return mem[x];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cin >> a; cin >> b; cin >> c;
    mem.assign(n+1,f);
    mem[0] = 0;
    cout << funcion(n) << endl;
}