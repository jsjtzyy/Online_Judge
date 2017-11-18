#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    vector<int> dp(N, 1);
    dp[0] = 1;
    int res = 1;
    for(int i = 1; i < N; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(((arr[i] > 0 &&arr[j] < 0 && -arr[i] < arr[j])||(arr[i] < 0 && arr[j] > 0 && -arr[j] >arr[i]))) 
            {                
                dp[i] = max(dp[i], dp[j] + 1);
               res = max(res, dp[i]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
