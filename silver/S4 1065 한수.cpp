#include <iostream>
using namespace std;

int count;
void isHansoo(string num) {
    if (num.size() == 1 || num.size() == 2) {
        count++;
    } else {
        int diff = (num[1] - '0') - (num[0] - '0');
        for (int i = 2; i < num.size(); i++) {
            if ((num[i] - '0') - (num[i - 1] - '0') != diff) {
                return;
            }
        }
        count++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        isHansoo(to_string(i));
    }

    cout << count;
    return 0;
}
