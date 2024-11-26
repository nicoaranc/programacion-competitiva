#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector <int> tiempos;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        tiempos.push_back(a);
    }
    int res = 0;
    if (n == 1){
        if (tiempos[0] <= t){
            res = 1;
        }
    }
    else{
        int i = 0;
        int j = 1;
        int tr = t;
        while(i < n){
            int r = 0;
            if (tiempos[i] > tr){
                i++;
                j++;
            }
            else{
                r++;
                if (r > res){
                    res = r;
                }
                tr -= tiempos[i];
                while(j < n && i < j){
                    if (tiempos[j] > tr){
                        tr += tiempos[i];
                        i++;
                        r--;
                    }
                    else{
                        tr -= tiempos[j];
                        j++;
                        r++;
                        if (r > res){
                            res = r;
                        }
                    }
                }
                if (j == n){
                    break;
                }
                else if (i == j){
                    j++;
                }
            }
        }
    }
    cout << res << endl;
}
