#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int max_h;
vector<int> tree;

void input(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        int h;
        cin >> h;
        tree.push_back(h);
        if( h > max_h )
            max_h = h;
    }
}

long long cut_tree(int h){
    long long sum_h = 0;
    for(int i = 0 ; i < N ; i++){
        if(tree[i] > h)
            sum_h += (tree[i] - h);
    }
    
    return sum_h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    
    int ans = 0;
    int bot = 0;
    int top = max_h;
    while(bot <= top){
        int mid = ( top + bot ) / 2;
        long long sum_h = cut_tree(mid);
        
        if(sum_h >= M){
            ans = mid;
            bot = mid + 1;
        }
        else{
            top = mid - 1;
        }
    }
    
    printf("%d", ans);
    return 0;
}