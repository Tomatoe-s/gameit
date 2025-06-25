#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <cmath>
#include <stdexcept>
namespace utilities {
class Vector2 {
public:
    float x;
    float y;
    Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }
    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }
    Vector2 operator/(float scalar) const {
        if (scalar == 0) {
            throw std::runtime_error("Division by zero in Vector2 division");
        }
        return Vector2(x / scalar, y / scalar);
    }
    float length() const {
        return std::sqrt(x * x + y * y);
    }
    Vector2 normalize() const {
        float len = length();
        if (len == 0) {
            throw std::runtime_error("Cannot normalize a zero-length vector");
        }
        return Vector2(x / len, y / len);
    }
    float dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }
    Vector2 operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2 operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Vector2 operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    Vector2 operator/=(float scalar) {
        if (scalar == 0) {
            throw std::runtime_error("Division by zero in Vector2 division");
        }
        x /= scalar;
        y /= scalar;
        return *this;
    }
    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2& other) const {
        return !(*this == other);
    }
    Vector2 operator-() const {
        return Vector2(-x, -y);
    }
    Vector2 rotate(float angle) const {
        float rad = angle * (3.14159265358979323846f / 180.0f); // Convert degrees to radians
        float cosA = std::cos(rad);
        float sinA = std::sin(rad);
        return Vector2(x * cosA - y * sinA, x * sinA + y * cosA);
    }
    Vector2 perpendicular() const {
        return Vector2(-y, x); // Rotate 90 degrees counter-clockwise
    }
    Vector2 project(const Vector2& other) const {
        float dotProduct = dot(other);
        float otherLengthSquared = other.length() * other.length();
        if (otherLengthSquared == 0) {
            throw std::runtime_error("Cannot project onto a zero-length vector");
        }
        return other * (dotProduct / otherLengthSquared);
    }
    Vector2 reflect(const Vector2& normal) const {
        float dotProduct = dot(normal);
        return *this - normal * (2 * dotProduct);
    }
    Vector2 clamp(const Vector2& min, const Vector2& max) const {
        return Vector2(
            std::fmax(min.x, std::fmin(x, max.x)),
            std::fmax(min.y, std::fmin(y, max.y))
        );
    }
    Vector2 lerp(const Vector2& other, float t) const {
        return Vector2(
            x + (other.x - x) * t,
            y + (other.y - y) * t
        );
    }
    Vector2 operator+(const Vector3& other) const {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator-(const Vector3& other) const {
        return Vector2(x - other.x, y - other.y);
    }
    Vector2 operator*(const Vector3& other) const {
        return Vector2(x * other.x, y * other.y);
    }

};
class Vector3 {
public:
    float x;
    float y;
    float z;
    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }
    Vector3 operator+(const Vector2& other) const {
        return Vector3(x + other.x, y + other.y, z );
    }
    Vector3 operator-(const Vector2& other) const {
        return Vector3(x - other.x, y - other.y, z);
    }
    Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }
    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }
    Vector3 lerp(const Vector3& other, float t) const {
        return Vector3(
            x + (other.x - x) * t,
            y + (other.y - y) * t,
            z + (other.z - z) * t
        );
    }
    Vector3 operator/(float scalar) const {
        if (scalar == 0) {
            throw std::runtime_error("Division by zero in Vector3 division");
        }
        return Vector3(x / scalar, y / scalar, z / scalar);
    }
    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    Vector3 normalize() const {
        float len = length();
        if (len == 0) {
            throw std::runtime_error("Cannot normalize a zero-length vector");
        }
        return Vector3(x / len, y / len, z / len);
    }
    float dot(const Vector3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    Vector3 cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
    Vector3 operator+=(const Vector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    Vector3 operator-=(const Vector3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }
    Vector3 operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }
    Vector3 operator/=(float scalar) {
        if (scalar == 0) {
            throw std::runtime_error("Division by zero in Vector3 division");
        }
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }
    bool operator==(const Vector3& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    bool operator!=(const Vector3& other) const {
        return !(*this == other);
    }
    Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }
  
    
};

}
#endif