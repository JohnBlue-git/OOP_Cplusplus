/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: Inheritance
Reference: http://ot-note.logdown.com/posts/173174/note-cpp-named-type-convertion

Modifier ::

public is accessible for everyone
protected is only accessible in the class and its derived class
private is only accessible in the class

Inheritance ::

          inheritance/ accessibility of asset become
public    inheritance: private protected public
protected inheritance: private protected protected
private   inheritance: private private   private

Override ::

is a mechanism for a dirived class to redefine functions in base class to meet its own demand

Virtual or Non-Virtual ::

in c++ C#, there are two inheritance situations
in Non-Virtual (if method is not defined virtual in base class)
, the method defined in derived class will not overide the method in base class
, but the object will use method from derived class
in Virtual (if method is defined virtual in base class)
, the method will be overide
, and the compiler will determine which class theo bject belong then use the method defined by the class
*/

#include <iostream>
using namespace std;

class Shape {
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
      return * this;
    }
    width = copy.width;
    height = copy.height;
    name = copy.name;
    return * this;
  }

  // function
  // virtual function for overriding
  virtual int area() const {
    cout << " is in base area: ";
    return 0;
  }
  //
  void spell_name() const {
    cout << "(in base area) the name: " << name << endl;
  }
};

class Rectangle: public Shape {
private:
  int ck;
public:
  // constructor
  explicit Rectangle(int a = 0, int b = 0, string s = "NULL"): Shape(a, b, s), ck(3) {}
  Rectangle(const Rectangle& copy): Shape(copy), ck(3) {}
  virtual ~Rectangle() {};

  // opertator
  Rectangle& operator=(const Rectangle& copy) {
    if (&copy == this){
      return * this;
    }
    ck = copy.ck;
    Shape::operator=(copy);
    return * this;
  }

  // function
  virtual int area () const {
    cout << " is in the upper class area: ";
    return width * height;// is width * height are private memeber, they are not accessable for Rect
  }
  //
  void spell_name() const {
    cout << "(in upper area) the name: " << endl;
    this->Shape::spell_name();
  }
};



int main(void)
{

  cout << "Basic test ...\n\n";

  Rectangle rect(3, 3, "cu");// object
  cout << "create object:\n";
  rect.spell_name();
  cout << "rect" << rect.area() << "\n" << endl;

  Rectangle* rt = &rect;// pointer of base
  cout << "pointer to object:\n";
  rt->spell_name();
  cout << "*rt" << rt->area() << "\n" << endl;

  Rectangle rect_c(rect);
  cout << "copy object:\n";
  rect_c.spell_name();
  cout << "rect_c" << rect_c.area() << "\n" << endl;

  Rectangle rect_a;
  rect_a = rect;
  cout << "assignment object:\n";
  rect_a.spell_name();
  cout << "rect_a" << rect_a.area() << "\n\n" << endl;

  //cout << "Base to derived(downcasting) is not safe, since some variables and function of base class are not match to derived class, but we can use dynamiccast to do it ...\n\n";
  /* the following not workable
  Shape sh;
  Rectangle rect_sc(sh);
  cout << "copy object:\n";
  rect_sc.spell_name();
  cout << "rect_sc" << rect_sc.area() << "\n" << endl;
  Rectangle rect_sa = sh;
  cout << "assignment object:\n";
  rect_sa.spell_name();
  cout << "rect_sa" << rect_sa.area() << "\n" << endl;
  */


  cout << "Derived to base(upcasting) will degrading ... \n\n";
  //Rectangle rect(3, 3, "cu");// object
  Shape sh_c(rect);
  cout << "copy object:\n";
  sh_c.spell_name();
  cout << "sh_c" << sh_c.area() << "\n" << endl;
  Shape sh_a = rect;
  cout << "assignment object:\n";
  sh_a.spell_name();
  cout << "sh_a" << sh_a.area() << "\n" << endl;

  cout << "Derived to base(upcasting) by using base pointer\n\n";
  Shape* sh_p = &rect;
  cout << "thought sh_p point to object of upper class, but it will call function in base class area due to non virtual function:\n";
  sh_p->spell_name();
  cout << "sh_p will call function in upper class area due to virtual function:\n";
  cout << "*rt" << sh_p->area() << "\n" << endl;
}
