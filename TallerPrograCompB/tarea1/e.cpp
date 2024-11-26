#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int x; cin >> x;
    int n; cin >> n;
    multiset <int> distancias = {x};
    set <int> semaforos = {0,x};
    for (int i = 0; i < n; i++){
        int p; cin >> p;
        auto a = *prev(semaforos.upper_bound(p));
        auto b = *semaforos.upper_bound(p);
        semaforos.insert(p);
        distancias.erase(distancias.find(b - a));
        distancias.insert(b - p);
        distancias.insert(p - a);
        cout << *prev(distancias.end()) << endl;
    }
}