#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &DNA);
int main(){
    int testNum;
    cin >> testNum;
    vector<int> DNA(10);
    for(int i = 0;i < testNum; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> DNA[j];
        }
        print(DNA);
    }
    return 0;
}

void print(vector<int> &DNA){
  vector<int> cur(42, 0);
  vector<int> next(42, 0);
  cur[20] = 1;
  for(int i = 0; i < 50; ++i){
     for(int j = 1; j <= 40; ++j){
        switch(cur[j]){
            case 0: cout << " "; break;
            case 1: cout << "."; break;
            case 2: cout << "x"; break;
            case 3: cout << "W"; break;
        }
        next[j] = DNA[cur[j - 1] + cur[j] + cur[j + 1]];
     }
     cout << endl;
     cur.swap(next);
  }
}
