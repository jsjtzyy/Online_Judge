#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num, val, index, cnt;
    cin >> num;
    while(num > 0){
        vector<int> v(num, 0);
        //if(num % 2 == 1) cout << 1 << endl; // # of piles is odd, can always pick the largets odd pile
        for(int i = 0; i < num; ++i){
            cin >> v[i];
        }
        if(num % 2 == 1) {
            cout << 1 << endl;
            cin >> num;
            continue;
        }
        sort(v.begin(), v.end());
        val = v[0];
        index = 0;
        cnt = 0;
        while(index < num){
            while(index < num && v[index] == val){
                ++cnt;
                ++index;
            }
            if(cnt % 2 == 1) {break;}
            cnt = 0;
            if(index < num) val = v[index];
        }
        if(cnt % 2 == 1) cout << 1 << endl;
        else cout << 0 << endl;
        cin >> num;
    }
    return 0;
}

