/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> sortedV;
bool isThere[1000001];
vector<int> score(1000001);

void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
        sortedV.push_back(temp);
        isThere[temp] = 1;
    }
}

void solve() {
    sort(sortedV.begin(), sortedV.end());

    for(int i = 0; i < n; i++) {
        for(int j = 2; sortedV[i] * j <= 1000000; j++) {
            if(isThere[sortedV[i] * j]) {
                score[sortedV[i]]++;
                score[sortedV[i] * j]--;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << score[v[i]] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}
*/
