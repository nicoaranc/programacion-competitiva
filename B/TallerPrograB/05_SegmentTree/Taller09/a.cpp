#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll merge(ll a, ll b){
        return a + b;
    }

template<class T, T m(T, T)> struct iter_seg_tree{
  ll n; vector<T> ST;
  iter_seg_tree(vector<T> &a){
    n = a.size(); ST.resize(n << 1, 0);
  }
  void update(ll pos, T val){ // replace with val
    ST[pos += n] = val;
    for (pos >>= 1; pos > 0; pos >>= 1)
      ST[pos] = m(ST[pos<<1], ST[pos<<1|1]);
  }
  T query(ll l, ll r){ // [l, r]
    T ansL, ansR; bool hasL = 0, hasR = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) 
        ansL=(hasL?m(ansL,ST[l++]):ST[l++]),hasL=1;
      if (r & 1) 
        ansR=(hasR?m(ST[--r],ansR):ST[--r]),hasR=1;
    }
    if (!hasL) return ansR; if (!hasR) return ansL;
    return m(ansL, ansR);
  }
};

int main(){
    ll n; cin >> n;
    vector <ll> arreglo;
    vector <ll> ordenado;
    for (ll i = 0;  i < n; i++){
        ll a; cin >> a;
        arreglo.push_back(a);
        ordenado.push_back(a);
    }
    sort(ordenado.begin(), ordenado.end());
    map <ll, ll> posiciones_ord;
    for (ll i = 0; i < n; i++){
        posiciones_ord[ordenado[i]] = i;
    }

    iter_seg_tree <ll, merge> ST(arreglo);

    ll res = 0;
    for (ll i = 0; i < n; i++){
        ll elemento = arreglo[i];
        ll aux = posiciones_ord[elemento];

        ll a = ST.query(aux,n-1);
        ll b = i - a;
        ll c = aux - b;

        res += a*c;

        ST.update(aux, 1);

    }

    cout << res << endl;


}