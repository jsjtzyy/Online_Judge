#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int tmp;
    while(a % b != 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return b;
}

long helper(long n, long r1, long r2){  // (0, n]
    //cout << "n = " << n << endl;    
    //cout << "r1 = " << r1 << ", r2 =" << r2 << endl;
    //int k = (n * r1) / r2;
    //cout << "k = " << k << endl;
    if(r1 % r2 == 0) return (n + 1) * n / 2 * (r1 / r2) + n + 1;
    long sum = (r1 / r2) * (n + 1) * n / 2;
    //r1 = r1 % r2;
    long d = n * r1 / r2 - n * (r1 / r2);     // use Pick's Theorem
    r1 = r1 % r2;
    sum += (n + 1) * (d + 1) + d / r1 + 1;
    return sum - helper(d, r2, r1);
}

int main(){
    int testNum;
    cin >> testNum;
    int n, a, b, d;
    long long r1, r2, k, m;
    long long res;
    for(int i = 0; i < testNum; ++i){
        res = 0;
        cin >> n >> a >> b;
        d = gcd(b, a);
        r1 = a / d;
        r2 = b / d;
        res = helper(n, r1, r2);
        cout << res << endl;
    }
}
