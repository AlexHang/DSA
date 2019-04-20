#include <iostream>
#include <math.h>
using namespace std;

class Point
{
   private:
       int x;
       int y;
   public:
    Point();
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
    friend double getDistanceFromOrigin(Point p);
};

double getDistanceFromOrigin(Point p){
    return sqrt(pow(p.x,2)+pow(p.y,2));
}
int main(){
    Point p1(3,4);
    cout<<getDistanceFromOrigin(p1);
}
