#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    stack <int> a;
    queue <int> b;
    priority_queue <int> c;
    int valor = 0;
    while(cin >> k){
        bool s = true;
        bool q = true;
        bool p = true;
        for (int i = 0; i < k; i++){
            int op; cin >> op;
            int v; cin >> v;
            if (op == 1){
                valor += 1;
                a.push(v);
                b.push(v);
                c.push(v);
            }
            if (op == 2){
                if (valor <= 0){
                    s = false;
                    q = false;
                    p = false;
                }
                else{
                    valor -= 1;
                    int x = a.top();
                    int y = b.front();
                    int z = c.top();
                    if (v == x){
                        if (v == y){
                            if (v != z){
                                p = false;
                                a.pop();
                                b.pop();
                                c.pop();
                            }
                            else{
                                a.pop();
                                b.pop();
                                c.pop();
                            }
                        }
                        else{
                            q = false;
                            if (v != z){
                                p = false;
                                a.pop();
                                b.pop();
                                c.pop();
                            }
                            else{
                                a.pop();
                                b.pop();
                                c.pop();
                            }
                        }
                    }
                    else{
                        s = false;
                        if (v == y){
                            if (v != z){
                                p = false;
                                a.pop();
                                b.pop();
                                c.pop();
                            }
                            else{
                                a.pop();
                                b.pop();
                                c.pop();
                            }
                        }
                        else{
                            q = false;
                            if (v != z){
                                p = false;
                                a.pop();
                                b.pop();
                                c.pop();
                            }
                            else{
                                a.pop();
                                b.pop();
                                c.pop();
                            }
                        }
                    }
                }
            }
        }
        if ((s and q and (not p)) or (s and p and (not q)) or (q and p and (not s)) or (s and q and q)){
            cout << "not sure" << endl;
        }
        else if (s and (q == false) and (p == false)){
            cout << "stack" << endl;
        }
        else if (q and (s == false) and (p == false)){
            cout << "queue" << endl;
        }
        else if (p and (q == false) and (s == false)){
            cout << "priority queue" << endl;
        }
        else if ((s == false) and (q == false) and (p == false)){
            cout << "impossible" << endl;
        }
        for (int i = 0; i < valor; i++){
            a.pop();
            b.pop();
            c.pop();
        }
        valor = 0;
        s = true;
        q = true;
        p = true;
        }
}