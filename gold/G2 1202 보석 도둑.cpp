/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    ll sumOfPrice = 0;
    scanf("%d %d", &N, &K);

    vector<pair<int, int>> jewel;
    for(int i = 0; i < N; i++) {
        int w, v;
        scanf("%d %d", &w, &v);
        jewel.push_back({w, v});
    }

    vector<int> bag;
    for(int i = 0; i < K; i++) {
        int weight;
        scanf("%d", &weight);
        bag.push_back(weight);
    }

    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> h;
    int idx = 0;
    for(int i = 0; i < bag.size(); i++) {
        for(int j = idx; j < jewel.size(); j++) {
            if(bag[i] >= jewel[j].first) {
                h.push(jewel[j].second);
                idx++;
            }

            else
                break;
        }

        if(!h.empty()) {
            sumOfPrice += h.top();
            h.pop();
        }
    }

    printf("%lld", sumOfPrice);
    return 0;
}*/
