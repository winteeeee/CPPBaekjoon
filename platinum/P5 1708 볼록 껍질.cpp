#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Coord {
public:
    long long x;
    long long y;
};

int n;
vector<Coord> coords;
Coord original;
vector<Coord> result;

bool comp(const Coord& a, const Coord& b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
}

bool comp2(const Coord& a, const Coord& b) {
    double aSlope;
    double bSlope;

    if (original.x != a.x) {
        aSlope = (double)(a.y - original.y) / (double)(a.x - original.x);
    } else {
        aSlope = INT_MAX;
    }

    if (original.x != b.x) {
        bSlope = (double)(b.y - original.y) / (double)(b.x - original.x);
    } else {
        bSlope = INT_MAX;
    }

    if (aSlope >= 0 && bSlope >= 0) {
        if (aSlope == 0 && bSlope == 0) {
            return comp(a, b);
        } else {
            return aSlope < bSlope;
        }
    } else {
        if (aSlope < 0 && bSlope < 0) {
            return aSlope < bSlope;
        } else {
            return aSlope > bSlope;
        }
    }
}

long long ccw(const Coord& a, const Coord& b, const Coord& c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords.push_back({x, y});
    }

    sort(coords.begin(), coords.end(), comp);
    original = coords[0];
    sort(coords.begin() + 1, coords.end(), comp2);
    result.push_back(coords[0]); result.push_back(coords[1]);

    for (int i = 2; i < coords.size(); i++) {
        Coord first = result[result.size() - 2];
        Coord second = result[result.size() - 1];
        Coord target = coords[i];

        if (ccw(first, second, target) >= 0) {
            result.push_back(target);
        } else {
            i--;
            result.resize(result.size() - 1);
        }
    }

    int count = 2;
    for (int i = 0; i < result.size() - 2; i++) {
        Coord first = result[i];
        Coord second = result[i + 1];
        Coord target = result[i + 2];

        if (ccw(first, second, target) != 0) {
            count++;
        }
    }

    cout << count;
    return 0;
}