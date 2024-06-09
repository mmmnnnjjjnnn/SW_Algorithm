#include <iostream>
#include <algotithm>
#define MAX 100000
using namespace std;

int N, M, max_id;
int ID[MAX];

void input(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        cin >> ID[i];
        if(max_id < ID[i])
            max_id = ID[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ans = -1;
    input();

    for(int k = 0 ; k <= max_id ; k++){
        int cnt = 0;
        for(int j = 0 ; j < M ; j++){
            if( k-1 <= ID[j] && ID[j] <= k+1)
                cnt++;
        }
        ans = max(ans, cnt);
        
        for(int i = 1 ; i < N - M ;i++){
            if( k-1 <= ID[i] && ID[i] <= k+1)
                cnt--;
            if( k-1 <= ID[i+M-1] && ID[i+M-1] <= k+1)
                cnt++;
            
            ans = max(ans, cnt);
        }
    }
    
    cout << ans;
    
    return 0;
}