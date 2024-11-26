#include <bits/stdc++.h>
using namespace std;

vector <vector <long long> > mem;

long long camino(long long k, vector <string> a){
    for (int i = k-1; i >= 0; i--){
        for (int j = k-1; j >= 0; j--){
            if (a[i][j] != '*'){
                if (j < k-1){
                    mem[i][j] = (mem[i][j] + mem[i][j+1]) % (1000000000+7) ;
                }
                if (i < k-1){
                    mem[i][j] = (mem[i][j] + mem[i+1][j]) % (1000000000+7);
                }
            }
        }
    }
    return mem[0][0] % (1000000000+7);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    long long n; cin >> n;
    vector <string> lineas;
    for (long long i = 0; i < n; i++){
        string l; cin >> l;
        lineas.push_back(l);
    }
	mem.resize(n + 1, vector<long long>(n + 1, 0));
	if (lineas[0][0] == '*' or lineas[n-1][n-1] == '*'){
	    cout << 0 << endl;
	    return 0;
	}
	mem[n-1][n-1] = 1;
    cout << camino(n,lineas) % (1000000000+7) << endl;
}