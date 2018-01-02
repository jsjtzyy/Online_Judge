#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int testNum, num, x, N;
    cin >> testNum;
    while(testNum--){
        cin >> num;
        if(num % 2 == 1) N = num + 1;
        else N = num;
        vector<int>v(N, 0);
        for(int i = 0; i < num; ++i){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        x = 0;
        for(int i = 0; i + 1 < N; i += 2)// every two adjacent chessman, compute slots between them
        {
            x ^= (v[i + 1] - v[i] - 1);
            cout << v[i + 1] << " " << v[i] <<" " << x << endl;
        }
        if(x == 0){
            cout<<"Bob will win"<<endl;
        }else{
            cout<<"Georgia will win"<<endl;
        }
    }
    return 0;
}
