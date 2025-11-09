#include <iostream>

struct Point
{
public:
    float x, y;

public:
    Point(float x, float y) : x(x), y(y) {}

    Point() : Point(0.0f, 0.0f) {}
};

struct A
{
    int b;
    int a;
    // int a;
    // int b;
    A(int i) : b(i), a(b + 1) {}
};

int main()
{
    Point p1;
    Point p2(1.0, 2.0);
    Point p3 = Point(7.5, 1.2);
    Point p4 = {3.0, 3.0};
    Point p5();
    // Point p5{};
    // std::cout << p5.x << std::endl;
    Point *p6 = new Point(0.5, 0.3);
    A a(237);
    std::cout << "b: " << a.b << std::endl;
    std::cout << "a (= b + 1): " << a.a << std::endl;
}