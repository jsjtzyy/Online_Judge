#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    int testNum;
    cin >> testNum;
    int n, k, m;
    for(int i = 1; i <= testNum; ++i){
        cin >> n >> k >> m;
        vector<double> dp(m + 1, 0.0);
        vector<double> P(n);
        for(int j = 0; j < n; ++j){
            cin >> P[j];
        }
        dp[0] = 0; dp[1] = P[0];
        for(int j = 2; j <= m; ++j){
            for(int t = 0; t < n; ++t) // n kinds of possibilities
            {
                dp[j] += P[t] * pow(dp[j - 1], t);
            }
        }
        cout << "Case #" << i << ": "; 
        cout << fixed << setprecision(7) << pow(dp[m], k) << endl;  // k tribes are independent
    }
    return 0;    
}
