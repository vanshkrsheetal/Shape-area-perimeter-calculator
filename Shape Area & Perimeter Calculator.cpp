
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Base class
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() const override {
        return 3.141592653589793 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.141592653589793 * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, breadth;

public:
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() const override {
        return length * breadth;
    }

    double perimeter() const override {
        return 2 * (length + breadth);
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double area() const override {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }
};

// Main function
int main() {
    int choice;
    double radius, length, breadth, a, b, c;

    cout << fixed << setprecision(2);

    do {
        cout << "\n===== Shape Area & Perimeter Calculator =====\n";
        cout << "1. Circle\n";
        cout << "2. Rectangle\n";
        cout << "3. Triangle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Shape* shape = nullptr;

        switch (choice) {
        case 1:
            cout << "Enter radius: ";
            cin >> radius;

            if (radius <= 0) {
                cout << "Radius must be positive!\n";
                break;
            }

            shape = new Circle(radius);
            break;

        case 2:
            cout << "Enter length: ";
            cin >> length;

            cout << "Enter breadth: ";
            cin >> breadth;

            if (length <= 0 || breadth <= 0) {
                cout << "Length and breadth must be positive!\n";
                break;
            }

            shape = new Rectangle(length, breadth);
            break;

        case 3:
            cout << "Enter first side: ";
            cin >> a;

            cout << "Enter second side: ";
            cin >> b;

            cout << "Enter third side: ";
            cin >> c;

            if (a <= 0 || b <= 0 || c <= 0 ||
                a + b <= c || a + c <= b ||
                b + c <= a) {
                cout << "Invalid triangle sides!\n";
                break;
            }

            shape = new Triangle(a, b, c);
            break;

        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

        if (shape != nullptr) {
            cout << "\nArea      : " << shape->area() << endl;
            cout << "Perimeter : " << shape->perimeter() << endl;

            delete shape;
        }

    } while (choice != 4);

    return 0;
}
