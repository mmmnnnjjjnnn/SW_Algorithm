#include <iostream>
#include <string>
#include <queue>
#include <utility>

#define endl '\n'

using namespace std;

bool visited[4003][4003];
int n;
string in;

// 우 좌 하 상
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 상 하 좌 우
int max_range[4] = {2000, 2000, 2000, 2000};

int main(void){
    int i, j;

    int cx, cy;
    int nx, ny;
    cin >> n;

    cin >> in;

    cx = 2000, cy = 2000;
    visited[cx][cy] = true;
    int dir;
    for(i=0; i<n; i++){
        dir = (int)in[i] - '0';

        nx = cx + dx[dir];
        ny = cy + dy[dir];

        visited[nx][ny] = true;

        nx = cx + 2 * dx[dir];
        ny = cy + 2 * dy[dir];

        visited[nx][ny] = true;

        if(max_range[0] > nx){
            max_range[0] = nx;
        }

        if(max_range[1] < nx){
            max_range[1] = nx;
        }

        if(max_range[2] > ny){
            max_range[2] = ny;
        }

        if(max_range[3] < ny){
            max_range[3] = ny;
        }

        cx = nx, cy = ny;
    }
    queue< pair<int, int> > Q;

    cout << max_range[0] << ", " << max_range[2] << " - " << max_range[1] << ", " << max_range[3] << endl;
    for(i=max_range[0] - 1; i<=max_range[1] + 1; i++){
        for(j=max_range[2] - 1; j<=max_range[3] + 1; j++){
            if(visited[i][j] == true){
                cout << 1 << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    int area_cnt = 0;
    for(i=max_range[0] - 1; i<=max_range[1] + 1; i++){
        for(j=max_range[2] - 1; j<=max_range[3] + 1; j++){
            if(visited[i][j] == false){
                cout << "----" << endl;

                Q.push(make_pair(i, j));

                visited[i][j] = true;
                while(!Q.empty()){
                    
                    cx = Q.front().first;
                    cy = Q.front().second;

                    cout << "(" << cx << ", " << cy << ")" << endl;
                    Q.pop();

                    for(int k=0; k<4; k++){
                        nx = cx + dx[k];
                        ny = cy + dy[k];

                        if(nx < max_range[0] - 1 || nx > max_range[1] + 1 || ny < max_range[2] - 1 || ny > max_range[3] + 1){
                            continue;
                        }
                        
                        if(visited[nx][ny] == true)
                            continue;

                        visited[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                    }
                }
                area_cnt++;
            }
        }
    }

    cout << max_range[0] << ", " << max_range[2] << " - " << max_range[1] << ", " << max_range[3] << endl;
    for(i=max_range[0] - 1; i<=max_range[1] + 1; i++){
        for(j=max_range[2] - 1; j<=max_range[3] + 1; j++){
            if(visited[i][j] == true){
                cout << 1 << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cout << area_cnt - 1 << endl;

    return 0;
}