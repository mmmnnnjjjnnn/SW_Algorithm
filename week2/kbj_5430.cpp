#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int tc;

int main(void){
	char cmd[100010];
	short arr[100010];
	int start, end;
	
	int i, j;
	char tmp;
	int cmd_len = 0, arr_len;
	
	cin >> tc;
    // cout << "tc: " << tc << endl;
    getchar();
	for(i=0; i<tc; i++){
        string tmp_str;
		cmd_len = 0, arr_len = 0;
		bool result_err = false;
        
        getline(cin, tmp_str);

        // cout << "cmd_str: " << tmp_str << ", cmd_len:" << tmp_str.length() << endl;

        for(j=0; j<tmp_str.length(); j++){
            cmd[j] = tmp_str.c_str()[j];
        }
        cmd_len = tmp_str.length();

        // cout << "after parsing, ";
        // for(j=0; j<cmd_len; j++){
        //     cout << cmd[j] << " ";
        // }
        // cout << endl;


        cin >> arr_len;
        // cout << "arr_len: " << arr_len << endl;
        int cur_arr = 0;
        
        getchar();
		getline(cin, tmp_str);
        // cout << "before parsing, ";
        // cout << "arr_str: " << tmp_str << endl;
		// cout << "arr_str_len: " << tmp_str.length() << endl;
        short tmp = 0;
        for(j=0; j<tmp_str.length(); j++){
            char now;
            now = tmp_str.c_str()[j];
            if(now == '['){
                continue;
            }
            else if(now == ']' || now == ','){
                arr[cur_arr] = tmp;
                tmp = 0;
                cur_arr++;
                continue;
            }
            tmp = tmp * 10 + now - '0';
            
        }
		
        // cout << "after parsing, arr_len: " << arr_len << ", [";
        // for(j=0; j<arr_len; j++){
        //     cout << arr[j];
        // }
        // cout << "]" << endl;
		
		start = 0, end = arr_len - 1;
		
		for(j=0; j<cmd_len; j++){
			if(cmd[j] == 'R'){
				int swap;
				swap = start;
				start = end;
				end = swap;
			}
			
			else{
				// 제거 불가
				if(arr_len == 0){
					result_err = true;
					break;
				}
				
				// 정방향 제거
				if(start < end){
					start++;
				}
				
				// 역방향 제거
				else{
					start--;
				}
				arr_len--;
			}
		}
		
		if(result_err == false){
			if(arr_len == 0){
				cout << "[]" << endl;
				continue;
			}
			// 정방향
			if(start < end){
				cout << "[";
				for(j=start; j<=end; j++){
					cout << arr[j];
					if(j != end){
						cout << ",";	
					}
				}
				cout << "]" << endl;
			}
			
			// 역방향
			else{
				cout << "[";
				for(j=start; j>=end; j--){
					cout << arr[j];
					if(j != end){
						cout << ",";	
					}
				}
				cout << "]" << endl;
			}
		}
		else{
			cout << "error" << endl;
		}
	}
	
	return 0;
}