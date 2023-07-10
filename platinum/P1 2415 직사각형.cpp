#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

class Coord {
public:
    long long x;
    long long y;
};

class Segment {
public:
    Coord a;
    Coord b;
    double getSize() const {
        return pow(pow((b.y - a.y), 2) + pow((b.x - a.x), 2), 0.5);
    }
};

int n;
long long result;
vector<Coord> coord;
vector<Segment> segment;

bool comp (const Segment& a, const Segment& b) {
    if (a.a.x == b.a.x) {
        if (a.a.y == b.a.y) {
            if (a.b.x == b.b.x) {
                return a.b.y < b.b.y;
            } else {
                return a.b.x < b.b.x;
            }
        } else {
            return a.a.y < b.a.y;
        }
    } else {
        return a.a.x < b.a.x;
    }
}

bool operator == (const Coord& a, const Coord& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator == (const Segment& a, const Segment& b) {
    return a.a == b.a && a.b == b.b;
}

long long findArea(const Segment& a, const Segment& b) {
    return a.getSize() * b.getSize();
}

long long innerProduct(const Segment& a, const Segment& b) {
    Coord aVector = {a.a.x - a.b.x, a.a.y - a.b.y};
    Coord bVector = {b.a.x - b.b.x, b.a.y - b.b.y};
    return aVector.x * bVector.x + aVector.y * bVector.y;
}

bool isRectangle(const Segment& a, const Segment& b) {
    if (a == b) {
        return false;
    }

    return ((a.a == b.a) || (a.a == b.b) || (a.b == b.a) || (a.b == b.b)) && (innerProduct(a, b) == 0);
}

Coord findIntersection(const Segment& a, const Segment& b) {
    if (a.a == b.a || a.a == b.b) {
        return a.a;
    } else {
        return a.b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        coord.push_back({a, b});
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coord[i].x == coord[j].x ? coord[i].y < coord[j].y : coord[i].x < coord[j].x) {
                segment.push_back({coord[i], coord[j]});
            } else {
                segment.push_back({coord[j], coord[i]});
            }
        }
    }

    sort(segment.begin(), segment.end(), comp);

    for (int i = 0; i < segment.size(); i++) {
        for (int j = i + 1; j < segment.size() && segment[i].a == segment[j].a; j++) {
            if (isRectangle(segment[i], segment[j])) {
                Segment a = segment[i];
                Segment b = segment[j];
                Segment c = {};
                Segment d = {};
                int point1Idx = lower_bound(segment.begin(), segment.end(), Segment{a.b}, comp) - segment.begin();
                int point2Idx = lower_bound(segment.begin(), segment.end(), Segment{b.b}, comp) - segment.begin();

                for (int k = point1Idx; k < segment.size() && segment[k].a == a.b; k++) {
                    if (isRectangle(a, segment[k]) && b.getSize() == segment[k].getSize()) {
                        c = segment[k];
                        break;
                    }
                }

                for (int k = point2Idx; k < segment.size() && segment[k].a == b.b; k++) {
                    if (isRectangle(b, segment[k]) && a.getSize() == segment[k].getSize()) {
                        d = segment[k];
                        break;
                    }
                }

                if (isRectangle(a, b) && isRectangle(a, c) && isRectangle(b, d) && isRectangle(c, d)) {
                    result = max(result, findArea(a, b));
                }
            }
        }
    }

    cout << result;
    return 0;
}
