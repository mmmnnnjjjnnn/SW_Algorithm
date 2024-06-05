#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int> > pq;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;

    cin >> n;

    int i, tmp;
    for(i=0; i<n; i++){
        cin >> tmp;

        if(tmp == 0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(tmp);
        }
    }


    return 0;
}