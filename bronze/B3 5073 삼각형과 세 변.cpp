#include <iostream>
#include <vector>
using namespace std;

vector<int> triangle;

bool isInvalid() {
    int max = -1;
    int maxIdx = 0;
    int sum = 0;

    for (int i = 0; i < 3; i++) {
        if (max < triangle[i]) {
            max = triangle[i];
            maxIdx = i;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (i != maxIdx) {
            sum += triangle[i];
        }
    }

    return max >= sum;
}

bool isEquilateral() {
    for (int i = 1; i < 3; i++) {
        if (triangle[0] != triangle[i]) {
            return false;
        }
    }

    return true;
}

bool isIsosceles() {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (triangle[i] == triangle[j]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        triangle.push_back(a);
        triangle.push_back(b);
        triangle.push_back(c);

        if (isInvalid()) {
          cout << "Invalid";
        } else if (isEquilateral()) {
            cout << "Equilateral";
        } else if (isIsosceles()) {
            cout << "Isosceles";
        } else {
            cout << "Scalene";
        }
        cout << '\n';
        triangle.clear();
    }

    return 0;
}
