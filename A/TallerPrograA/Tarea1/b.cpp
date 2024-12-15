#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    
    long long x; cin >> x;
    
    vector <pair <long long, int>> v;
    
    for (int i = 0; i < n; i++){
        long long a; cin >> a;
        pair <long long, int> p = {a, i+1};
        v.push_back(p);
    }
    
    if (n < 4){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    sort(v.begin(), v.end());
    
    bool y = false;
    pair <long long, int> primero_;
    pair <long long, int> segundo_;
    pair <long long, int> tercero_;
    pair <long long, int> cuarto_;
    
    for (int i = 0; i < n-3; i++){
        if (y){
            break;
        }
        for (int j = i+1; j < n-2; j++){
            if (y){
                break;
            }
            int k = j+1;
            int l = n-1;
            long long meta = x - v[i].first - v[j].first;
            while (k < l){
                long long m = meta - v[k].first - v[l].first;
                if (m == 0){
                    primero_ = v[i];
                    segundo_ = v[j];
                    tercero_ = v[k];
                    cuarto_ = v[l];
                    y = true;
                    break;
                }
                else if (m < 0){
                    l--;
                }
                else{
                    k++;
                }
            }
        }
    }

    if (y){
        set <int> res;
        res.insert(primero_.second);
        res.insert(segundo_.second);
        res.insert(tercero_.second);
        res.insert(cuarto_.second);
        for (auto p = res.begin(); p != res.end(); p++){
            cout << *p << endl;
        }
    }
    if (!y){
        cout << "IMPOSSIBLE" << endl;
    }


}