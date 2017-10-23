#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream> 
using namespace std;

class Node{
public:
    unordered_map<string, Node*> map;
    Node(){}
};

string generateString(Node *root){
    unordered_map<string, Node*> map = root -> map;
    vector<string> sv;
    unordered_map<string, Node*>::iterator it;
    for(it = map.begin(); it != map.end(); ++it){
        if(it -> second == NULL){ // if node is leaf node, that is file
            sv.push_back("1");    // number indicate the depth of file path
        }else{
            sv.push_back(generateString(it -> second)); // if intermediate node, recursively call function
        }
    }
    sort(sv.begin(), sv.end());
    stringstream ss;
    string tmp = sv[sv.size() - 1];
    ss << tmp[0];     // recode the deepest depth of file path as current node path;
    for(int i = 0; i < sv.size(); ++i){
        ss << "(" << sv[i] << ")";
    }
    return ss.str();
}

int main(){
    int N, M; // N= # of files in original system;  M = # of files in backup system (should be identical)
    string str;
    cin >> N;
    int len = 0;
    Node* origin = new Node();
    Node* node = origin;
    Node* prev;
    string sub;
    int i, j;
    for(i = 0; i < N; ++i){ // build original tree
        cin >> str;
        node = origin;
        prev = origin;
        stringstream ss(str);
        while(getline(ss, sub, '/')){
            unordered_map<string, Node*> &tmp = node->map;
            if(tmp.find(sub) != tmp.end()){
                node = tmp[sub];
            }else{
                Node *n = new Node();
                tmp[sub] = n;
                prev = node;
                node = tmp[sub];
            }
        }
        (prev->map)[sub] = NULL;
        delete node;
    }
    cin >> M;
    if(M != N) {cout << "INVALID" << endl; return 0;}
    Node* backup = new Node();
    for(i = 0; i < M; ++i){
        cin >> str;
        node = backup;
        prev = backup;
        stringstream ss(str);
        while(getline(ss, sub, '/')){
            unordered_map<string, Node*> &tmp = node->map;
            if(tmp.find(sub) != tmp.end()){
                node = tmp[sub];
            }else{
                Node *n = new Node();
                tmp[sub] = n;
                prev = node;
                node = tmp[sub];
            }
        }
        (prev->map)[sub] = NULL;
        delete node;
    }

    string strOrigin = generateString(origin);
    string strBackup = generateString(backup);
    if(strOrigin != strBackup) cout << "INVALID" << endl;
    else cout << "OK" << endl;
    return 0;
}
