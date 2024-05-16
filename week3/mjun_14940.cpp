#include <iostream>
#include <queue>

using namespace std;

int n,m;
int map[1000][1000];
bool visited[1000][1000];

struct grid {
    int x;
    int y;
};
queue<grid> q;
grid target;

int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

void input(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            cin >> map[i][j];
            if(map[i][j] == 2)
                target = {j, i};
        }
}

void bfs(){
    q.push(target);
    map[target.y][target.x] = 0;
    visited[target.y][target.x] = true;
    
    while(!q.empty()){
        grid cur = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            grid next = {cur.x + dir[i][0], cur.y + dir[i][1]};

            if(next.x < 0 || next.x >= m || next.y < 0 || next.y >= n)
                continue;
            if(visited[next.y][next.x] == true || map[next.y][next.x] == 0)
                continue;

            visited[next.y][next.x] = true;
            map[next.y][next.x] = map[cur.y][cur.x] + 1;
            q.push(next);
            
        }
    }
}

void output(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visited[i][j] == false && map[i][j] == 1)
                cout << "-1 ";
            else if(target.x == j && target.y == i)
                cout << "0 ";
            else
                cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    input();
    bfs();
    output();
    
    return 0;
}