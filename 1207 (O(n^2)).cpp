#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long double points[n][2]; long long num_points;

    for(long long i = 0; i < n; i++){
        cin >> points[i][0] >> points[i][1];
    }
    for(long long j = 1; j < n; j++){
        num_points = 0;
        if(points[0][0] - points[j][0] == 0){
            for(long long c = 1; c < n; c++){
                if(points[c][0] < points[0][0]){
                    num_points += 1;
                }
            }
        }
        else{
            long double k = (points[0][1] - points[j][1])/(points[0][0] - points[j][0]);
            long double b = points[j][1] - k*points[j][0];
            for(long long c = 1; c < n; c++){
                if((points[c][1] > k*(points[c][0]) + b) && (c != j)){
                    num_points += 1;
                }
            } 
        }
        if(num_points == (n - 2)/2){
                cout << 1 << " " << j+1 << "\n";
                return 0;
        }
    }
    return 0;
}