#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    int finish_x, finish_y;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    // 입력
    cin >> N >> M;
    int map[N][M]; // 입력으로 주어진 지도의 크기로 배열 선언
    int result[N][M]; // 입력으로 주어진 지도의 크기로 배열 선언
    fill_n(&result[0][0], N * M, -1); // result 배열 -1로 초기화

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int value;
            cin >> value;
            map[i][j] = value;

            if (value == 2) {
                result[i][j] = 0;
                finish_x = i;
                finish_y = j;
            } else if (value == 0) {
                result[i][j] = 0;
            }
        }
    }

    // bfs
    queue<pair<int, int>> q;
    q.push(make_pair(finish_x, finish_y)); // 초기 위치로 시작
    while (!q.empty()) {

        // pop
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            // 기본적으로는 상하좌우 1칸씩 이동
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            // map을 나가면 continue
            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) {
                continue;
            }
            // 이미 최단거리가 나왔으면 continue
            else if (result[next_x][next_y] != -1) {
                continue;
            }
            // 다 아니면 push
            else if(result[next_x][next_y] == -1){
                q.push(make_pair(next_x, next_y));
                result[next_x][next_y] = result[current_x][current_y] + 1;
            }
        }
    }

    // 출력
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++)
            cout << result[j][i] << " ";

        cout << "\n";
    }

    return 0;
}
