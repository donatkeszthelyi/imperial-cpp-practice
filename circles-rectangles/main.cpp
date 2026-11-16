#include <iostream>

using namespace std;

class Circle {
private:
    float x;
    float y;
    float radius;

public:
    Circle(float x, float y, float radius) 
        : x(x), y(y), radius(radius) {};

    void view() {
        cout << "Circle(x: " << x << ", y: " << y 
            << ", radius: " << radius << ")" << endl;
    };
    
    float get_x() const {
        return x;
    };

    float get_y() const {
        return y;
    };

    float get_radius() const {
        return radius;
    };
    
    float calculate_area() const {
        return radius * radius * 3.1415;
    };
};

class Rectangle {
private:
    float x;
    float y;
    float width;
    float height;

public:
    Rectangle(float x, float y, float width, float height) 
        : x(x), y(y), width(width), height(height) {};

    void view() {
        cout << "Rectangle(x: " << x << ", y: " << y 
            << ", width: " << width << ", height: " 
            << height << ")" << endl;
    };

    float get_x() const {
        return x;
    };

    float get_y() const {
        return y;
    };

    float get_width() const {
        return width;
    };

    float get_height() const {
        return height;
    };

    float calculate_area() {
        return width * height;
    };
};

int main() {
    Circle circle1(1, 2, 3);
    circle1.view();
    cout << "Circle area: " << circle1.calculate_area() << endl;
    
    Rectangle rect1(1, 2, 3, 4);
    rect1.view();
    cout << "Rectangle area: " << rect1.calculate_area() << endl;

    return 0;
}
