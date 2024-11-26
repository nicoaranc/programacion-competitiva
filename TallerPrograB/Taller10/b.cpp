#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <vector <ll>> auxiliar;

struct SegmentTree {
    ll N;
    ll altura;
    vector <ll> tree;
    const ll neutro = -1e18;

    SegmentTree(vector <ll> &A, ll s){
        altura = s;
        N = A.size();
        tree.resize(4*N);
        build(0, 0, N-1, A, s);
    }

    ll merge(ll a, ll b, ll t){
        if (t % 2 == 1){
            ll x = a;
            ll y = b;
            ll res = x | y;
            return res;
        }
        else{
            ll x = a;
            ll y = b;
            ll res = x ^ y;
            return res;
        }
    }

    void build(ll n, ll i, ll j, vector <ll> &A, ll t){
        if (i == j){
            tree[n] = A[i];
            return;
        }
        ll mid = (i+j)/2;
        build(2*n+1, i, mid, A, t-1);
        build(2*n+2, mid+1, j, A, t-1);
        tree[n] = merge(tree[2*n+1], tree[2*n+2], t);
    }

    ll query(ll l, ll r, ll t){
        return query(0, 0, N-1, l, r, t);
    }

    ll query(ll n, ll i, ll j, ll l, ll r, ll t){
        if (l <= i && j <= r){
            return tree[n];
        }
        if (r < i || j < l){
            return 0;            
        }
        ll mid = (i+j)/2;
        return merge(query(2*n+1, i, mid, l, r, t-1), query(2*n+2, mid+1, j, l, r, t-1), t);
    }

    ll update(ll l, int value, ll t){
        update(0, 0, N-1, l, value, t);
        return query(0, N-1, t);
    }

    void update(ll n, ll i, ll j, ll r, int value, ll t){
        if (r < i || r > j){
            return;
        }
        if (i == j && i == r){
            tree[n] = value;
            return;
        }
        ll mid = (i+j)/2;
        update(2*n+1, i, mid, r, value, t-1);
        update(2*n+2, mid+1, j, r, value, t-1);
        tree[n] = merge(tree[2*n+1], tree[2*n+2], t);       
    }

};


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll s; cin >> s;
    ll querys; cin >> querys;
    vector <ll> arreglo;
    ll largo = 1;
    for (ll i = 0; i < s; i++){
        largo *= 2;
    }
    for (ll i = 0; i < largo; i++){
        ll a; cin >> a;
        arreglo.push_back(a);
    }

    SegmentTree ST(arreglo, s);

    for (ll i = 0; i < querys; i++){
        ll l, r; cin >> l >> r;
        cout << ST.update(l-1, r, s) << endl;
    }
}