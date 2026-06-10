#include <iostream>
#include <vector>
#include <climits>
#include "max_heapify.h"

using namespace std;

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void build_max_heap(heap &A){
    A.heap_size = A.length;
    for(int i = A.length/2 -1; i>=0; i--){
        while_max_heapify(A,i);
    }
}

void heapsort(heap &A){
    build_max_heap(A);
    for(int i= A.length-1; i>=0; i--){
        swap(A.A[i],A.A[0]);
        A.heap_size = A.heap_size -1;
        max_heapify(A,0);

    }
}
#endif