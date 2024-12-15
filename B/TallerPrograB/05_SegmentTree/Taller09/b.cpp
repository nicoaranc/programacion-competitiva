#include <bits/stdc++.h>
using namespace std;


vector <vector <int>> auxiliar;

int merge(int a, int b){
    return max(a, b);
}

template<class T, T m(T, T)> struct iter_seg_tree{
  int n; vector<T> ST;
  iter_seg_tree(vector<T> &a){
    n = a.size(); ST.resize(n << 1);
    for (int i=n;i<(n<<1);i++)ST[i]=a[i-n];
    for (int i=n-1;i>0;i--)ST[i]=m(ST[i<<1],ST[i<<1|1]);
  }
  void update(int pos, T val){ // replace with val
    ST[pos += n] = val;
    for (pos >>= 1; pos > 0; pos >>= 1)
      ST[pos] = m(ST[pos<<1], ST[pos<<1|1]);
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
    int querys; cin >> querys;
    int largo = s.size();
    vector <int> init(largo, 0);
    auxiliar.resize(26, init);

    for (int i = 0; i < largo; i++){
        char letra = s[i] - 'a';
        auxiliar[letra][i] = 1;
    }

    vector <iter_seg_tree <int, merge>> trees;

    for (int i = 0; i < 26; i++){
        trees.emplace_back(auxiliar[i]);
    }

    for (int i = 0; i < querys; i++){
        int tipo; cin >> tipo;
        if (tipo == 1){
            int pos; cin >> pos;
            pos--;
            char reemplazo; cin >> reemplazo;
            int reemp = reemplazo - 'a';
            char letra = s[pos];
            int letra_aux = letra - 'a';
            trees[letra_aux].update(pos, 0);
            trees[reemp].update(pos, 1);
            s[pos] = reemplazo;
        }
        else {
            int l; cin >> l;
            int r; cin >> r;
            int res = 0;
            for (int j = 0; j < 26; j++){
                res += trees[j].query(l-1, r-1);
            }
            cout << res << '\n';

        }
    }

}