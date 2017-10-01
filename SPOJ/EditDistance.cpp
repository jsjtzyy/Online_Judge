#include <iostream>
#include <algorithm>

using namespace std;

int distance(string A, string B);
int main(){
    int testNum;
    cin>> testNum;
    string A, B;
    for(int i = 0; i < testNum; ++i){
        cin >> A >> B;
        cout << distance(A, B) << endl;
    }
    return 0;
}

int distance(string A, string B){
    int aLen = A.length();
    int bLen = B.length();
    int dp[aLen + 1][bLen + 1];
    for(int i = 1; i <= aLen; ++i) dp[i][0] = i;
    for(int i = 1; i <= bLen; ++i) dp[0][i] = i;
    for(int i = 1; i <= aLen; ++i){
        for(int j = 1; j <= bLen; ++j){
            if(A[i - 1] == B[j - 1]){
                dp[i][j] = min(dp[i- 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]) + 1);
            }else{
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
    }
    return dp[aLen][bLen];
}
