/*
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

bool coordComp(const Segment& a, const Segment& b) {
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

bool comp (const Segment& a, const Segment& b) {
    return abs(a.slope - b.slope) < 0.000001 ? coordComp(a, b) : a.slope < b.slope;
}

bool comp2 (const Segment& a, const Segment& b) {
    return abs(a.slope - b.slope) < 0.000001 ? a.getSize() < b.getSize() : a.slope < b.slope;
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
                    if (coord[i].x == coord[j].x ? coord[i].y < coord[j].y : coord[i].x < coord[j].x) {
                        slopePlus.push_back({coord[i], coord[j], temp});
                    } else {
                        slopePlus.push_back({coord[j], coord[i], temp});
                    }
                } else {
                    if (coord[i].x == coord[j].x ? coord[i].y < coord[j].y : coord[i].x < coord[j].x) {
                        slopeMinus.push_back({coord[i], coord[j], temp});
                    } else {
                        slopeMinus.push_back({coord[j], coord[i], temp});
                    }
                }

            }
        }
    }

    sort(slopePlus.begin(), slopePlus.end(), comp);
    sort(slopeMinus.begin(), slopeMinus.end(), comp);
    sort(slopeZero.begin(), slopeZero.end(), comp2);
    sort(slopeInf.begin(), slopeInf.end(), comp2);

    for (int i = 0; i < slopePlus.size(); i++) {
        double targetSlope = -1 / slopePlus[i].slope;
        int targetIdx = lower_bound(slopeMinus.begin(), slopeMinus.end(), Segment{slopePlus[i].a, {INT_MIN, INT_MIN}, targetSlope}, comp) - slopeMinus.begin();
        for (int j = targetIdx; j < slopeMinus.size() && abs(slopeMinus[j].slope - targetSlope) < 0.000001 && slopePlus[i].a == slopeMinus[j].a; j++) {
            if (isRectangle(slopePlus[i], slopeMinus[j])) {
                Segment a = slopePlus[i];
                Segment b = slopeMinus[j];
                Segment c = {};
                Segment d = {};

                if (findArea(a, b) < result1) {
                    continue;
                }

                int cIdx = lower_bound(slopePlus.begin(), slopePlus.end(), Segment{b.b, {INT_MIN, INT_MIN}, slopePlus[i].slope},
                                       comp) - slopePlus.begin();
                int dIdx = lower_bound(slopeMinus.begin(), slopeMinus.end(), Segment{a.b, {INT_MIN, INT_MIN}, slopeMinus[j].slope},
                                       comp) - slopeMinus.begin();

                for (int k = cIdx; k < slopePlus.size() && abs(slopePlus[i].slope - slopePlus[k].slope) < 0.000001 &&
                                   slopeMinus[j].b == slopePlus[k].a; k++) {
                    if (isRectangle(slopeMinus[j], slopePlus[k]) &&
                        slopePlus[i].getSize() == slopePlus[k].getSize() && i != k) {
                        c = slopePlus[k];
                        break;
                    }
                }

                for (int k = dIdx; k < slopeMinus.size() && abs(slopeMinus[j].slope - slopeMinus[k].slope) < 0.000001 &&
                                   slopePlus[i].b == slopeMinus[k].a; k++) {
                    if (isRectangle(slopePlus[i], slopeMinus[k]) &&
                        slopeMinus[j].getSize() == slopeMinus[k].getSize() && j != k) {
                        d = slopeMinus[k];
                        break;
                    }
                }

                if (isRectangle(a, b) && isRectangle(b, c) && isRectangle(a, d) && isRectangle(c, d)) {
                    result1 = max(result1, findArea(a, b));
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
*/
