//
// Created by ASUS on 2022. 10. 12..
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H
#define M 2000

class Point{
private:
    int x, y;
    static int counter;
public:
    Point(int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const ;
    Point(const Point&);
    ~Point(){
        counter--;
    }
    static int getCounter() {
        return counter;
    }

};


#endif //CPP_2022_POINT_H
