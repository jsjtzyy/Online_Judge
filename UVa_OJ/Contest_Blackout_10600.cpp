#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

class Edge{
public:
    int node1;
    int node2;
    int cost;
    Edge(int x, int y, int c):node1(x),node2(y),cost(c){}
};

struct cmp{
    bool operator()(Edge* a, Edge*b){
        return (a->cost) > (b->cost);
    }
};

int helper(Edge* remove, vector<Edge*> &backup, int nodeNum){
    int res = 0, cnt = 0;
    vector<int> parent(nodeNum + 1, 0);
    vector<int> rank(nodeNum + 1, 1);
    Edge* edge;
    int index1, index2, i = 0;
    while(i < backup.size() && cnt < nodeNum - 1){
        edge = backup[i++];
        if(edge == remove) continue;
        index1 = edge->node1;
        index2 = edge -> node2;
        while(parent[index1] != 0) index1 = parent[index1];
        while(parent[index2] != 0) index2 = parent[index2];
        if(index1 == index2) continue;
        cnt++;
        res += edge->cost;
        if(rank[index1] == rank[index2]){
            parent[index2] = index1;
            rank[index1] +=1;
        }else if(rank[index1] > rank[index2]){
            parent[index2] = index1;
        }else{
            parent[index1] = index2;
        }
    }
    if(cnt < nodeNum - 1) return INT_MAX; // important!!! there might be no MST if specific edge removed
    return res;
}

void kruscal(priority_queue<Edge*, vector<Edge*>, cmp> &pq, int nodeNum, vector<int> &res){
    int cnt = 0;
    vector<int> parent(nodeNum + 1, 0);
    vector<int> rank(nodeNum + 1, 1);
    vector<Edge*> mst;
    vector<Edge*> backup;
    Edge* edge;
    int index1, index2;
    while(cnt < nodeNum - 1){
        edge = pq.top();
        pq.pop();
        backup.push_back(edge);
        index1 = edge -> node1;
        index2 = edge -> node2;
        while(parent[index1] != 0) index1 = parent[index1];
        while(parent[index2] != 0) index2 = parent[index2];
        if(index1 == index2) {
            continue;
        }
        res[0] += edge->cost;
        mst.push_back(edge);
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
    while(!pq.empty()){
        backup.push_back(pq.top());
        pq.pop();
    }
    res[1] = INT_MAX;
    for(int i = 0; i < mst.size(); ++i){
       res[1] = min(res[1], helper(mst[i], backup, nodeNum));
    }
}



int main(){
    int testNum;
    cin >> testNum;
    int nodeNum, edgeNum;
    int x, y, c;
    Edge* e;
    for(int i = 0; i < testNum; ++i){
        cin >> nodeNum >> edgeNum;
        priority_queue<Edge*, vector<Edge*>, cmp> pq;
        for(int j = 0; j < edgeNum; ++j){
            cin >> x >> y >> c;
            e = new Edge(x, y, c);
            pq.push(e);
        }
        vector<int> res(2);
        kruscal(pq, nodeNum, res);
        cout << res[0] << " "<< res[1] << endl;
    }
    return 0;
}
