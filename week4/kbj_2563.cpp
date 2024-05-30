#include <iostream>

using namespace std;

bool board[100][100];
int x, y;

int main(void){
    int num;

    int i, j, k;

    cin >> num;

    for(i=0; i<100; i++){
        for(j=0; j<100; j++){
            board[i][j] = false;
        }
    }

    for(i=0; i<num; i++){
        cin >> x >> y;

        for(j=0; j<10; j++){
            for(k=0; k<10; k++){
                if(board[x + j][y + k] == true){
                    continue;
                }

                else{
                    board[x + j][y + k] = true;
                }
            }
        }

    }
    int ans = 0;
    for(i=0; i<100; i++){
        for(j=0; j<100; j++){
            if(board[i][j] == true){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}