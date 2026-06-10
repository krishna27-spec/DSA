#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void counting_sort(vector<int>&A, vector<int>&B, int k){
    vector <int> C(k+1,0);
    for(int i=0; i<A.size(); i++){
        C[A[i]] +=1;
    }
    for(int i=1; i<k+1; i++){
        C[i] += C[i-1];
    }
    for(int i =0; i<A.size();i++){
        B[C[A[i]]] = A[i];
        C[A[i]] -= 1;
    }


}
int main(){
    int n; cin >> n;
    vector<int> num;
    for(int i =0; i<n; i++){
        int num1; cin>>num1;
        num.push_back(num1);
    }
    vector<int> B(n,0);
    int mx = *max_element(num.begin(), num.end());
    counting_sort(num,B, mx);
    for(int i =0; i<n;i++){
        cout << B[i] << " ";
    }
    cout << endl;
    
}