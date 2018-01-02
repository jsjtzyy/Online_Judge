#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(){
    int n, dividend;
    cout << "Input dividend" << endl;
    cin >> dividend;
    cout << "Input a divisor" << endl;
    cin >> n;
    unordered_map<int, int> indexMap;
    //int dividend = 1;
    dividend %= n;
    vector<int> digits;
    dividend *= 10;
    while(dividend < n){
        digits.push_back(0);
        dividend *= 10;
    }
    //indexMap[dividend] = digits.size();
    while(indexMap.find(dividend) == indexMap.end()){
        indexMap[dividend] = digits.size();
        digits.push_back(dividend / n);
        dividend = dividend % n;
        if(dividend == 0) {
            cout << "most frequent digits are: " << 0 << endl;
            return 0;
        }
        dividend *= 10;
        while(dividend < n){
            digits.push_back(0);
            dividend *= 10;
        }
    }
    int cnt[10] = {0};
    int nonPeriodic[10] = {0};
    for(int i = indexMap[dividend]; i < digits.size(); ++i){
        ++cnt[digits[i]];
    }
    for(int i = indexMap[dividend] - 1; i >= 0; --i){
        nonPeriodic[digits[i]]++;
    }
    int maxVal = 0;
    unordered_set<int> set;
    for(int i = 0; i < 10; ++i){
        if(cnt[i] > maxVal){
            set.clear();
            set.insert(i);
            maxVal = cnt[i];
        }else if(cnt[i] == maxVal){
            set.insert(i);
        }
    }
    unordered_set<int> res;
    maxVal = 0;
    for(int num : set){
        if(nonPeriodic[num] > maxVal){
            res.clear();
            res.insert(num);
            maxVal = nonPeriodic[num];
        }else if ( nonPeriodic[num] == maxVal ){
            res.insert(num);
        }
    }
    cout << "most frequent digits are: ";
    for(int num : res){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
