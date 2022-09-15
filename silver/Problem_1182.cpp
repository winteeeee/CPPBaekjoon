#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> sequence;
vector<ll> sequenceA;
vector<ll> sequenceB;
void DFS(int cur, int r, int innerStart, int innerEnd, int sum, vector<ll> &target);
int main() {
    int N, S;
    scanf("%d %d", &N, &S);

    for(int i = 0; i < N; i++) {
        int value;
        scanf("%d", &value);
        sequence.push_back(value);
    }


    sequenceA.push_back(0);
    sequenceB.push_back(0);
    DFS(0, N / 2, 0, N / 2, 0, sequenceA);
    DFS(0, N / 2 + 1, N / 2, sequence.size(), 0, sequenceB);

    sort(sequenceA.begin(), sequenceA.end());
    sort(sequenceB.begin(), sequenceB.end());

    long long count = 0;
    for (int i = 0; i < sequenceB.size(); i++) {
        count += upper_bound(sequenceA.begin(), sequenceA.end(), S - sequenceB[i]) - lower_bound(sequenceA.begin(), sequenceA.end(), S - sequenceB[i]);
    }

    if(S == 0) count--;
    printf("%lld", count);

    return 0;
}

void DFS(int cur, int r, int innerStart, int innerEnd, int sum, vector<ll> &target) {
    if(cur == r) {
        return;
    }

    for(int i = innerStart; i < innerEnd; i++) {
        sum += sequence[i];
        target.push_back(sum);
        DFS(cur + 1, r, i + 1, innerEnd, sum, target);
        sum -= sequence[i];
    }
}