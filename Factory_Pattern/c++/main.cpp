// C++ program to demonstrate factory method design pattern
#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // pure virtual function providing interface framework
    virtual void draw() {
      printf("Inside Base::draw() method.");
    };
    static Shape* Create(string type);
};

// Derived classes
class Rectangle : public Shape {
public:
    void draw() {
        cout << "I am a rectangle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "I am a square" << endl;
    }
};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
Shape* Shape::Create(string type) {
    if (type == "RECTANGLE")
        return new Rectangle();
    else if (type == "SQUARE")
        return new Square();
    else return NULL;
}

// Client class
class Client {
public:
    // Client doesn't explicitly create objects
    // but passes type to factory method "Create()"
    Client() {
        string type = "RECTANGLE";
        pShape = Shape::Create(type);
    }
    ~Client() {
        if (pShape) {
            delete[] pShape;
            pShape = NULL;
        }
    }
    Shape* getShape()  {
        return pShape;
    }

private:
    Shape *pShape;
};

// Driver program
int main() {
    Client *pClient = new Client();
    Shape * pShape = pClient->getShape();
    pShape->draw();
    return 0;
}
