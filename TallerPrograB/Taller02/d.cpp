#include <bits/stdc++.h>
using namespace std;


int main(){
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()){
        cout << "NO" << endl;
    }
    else{
        int l = s.size();
        int dif = 0;
        int res = 1;
        vector <int> count_s (26,0);
        vector <int> count_t (26,0);
        for (int i = 0; i < l; i++){
            int ls = s[i] - 'a';
            int lt = t[i] - 'a';
            count_s[ls]++;
            count_t[lt]++;
            if (ls != lt){
                dif++;
                if (dif > 2){
                    break;
                    res = 0;
                }
            }
        }
        if (res){
            for (int i = 0; i < 26; i++){
                if (count_s[i] != count_t[i]){
                    res = 0;
                    break;
                }
            }
        }
        if (res){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}