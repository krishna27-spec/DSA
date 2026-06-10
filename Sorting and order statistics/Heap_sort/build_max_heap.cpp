#include <iostream>
#include <vector>
#include <climits>
#include "max_heapify.h"
#include "heap_sort.h"

using namespace std;

int main(){
    int n; cin >>n;
    heap A;
    A.length = n;
    A.A = new int[n];
    for(int i =0; i<n; i++){
        int num; cin>>num;
        A.A[i] = num;
    }
    heapsort(A);
    for(int i =0; i<n;i++){
        cout << A.A[i] << " ";
    }
    cout << endl;
}