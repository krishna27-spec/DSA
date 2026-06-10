#include <iostream>
#include <vector>
#include <climits>

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define PARENT(i) (((i)-1)/2)
#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)
using namespace std;

struct heap{
    int* A;
    int heap_size;
    int length;
};

void min_heap(heap &A, int i){
    int l = LEFT(i);
    int r = RIGHT(i);
    int smallest;
    if (l< A.heap_size && A.A[l]< A.A[i]){
        smallest = l;
    }
    else{
        smallest = i;
    }
    if (r< A.heap_size && A.A[r]<A.A[smallest]){
        smallest = r;
    }
    if (smallest != i){
        int number = A.A[i];
        A.A[i] = A.A[smallest];
        A.A[smallest] = number;
        min_heap(A,smallest);
    }
}

#endif

