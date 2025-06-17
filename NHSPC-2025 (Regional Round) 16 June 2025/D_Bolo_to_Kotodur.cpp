#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c_min;
    cin >> a >> b >> c_min;
    
    double time_seconds = c_min * 60.0;
    double distance = (time_seconds * sqrt(a * a - a * b + b * b)) / 2.0;
    
    cout << fixed << setprecision(10) << distance << endl;
    
    return 0;
}