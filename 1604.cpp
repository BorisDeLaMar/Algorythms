#include <iostream>
using namespace std;

typedef struct{
    int value;
    int ptr;
} max_num;

int main()
{
    int n;
    cin >> n;
    int a[n];
    max_num max1 = {}; max_num max2 = {}; max_num pred = {}; bool was = false; int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(max1.value < a[i]){
            pred = max1;
            max1 = {a[i], i};
            was = true;
        }
        if((max2.value < a[i]) && (!was)){
            max2 = {a[i], i};
        }
        else if(was){
            max2 = pred;
        }
        was = false;
        sum += a[i];
    }

    for(int i = 0; i < n*sum; i++){
        if(max2.value > 0){
            a[max1.ptr] -= 1;
            a[max2.ptr] -= 1;
            //cout << "\nmax2.value " << max2.value << "\n"; 
            cout << max1.ptr+1 << " " << max2.ptr+1 << " ";
        }
        else if(max1.value > 0){
            a[max1.ptr] -= 1;
            cout << max1.ptr+1 << " ";
        }
        else{
            break;
        }

        max1 = {}; max2 = {};

        for(int j = 0; j < n; j++){
            if(max1.value < a[j]){
                pred = max1;
                max1 = {a[j], j};
                was = true;
            }
            if((max2.value < a[j]) && (!was)){
                max2 = {a[j], j};
            }
            else if(was){
                max2 = pred;
            }
            was = false;
        }
        
        /*cout << "\nmass: ";
        for(int j = 0; j < n; j++){
            cout << a[j] << " ";
        }*/
    }

    //cout << max1.value << " " << max1.ptr << " " << max2.value << " " << max2.ptr;
    return 0;
}