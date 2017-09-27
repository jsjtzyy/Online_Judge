#include <iostream>
#include <vector> 
#include <unordered_map>
using namespace std;
void solve(vector<vector<char> > &cities, vector<vector<int> > &count, int total, unordered_map<char, int> &map);

int main(){
   string line;
   vector<vector<char> > cities;
   //vector<int> city;
   vector<vector<int> > count;
   count.resize(5, vector<int>(5, 0));
   int total = 0;
   char ch;
   unordered_map<char, int> map;
   map['P'] = 0;
   map['G'] = 1;
   map['A'] = 2;
   map['S'] = 3;
   map['N'] = 4;
   while(true){
     cin >> line;
     if(line[0] == '#') break;
     if(line[0] == 'e'){
       solve(cities, count, total, map);
       cities.clear();
       count.clear();
       count.resize(5, vector<int>(5, 0));
       total = 0;
       continue;
     }
     vector<char> city(5); 
     total++;
     for(int i = 0; i < line.length(); i = i + 4){
        ch = line[i];
        unordered_map<char, int>::iterator it;
        switch(ch){
            case 'r': it = map.find(line[i + 2]); city[0] = line[i + 2]; count[0][it->second]++; break;
            case 'o': it = map.find(line[i + 2]); city[1] = line[i + 2]; count[1][it->second]++;break;
            case 'y': it = map.find(line[i + 2]); city[2] = line[i + 2]; count[2][it->second]++;break;
            case 'g': it = map.find(line[i + 2]); city[3] = line[i + 2]; count[3][it->second]++;break;
            case 'b': it = map.find(line[i + 2]); city[4] = line[i + 2]; count[4][it->second]++;break;
        }
    }
    cities.push_back(city);
   }
    return 0;
}

void solve(vector<vector<char> > &cities, vector<vector<int> > &count, int total, unordered_map<char, int> &map){
    int minIndex = -1, minVal = 1 << 30;
    int sum = 0;
    unordered_map<char, int>::iterator it;
    for(int i = 0; i < total; ++i){
        sum = 0;
        for(int j = 0; j < 5; ++j){
            it = map.find(cities[i][j]);
            sum += total - count[j][it->second];
        }
        if(sum < minVal){
            minVal = sum;
            minIndex = i;
        }
    }
    cout << minIndex + 1 <<endl;
}
