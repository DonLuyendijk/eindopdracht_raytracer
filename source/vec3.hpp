#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>

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

    inline Vec3<T> abs() {
        return Vec3<T>(std::abs(x), std::abs(y), std::abs(z));
    }

    inline Vec3<T> sign() {
        return Vec3<T>(std::copysign(1.0, x), std::copysign(1.0, y), std::copysign(1.0, z));
    }

    inline Vec3<T> reflect(Vec3<T> normal) {
        return (*this) - 2 * normal.dot(*this) * normal;
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

    inline Vec3<T> operator - () {
        return Vec3<T>(-x, -y, -z);
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