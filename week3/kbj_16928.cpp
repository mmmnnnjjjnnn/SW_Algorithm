#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int visited[101], snake_ladder[101];
int n, m;

int main(void){

    cin >> n >> m;

    int i;
    int x, y;

    for(i=1; i<101; i++){
        snake_ladder[i] = -1;
        visited[i] = 0;
    }

    for(i=0; i<n + m; i++){
        cin >> x >> y;

        snake_ladder[x] = y;
    }

    queue< pair<int, int> > Q;

    Q.push(make_pair(1, 0));

    int ans = -1;
    while(!Q.empty()){
        int cur, next, times;

        cur = Q.front().first;
        times = Q.front().second;
        // cout << "cur: " << cur << endl;

        if(cur == 100){
            ans = times;
            break;
        }
        Q.pop();

        // dice
        for(i=1; i<=6; i++){
            next = cur + i;

            if(next > 100)
                continue;

            if(snake_ladder[next] != -1){
                // cout << "s&l: " << next << " -> " << snake_ladder[next] << endl;
                next = snake_ladder[next];
            } 

            if(visited[next] == 1)
                continue;

            // cout << "next: " << next << endl;
            Q.push(make_pair(next, times + 1));
            visited[next] = 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

// dp
/*
int main(void){
    int min_time[101];

    cin >> n >> m;

    int i, j;
    int x, y;

    for(i=1; i<101; i++){
        snake_ladder[i] = -1;
        min_time[i] = 999999999;
    }

    for(i=0; i<n + m; i++){
        cin >> x >> y;

        snake_ladder[x] = y;
    }

    min_time[0] = 999999999;
    min_time[1] = 0;

    int next;
    for(i=1; i<=100; i++){
        for(j=1; j<=6; j++){
            next = i + j;

            if(next > 100)
                continue;

            if(snake_ladder[next] != -1){
                next = snake_ladder[next];
            }

            // 다음 갈 곳 최소 거리 갱신
            if(min_time[next] > min_time[i] + 1){
                min_time[next] = min_time[i] + 1;
            }

        }
    }

    cout << min_time[100] << endl;


    return 0;
}
*/