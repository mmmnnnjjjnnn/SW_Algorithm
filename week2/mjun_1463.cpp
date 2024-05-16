#include <iostream>
#include <queue>

using namespace std;

struct info{
    int num;
    int cnt;
};

int bfs(int X){
    queue<info> q;
    q.push({X,0});
    int visited[1000000] = {0};
    
    while(!q.empty()){
        info data = q.front();
        q.pop();
        if(visited[1] != 0 || data.num == 1)
            return visited[1];
        
        for(int i = 0 ; i < 3 ; i++){
            int tmp = -1;
            if(i == 0 && data.num % 3 == 0)
                tmp = data.num / 3;
            else if(i == 1 && data.num % 2 == 0)
                tmp = data.num / 2;
            else if(i == 2)
                tmp = data.num - 1;
            
            if(tmp > 0 && visited[tmp] == 0){
                visited[tmp] = data.cnt + 1;
                q.push({tmp, data.cnt + 1});
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    cout << bfs(N);
    
    return 0;
}