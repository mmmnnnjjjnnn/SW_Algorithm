#include <iostream>
#include <queue>

using namespace std;

struct grid {
    int z;
    int y;
    int x;
};

int dir[6][3] = {
    {0, 0, 1},
    {0, 0, -1},
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0}
};

int m, n, h;
int t = 0;

int box[101][101][101];

queue<grid> q;

void input(){
    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= m ; k++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                    q.push({i,j,k});
            }
        }
    }
}

void bfs(){
    while(!q.empty()){
        grid cur = q.front();
        q.pop();
        
        for(int i = 0 ; i < 6 ; i++){
            grid next = {cur.z+dir[i][0], cur.y+dir[i][1], cur.x+dir[i][2]};

            if(next.x < 1 || next.x > m || next.y < 1 || next.y > n || next.z < 1 || next.z > h)
                continue;
            if(box[next.z][next.y][next.x] == 0){
                box[next.z][next.y][next.x] = box[cur.z][cur.y][cur.x] + 1;
                q.push(next);
            }
        }
    }
}

int output(){
    int max_t = 0;
    for(int i = 1 ; i <= h ; i++){
        for(int j = 1 ; j <= n ; j++){
            for(int k = 1 ; k <= m ; k++){
                if(max_t < box[i][j][k])
                    max_t = box[i][j][k];
                if(box[i][j][k] == 0){
                    return -1;
                }
            }
        }
    }
    return max_t - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n >> h;
    input();

    bfs();

    cout << output();
    
    return 0;
}