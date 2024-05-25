#include <iostream>
using namespace std;

int T;
int dp[10] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};

long long f3(long long n, long long digit){
    long long ret = 0;
    long long num = n % (digit*10);     // n : 1234, target_diget : 10 -> 34
    if(num / digit - 1 >= 0 && num / digit - 1 < 10)
        ret += dp[(num / digit - 1)] * digit;   // dp[2] x 10 (0-9 x 10)
    ret += (num % digit + 1) * (num / digit);   // 3 x 5 (30 31 32 33 34)

    return ret;
}

long long f2(long long n, long long digit){
    long long ret = 0;
    ret = (n / (digit *10)) * 45 * digit;   // n : 1234, target_diget : 10, 12 * (0-9) * 100
    return ret;
}

long long f1(long long n){
    long long sum = 0;
    long long digit = 1;
    while(n / digit > 0){   // 1의 자리 수부터 끝까지
        sum += f2(n, digit) + f3(n, digit);
        digit *= 10;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    for(int i = 0 ; i < T ;i++){
        long long n1, n2;
        cin >> n1 >> n2;
        cout << f1(n2) - f1(n1-1) << "\n";
    }
    return 0;
}