#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll neutro = -1e18;

struct SegmentTree{
    int N;
    vector <ll> tree;
    
    SegmentTree(vector <ll> &A){
        N = A.size();
        tree.resize(4*N, neutro);
    }
    
    
    ll query(int l, int r){
        return query(0, 0, N-1, l, r);
    }
    
    ll query(int n, int i, int j, int l, int r){
        if (l <= i && j <= r){
            return tree[n];
        }
        if (r < i || j < l){
            return neutro;
        }
        int mid = (i+j)/2;    
        return max(query(2*n+1, i, mid, l, r),query(2*n+2, mid+1, j, l, r));
    }
    
    void cambio(int t, ll val){
        cambio(0, 0, N-1, t, val);
    }
    
    void cambio(int n, int i, int j, int t, ll val){
        if (t < i || t > j){
            return;
        }
        if (i == j && i == t){
            tree[n] = val;
            return;
        }
        int mid = (i+j)/2;
        cambio(2*n+1, i, mid, t, val);
        cambio(2*n+2, mid+1, j, t, val);
        tree[n] = max(tree[2*n+1],tree[2*n+2]);
    }
    
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector <ll> alturas;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        alturas.push_back(a);
    }
    vector <ll> belleza;
    for (int i = 0; i < n; i++){
        ll b; cin >> b;
        belleza.push_back(b);
    }
    
    SegmentTree ST(belleza);

    for (int i = 0; i < n; i++){
        ll b = belleza[i];
        ll h = alturas[i];
        if (h == 1){
            ST.cambio(h-1, b);
        }
        else{
            ll valor = ST.query(0,h-2);
            if (valor == neutro){
                ST.cambio(h-1, b);
            }
            else{
                ST.cambio(h-1, b + valor);
            }
        }
    }
    cout << ST.query(0,n-1) << endl;
}