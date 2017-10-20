#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;
int main(){
    int D, V;
    double d, val;
    int res;
    while(true){
        cin >> D >> V;
        if(D == 0) break;
        val = (double)(D*D*D) - 6.0 * (double)V / M_PI;
        val = pow(val, 1.0/3.0);
        res = round(val * 1000.0);
        cout <<  fixed << setprecision(3)  << res/1000.0 << endl;
    }
    return 0;
}
