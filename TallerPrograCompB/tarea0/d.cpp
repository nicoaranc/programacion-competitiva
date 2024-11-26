#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int c0 = 0, c1 = 0;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            if(a[i] == 0) c0++;
            else c1++;
        }
        if (c0 >= n/2){
            cout<<c0<<'\n';
            while (c0--) cout << 0 << ' ';
            cout << '\n';
        } else{ 
            if(c1%2 == 1) c1--;
            cout<<c1<<'\n';
            while(c1--) cout << 1 << ' ';
            cout << '\n'; 
        }
    }
}