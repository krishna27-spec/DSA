#include <iostream>
#include <vector>
 using namespace std;

void merge(vector<int>& A, int left, int right, int* total)
{
    int middle = (left + right)/2;

    vector<int> left1;
    vector<int> right1;

    for(int i=left;i<=middle;i++)
        left1.push_back(A[i]);

    for(int i=middle+1;i<=right;i++)
        right1.push_back(A[i]);

    int l = 0;
    int r = 0;
    int k = left;

    while(l < left1.size() && r < right1.size())
    {
        if(left1[l] <= right1[r])
        {
            A[k++] = left1[l++];
        }
        else
        {
            (*total) += left1.size() - l;
            A[k++] = right1[r++];
        }
    }

    while(l < left1.size())
        A[k++] = left1[l++];

    while(r < right1.size())
        A[k++] = right1[r++];
}


void mergesort(vector<int>& A, int left, int right, int* total){
    if(left >= right)
        return;

    int middle = (left + right)/2;

    mergesort(A, left, middle, total);
    mergesort(A, middle + 1, right, total);

    merge(A, left, right, total);
}

 int main(){
    int n; cin>> n;
    vector<int> m;
    int count = 0;
    for(int i= 0; i<n; i++){
        int number; cin>> number;
        m.push_back(number);
    }
    mergesort(m,0,n-1,&count);
    for(int i =0; i<n; i++){
        cout << m[i] << " "; 
    }
    cout << endl;
    cout << count << endl;
 }