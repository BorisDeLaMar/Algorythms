#include <iostream>
using namespace std;

int main(){
    int arr[8];
    for(int i = 0; i < 8; i++){
        cin >> arr[i];
    }
    int points[8][8] = { //Расстояние в отрезках до точки соответствующего индекса. i - первая тчк, j - вторая
        {0, 1, 2, 1, 1, 2, 3, 2},
        {1, 0, 1, 2, 2, 1, 2, 3},
        {2, 1, 0, 1, 3, 2, 1, 2},
        {1, 2, 1, 0, 2, 3, 2, 1},
        {1, 2, 3, 2, 0, 1, 2, 1},
        {2, 1, 2, 3, 1, 0, 1, 2},
        {3, 2, 1, 2, 2, 1, 0, 1},
        {2, 3, 2, 1, 1, 2, 1, 0}
    };  
    string answer = ""; 
    char letters[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}; 
    for(int i = 0; i < 8; i++){
        if(arr[i] > 0){
            for(int j = 0; j < 8; j++){
                if(points[i][j] == 1){
                    while((arr[i] > 0) && (arr[j] > 0)){
                        arr[i] -= 1;
                        arr[j] -= 1;
                        answer = answer + letters[i] + letters[j] + '-' + "\n";
                    }
                }
                if(points[i][j] == 3){
                    int appropriate_point_one; int appropriate_point_two;
                    for(int k = 0; k < 8; k++){
                        if((points[i][k] == 1) && (points[j][k] == 2)){
                            appropriate_point_one = k;
                            break;
                        }
                    }
                    for(int k = 0; k < 8; k++){
                        if((points[appropriate_point_one][k] == 1) && (i != k)){
                            appropriate_point_two = k;
                            break;
                        }
                    }
                    while((arr[i] > 0) && (arr[j] > 0)){
                        arr[appropriate_point_one] += 1;
                        arr[appropriate_point_two] += 1;
                        answer = answer + letters[appropriate_point_one] + letters[appropriate_point_two] + '+' + "\n";
                        arr[appropriate_point_one] -= 1;
                        arr[i] -= 1;
                        answer = answer + letters[i] + letters[appropriate_point_one] + '-' + "\n";
                        arr[j] -= 1;
                        arr[appropriate_point_two] -= 1;
                        answer = answer + letters[appropriate_point_two] + letters[j] + '-' + "\n";
                    }
                }
            }
        }
    }
    for(int i = 0; i < 8; i++){
        if(arr[i] > 0){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << answer;
    return 0;
}