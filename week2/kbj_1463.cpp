#include <iostream>

using namespace std;

int x;

int main(){
	
	int num[1000001];
	int i;
	
	cin >> x;
	
	num[1] = 0;
	num[2] = 1;
	num[3] = 1;
	
	for(i=4; i<=x; i++){
		int tmp = 99999999;
		
		if(i % 3 == 0){
			if(num[i/3] + 1 < tmp){
				tmp = num[i/3] + 1;
			}
		}
		if(i % 2 == 0){
			if(num[i/2] + 1 < tmp){
				tmp = num[i/2] + 1;
			}
		}
		
		if(num[i-1] + 1 < tmp){
			tmp = num[i-1] + 1;
		}
		
		
		num[i] = tmp;
	}
	
// 	for(i=2; i<=x; i++){
// 		cout << i << ": " << num[i] << endl;
// 	}
	
 	cout << num[x] << endl;
	
	return 0;
}