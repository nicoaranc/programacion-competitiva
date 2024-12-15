#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree{
    int N;
    vector <ll> tree;
    const ll neutro = -1;
    
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
        tree[n] = tree[2*n+1] & tree[2*n+2];
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
        return query(2*n+1, i, mid, l, r) & query(2*n+2, mid+1, j, l, r);
    }

    ll busqueda(int l, ll x, int y){
        int r = l;
        ll resultado = query(l,r);
        if (resultado < x){
            return -1;
        }
        else{
            while (r < y){
                int mid = (r+y)/2;
                resultado = query(l,mid);
                if (resultado < x){
                    y = mid;
                }
                else{
                    r = mid + 1;
                }
            }
            return r;
        }
    }

    
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        vector <ll> arreglo;
        for (int j = 0; j < n; j++){
            int a; cin >> a;
            arreglo.push_back(a);
        }

        SegmentTree ST(arreglo);

        int q; cin >> q;
        for (int j = 0; j < q; j++){
            int l; cin >> l;
            int x; cin >> x;
            cout << ST.busqueda(l-1,x,arreglo.size()) << endl;
        }
    }
}
