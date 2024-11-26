#include <bits/stdc++.h>
using namespace std;

vector <long long> dp;
long long minimo = -1e9;

long long func(long long x, long long a, long long b, long long c){
    if (x < 0){
        return minimo;
    }
    else if (dp[x] != -1){
        return dp[x];
    }
    else{
        long long d = 1+func(x-a, a, b, c);
        long long e = 1+func(x-b, a, b, c);
        long long f = 1+func(x-c, a, b, c);
        long long aux = max(d,e);
        dp[x] = max(aux,f);
        return dp[x];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    long long a, b, c;
    cin >> a >> b >> c;
    dp.resize(n+1, -1);
    dp[0] = 0;
    long long res = func(n, a, b, c);
    cout << res << endl;
}