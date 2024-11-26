#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree{
    int N;
    vector <ll> tree;
    const ll neutro = 1e18;
    
    SegmentTree(vector <ll> &A){
        N = A.size();
        tree.resize(4*N);
        build(0,0,N-1,A);
    }
    
    void build(int n, int i, int j, vector <ll> &A){
        if(i == j){
            tree[n] = A[i];
            return;
        }
        int mid = (i+j)/2;
        build(2*n+1, i, mid, A);
        build(2*n+2, mid+1, j, A);
        tree[n] = min(tree[2*n+1],tree[2*n+2]);
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
        return min(query(2*n+1, i, mid, l, r),query(2*n+2, mid+1, j, l, r));
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
        tree[n] = min(tree[2*n+1],tree[2*n+2]);
    }
    
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    ll q; cin >> q;
    vector <ll> arreglo;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        arreglo.push_back(a);
    }
    
    SegmentTree ST(arreglo);
    
    for (int m = 0; m < q; m++){
        int k; cin >> k;
        int i; cin >> i;
        int j; cin >> j;
        if (k == 1){
            ST.cambio(i-1, j);
        }
        if (k == 2){
            cout << ST.query(i-1,j-1) << endl;
        }
    }
}
