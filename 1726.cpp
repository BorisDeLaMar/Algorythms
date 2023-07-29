#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

typedef struct{
    unsigned long long x;
    unsigned long long y;
} cords;

int comp_x(const void* a1, const void* a2){
    cords first = *(cords*) a1;
    cords sec = *(cords*) a2; 
    if(first.x < sec.x){
        return 1;
    }
    else if(first.x > sec.x){
        return -1;
    }
    return 0;
}

int comp_y(const void* a1, const void* a2){
    cords first = *(cords*) a1;
    cords sec = *(cords*) a2; 
    if(first.y < sec.y){
        return 1;
    }
    else if(first.y > sec.y){
        return -1;
    }
    return 0;
}

int main(){
    unsigned long long n;
    cin >> n;
    cords a[n]; unsigned long long cur_avg = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }

    qsort(a, n, sizeof(cords), comp_x);
    for(unsigned long long i = 0; i < n; i++){
        cur_avg += (n - 2*i - 1)*a[i].x;
    }

    qsort(a, n, sizeof(cords), comp_y);
    for(unsigned long long i = 0; i < n; i++){
        cur_avg += (n - 2*i - 1)*a[i].y;
    }

    cout << cur_avg*2/(n*(n-1));
    return 0;
}