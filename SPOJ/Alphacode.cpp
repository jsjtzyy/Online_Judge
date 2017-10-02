#include <iostream>
#include <vector>
using namespace std;

int decode(string &str);

int main(){
    string str;
    while(1){
        cin >> str;
        if(str[0] == '0') break;
        cout << decode(str) << endl;
    }
    return 0;
}

int decode(string &str){
   int len = str.length();
   if(len <= 1) return len;
   vector<int> dp(len, 0);
   dp[0] = 1;
   if(str[0] != '0' && (str[0] - '0') * 10 + (str[1] - '0') <= 26) dp[1] += dp[0];
   if(str[1] != '0') dp[1] += 1;
   int val;
   for(int i = 2; i < len; ++i){
        val = (str[i - 1] - '0') * 10 + (str[i] - '0');
        if(str[i - 1] != '0' && val <= 26) dp[i] += dp[i - 2];
        if(str[i] != '0') dp[i] += dp[i - 1];
   }
   return dp[len - 1];
}

