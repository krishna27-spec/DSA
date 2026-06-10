#include <iostream>
#include <vector>
#include <climits>

#ifndef MAX_HEAPIFY_H
#define MAX_HEAPIFY_H

#define PARENT(i) (((i)-1)/2)
#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)
using namespace std;

struct heap{
    int* A;
    int heap_size;
    int length;
};

void max_heapify(heap &A, int i){
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;
    if (l< A.heap_size && A.A[l]> A.A[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if (r< A.heap_size && A.A[r]>A.A[largest]){
        largest = r;
    }
    if (largest != i){
        int number = A.A[i];
        A.A[i] = A.A[largest];
        A.A[largest] = number;
        max_heapify(A,largest);
    }
}

void while_max_heapify(heap &A, int i){
    while(i<A.heap_size/2){
        int l = LEFT(i);
        int r = RIGHT(i);
        int largest;
        if (l< A.heap_size && A.A[l]> A.A[i]){
            largest = l;
        }
        else{
            largest = i;
        }
        if (r< A.heap_size && A.A[r]>A.A[largest]){
            largest = r;
        }
        if (largest != i){
            int number = A.A[i];
            A.A[i] = A.A[largest];
            A.A[largest] = number;
            i = largest;
        }
        else{
            break;
        }
    }
}

#endif

