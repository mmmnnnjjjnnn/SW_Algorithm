#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct time_table {
    int s;
    int e;
    bool operator<(const time_table& other) const {
        if(e == other.e)
            return s > other.s;
        return e > other.e;
    }
};

priority_queue<time_table> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin >> a>> b;
        pq.push({a,b});
    }

    int start = 0;
    int cnt = 0;
    while(!pq.empty()){
        if(start <= pq.top().s){
            start = pq.top().e;
            cnt++;
        }
        pq.pop();
    }
    cout << cnt;
    return 0;
}