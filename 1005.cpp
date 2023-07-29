#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int weights[n];
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> weights[i];
        sum += weights[i];
    }
    int j = 0;
    int diff = sum;
    int temp_sum = 0;
    int pow = 2;
    for(int j = 0; j < n-1; j++){
        pow *= 2;
    }
    for(int i = 0; i < pow; i++){
        int copy_i = i;
        while(copy_i > 0){
            if(copy_i%2 == 1){
                temp_sum += weights[j];
            }
            copy_i /= 2;
            j++;
        }
        if(diff > abs(sum - 2*temp_sum)){
            diff = abs(sum - 2*temp_sum);
        }
        temp_sum = 0;
        j = 0;
    }
    
    cout << diff; //36 12 1
    
    return 0;
}