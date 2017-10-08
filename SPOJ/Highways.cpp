#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Edge{
public:
    int node1;
    int node2;
    int time;
    Edge(int x, int y, int t):node1(x), node2(y), time(t){}
};

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};
int Dijkstra(unordered_map<int, vector<Edge*> > &map, int nodeNum, int start, int end){ 
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    unordered_map<int, int> mp;
    unordered_set<int> st;
    for(int i = 0; i < nodeNum; ++i){
        pair<int, int> p;
        if(i + 1 == start){
            mp[i+1] = 0;
            p = make_pair(i+1, 0);
        }else{
            mp[i+1] = INT_MAX;
            p = make_pair(i + 1, INT_MAX);
        }
        pq.push(p);
        st.insert(i+1);
    }
    vector<Edge*> edges;
    int dest, src;
    pair<int, int> pr;
    while(!pq.empty()){
        pr = pq.top(); pq.pop();
    //    cout << "id = " << id << "; " << "time = " << mp[id] <<endl;
            if(pr.first == end) return pr.second;
            if(pr.second == INT_MAX) return INT_MAX;
            edges = map[pr.first];
            for(Edge* e: edges){
                dest = e -> node2;
                if(st.find(dest)  != st.end()){
                    if(pr.second + e->time < mp[dest]){
                        mp[dest] = pr.second + e->time;
                        pq.push(make_pair(dest, mp[dest])); // there may be pairs with same first value
                    }         // the idea is waste some space to acquire the minimum weight for the pq
                }
            }
        st.erase(pr.first);
    }
    return INT_MAX;
}

int main(){
    int testNum;
    cin >> testNum;
    int nodeNum, edgeNum, start, end;
    int x, y, t, res;
    for(int i = 0; i < testNum; ++i){
        unordered_map<int, vector<Edge*> > map;
        cin >> nodeNum >> edgeNum >> start >> end;
        for(int j = 0; j < edgeNum; ++j){
            cin >> x >> y >> t;
            if(map.find(x) != map.end()){
                map[x].push_back(new Edge(x, y, t));
            }else{
                vector<Edge*> vec;
                vec.push_back(new Edge(x, y, t));
                map[x] = vec;
            }
            if(map.find(y) != map.end()){
                map[y].push_back(new Edge(y, x, t));
            }else{
                vector<Edge*> vec;
                vec.push_back(new Edge(y, x, t));
                map[y] = vec;
            }
        }
        res = Dijkstra(map, nodeNum, start, end);
        if(res == INT_MAX) cout << "NONE"<<endl;
        else cout << res << endl;
    }
    return 0;
}
