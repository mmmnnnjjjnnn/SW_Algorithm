#include <iostream>
#include <queue>

using namespace std;

int N, M;

int map[101];
int visited[101];
queue<int> q;

void input(){
    cin >> N >> M;
    for(int i = 0 ; i < N + M ;i++){
        int a, b;
        cin >> a >> b;
        map[a] = b;
    }
}

void bfs(){
    q.push(1);
    visited[1] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 1 ; i <= 6;i++){
            int next = cur + i;

            if(next > 100)
                break;

            if(map[next] > 0)
                next = map[next];
            if(!visited[next]){
                visited[next] = visited[cur]+1;
                q.push(next);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    bfs();
    cout << visited[100]-1;

    return 0;
}