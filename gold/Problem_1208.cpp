#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sequence;
vector<int> sequenceA;
vector<int> sequenceB;
void DFS(int cur, int r, int innerStart, int innerEnd, int sum, vector<int> &target);
int binarySearch(vector<int> source, int target);
int main() {
    int N, S;
    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        sequence.push_back(value);
    }

    if(N != 1) {
        for (int i = 1; i <= N / 2; i++)
            DFS(0, i, 0, N / 2, 0, sequenceA);
        for (int i = N / 2; i <= sequence.size(); i++)
            DFS(0, i - N / 2 + 1, N / 2, sequence.size(), 0, sequenceB);

        sort(sequenceA.begin(), sequenceA.end());
        sort(sequenceB.begin(), sequenceB.end());

        long long count = 0;
        for (int i = 0; i < sequenceB.size(); i++) {
            bool find = binarySearch(sequenceA, S - sequenceB[i]) != -1;
            if (find) {
                count++;
            }
        }

        printf("%lld", count);
    }

    else
        printf("1");
    return 0;
}

void DFS(int cur, int r, int innerStart, int innerEnd, int sum, vector<int> &target) {
    if(cur == r) {
        target.push_back(sum);
        return;
    }

    for(int i = innerStart; i < innerEnd; i++) {
        sum += sequence[i];
        DFS(cur + 1, r, i + 1, innerEnd, sum, target);
        sum -= sequence[i];
    }
}

int binarySearch(vector<int> source, int target) {
    int low = 0;
    int high = source.size() - 1;
    int mid;

    while(low < high) {
        mid = high + low / 2;

        if(source[mid] == target)
            return mid;

        else if(source[mid] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return -1;
}