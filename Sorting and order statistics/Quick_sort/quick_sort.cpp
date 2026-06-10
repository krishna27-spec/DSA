#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&A, int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j =0; j<r-1; j++){
        if(A[j]<x){
             i++;
             swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;

}

void quicksort(vector<int>&A, int p, int r){
    if(p<r){
        int q = partition(A,p,r);
        quicksort(A, p, q-1);
        quicksort(A, q+1,p);
    }
}

int main(){
    int n; cin >> n;
    vector<int> num1;
    for(int i =0; i<n; i++){
        int num; cin>>num;
        num1.push_back(num);
    }
    quicksort(num1,0,num1.size()-1);
    for(int i =0; i<n;i++){
        cout << num1[i] << " ";
    }
    cout << endl;

}

