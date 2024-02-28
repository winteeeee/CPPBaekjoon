/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> edge[1001];
int inEdge[1001];
int n, m;

void input();
void solve();
int main() {
    ios_base::sync_with_stdio(false);
    input();
    solve();

    return 0;
}

void input() {
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;

        int temp[num];
        for(int j = 0; j < num; j++)
            cin >> temp[j];

        for(int j = 0; j < num - 1; j++) {
            edge[temp[j]].push_back(temp[j + 1]);
            inEdge[temp[j + 1]]++;
        }
    }
}

void solve() {
    stack<int> s;
    int count = 0;
    int result[n];

    for(int i = 1; i <= n; i++) {
        if(inEdge[i] == 0)
            s.push(i);
    }

    while(!s.empty()) {
        int cur = s.top(); s.pop();
        result[count] = cur;
        count++;

        for(int i = 0; i < edge[cur].size(); i++) {
            inEdge[edge[cur][i]]--;

            if(inEdge[edge[cur][i]] == 0)
                s.push(edge[cur][i]);
        }
    }

    if(count != n)
        cout << "0";

    else {
        for(int i = 0; i < n; i++)
            cout << result[i] << "\n";
    }
}*/
