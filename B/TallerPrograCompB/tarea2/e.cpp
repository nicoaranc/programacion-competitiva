#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

bool aux(double d, int n, vector <int> a){
    int rt = 1;
    double ult = a[0] + d;
    for (int i = 0; i < a.size(); i++){
        if (abs(ult - a[i]) > d){
            rt++;
            ult = a[i] + d;
        }
    }
    return (rt <= n);
}


int main(){
    int k; cin >> k;
    for (int i = 0; i < k; i++){
        int n; cin >> n;
        int m; cin >> m;
        vector <int> arboles = {};
        for (int i = 0; i < m; i++){
            int j; cin >> j;
            arboles.push_back(j);
        }
        sort(arboles.begin(),arboles.end());
        double r;
        double izq = 0;
        double der = arboles[arboles.size()-1];
        double eps = 1e-9;
        while(der - izq > eps){
            double mid = izq + ((der - izq) / 2);
            if (aux(mid,n,arboles)){
              der = mid;
              r = mid;
            }
            else{
                izq = mid++;
            }
        }
        cout << fixed << setprecision(1) << r << endl;
    }
}