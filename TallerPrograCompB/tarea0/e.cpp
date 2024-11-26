#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    int j = 1;
    while(j <= k){
        int n; cin >> n; int q = 0;
        int m; cin >> m; int w = 0;
        string a; cin >> a;
        string b; cin >> b;
        for(int i = 0; i < n-1; i++){
            if(a[i] == a[i+1]){
                q = q + 1;
                if(q >= 2){
                    break;
                }
            }
        }
        for(int i = 0; i < m-1; i++){
            if(b[i] == b[i+1]){
                w = w + 1;
                if(w >= 2){
                    break;
                }
            }
        }
        if(q != 0 and w != 0){
            cout << "NO" << endl;
            j = j + 1;
        }
        else{
            if(q != 0 or w != 0){
                if(a[n-1] == b[m-1]){
                    cout << "NO" << endl;
                    j = j + 1;
                }
                else{
                    if(q >= 2 or w >= 2){
                        cout << "NO" << endl;
                        j = j + 1;
                    }
                    else{
                        cout << "YES" << endl;
                        j = j + 1;
                    }
                }
                
            }
            else{
                cout << "YES" << endl;
                j = j + 1;
            }
        }
    }
}