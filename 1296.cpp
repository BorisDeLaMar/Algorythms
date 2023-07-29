#include <iostream>
using namespace std;

int main(){
    int n; int sum = 0; int max_sum = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
        if(sum < 0){
            sum = 0;
        }
        if(max_sum < sum){
            max_sum = sum;
        }
    }
    cout << max_sum;
    return 0;
}