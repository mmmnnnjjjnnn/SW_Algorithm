#include <iostream>
#include <utility>
#include <queue>

using namespace std;

short board[1001][1001];
bool visited[1001][1001];
int out_board[1001][1001];

// 좌상단 (0,0), 우하단 (n,m)
// 상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void){

    int goal;
    int n, m;
    int i, j;

    cin >> n >> m;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> board[i][j];
            visited[i][j] = false;
            if(board[i][j] == 2)
                goal = i * 1001 + j;
            out_board[i][j] = -1;
        }   
    }

    queue< pair<int, int> > Q;

    Q.push(make_pair(goal, 0));
    visited[goal / 1001][goal % 1001] = true;

    int nx, ny, cx, cy;
    while(!Q.empty()){
        pair<int, int> tmp;

        tmp = Q.front();
        Q.pop();

        cx = tmp.first / 1001;
        cy = tmp.first % 1001;
        out_board[cx][cy] = tmp.second;
        

        // cout << "(" << cx << ", " << cy << ")" << endl;

        for(i=0; i<4; i++){
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if(visited[nx][ny] == true)
                continue;

            if(board[nx][ny] == 1){
                 Q.push(make_pair(nx * 1001 + ny, tmp.second + 1));
                 visited[nx][ny] = true;
            }
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(out_board[i][j] == -1){
                if(board[i][j] == 0)
                    out_board[i][j] = 0;
            }
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout << out_board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}