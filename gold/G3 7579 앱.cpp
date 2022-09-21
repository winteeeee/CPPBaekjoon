#include <iostream>
using namespace std;

int n, m;
int memory[101];
int cost[101];

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

    for(int i = 0; i < n; i++)
        cin >> memory[i];
    for(int i = 0; i < n; i++)
        cin >> cost[i];
}

void solve() {
    cout.tie(NULL);

}