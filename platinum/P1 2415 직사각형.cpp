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
    double slope;
    double getSize() const {
        return pow(pow((b.y - a.y), 2) + pow((b.x - a.x), 2), 0.5);
    }
};

int n;
long long result1, result2;
vector<Coord> coord;
vector<Segment> slopeZero;
vector<Segment> slopeInf;
vector<Segment> slopePlus;
vector<Segment> slopeMinus;

bool comp (const Segment& a, const Segment& b) {
    return a.slope == b.slope ? a.getSize() < b.getSize() : a.slope < b.slope;
}

bool operator == (const Coord& a, const Coord& b) {
    return a.x == b.x && a.y == b.y;
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
    return ((a.a == b.a) || (a.a == b.b) || (a.b == b.a) || (a.b == b.b)) && (innerProduct(a, b) == 0);
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
            if (coord[i].x == coord[j].x) {
                slopeInf.push_back({coord[i], coord[j], INT_MAX});
            } else if (coord[i].y == coord[j].y) {
                slopeZero.push_back({coord[i], coord[j], 0});
            } else {
                double temp = (double)(coord[i].y - coord[j].y) / (double)(coord[i].x - coord[j].x);
                if (temp > 0) {
                    slopePlus.push_back({coord[i], coord[j], temp});
                } else {
                    slopeMinus.push_back({coord[i], coord[j], temp});
                }

            }
        }
    }

    sort(slopePlus.begin(), slopePlus.end(), comp);
    sort(slopeMinus.begin(), slopeMinus.end(), comp);
    sort(slopeZero.begin(), slopeZero.end(), comp);
    sort(slopeInf.begin(), slopeInf.end(), comp);

    for (int i = 0; i < slopePlus.size(); i++) {
        for (int j = 0; j < slopeMinus.size(); j++) {
            if (isRectangle(slopePlus[i], slopeMinus[j])) {
                bool isFind1 = false;
                bool isFind2 = false;

                for (int k = i + 1; k < slopePlus.size() && slopePlus[i].getSize() == slopePlus[k].getSize() && slopePlus[i].slope == slopePlus[k].slope; k++) {
                    if (isRectangle(slopePlus[k], slopeMinus[j])) {
                        isFind1 = true;
                        break;
                    }
                }

                for (int k = j + 1; k < slopeMinus.size() && slopeMinus[j].getSize() == slopeMinus[k].getSize() && slopeMinus[j].slope == slopeMinus[k].slope; k++) {
                    if (isRectangle(slopePlus[i], slopeMinus[k])) {
                        isFind2 = true;
                        break;
                    }
                }

                if (isFind1 && isFind2) {
                    result1 = max(result1, findArea(slopePlus[i], slopeMinus[j]));
                }
            }
        }
    }

    for (int i = 0; i < slopeZero.size(); i++) {
        for (int j = 0; j < slopeInf.size(); j++) {
            if (isRectangle(slopeZero[i], slopeInf[j])) {
                bool isFind1 = false;
                bool isFind2 = false;

                for (int k = i + 1; k < slopeZero.size() && slopeZero[i].getSize() == slopeZero[k].getSize(); k++) {
                    if (isRectangle(slopeZero[k], slopeInf[j])) {
                        isFind1 = true;
                        break;
                    }
                }

                for (int k = j + 1; k < slopeInf.size() && slopeInf[j].getSize() == slopeInf[k].getSize(); k++) {
                    if (isRectangle(slopeZero[i], slopeInf[k])) {
                        isFind2 = true;
                        break;
                    }
                }

                if (isFind1 && isFind2) {
                    result2 = max(result2, findArea(slopeZero[i], slopeInf[j]));
                }
            }
        }
    }

    cout << max(result1, result2);
    return 0;
}
