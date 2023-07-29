#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a; stack <int> st; int max = 0; bool flag = false;

    for(int i = 0; i < n; i++){
        cin >> a;
        
        if(a > max){
            for(int j = max+1; j < a; j++){
                st.push(j);
            }
            max = a;
        }
        else{
            if(a == st.top()){
                st.pop();
            }
            else{
                flag = true;
            }
        }
    }
    if(flag){
        cout << "Cheater"; 
    }
    else{
        cout << "Not a proof";
    }

    return 0;
}