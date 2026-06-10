#include <iostream>
#include <vector>
 using namespace std;

 int main(){
    int n; cin>> n;
    vector<int> m;
    for(int i= 0; i<n; i++){
        int number; cin>> number;
        m.push_back(number);
    }
    for(int i=1; i<n; i++){
        int to_add = m[i];
        int index = i-1;
        while(index >= 0 && to_add < m[index]) {
            m[index + 1] = m[index];
            index--;
        }
        m[index+1] = to_add;
    }
    for(int i =0; i<n; i++){
        cout << m[i] << " "; 
    }
    cout << endl;
    return 0; 
 }