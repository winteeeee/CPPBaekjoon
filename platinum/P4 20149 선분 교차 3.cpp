#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Segment {
private:
    pair<double, double> point1;
    pair<double, double> point2;

public:
    Segment(double x1, double y1, double x2, double y2);
    pair<double, double> getPoint1();
    pair<double, double> getPoint2();
};

Segment::Segment(double x1, double y1, double x2, double y2) {
    point1 = {x1, y1};
    point2 = {x2, y2};
}

pair<double, double> Segment::getPoint1() {
    return point1;
}

pair<double, double> Segment::getPoint2() {
    return point2;
}

long long ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c);
bool isCross(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<Segment> segments;
    for(int i = 0; i < 2; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments.push_back(Segment(x1, y1, x2, y2));
    }

    if(isCross(segments[0].getPoint1(), segments[0].getPoint2(), segments[1].getPoint1(), segments[1].getPoint2())) {
        cout << "1" << "\n";

        double x1 = segments[0].getPoint1().first;
        double x2 = segments[0].getPoint2().first;
        double x3 = segments[1].getPoint1().first;
        double x4 = segments[1].getPoint2().first;
        double y1 = segments[0].getPoint1().second;
        double y2 = segments[0].getPoint2().second;
        double y3 = segments[1].getPoint1().second;
        double y4 = segments[1].getPoint2().second;
        double temp1 = y2 - y1;
        double temp2 = x2 - x1;
        double temp3 = y4 - y3;
        double temp4 = x4 - x3;
        double seg1Angle = temp1 / temp2;
        double seg2Angle = temp3 / temp4;
        double x = abs((seg1Angle * x1 * -1 + y1) - (seg2Angle * x3 * - 1 + y3)) / abs(seg1Angle - seg2Angle);
        double y = seg1Angle * x - seg1Angle * x1 + y1;
        cout.precision(9);


        if(!isnan(x) && !isnan(y) && seg1Angle != seg2Angle)
            cout << x << " " << y;

        else if(isnan(x) && isnan(y) && seg1Angle == seg2Angle && !isinf(seg1Angle) && !isinf(seg2Angle)) {
            if(x1 == x3 && y1 == y3) {
                if(x2 < x1 && x1 < x4 ||
                   x4 < x1 && x1 < x2)
                    if(x2 != x4)
                        cout << x1 << " " << y1;
            }

            if(x1 == x4 && y1 == y4) {
                if(x2 < x1 && x1 < x3 ||
                   x3 < x1 && x1 < x2) {
                    if(x2 != x3)
                        cout << x1 << " " << y1;
                }
            }

            if(x2 == x3 && y2 == y3) {
                if(x1 < x2 && x2 < x4 ||
                   x4 < x2 && x2 < x1) {
                    if(x1 != x4)
                        cout << x2 << " " << y2;
                }
            }

            if(x2 == x4 && y2 == y4) {
                if(x1 < x2 && x2 < x3 ||
                   x3 < x2 && x2 < x1) {
                    if(x1 != x3)
                        cout << x2 << " " << y2;
                }
            }
        }

        else if(isinf(seg1Angle) || isinf(seg2Angle)) {
            if(isinf(seg1Angle) && !isinf(seg2Angle)) {
                cout << x1 << " " << seg2Angle * x1 - seg2Angle * x3 + y3;
            }

            else if(!isinf(seg1Angle) && isinf(seg2Angle)) {
                cout << x3 << " " << seg1Angle * x3 - seg1Angle * x1 + y1;
            }

            else {
                if(x1 == x3 && y1 == y3) {
                    if(y2 < y1 && y1 < y4 ||
                       y4 < y1 && y1 < y2)
                        if(y2 != y4)
                            cout << x1 << " " << y1;
                }

                if(x1 == x4 && y1 == y4) {
                    if(y2 < y1 && y1 < y3 ||
                       y3 < y1 && y1 < y2) {
                        if(y2 != y3)
                            cout << x1 << " " << y1;
                    }
                }

                if(x2 == x3 && y2 == y3) {
                    if(y1 < y2 && y2 < y4 ||
                       y4 < y2 && y2 < y1) {
                        if(y1 != y4)
                            cout << x2 << " " << y2;
                    }
                }

                if(x2 == x4 && y2 == y4) {
                    if(y1 < y2 && y2 < y3 ||
                       y3 < y2 && y2 < y1) {
                        if(y1 != y3)
                            cout << x2 << " " << y2;
                    }
                }
            }
        }
    }

    else
        cout << "0";

    return 0;
}

long long ccw(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    long long val = (a.first * b.second) + (b.first * c.second) + (c.first * a.second) - ((a.first * c.second) + (b.first * a.second) + (c.first * b.second));

    if(val < 0)
        return -1;

    else if(val > 0)
        return 1;

    else
        return 0;
}

bool isCross(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d) {
    long long seg1 = ccw(a, b, c) * ccw(a, b, d);
    long long seg2 = ccw(c, d, a) * ccw(c, d, b);

    if(seg1 <= 0 && seg2 <= 0) {
        if ((a.first > c.first && a.first > d.first && b.first > c.first && b.first > d.first) ||
            (c.first > a.first && c.first > b.first && d.first > a.first && d.first > b.first)) return false;
        else if ((a.second > c.second && a.second > d.second && b.second > c.second && b.second > d.second) ||
                 (c.second > a.second && c.second > b.second && d.second > a.second && d.second > b.second)) return false;
        return true;
    }

    return false;
}