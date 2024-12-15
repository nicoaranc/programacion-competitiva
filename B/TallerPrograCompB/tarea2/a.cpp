#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset <int> maquinas;
    int n; cin >> n;
    int t; cin >> t;
    long long max;
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        maquinas.insert(k);
    }
    auto ptr = maquinas.end();
    ptr--;
    max = *ptr;
    long long i = 0;
    long long j = max*t;
    long long mid;
    while(i < j){
        long long x = 0;
        mid = i + ((j - i) / 2);
        for (auto itr = maquinas.begin(); itr != maquinas.end(); itr++){
           x += mid / *itr;
           if (x >= t){
               break;
           }
        }
        if (x >= t){
            j = mid
        }
        else{
            i = mid + 1
        }
    }
    cout << j << endl;
}
