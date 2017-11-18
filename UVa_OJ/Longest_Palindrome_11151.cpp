#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numOfStrings;
    cin >> numOfStrings;
    string str;
    cin.ignore();
    int len;
    for(int i = 0; i < numOfStrings; ++i){
        //cin >> str;
        getline(cin,str);
        if(str == "") {
            cout << 0 << endl;
            continue;
        }
        len = str.length();
        vector<vector<int> > dp(len, vector<int>(len, 0));
        for(int d = 0; d < len; ++d){
            for(int r = 0; r + d < len; ++r){
                if(d == 0) {
                    dp[r][r] = 1;
                    continue;
                }
                if(d == 1){
                    dp[r][r + d] = (str[r] == str[r + d])? 2: 1;
                    continue;
                }
                dp[r][r + d] = dp[r + 1][r + d - 1] + ((str[r] == str[r + d])? 2: 0);
                dp[r][r + d] = max(dp[r][r + d - 1], max(dp[r][r + d], dp[r + 1][r + d]));
            }
        }

        cout << dp[0][len - 1] << endl;
    }
    return 0;
}
