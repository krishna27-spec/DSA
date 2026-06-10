#include <iostream>
#include <vector>
#include <climits>

using namespace std;
 int main(){
    int n; cin>> n;
    vector<int> m;
    int sum = 0;
    int left = 0;
    int right = 0;
    int right_sum = 0;
    for(int i= 0; i<n; i++){
        int number; cin>> number;
        m.push_back(number);
    }
    sum = m[0];
    int max_sum = sum;
    for(int i= 1; i<n; i++){
        right_sum += m[i];
        if(max_sum<0 && m[i]>=0){
            left = i;
            right = left;
            right_sum =0;
        }
        else if(right_sum>0){
            max_sum += right_sum;
            right =i;
            right_sum = 0;
        }
    }
    cout << left << " " << right << " " << max_sum << endl;

}