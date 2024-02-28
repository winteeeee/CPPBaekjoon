/*
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class construction {
public:
    string info;
    int i;
    int j;
};

int n, m;
list<int> line2;
vector<list<int>::iterator> serialNumber(1000001);
vector<construction> constructions;

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        line2.push_back(temp);
        serialNumber[temp] = --line2.end();
    }

    for (int i = 0; i < m; i++) {
        string info;
        int a;

        cin >> info;
        if (info == "BN" || info == "BP") {
            int b;
            cin >> a >> b;
            constructions.push_back({info, a, b});
        } else {
            cin >> a;
            constructions.push_back({info, a});
        }
    }
}

void solve() {
    for (int i = 0; i < m; i++) {
        construction cur = constructions[i];
        list<int>::iterator iter = serialNumber[cur.i];

        if (cur.info == "BN") {
            iter++;
            if (iter == line2.end()) {
                iter = line2.begin();
            }
            cout << *iter;
            line2.insert(iter, cur.j);
        } else if (cur.info == "BP") {
            line2.insert(iter, cur.j);
            iter--;
            iter--;
            if (iter == line2.end()) {
                iter--;
            }
            cout << *iter;
        } else if (cur.info == "CN") {
            iter++;
            if (iter == line2.end()) {
                iter = line2.begin();
            }
            cout << *iter;
            line2.erase(iter);
        } else {
            iter--;
            if (iter == line2.end()) {
                iter--;
            }
            cout << *iter;
            line2.erase(iter);
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}*/
