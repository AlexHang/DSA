#include <iostream>
#define n 10
using namespace std;

class Point
{
    private:

    int coord_x, coord_y;//the coordinates of a point// rectangle size

    public:

    Point(){

    };
    Point(int x, int y){
        setX(x);
        setY(y);
    };

    ~Point(){
      //  cout<<"object destroyed";
    }

    int getX(){
        return coord_x;
    }
    int getY(){
        return coord_y;
    }

    void setX(int x){
        this->coord_x=x;
    }
    void setY(int y){
        this->coord_y=y;
    }
    void reset() //places the point into the origin
    {
        coord_x = coord_y = 0;
    }

    void moveX(int x ){
        if(this->coord_x+x>n){
            coord_x=0;
        }else this->coord_x+=x;
    }

    void moveY(int y){
        if(this->coord_y+y>n){
            coord_y=0;
        }else this->coord_y+=y;
    }

    void moveXY(int x , int y ){
        moveX(x);
        moveY(y);
    }

    void print(){
        cout<<this->coord_x<<" "<<this->coord_y<<endl;
    }

};
