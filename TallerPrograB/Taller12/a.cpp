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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector <string> pref;
    for (ll i = 1; i <= n; i++){
        pref.push_back(s.substr(0,i));
    }
    for (ll i = 0; i < pref.size(); i++){
        string prefijo = pref[i];
        ll largo = prefijo.size();
        while(prefijo.size() < k){
            prefijo += prefijo;
        }
        if (prefijo.size() > k){
            prefijo = prefijo.substr(0,k);
        }
        pref[i] = prefijo;
    }
    string res = "";
    for (ll i = 0; i < pref.size(); i++){
        string candidato = pref[i];
        if (res == ""){
            res = candidato;
        }
        else{
            for (ll j = 0; j < n; j++){
                ll a = res[j];
                ll b = candidato[j];
                if (b == a){
                    continue;
                }
                else if (b < a){
                    res = candidato;
                    break;
                }
                else{
                    break;
                }
            }
        }
    }
    cout << res << endl;
}