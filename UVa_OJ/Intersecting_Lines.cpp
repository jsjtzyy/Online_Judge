#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int cross(pair<int, int>p1, pair<int, int> p2, pair<int, int>p3){
   pair<int, int> vec1 = make_pair(p2.first - p1.first, p2.second - p1.second);
   pair<int, int> vec2 = make_pair(p3.first - p1.first, p3.second - p1.second);
   return vec1.first * vec2.second - vec1.second * vec2.first; 
}

int checkParallel(pair<int, int>p1, pair<int, int> p2){
    return p1.first * p2.second - p1.second * p2.first;
}

int main(){
    int num;
    cin >> num;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    pair<int, int> p1, p2, p3,p4;
    int A1, B1, C1, A2, B2, C2;
    for(int i = 0; i < num; ++i){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        p1 = make_pair(x1, y1);
        p2 = make_pair(x2, y2);
        p3 = make_pair(x3, y3);
        p4 = make_pair(x4, y4);
        if(cross(p1, p2, p3) == 0 && cross(p1, p2, p4) == 0){
            cout << "LINE" << endl;
        }else if(checkParallel(make_pair(p2.first - p1.first, p2.second - p1.second), make_pair(p4.first - p3.first, p4.second - p3.second)) == 0){
            cout << "NONE" << endl;
        }else{
            A1 = y2 - y1; B1 = x1 - x2; C1 = x1*A1+y1*B1;
            A2 = y4 - y3; B2 = x3 - x4; C2 = x3*A2 + y3*B2;
            double x = (double)(C1 * B2 - C2 * B1) /(A1 * B2 - A2 * B1);
            double y = (double)(C1 * A2 - C2 * A1) / (B1 * A2 - B2 * A1);
            cout << "POINT " << setiosflags(ios::fixed) << setprecision(2) << x << " " << setprecision(2) << y << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    
    return 0;
}
