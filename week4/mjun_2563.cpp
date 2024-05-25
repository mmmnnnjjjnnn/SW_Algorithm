#include <iostream>
using namespace std;

int n;
int m[100][100];

void fill_map(int y, int x){
    for(int i = 0 ; i < 10 ; i++)
        for(int j = 0 ; j < 10 ; j++)
            m[y+i][x+j] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x,y;
        cin >> x >> y;
        fill_map(y,x);
    }
    int sum = 0;
    for(int i = 0 ; i < 100; i++)
        for(int j = 0 ; j < 100; j++)
            if(m[i][j]==1)
                sum += 1;
    cout << sum;
    return 0;
}