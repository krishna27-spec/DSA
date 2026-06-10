#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct arguments {
    int a; // left index
    int b; // right index
    int c; // max sum
};

arguments max_cross_subarray(vector<int>& A, int left, int right) {
    int middle = (left + right) / 2;

    int left_sum = INT_MIN;
    int right_sum = INT_MIN;

    int sum = 0;
    int max_left = middle;
    int max_right = middle + 1;

    // Find best left half ending at middle
    for (int i = middle; i >= left; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    // Find best right half starting at middle+1
    sum = 0;
    for (int i = middle + 1; i <= right; i++) {
        sum += A[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    return {max_left, max_right, left_sum + right_sum};
}

arguments max_subarray(vector<int>& A, int left, int right) {
    if (left == right) {
        return {left, right, A[left]};
    }

    int middle = (left + right) / 2;

    arguments left_result =
        max_subarray(A, left, middle);

    arguments right_result =
        max_subarray(A, middle + 1, right);

    arguments cross_result =
        max_cross_subarray(A, left, right);

    if (left_result.c >= right_result.c &&
        left_result.c >= cross_result.c) {
        return left_result;
    }
    else if (right_result.c >= left_result.c &&
             right_result.c >= cross_result.c) {
        return right_result;
    }
    else {
        return cross_result;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> m(n);

    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    arguments ans = max_subarray(m, 0, n - 1);

    cout << "Left Index : " << ans.a << '\n';
    cout << "Right Index: " << ans.b << '\n';
    cout << "Max Sum    : " << ans.c << '\n';

    return 0;
}