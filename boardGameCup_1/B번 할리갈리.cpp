/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<pair<string, int>> v;

void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string tempS;
        int tempI;

        cin >> tempS >> tempI;
        v.push_back({tempS, tempI});
    }
}

void solve() {
    string result = "NO";
    int sSum = 0;
    int bSum = 0;
    int lSum = 0;
    int pSum = 0;

    for(int i = 0; i < n; i++) {
        pair<string, int> cur = v[i];

        if(cur.first == "STRAWBERRY") {
            sSum += v[i].second;
        } else if(cur.first == "BANANA") {
            bSum += v[i].second;
        } else if(cur.first == "LIME") {
            lSum += v[i].second;
        } else {
            pSum += v[i].second;
        }
    }

    if(sSum == 5 || bSum == 5 || lSum == 5 || pSum == 5) {
        result = "YES";
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}
*/
