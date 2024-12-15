#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int j = 1;
    string y = " ";
    int k = 1;
    int r = 10;
    while(j <= t){
        string s;
        cin >> s;
        for(int i = 0; i < 8; i++){
            if(s[i] != '.'){
                if(r == 10){
                    r = i;
                    y = s[i];
                    if(i == 7){
                        k = k + 1;
                    }
                }
                else{
                    y = y + s[i];
                    if(i == 7){
                        k = k + 1;
                    }
                    }
                }
            
            else{
                if(i == r){
                    r = 10;
                }
                if(i == 7){
                    k = k + 1;
                }
            }
        }

        if(k == 9){
            cout << y << endl;
            r = 10;
            j = j + 1;
            k = 1;
        }
        }
    }
