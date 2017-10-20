#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Seg{
public:
    pair<int, int> high;
    pair<int, int> low;
    Seg(){
        high = make_pair(0, 0);
        low = make_pair(0, 0);
    }
    Seg(int x1, int y1, int x2, int y2){
        if(y2 > y1){
            high = make_pair(x2, y2);
            low = make_pair(x1, y1);
        }else{
            high = make_pair(x1, y1);
            low = make_pair(x2, y2);
        }
    }
};

struct cmp{
    bool operator()(Seg &a, Seg &b){
        return a.low.second < b.low.second;
    }
}cmpSeg;

int cross(pair<int, int> &p1, pair<int, int> &p2){
    return p1.first * p2.second - p1.second * p2.first;
}

bool intersect(Seg &a, Seg &b){
    pair<int, int> vecA(a.high.first - a.low.first, a.high.second - a.low.second);
    pair<int, int> vecAb1(b.high.first - a.low.first, b.high.second - a.low.second);
    pair<int, int> vecAb2(b.low.first - a.low.first, b.low.second - a.low.second);
    pair<int, int> vecB(b.high.first - b.low.first, b.high.second - b.low.second);
    pair<int, int> vecBa1(a.high.first - b.low.first, a.high.second - b.low.second);
    pair<int, int> vecBa2(a.low.first - b.low.first, a.low.second - b.low.second);
    if(cross(vecA, vecAb1) * cross(vecA, vecAb2) < 0 && cross(vecB, vecBa1) * cross(vecB, vecBa2) < 0) return true;
    return false;
}

void findFallPoint(vector<Seg> &segments, vector<pair<int, int> > &sources){
    unordered_map<int, int> map; // key = index of Seg in vector; val = final ground point of this Seg;
    sort(segments.begin(), segments.end(), cmpSeg);
    
    for(int i = 0; i < segments.size(); ++i){
        for(int j = i - 1; j >= 0; --j){
            Seg tmp = segments[i];
            Seg newSeg = Seg(tmp.low.first,tmp.low.second, tmp.low.first, segments[j].low.second);
            if(intersect(newSeg, segments[j])){
                map[i] = map[j];
                break;
            }
        }
        if(map.find(i) == map.end()){
            map[i] = segments[i].low.first;
        }
    }
    bool hitPlane;
    for(int i = 0; i < sources.size(); ++i){
        hitPlane = false;
        for(int j = segments.size() - 1; j >= 0; --j){
            if(sources[i].second <= segments[j].low.second) continue;
            Seg newSeg = Seg(sources[i].first, sources[i].second, sources[i].first, segments[j].low.second);
            if(intersect(newSeg, segments[j])){
             cout << map[j] << endl;
             hitPlane = true;
             break;
            }
        }
        if(!hitPlane) cout << sources[i].first<< endl;
    }
}

int main(){
    int testNum, NP, NS; // NP = number of segments, NS = number of sources
    int x1, y1, x2, y2;
    cin >> testNum;
    for(int i = 0; i < testNum; ++i){
        cin >> NP;
        vector<Seg> segments(NP);
        for(int j = 0; j < NP; ++j){
            cin >> x1 >> y1 >> x2 >> y2;
            segments.push_back(Seg(x1, y1, x2, y2));
        }
        cin >> NS;
        vector<pair<int, int> > sources;
        for(int j = 0;j < NS; ++j){
            cin >> x1 >> y1;
           sources.push_back(make_pair(x1, y1));
        }
        findFallPoint(segments, sources);
        cout << endl;
    }
    return 0;
}
