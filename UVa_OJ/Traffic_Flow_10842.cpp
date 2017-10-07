#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Edge{
public:
    int node1;
    int node2;
    int capacity;
    Edge(int x, int y, int c):node1(x), node2(y), capacity(c){}
};

struct cmp{
    bool operator() (Edge *a, Edge *b){
        return (a->capacity) < (b->capacity);
    }
};

int kruscal(priority_queue<Edge*, vector<Edge*>, cmp>&pq, int nodeNum){
    vector<int> parent(nodeNum, -1);
    vector<int> rank(nodeNum, 1);
    int cnt = 0;
    Edge* edge;
    int minVal, index1, index2;
    while(cnt < nodeNum - 1){
        edge = pq.top();
        pq.pop();
        index1 = edge->node1;
        index2 = edge->node2;
        //cout << edge -> capacity << endl;
        while(parent[index1] != -1) index1 = parent[index1];
        while(parent[index2] != -1) index2 = parent[index2];
        if(index1 == index2) continue;
        minVal = edge->capacity;
        if(rank[index1] == rank[index2]){
            parent[index2] = index1;
            rank[index1] += 1;
        }else if(rank[index1] > rank[index2]){
            parent[index2] = index1;
        }else{
            parent[index1] = index2;
        }
        ++cnt;
    }
    return minVal;
}

int main(){
    int testNum;
    cin >> testNum;
    int nodeNum, edgeNum;
    int x, y, c;
    //priority_queue<Edge*, vector<Edge*>, cmp> pq;
    for(int i = 0; i < testNum; ++i){
        cin >> nodeNum >> edgeNum;
        priority_queue<Edge*, vector<Edge*>, cmp> pq;
        //pq.clear();
        for(int j = 0; j < edgeNum; ++j){
            cin >> x >> y >> c;
            Edge* e = new Edge(x, y, c);
            pq.push(e);
        }
        cout <<"Case #"<<i+1<<": " << kruscal(pq, nodeNum) << endl;
    }
    return 0;
}
