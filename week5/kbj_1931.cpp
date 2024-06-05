#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

vector< pair<int, int> > time_pair;
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }

}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    int start, end, cnt;
    
    cin >> n;
    int i;
    for(i=0; i<n; i++){
        cin >> start >> end;

        time_pair.push_back(make_pair(end, start));
    }

    sort(time_pair.begin(), time_pair.end(), compare);

    // for(i=0; i<n; i++){
    //     cout << time_pair[i].second << ", " << time_pair[i].first << endl;
    // }
    pair<int, int> cur;
    cur = time_pair[0];
    cnt = 1;
    for(i=1; i<n; i++){
        if(time_pair[i].second >= cur.first){
            // cout << "(" << cur.second << ", "  << cur.first << ") -> (" << time_pair[i].second << ", " << time_pair[i].first << ")" << endl;
            cur = time_pair[i];
            cnt++;
        }
        else{
            continue;
        }
    }

    cout << cnt << endl;

    return 0;
}