#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, k, m;
    while(true){
        cin >> N >> k >> m;
        if(N == 0) break;
        vector<int> v(N);
        for(int i = 0; i < N; ++i) v[i] = i + 1;
        string res = "";
        int cw = N - 1, ccw = 0;
        ccw = (ccw + k - 1) % N;
        cw = cw - m + 1 ;
        while(cw < 0) cw += N;
        cw %= N;
        if(cw == ccw){
            if(v[cw] > 9){
                res.append(" " + to_string(v[cw]));
            }else{
                res.append("  " + to_string(v[cw]));
            }
            v.erase(v.begin() + cw);
            if(v.size() != 0){
                ccw = ccw % v.size();
                cw = (cw - 1 + v.size()) % v.size();
            }
        }else{
            if(v[ccw] > 9){
                res.append(" " + to_string(v[ccw]));
            }else{
                res.append("  " + to_string(v[ccw]));
            }
            if(v[cw] > 9){
                res.append(" " + to_string(v[cw]));
            }else{
                res.append("  " + to_string(v[cw]));
            }
            if(cw > ccw){
                v.erase(v.begin() + cw);
                v.erase(v.begin() + ccw);
                if(v.size() != 0){
                    ccw  = ccw % v.size();
                    cw = (cw - 2 + v.size()) % v.size();
                }
            }else{
                v.erase(v.begin() + ccw);
                v.erase(v.begin() + cw);
                if(v.size() != 0){
                    ccw = (ccw - 1 + v.size()) % v.size();
                    cw = (cw - 1 + v.size()) % v.size();
                }
            }
        }
        while(v.size() > 0){
        ccw = (ccw + k - 1) % v.size();
        cw = cw - m + 1;
        while(cw < 0) cw += v.size();
        cw %= v.size();
        if(cw == ccw){
            if(v[cw] > 9){
                res.append(", " + to_string(v[cw]));
            }else{
                res.append(",  " + to_string(v[cw]));
            }
            v.erase(v.begin() + cw);
            if(v.size() != 0){
                 ccw = ccw % v.size();
                 cw = (cw - 1 + v.size()) % v.size();
            }
        }else{
            if(v[ccw] > 9){
                res.append(", " + to_string(v[ccw]));
            }else{
                res.append(",  " + to_string(v[ccw]));
            }
            if(v[cw] > 9){
                res.append(" " + to_string(v[cw]));
            }else{
                res.append("  " + to_string(v[cw]));
            }
            if(cw > ccw){
                v.erase(v.begin() + cw);
                v.erase(v.begin() + ccw);
                if(v.size() != 0){
                    ccw  = ccw % v.size();
                    cw = (cw - 2 + v.size()) % v.size();
                }
            }else{
                v.erase(v.begin() + ccw);
                v.erase(v.begin() + cw);
                if(v.size() != 0){
                    ccw = (ccw - 1 + v.size()) % v.size();
                    cw = (cw - 1 + v.size())  % v.size();
                }
            }
        }
             
        }
        cout << res <<endl;
    }
    return 0;
}
