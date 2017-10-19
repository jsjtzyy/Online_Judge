#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

const double PI = M_PI;
const double Radius = 6371009.0;

using namespace std;

int main(){
    int testNum;
    unsigned int res;
    double theta, phi, straight, circle;
    double x1, y1, z1, x2, y2, z2;
    cin >> testNum;
    for(int i = 0; i < testNum; ++i){
        cin >> theta >> phi;
        x1 = Radius * cos(theta*PI/180.0) * cos(phi*PI/180.0);
        y1 = Radius * cos(theta*PI/180.0) * sin(phi*PI/180.0);
        z1 = Radius * sin(theta*PI/180.0);
        cin >> theta >> phi;
        x2 = Radius * cos(theta*PI/180.0) * cos(phi*PI/180.0);
        y2 = Radius * cos(theta*PI/180.0) * sin(phi*PI/180.0);
        z2 = Radius * sin(theta*PI/180.0);
        double cosTheta = (x1*x2 + y1*y2 + z1*z2) / Radius /Radius;
        straight = 2.0 *Radius *(1.0 - cosTheta)*Radius;
        straight = sqrt(straight);
        theta = asin(straight / 2.0 / Radius) * 2; 
        circle = theta * Radius;
        res = round(circle - straight);
        cout << res << endl;
    }
    return 0;
}
