#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int compute(int num);
int main(){
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(3);
    int n;
    int cnt = 0;
    int maxCube = 0, val;
    while(scanf("%d",&n)){
        if(n == 0) break;
        ++cnt;
        if(n < dp.size()){
            cout << "Case #" << cnt <<": "<<dp[n]<<endl;
            continue;
        }
        for(int i = dp.size(); i <= n; ++i){
            maxCube = compute(i);
            val = i;
            for(int j = 1; j <= maxCube; ++j){
                val = min(val, dp[i - j*j*j] + 1);
            }
            dp.push_back(val);
        }
        cout << "Case #" << cnt <<": "<<dp[n]<<endl;
    }
    return 0;
}

int compute(int num){
    int left = 1, right = num;
    int mid; long val;
    while(left < right - 1){
        mid = (left + right) / 2;
        val = (long)mid * mid * mid;
        if(val == (long)num){
            left = mid; 
            break;
        }
        if(val < (long)num){
            left = mid;
        }else{
            right = mid;
        }
    }
    return left;
}
