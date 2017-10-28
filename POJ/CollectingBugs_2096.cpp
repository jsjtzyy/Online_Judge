#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>

using namespace std;

int main(){
    int n, s;
    double e1, e2, e3;
    double p0, p1, p2, p3;
    cout << fixed << setprecision(4);
    while(~scanf("%d %d", &n, &s))
    {
        vector<vector<double> > dp(n + 1, vector<double>(s + 1, 0.0));
        for(int i = n; i >= 0; --i){
            for(int j = s; j >= 0; --j){
                if(i == n && j == s) continue;
                if(j + 1 > s) e1 = 0.0;
                else e1 = dp[i][j + 1];
                if(i + 1 > n) e2 = 0.0;
                else e2 = dp[i + 1][j];
                if(i + 1 > n || j + 1 > s) e3 = 0.0;
                else e3 = dp[i + 1][j + 1];
                p0 = (double)j / s * (double)i / n;
                p1 = (double)(s - j) / s * (double)i / n;
                p2 = (double)(n - i)/ n * (double)j / s;
                p3 = (double)(n - i) / n * (double)(s - j) / s;
                dp[i][j] = 1 /(1-p0) * (p1*e1 + p2*e2 + p3*e3 + 1);
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}
/*
 dp[i][j]表示已经找到i种bug，并存在于j个子系统中，要达到目标状态的天数的期望。
 显然，dp[n][s]=0，因为已经达到目标了。而dp[0][0]就是我们要求的答案。
 dp[i][j]状态可以转化成以下四种：
 dp[i][j] 发现一个bug属于已经找到的i种bug和j个子系统中
 dp[i+1][j] 发现一个bug属于新的一种bug，但属于已经找到的j种子系统
 dp[i][j+1] 发现一个bug属于已经找到的i种bug，但属于新的子系统
 dp[i+1][j+1]发现一个bug属于新的一种bug和新的一个子系统
 以上四种的概率分别为：
 p1 = i*j / (n*s)
 p2 = (n-i)*j / (n*s)
 p3 = i*(s-j) / (n*s)
 p4 = (n-i)*(s-j) / (n*s)
 又有：期望可以分解成多个子期望的加权和，权为子期望发生的概率，即 E(aA+bB+...) = aE(A) + bE(B) +...
 所以：
 dp[i,j] = p1*dp[i,j] + p2*dp[i+1,j] + p3*dp[i,j+1] + p4*dp[i+1,j+1] + 1;公式中的+1代表本次的操作
 */
