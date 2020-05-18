template<typename T>
class Point3D{
public:
    T x,y,z;
    Point3D(){
        x = y = z = 0;
    }

    Point3D(T x,T y,T z){
        this->x = x,this->y = y,this->z = z;
    }

    Point3D& operator+=(const Point3D &t){
        x += t.x,y += t.y,z += t.z;
        return *this;
    }

    Point3D& operator-=(const Point3D &t){
        x -= t.x, y -= t.y, z -= t.z;
        return *this;
    }

    Point3D& operator*=(T t){
        x *= t, y *= t, z *= t;
        return *this;
    }

    Point3D& operator/=(T t){
        assert(t != 0);
        x *= t, y *= t, z *= t;
        return *this;
    }

    Point3D operator+(const Point3D &t) const{
        return Point3D(*this) += t;
    }

    Point3D operator-(const Point3D &t) const{
        return Point3D(*this) -= t;
    }

    Point3D operator*(T t) const{
        return Point3D(*this) *= t;
    }

    Point3D operator/(T t) const{
        return Point3D(*this) /= t;
    }

    friend Point3D operator*(T a,Point3D b){
        return b*a;
    }
};