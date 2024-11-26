#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q; cin >> q;
    for (long long i = 0; i < q; i++){
        long long k; cin >> k;
        long long n; cin >> n;
        long long a; cin >> a;
        long long b; cin >> b;
        if ((b * n) >= k){
            cout << -1 << endl;
        }
        else{
            long long r;
            long long x = 0;
            long long y = n;
            while(x <= y){
                long long mid = x + ((y - x) / 2);
                long long w = n - mid;
                long long s = (a * mid) + (b * w);
                if ((k - s) > 0){
                    r = mid;
                    x = mid + 1;
                }
                else{
                    y = mid - 1;
                }
            }
            cout << r << endl;
        }
    }
}