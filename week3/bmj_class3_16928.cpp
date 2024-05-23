#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    //입력
    int N,M;
    int x,y;
    int u,v;
    int map[101] = {0};
    bool visit[101] = {0};

    cin>>N>>M;

    for(int i=0 ; i<N; i++){
        cin>>x>>y;
        map[x] = y;
    }

    for(int i=0 ; i<M; i++){
        cin>>u>>v;
        map[u] = v;
    }
    
    //bfs
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    while(!q.empty()){

        //pop
        int current_x = q.front().first;
        int current_num = q.front().second;
        q.pop();
 
        for (int i = 1; i <= 6;i++){
            //기본적으로는 1칸씩 이동
            int next_x = current_x + i; 

            //끝나는 조건
            if(next_x == 100){
                cout << current_num+1;
                return 0;
            }
            else if(next_x < 100){ 
                //뱀이나 사다리가 있으면 해당칸으로 이동
                while(map[next_x] != 0){ 
                    next_x = map[next_x]; 
                }

                //방문한적이 없으면 push
                if(!visit[next_x]){ 
                    q.push(make_pair(next_x, current_num + 1)); 
                    visit[next_x] = true; 
                }
                
            }
        }
    }

    return 0;
}