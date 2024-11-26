#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
std::vector<ll> prefixFunction(T &s){
	ll n = s.size();
	std::vector<ll> pi(n);
	for (ll i = 1; i < n; i ++){
		ll k = pi[i - 1];
		while(k > 0 and s[i] != s[k]) k = pi[k - 1];
		if (s[i] == s[k]) k ++;
		pi[i] = k;
	}
	return pi;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s1; cin >> s1;
    ll n = s1.length();
    string s2; cin >> s2;
    ll m = s2.length();
    string aux = s2+'$'+s1;
    vector <ll> arreglo = prefixFunction(aux);
    ll res = 0;
    for (ll i = m+1; i < m+1+n; i++){
        if (arreglo[i] == m){
            res++;
        }
    }
    cout << res << endl;
}