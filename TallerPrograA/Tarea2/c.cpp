#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <vector <int>> grafo(n);

    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u; cin >> v;
        grafo[u-1].push_back(v-1);
        grafo[v-1].push_back(u-1);
    }

    int res = 0;
    for (int i = 0; i < n; i++){
        if (grafo[i].size() == 1){
            res++;
        }
    }
    
    if (res%2 == 0){
        cout << res/2 << endl;
    }
    else{
        cout << (res/2)+1 << endl;
    }


}
