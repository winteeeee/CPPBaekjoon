#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> word(n);
    for(int i = 0; i < n; i++)
        cin >> word[i];
    pair<int, int> sizes[n]; //size, idx
    for(int i = 0; i < n; i++)
        sizes[i] = {word[i].size(), i};

    sort(sizes, sizes + n, greater<pair<int, int>>());



    return 0;
}
