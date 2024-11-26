#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        long long suma = 0;
        priority_queue <int> pq;
        for (int i = 0; i < n; i++){
            int s; cin >> s;
            int max;
            if (s == 0){
                if (pq.size() != 0){
                    max = pq.top();
                    pq.pop();
                    suma += max;
                }
            }
            else{
                pq.push(s);
            }
        }
        cout << suma << endl;
    }
}