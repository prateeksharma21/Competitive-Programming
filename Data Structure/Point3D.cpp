template<typename T>
class Point{
public:
    T x,y,z;
    Point(){ x = y = z = 0; }
    Point(T x,T y){ this->x = x,this->y = y,this->z = 0; }
    Point(T x,T y,T z){ this->x = x,this->y = y,this->z = z; }
    Point& operator+=(const Point &t){
        x += t.x,y += t.y,z += t.z;
        return *this;
    }
    Point& operator-=(const Point &t){
        x -= t.x, y -= t.y, z -= t.z;
        return *this;
    }
    Point& operator*=(T t){
        x *= t, y *= t, z *= t;
        return *this;
    }
    Point& operator/=(T t){
        assert(t != 0);
        x /= t, y /= t, z /= t;
        return *this;
    }
    Point operator+(const Point &t) const{ return Point(*this) += t; }
    Point operator-(const Point &t) const{ return Point(*this) -= t; }
    Point operator*(T t) const{ return Point(*this) *= t; }
    Point operator/(T t) const{ return Point(*this) /= t; }
    friend Point operator*(T a,Point b){ return b*a; }
    T dot(Point a){ return x*a.x+y*a.y+z*a.z;}
    T dot(Point a,Point b){ return a.x*b.x+a.y*b.y+a.z*b.z; }
    T norm(){ return dot(*this,*this); }
    T norm(Point a){ return dot(a,a); }
    double abs(){return sqrt(norm()); }
    double abs(Point a){ return sqrt(norm(a)); }
    double proj(Point a,Point b){ return dot(a,b)/abs(b);}
    double proj(Point b){ return proj(*this,b);}
    double angle(Point a,Point b){ return acos(dot(a,b)/abs(a)/abs(b)); }
    double angle(Point b){ return angle(*this,b);}
};