#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; 
    cin >> n;
    cin >> k;
    vector <int> v;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    
    
    int res = 0;
    
    for (int i = 0; i < k; i++){
        int sum_uno = 0;
        int sum_dos = 0;
        for (int j = i; j < n; j+=k){
            if (v[j] == 1){
                sum_uno++;
            }
            else{
                sum_dos++;
            }
        }
        if (sum_dos == 0 || sum_uno == 0){
            continue;
        }
        else{
            if (sum_uno == sum_dos){
                res += sum_dos;
            }
            else{
                if (sum_uno > sum_dos){
                    res += sum_dos;
                }
                else{
                    res += sum_uno;
                }
            }
        }
    }
    cout << res << endl;
}