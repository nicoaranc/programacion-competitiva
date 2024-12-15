#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> mapa;
int n, m;


vector <int> dirx = {-1, 0, 1, 0};
vector <int> diry = {0, 1, 0, -1};

void dfs(int x, int y){
    int valor = mapa[x][y];
    mapa[x][y] = 0;
    
    for(int dir=0; dir<4; dir++){
        int nx = x+dirx[dir];
        int ny = y+diry[dir];
        if(nx<0 || ny<0 || nx>=n || ny>=m){
        continue;
        }
        if(mapa[nx][ny] != 0 && mapa[nx][ny] <= valor){
        dfs(nx, ny);
        }
    }
}

int main(){
    cin >> n >> m;
    mapa.resize(n);
    vector<tuple<int,int,int>> v; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int x; cin >> x;
            mapa[i].push_back(x);
            v.push_back({x,i,j});
        }
    }
    sort(v.begin(), v.end());
    int largo = v.size() - 1;
    int ans = 0;
    while (largo >= 0){
        int i = get<1>(v[largo]);
        int j = get<2>(v[largo]);
        int val = mapa[i][j];
        int rodeado = 1;
        if(val > 1){
            if (i > 0){
                if (mapa[i-1][j] != 0){
                    rodeado = 0;
                }
            }
            if (j > 0){
                if ( mapa[i][j-1] != 0){
                    rodeado = 0;
                }
            }
            if (i < n-1){
                if (mapa[i+1][j] != 0){
                    rodeado = 0;
                }
            }
            if (j < m-1){
                if (mapa[i][j+1] != 0){                 
                    rodeado = 0;
                }
            }
            if (!rodeado){
                dfs(i, j);
                ans++;  
            }
            else{
                if (val > 1){
                    dfs(i, j);
                    ans++;  
                }
            }            
                                    
        }
        largo--;
    }
    
    cout << ans << '\n';
    return 0;    
}