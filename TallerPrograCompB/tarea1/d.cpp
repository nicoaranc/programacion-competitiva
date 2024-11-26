#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x; cin >> x;
    map <int, int> a;
    string s = "not ok";
    int q;
    int w;
    for(int i = 1; i <= n; i++){
        int j; cin >> j;
        if (s == "not ok"){
            int c = x - j;
            if (a.find(c) != a.end()){
                q = i;
                w = a[c];
                s = "ok";
            }
            else{
                a[j] = i;
            }
        }
        
    }
    if (s == "ok"){
        cout << w << endl;
        cout << q << endl;
        return 0;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    }