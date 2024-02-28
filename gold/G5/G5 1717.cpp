/*
#include <iostream>
using namespace std;

int n, m;
int arr[1000001];

int find(int a) {
    if (a == arr[a]) {
        return arr[a];
    } else {
        return arr[a] = find(arr[a]);
    }
}

void mergeSet(int a, int b) {
    int aP = find(a);
    int bP = find(b);
    arr[bP] = aP;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a) {
            int bParent = find(b);
            int cParent = find(c);
            if (bParent == cParent) {
                cout << "yes";
            } else {
                cout << "no";
            }
            cout << '\n';
        } else {
            mergeSet(b, c);
        }
    }

    return 0;
}
*/
