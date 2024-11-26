#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree{
    int N;
    vector <ll> tree;
    vector <ll> lista;

    const ll neutro = 0;
    
    SegmentTree(vector <ll> &A){
        N = A.size();
        tree.resize(4*N);
        lista.resize(4*N);
        build(0,0,N-1,A);
    }
    
    void build(int n, int i, int j, vector <ll> &A){
        if(i == j){
            tree[n] = 1;
            lista[n] = A[i];
            return;
        }
        int mid = (i+j)/2;
        build(2*n+1, i, mid, A);
        build(2*n+2, mid+1, j, A);
        tree[n] = tree[2*n+1]+tree[2*n+2];
        lista[n] = 0;
    }
    
    void query(int t){
        query(0, 0, N-1, t);
    }
    
    void query(int n, int i, int j, int t){
        if (i == j && tree[n] >= t){
            cout << lista[n] << endl;
            eliminar(i);
        }
        else{
            int mid = (i+j)/2;
            if (tree[2*n+1] >= t){
                query(2*n+1, i, mid, t);
            }
            else{
                query(2*n+2, mid + 1, j, t - tree[2*n+1]);
            }
        }


    }
    
    void eliminar(int t){
        eliminar(0, 0, N-1, t);
    }
    
    void eliminar(int n, int i, int j, int t){        
        if (t < i || t > j){
            return;
        }
        if (i == j && i == t){
            tree[n] = 0;
            return;
        }
        int mid = (i+j)/2;
        eliminar(2*n+1, i, mid, t);
        eliminar(2*n+2, mid+1, j, t);
        tree[n] = tree[2*n+1]+tree[2*n+2];
    }
    
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector <ll> arreglo;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        arreglo.push_back(a);
    }
    
    SegmentTree ST(arreglo);
    
    for (int m = 0; m < n; m++){
        int k; cin >> k;
        ST.query(k);
    }
}
