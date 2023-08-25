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
    int time = 1;
    bool hourOn = false;

    for(int i = 0; i < n; i++) {
        string action = "NO";
        pair<string, int> cur = v[i];

        if(cur.second == time && cur.first != "HOURGLASS") {
            action = "YES";
        }

        if(cur.first == "HOURGLASS" && cur.second != time) {
            hourOn = !hourOn;
        }

        cout << time << " " << action << '\n';

        if(!hourOn) {
            time++;

            if(time == 13) {
                time = 1;
            }
        } else {
            time--;

            if(time == 0) {
                time = 12;
            }
        }
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
