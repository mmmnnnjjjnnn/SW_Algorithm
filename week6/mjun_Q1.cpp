#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int R, C;
int map[MAX][MAX];

void input(){
    cin >> R >> C;
    for(int i = 0 ; i < R ; i++)
        for(int j = 0 ; j < C ; j++)
            cin >> map[i][j];
}

void Rotate(int sr, int sc, int er, int ec){
    int a = map[sr][sc];

    for (int r = sr + 1; r <= er; ++r) {
        int temp = map[r][sc];
        map[r][sc] = a;
        a = temp;
    }//row +
    
    for (int c = sc + 1; c <= ec; ++c) {
        int temp = map[er][c];
        map[er][c] = a;
        a = temp;
    }//col +

    for (int r = er - 1; r >= sr; --r) {
        int temp = map[r][ec];
        map[r][ec] = a;
        a = temp;
    }//row -
    
    for (int c = ec - 1; c >= sc; --c) {
        int temp = map[sr][c];
        map[sr][c] = a;
        a = temp;
    }//col -
    
}


void output(){
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < C ; j++)
            cout << map[i][j];
        cout<< "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();        
    int N = max(R,C);
    for(int i = 0 ; i < N ; i++){
        if( i == R-i-1 || i == C-i-1)
            break;
        Rotate(i, i, R-i-1, C-i-1);
    }
    
    output();
    
    return 0;
}