#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int T;

deque<string> split(string str, char c){
    deque<string> dq;
    int first = 0;
    for(int i = 0 ; i < str.length() ; i++){
        if(i == str.length() - 1)
            dq.push_back(str.substr(first));
        if(str[i] == c){
            dq.push_back(str.substr(first, i-first));
            first = i + 1;
        }
    }
    return dq;
}

string remove_R(string str){
    string removed_str;
    for(int i = 0 ; i < str.length() ; i++){
        if( str[i] == 'R' && str[i + 1] == 'R'){
            i++;
            continue;
        }
        removed_str += str[i];
    }
    return removed_str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0 ; i < T ;i++){
        int n;
        bool dir = true;
        bool error_flag = false;
        
        string cmd, str;
        cin >> cmd >> n >> str;
        deque<string> nums = split(str.substr(1, str.size() -2), ',');

        cmd = remove_R(cmd);
        for(int i = 0 ; i < cmd.length() ;i++){
            if(cmd[i] == 'R'){
                if(dir == true)
                    dir = false;
                else
                    dir = true;
            }
            else if(cmd[i] == 'D'){
                if(nums.empty()){
                    error_flag = true;
                    cout << "error" << "\n";
                    break;
                }
                if(dir)
                    nums.pop_front();
                else
                    nums.pop_back();
            }
        }
        
        if(error_flag == false){
            if(dir == false)
                reverse(nums.begin(), nums.end());
            string output;
            output += '[';
            for(int i = 0 ; i < nums.size(); i++){
                output += nums[i];
                if(i != nums.size() - 1){
                    output += ',';
                }
            }
            output += ']';
            cout << output <<"\n";
        }
    }
    return 0;
}