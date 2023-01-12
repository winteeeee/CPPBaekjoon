/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> minsuHand;
vector<bool> isUsed;
vector<int> willBeUsedCards;

void input() {
    cin >> n >> m >> k;

    int temp;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        minsuHand.push_back(temp);
        isUsed.push_back(0);
    }

    for(int i = 0; i < k; i++) {
        cin >> temp;
        willBeUsedCards.push_back(temp);
    }
}

int minsuPick(int cheolsooPick) {
    int upperBoundIndex, picked;

    upperBoundIndex = upper_bound(minsuHand.begin(), minsuHand.end(), cheolsooPick) - minsuHand.begin();
    int leastCardIndex;

    if(upperBoundIndex == minsuHand.size()) { //탐색 실패
        leastCardIndex = 0;
    } else {
        leastCardIndex = upperBoundIndex;
    }

    for(; isUsed[leastCardIndex]; leastCardIndex++);
    picked = minsuHand[leastCardIndex];
    isUsed[leastCardIndex] = 1;

    return picked;
}

void solve() {
    sort(minsuHand.begin(), minsuHand.end());

    for(int i = 0; i < k; i++) {
        cout << minsuPick(willBeUsedCards[i]) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/
