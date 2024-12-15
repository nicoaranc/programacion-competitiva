#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple <ll, ll, ll> tupla;

tupla merge(tupla a, tupla b){
    ll count_izq_a = get<1>(a);
    ll count_der_a = get<2>(a);

    ll count_izq_b = get<1>(b);
    ll count_der_b = get<2>(b);

    ll res = get<0>(a) + get<0>(b);
    ll aux = min(count_izq_a, count_der_b);
    res += aux*2;

    count_izq_a -= aux;
    count_der_b -= aux;

    return {res, count_izq_a+count_izq_b, count_der_a+count_der_b};

}

template<class T, T m(T, T)> struct iter_seg_tree{
  int n; vector<T> ST;
  iter_seg_tree(vector<char> &a){
    n = a.size(); ST.resize(n << 1);
    for (int i=n;i<(n<<1);i++){
        if (a[i-n] == '('){
            ST[i] = {0,1,0};
        }
        else{
            ST[i] = {0,0,1};
        }
    }
    for (int i=n-1;i>0;i--){
        ST[i]=m(ST[i<<1],ST[i<<1|1]);
    }
  }

  T query(int l, int r){ // [l, r]
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    ll querys; cin >> querys;
    ll largo = s.size();
    vector <char> aux;

    for (ll i = 0; i < largo; i++){
        aux.push_back(s[i]);
    }

    iter_seg_tree<tupla, merge> ST(aux);

    for (ll i = 0; i < querys; i++){
        ll l, r; cin >> l >> r;
        tupla tup = ST.query(l-1,r-1);
        cout << get<0>(tup) << '\n';
    }
}