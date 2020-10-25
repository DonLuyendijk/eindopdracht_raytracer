#pragma once

#include <iostream>
#include <cmath>

template <typename T>
class Vec2 {
public:
    T x, y;
    
    inline Vec2(T x, T y) : x(x), y(y) {}

    inline Vec2(T value) : x(value), y(value) {}

    inline Vec2() {}

    inline T dot(Vec2<T> other) {
        return x * other.x + y * other.y;
    }

    inline T length() {
        return sqrt(x * x + y * y);
    }
    
    inline Vec2<T> normalized() {
        return (*this) / length();
    }

    inline void operator += (Vec2<T> other) {
        x += other.x;
        y += other.y;
    }

    inline void operator += (T value) {
        x += value;
        y += value;
    }

    inline void operator -= (Vec2<T> other) {
        x -= other.x;
        y -= other.y;
    }

    inline void operator -= (T value) {
        x -= value;
        y -= value;
    }

    inline void operator *= (Vec2<T> other) {
        x *= other.x;
        y *= other.y;
    }

    inline void operator *= (T value) {
        x *= value;
        y *= value;
    }

    inline void operator /= (Vec2<T> other) {
        x /= other.x;
        y /= other.y;
    }

    inline void operator /= (T value) {
        x /= value;
        y /= value;
    }

    inline Vec2<T> operator + (Vec2<T> other) {
        return Vec2<T>(x + other.x, y + other.y);
    }

    inline Vec2<T> operator + (T value) {
        return Vec2<T>(x + value, y + value);
    }

    inline Vec2<T> operator - (Vec2<T> other) {
        return Vec2<T>(x - other.x, y - other.y);
    }

    inline Vec2<T> operator - (T value) {
        return Vec2<T>(x - value, y - value);
    }

    inline Vec2<T> operator * (Vec2<T> other) {
        return Vec2<T>(x * other.x, y * other.y);
    }

    inline Vec2<T> operator * (T value) {
        return Vec2<T>(x * value, y * value);
    }

    inline Vec2<T> operator / (Vec2<T> other) {
        return Vec2<T>(x / other.x, y / other.y);
    }

    inline Vec2<T> operator / (T value) {
        return Vec2<T>(x / value, y / value);
    }
};

template <typename T>
inline Vec2<T> operator + (T value, Vec2<T> vector) {
    return Vec2<T>(value + vector.x, value + vector.y);
}

template <typename T>
inline Vec2<T> operator - (T value, Vec2<T> vector) {
    return Vec2<T>(value - vector.x, value - vector.y);
}

template <typename T>
inline Vec2<T> operator * (T value, Vec2<T> vector) {
    return Vec2<T>(value * vector.x, value * vector.y);
}

template <typename T>
inline Vec2<T> operator / (T value, Vec2<T> vector) {
    return Vec2<T>(value / vector.x, value / vector.y);
}

template <typename T>
inline std::ostream& operator << (std::ostream& os, Vec2<T> vector) {
    os << vector.x << ", " << vector.y;
    return os;
}

typedef Vec2<float> Vec2f;
typedef Vec2<double> Vec2d;
typedef Vec2<long double> Vec2ld;