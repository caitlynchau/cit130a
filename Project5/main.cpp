//
//  main.cpp
//  Project5
//
//  Created by Caitlyn Chau on 7/24/19.
//  Copyright © 2019 Caitlyn Chau. All rights reserved.
//

#include <iostream>
#include <cctype>
using namespace std;

class Shape {
public:
    double getArea() const {
        return area_;
    }
    
    void setArea(double a) {
        area_ = a;
    }
    
    double getPerimeter() const {
        return perimeter_;
    }
    
    void setPerimeter(double p) {
        perimeter_ = p;
    }
    
    virtual void calcArea() = 0;
    virtual void calcPerimeter() = 0;
    
private:
    double area_;
    double perimeter_;
};

class Circle : public Shape {
public:
    Circle() {}
    Circle(double r) : radius_(r) {}
    
    double getRadius() const {
        return radius_;
    }
    
    void setRadius(double r) {
        radius_ = r;
    }
    
    virtual void calcArea() {
        setArea(3.14159*radius_*radius_);
    }
    
    virtual void calcPerimeter() {
        setPerimeter(3.14159*radius_ * 2);
    }
private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle() {}
    Rectangle(long w, long l) : width_(w), length_(l) {}
    
    long getWidth() const {
        return width_;
    }
    
    void setWidth(long w) {
        width_ = w;
    }
    
    long getLength() const {
        return length_;
    }
    
    void setLength(long l) {
        length_ = l;
    }
    
    virtual void calcArea() {
        setArea(length_*width_);
    }
    
    virtual void calcPerimeter() {
        //perimeter = 2l + 2w
        setPerimeter(2 * (length_ + width_));
    }
private:
    long width_;
    long length_;
};

//helper functions
void createCircle();
void createRectangle();

int main() {
    cout << "Welcome to my application" << endl << endl;
    
    for (;;) { //infinite loop
        cout << "Enter R for the rectangle or C for the circle: ";
        char choice;
        cin >> choice;
        cout << endl;
        
        if (toupper(choice) == 'R')
            createRectangle();
        else if (toupper(choice) == 'C')
            createCircle();
        else
            cout << "Error! R or C only" << endl;
        
        cout << endl;
        bool loop = true;
        while (loop) {
            cout << "Continue? y/n: ";
            char cont;
            cin >> cont;
            cout << endl;
            
            if (toupper(cont) == 'N') {
                cout << "Thank you for using my app!" << endl;
                return 0;
            }
            else if (toupper(cont) == 'Y')
                loop = false;
            else
                cout << "Error! y or n only" << endl << endl;
        }
    }
}

void createRectangle() {
    bool wLoop = true, lLoop = true;
    long width = 0, length = 0;
    
    while (wLoop) {
        cout << "Enter the width: ";
        cin >> width;
        
        if (width <= 0)
            cout << "Error! Positive number only." << endl;
        else
            wLoop = false;
    }
    
    while (lLoop) {
        cout << "Enter the length: ";
        cin >> length;
        
        if (length <= 0)
            cout << "Error! Positive number only." << endl;
        else
            lLoop = false;
    }
    
    cout << endl;
    Rectangle r(width, length);
    r.calcArea();
    r.calcPerimeter();
    cout << "The area of the rectangle (width: " << r.getWidth() << " and length: " << r.getLength() << ") is " << r.getArea() << endl;
    cout << "The perimeter of the rectangle (width: " << r.getWidth() << " and length: " << r.getLength() << ") is " << r.getPerimeter() << endl;
}

void createCircle() {
    bool rLoop = true;
    double radius;
    
    while (rLoop) {
        cout << "Enter the radius: ";
        cin >> radius;
        
        if (radius <= 0)
            cout << "Error! Positive number only." << endl;
        else
            rLoop = false;
    }
    
    cout << endl;
    Circle c(radius);
    c.calcArea();
    c.calcPerimeter();
    cout << "The area of the circle (radius: " << c.getRadius() << ") is " << c.getArea() << endl;
    cout << "The perimeter of the circle (radius: " << c.getRadius() << ") is " << c.getPerimeter() << endl;
}
