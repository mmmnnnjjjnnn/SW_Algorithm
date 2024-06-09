#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 4000
int N;
int sy = MAX/2;
int sx = MAX/2;
string path;
int map[MAX][MAX];

int mv[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void input(){
    cin >> N >> path;
    int cy = sy;
    int cx = sx;
    map[cy][cx] = 1;
    for(int i = 0 ; i < path.length(); i++){
        cy += mv[path[i] - '0'][0];
        cx += mv[path[i] - '0'][1];
        map[cy][cx] = 1;

        cy += mv[path[i] - '0'][0];
        cx += mv[path[i] - '0'][1];
        map[cy][cx] = 1;
    }
}

void bfs(int i, int j){
    queue<pair<int,int>> q;
    map[i][j] = 1;
    q.push({i,j});

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
                    
        for(int k = 0 ; k < 4; k++){
            int ny = y + mv[k][0];
            int nx = x + mv[k][1];
    
            if(ny > sy + 2*N || ny < sy - 2*N || nx > sx + 2*N || nx < sx - 2*N)
                continue;
            if(map[ny][nx] == 0){
                map[ny][nx] = 1;
                q.push({ny,nx});
            }
                            
        }
    }
}

void output(){
    for(int i = sy - 2*N ; i < sy + 2*N ; i++ ){
        for(int j = sx - 2*N ; j < sx + 2*N ; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sol = 0;
    input();
    for(int i = sy - 2*N ; i < sy + 2*N ; i++)
        for(int j = sx - 2*N ; j < sx + 2*N ; j++){
            if(map[i][j] == 0){
                sol++;
                bfs(i,j);
            }
        }
    
    
    output();
    cout << sol - 1;
    
    return 0;
}