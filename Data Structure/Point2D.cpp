template <typename T>
class Point2D
{
public:
    T x, y;

    Point2D()
    {
        x = 0, y = 0;
    }

    Point2D(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    Point2D &operator+=(const Point2D &t)
    {
        x += t.x;
        y += t.y;
        return *this;
    }

    Point2D &operator-=(const Point2D &t)
    {
        x -= t.x;
        y -= t.y;
        return *this;
    }

    Point2D &operator*=(T t)
    {
        x *= t;
        y *= t;
        return *this;
    }

    Point2D &operator/=(T t)
    {
        assert(t != 0);
        x /= t;
        y /= t;
        return *this;
    }

    Point2D operator+(const Point2D &t)
    {
        return Point2D(*this) += t;
    }

    Point2D operator-(const Point2D &t)
    {
        return Point2D(*this) -= t;
    }

    Point2D operator*(T t) const
    {
        return Point2D(*this) *= t;
    }

    Point2D operator/(T t) const
    {
        return Point2D(*this) /= t;
    }

    friend Point2D operator*(T a, Point2D b)
    {
        return b * a;
    }

    T dot(Point2D A,Point2D B){
        return A.x*B.x+A.y*B.y;
    }
};
