#include <iostream>
#include <vector>
using namespace std;

int N;
long long count;
vector<int> A, arr;
vector<int> cable(1000001);

void input() {
    cin >> N;

    int temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    for(int i = 0; i < N; i++) {
        cin >> temp;
        cable[temp] = i;
    }
}

void makeArr() {
    for(int i = 0; i < N; i++) {
        arr.push_back(cable[A[i]]);
    }
}

void merge(int start, int mid, int end) {
    vector<int> temp;
    int leftIndex = start;
    int rightIndex = mid + 1;

    while(leftIndex < mid + 1 && rightIndex < end) {
        if (arr[leftIndex] < arr[rightIndex]) {
            temp.push_back(arr[leftIndex++]);
        } else {
            temp.push_back(arr[rightIndex++]);
            count += (mid - leftIndex + 1);
        }
    }
}

void mergeSort(int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
}


void solve() {
    makeArr();
    mergeSort(0, N - 1);
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    return 0;
}