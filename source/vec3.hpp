#pragma once

#include <iostream>
#include <cmath>

template <typename T>
class Vec3 {
public:
    T x, y, z;
    
    inline Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    inline Vec3(T value) : x(value), y(value), z(value) {}

    inline Vec3() {}

    inline T dot(Vec3<T> other) {
        return x * other.x + y * other.y;
    }
    
    inline Vec3<T> cross(Vec3<T> other) {
        return Vec3<T>(
            y * other.z - other.y * z,
            z * other.x - other.z * x,
            x * other.y - other.x * y
        );
    }

    inline T length() {
        return sqrt(x * x + y * y + z * z);
    }
    
    inline Vec3<T> normalized() {
        return (*this) / length();
    }

    inline void operator += (Vec3<T> other) {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    inline void operator += (T value) {
        x += value;
        y += value;
        z += value;
    }

    inline void operator -= (Vec3<T> other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    inline void operator -= (T value) {
        x -= value;
        y -= value;
        z -= value;
    }

    inline void operator *= (Vec3<T> other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
    }

    inline void operator *= (T value) {
        x *= value;
        y *= value;
        z *= value;
    }

    inline void operator /= (Vec3<T> other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
    }

    inline void operator /= (T value) {
        x /= value;
        y /= value;
        z /= value;
    }

    inline Vec3<T> operator + (Vec3<T> other) {
        return Vec3<T>(x + other.x, y + other.y, z + other.z);
    }

    inline Vec3<T> operator + (T value) {
        return Vec3<T>(x + value, y + value, z + value);
    }

    inline Vec3<T> operator - (Vec3<T> other) {
        return Vec3<T>(x - other.x, y - other.y, z - other.z);
    }

    inline Vec3<T> operator - (T value) {
        return Vec3<T>(x - value, y - value, z - value);
    }

    inline Vec3<T> operator * (Vec3<T> other) {
        return Vec3<T>(x * other.x, y * other.y, z * other.z);
    }

    inline Vec3<T> operator * (T value) {
        return Vec3<T>(x * value, y * value, z * value);
    }

    inline Vec3<T> operator / (Vec3<T> other) {
        return Vec3<T>(x / other.x, y / other.y, z / other.z);
    }

    inline Vec3<T> operator / (T value) {
        return Vec3<T>(x / value, y / value, z / value);
    }
};

template <typename T>
inline Vec3<T> operator + (T value, Vec3<T> vector) {
    return Vec3<T>(value + vector.x, value + vector.y, value + vector.z);
}

template <typename T>
inline Vec3<T> operator - (T value, Vec3<T> vector) {
    return Vec3<T>(value - vector.x, value - vector.y, value - vector.z);
}

template <typename T>
inline Vec3<T> operator * (T value, Vec3<T> vector) {
    return Vec3<T>(value * vector.x, value * vector.y, value * vector.z);
}

template <typename T>
inline Vec3<T> operator / (T value, Vec3<T> vector) {
    return Vec3<T>(value / vector.x, value / vector.y, value / vector.z);
}

template <typename T>
inline std::ostream& operator << (std::ostream& os, Vec3<T> vector) {
    os << vector.x << ", " << vector.y << ", " << vector.z;
    return os;
}

typedef Vec3<float> Vec3f;
typedef Vec3<double> Vec3d;
typedef Vec3<long double> Vec3ld;