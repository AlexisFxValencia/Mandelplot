#include <cmath>
using namespace std;

class Point{
    public:
        double x;
        double y;
        Point();
        Point(double x, double y);
        double distanceTo(const Point& o);
  
};