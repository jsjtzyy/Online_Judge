#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    stack<int> s; // record the index of left parenthesis
    string str;
    cin >> str;
    int len = str.length();
    int res = 0, index, lastUnMatchRight = -1;
    for(int i = 0; i < len; ++i){
        if(str[i] == '('){
            s.push(i);
        }else{
            if(!s.empty()){
                index = s.top();
                s.pop();
                if(s.empty()){
                    res = max(res, i - lastUnMatchRight);
                }else{
                    res = max(res, i - s.top());
                }
            }else{
                lastUnMatchRight = i;
            }
        }
    }
    cout << "max length is "<< res << endl;
    return 0;
}
