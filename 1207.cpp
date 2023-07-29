#include <iostream>
#include <cmath>
using namespace std;

typedef struct{
    long double x;
    long double y;
    long double angle;
} point;

int main(){
    long long n;
    cin >> n;
    point points[n]; long long min = 1000001; long long min_ptr = 0; long double avg_angle = 0;
    long double diff = 2000001; long long ptr = 0;

    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
        if(points[i].x < min){
            min = points[i].x;
            min_ptr = i;
        }
    }
    for(int i = 0; i < n; i++){
        points[i].angle = atan2(points[i].y - points[min_ptr].y, points[i].x - points[min_ptr].x);
        avg_angle += points[i].angle;
    }
    for(int i = 0; i < n; i++){
        if(abs(points[i].angle - avg_angle)){
            diff = abs(abs(points[i].angle) - abs(avg_angle));
            ptr = i;
        }
    }
    cout << ptr + 1 << " " << min_ptr+1;
    return 0;
}