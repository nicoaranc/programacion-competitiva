#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    long long k; cin >> k;
    vector <long long> arreglo;
    set <long long> arreglo2;
    long long m = 0;
    for (long long i = 1; i <= n; i++){
        long long x; cin >> x;
        arreglo.push_back(x);
        arreglo2.insert(x);
    }
    auto itr = arreglo2.end();
    itr--;
    long long y = 1;
    while (y <= n - k + 1){
        m += *itr;
        itr--;
        y += 1;
    }
    long long mid;
    long long i = 0;
    long long j = m;
    while (i < j){
        bool e = true;
        long long s = 0;
        long long d = 0;
        mid = i + (j - i) / 2;
        long long r = 0;
        while (r < arreglo.size()){
            if (s == k){
                e = false;
                break;
            }
            if (arreglo[r] > mid){
                e = false;
                break;
            }
            else{
                if (d + arreglo[r] <= mid){
                    d += arreglo[r];
                    r += 1;
                }
                else{
                    s += 1;
                    d = 0;
                }
            } 
        }
        if (e == false){
            i = mid + 1;
        }
        else{
            j = mid;
        }
    }
    cout << j << endl;
}