#include <iostream>

class Vector {
public:
    int x_, y_;

    Vector() {}

    Vector(int x, int y) {
        x_ = x;
        y_ = y;
    }

    Vector operator*(const Vector& other) const {
        std::cout << "Multiplication of 2 vectors is called" << std::endl;
        return Vector(x_ * other.x_, y_ * other.y_);
    }
};

Vector operator+(const Vector& lhs, const Vector& rhs) {
    std::cout << "Add of 2 vectors is called" << std::endl;
    return Vector(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "(" << vec.x_ << ", " << vec.y_ << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Vector& vec) {
    int x, y;
    is >> x >> y;
    vec.x_ = x;
    vec.y_ = y;
    return is;
}

int main() {
    Vector v1 = {1, 2};
    Vector v2 = {3, 4};
    Vector v3 = v1 * v2;
    Vector v4 = v1 + v2;
    std::cout << v4 << std::endl;
    Vector v5;
    std::cin >> v5;
    std::cout << v5 << std::endl;
}