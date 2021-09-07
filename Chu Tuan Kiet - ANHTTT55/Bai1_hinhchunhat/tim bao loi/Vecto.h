#include "Point.h"

class Vecto:public Point
{
    public:
        Point vec;

        Vecto(){ };
        Vecto(Point x, Point y){
            vec = y - x;
        }
        
        friend ostream &operator<<(ostream &, Vecto &v){
            cout << v.vec;
        }
        Vecto operator=(const Vecto &p){
            vec.x = p.vec.x;
            vec.y = p.vec.y;
        }
        Vecto operator-(const Vecto &p){

        }
        double DoDai(){
            return sqrt(pow(this->vec.x,2) + pow(this->vec.y,2)); 
        }
};

