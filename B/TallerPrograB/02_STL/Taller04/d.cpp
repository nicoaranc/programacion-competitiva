#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    map <int, int> Buy;
    map <int, int> Sell;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        int p; cin >> p;
        int q; cin >> q;
        if (c == 'S'){
            if (Sell.find(p) == Sell.end()){
                Sell[p] = q;
            }
            else{
                Sell[p] += q;
            }
        }
        else{
            if (Buy.find(p) == Buy.end()){
                Buy[p] = q;
            }
            else{
                Buy[p] += q;
            }
        }
    }
    set < pair < int, int>> b;
    set < pair < int, int>> s;
    auto itb = Buy.begin();
    while (itb != Buy.end()){
        int x = itb->first;
        int y = itb->second;
        pair < int, int> tupla = {x, y};
        b.insert(tupla);
        itb++;
    }
    auto its = Sell.begin();
    while (its != Sell.end()){
        int x = its->first;
        int y = its->second;
        pair <int, int> tupla = {-x, y};
        s.insert(tupla);
        its++;
    }
    auto it = s.end();
    vector <pair <int, int>> aux;
    for (int i = 0; i < k; i++){
        if (it == s.begin()){
            break;
        }
        it--;
        pair par = *it;
        aux.push_back(par);
    }
    for (int i = aux.size()-1; i >= 0; i--){
        pair par = aux[i];
        int g, h;
        g = -par.first;
        h = par.second;
        cout << "S " << g << " " << h << endl;
    }
    it = b.end();
    for (int i = 0; i < k; i++){
        if (it == b.begin()){
            break;
        }
        it--;
        pair par = *it;
        int g, h;
        g = par.first;
        h = par.second;
        cout << "B " << g << " " << h << endl;
    }
}