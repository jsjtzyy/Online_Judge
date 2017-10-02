#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num;
    //cout << INT_MAX <<endl;
    //cout << INT_MIN << endl;
    //return 0;
    cin >> num;
    vector<int> input(num);
    for(int i = 0; i < num; ++i){
        cin >> input[i];
    }
    vector<int> dp(num, 1);
    int absVal = 0, cur;
    int isPositive;
    int res = 1;
    for(int i = 1; i < num; ++i){
        absVal = 0;
        cur = input[i];
        isPositive = (cur > 0) ? 1 : -1;
        for(int j = i - 1; j >= 0; --j){
            if(input[j] * isPositive < 0 && abs(input[j]) < abs(cur)){
                if(abs(input[j]) <= absVal) continue;
                absVal = abs(input[j]);
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(res, dp[i]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
