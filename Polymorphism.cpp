/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: Polymorphism

Polymorphism ::

is a property to offer a single interface for different type of child classes
is a property to allow different implementations with the same function names in different child class that inherent the same parent

Pure Virtual Function ::

it mean that the defined function in base class is purely empty, and the derived class will have to defined implementation
*/

#include <iostream>
using namespace std;

class Shape {// Shape is a single interface for ...
private:
  string name;
protected:
  int width, height;
public:
// constructor
  //explicit  means that we cannot use Shape = a, b, "...";
  // default constructor
  explicit Shape(int a = 0, int b = 0, string s = "NULL"): width(a), height(b), name(s) {}
  // copy constructor
  Shape(const Shape& copy) {
    width = copy.width;
    height = copy.height;
    name = copy.name;
  }
  // deconstructor
  virtual ~Shape() {}// have to delete var with pointer property

  // operator
  Shape& operator=(const Shape& copy) {
    if (&copy == this){
      return *this;
    }
    width = copy.width;
    height = copy.height;
    name = copy.name;
    return *this;
  }

  // function
  virtual int area() const {
    cout << " is in base area: ";
    return 0;
  }
  //
  void spell_name() const {
    cout << "the name: " << name << endl;
  }
};

class Rectangle: public Shape {
public:
  // constructor
  explicit Rectangle(int a = 0, int b = 0, string s = "NULL"): Shape(a, b, s) {}
  Rectangle(const Rectangle& copy): Shape(copy) {}
  virtual ~Rectangle() {};

  // opertator
  Rectangle& operator=(const Rectangle& copy) {
    if (&copy == this){
      return * this;
    }
    Shape::operator=(copy);
    return * this;
  }

  // function
  int area () const {
    cout << " is in the Rectangle class area: ";
    return width * height;// is width * height are private memeber, they are not accessable for Rect
  }
};

class Triangle: public Shape {
public:
  // constructor
  explicit Triangle(int a = 0, int b = 0, string s = "NULL"): Shape(a, b, s) {}
  Triangle(const Triangle& copy): Shape(copy) {}
  virtual ~Triangle() {};

  // opertator
  Triangle& operator=(const Triangle& copy) {
    if (&copy == this){
      return * this;
    }
    Shape::operator=(copy);
    return * this;
  }

  // function
  int area () const {
    cout << " is in the Triangle class area: ";
    return width * height / 2;// is width * height are private memeber, they are not accessable for Rect
  }
};

class Circle: public Shape {
public:
  // constructor
  explicit Circle(int a = 0, int b = 0, string s = "NULL"): Shape(a, b, s) {}
  Circle(const Circle& copy): Shape(copy) {}
  virtual ~Circle() {};

  // opertator
  Circle& operator=(const Circle& copy) {
    if (&copy == this){
      return * this;
    }
    Shape::operator=(copy);
    return * this;
  }

  // function
  int area () const {
    cout << " is in the Circle class area: ";
    return width * height * 3.14;// is width * height are private memeber, they are not accessable for Rect
  }
};



int main() {

    cout << "Basic test ...\n\n";

    Rectangle rect(3, 3, "rect");// object
    rect.spell_name();
    cout << "rect" << rect.area() << "\n" << endl;

    Triangle tri(3, 3, "tri");// pointer of base
    tri.spell_name();
    cout << "tri" << tri.area() << "\n" << endl;

    Circle cir(3, 3, "cir");
    cir.spell_name();
    cout << "cir" << cir.area() << "\n" << endl;



    cout << "Further test ...\n\n";

    cout << "Use base pointer ...\n\n";

    Shape* sh_p;
    sh_p = &rect;
    sh_p->spell_name();
    cout << "area = " << sh_p->area() << "\n" << endl;
    sh_p = &tri;
    sh_p->spell_name();
    cout << "area = " << sh_p->area() << "\n" << endl;
    sh_p = &cir;
    sh_p->spell_name();
    cout << "area = " << sh_p->area() << "\n" << endl;

    cout << "Create space by using base pointer ...\n\n";

    Shape** c_sh = new Shape*[3];
    c_sh[0] = new Rectangle;
    c_sh[0]->spell_name();
    cout << "area = " << c_sh[0]->area() << "\n" << endl;
    c_sh[1] = new Triangle;
    c_sh[1]->spell_name();
    cout << "area = " << c_sh[1]->area() << "\n" << endl;
    c_sh[2] = new Circle;
    c_sh[2]->spell_name();
    cout << "area = " << c_sh[2]->area() << "\n" << endl;
    for(int i = 0; i < 3; i++) {
      delete c_sh[i];
    }
    delete[] c_sh;
}
