/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: Multi - Inheritance

Multi - Inheritance ::

is property to inherent from differet parent classes
(c++) can do multi_inheritance but java,c# can't
(java)(C#) can use interface to implment multi_inheritance

when to use?

it is useful when you don't want to create an instance of an object but want to execute some function on it
(by using static functions, we don't have to depend on any entities)
it can be used as interface in C++
*/


#include<iostream>
using namespace std;

class Grand
{
private:
  int x;
  static int y;
public:
  Grand() {
    cout << "defaut construct Grand..." << endl;
    x = 0;
  }
  Grand(int i) {
    cout << "construct Grand..." << endl;
    x = 1;
    set(i);
  }
  virtual ~Grand() {}

  void set(int i) {
    y = i;
  }

  void print() {
    cout << "int x = " << x << ";\n";
  }

  static void print_s() {
    //cout << x;// not workable for member var since static function don't have host
    //cout << this->x;// not workable since static function don't have "this"
    //print();// not workable either
    cout << "static int y = " << y << ";\n";
  }
};
// !!! must initialize static var
int Grand::y = 0;
//Grand::y = 9;// not allowed

// parent
class Dad: public Grand
{
public:
  Dad(): Grand(30) {
    cout << "construct Dad..." << endl;
    //set(30);
  }
  virtual ~Dad() {}
};

class Mom: public Grand
{
public:
  Mom(): Grand(33) {
    cout << "construct Mom..." << endl;
    //set(33);
  }
  virtual ~Mom() {}
};

class Kid: public Dad, public Mom
//class Kid: public Mom, public Dad // the order of Dad and Mom will decide the order set(int) be called
{
public:
  Kid(): Dad(), Mom() {
    cout << "construct Kid..." << endl;
  }
  // Kid(): Mom(), Dad() {} // the order of Dad and Mom won't make any difference
  virtual ~Kid() {}
};

// parent with virtual
class Dad_v: virtual public Grand
{
public:
  Dad_v(): Grand(300) {
    cout << "construct Dad..." << endl;
    //set(300);
  }
  virtual ~Dad_v() {}
};

class Mom_v: virtual public Grand
{
public:
  Mom_v(): Grand(303) {
    cout << "construct Mom..." << endl;
    //set(303);
  }
  virtual ~Mom_v() {}
};

class Kid_v: public Dad_v, public Mom_v
{
public:
  Kid_v(): Dad_v(), Mom_v() {// set to use Grand() default constructor
    cout << "default construct Kid..." << endl;
  }
  Kid_v(int s): Dad_v(), Mom_v(), Grand(s) {// force to use Grand(int)
    cout << "construct Kid..." << endl;
  }
  virtual ~Kid_v() {}
};



int main()
{
  cout << "kid without virtual inheritance ..." << endl;
  cout << "(default construct):" << endl;
  Kid k;
  k.print_s();// 33 due to the last triggering by Mon(...) constructor
  //k.print();//(Diamond problem: not knowing which grand to call) and it is not workable since it is not static function

  cout << "\n";

  cout << "kid_v with virtual inheritance ..." << endl;
  cout << "(default construct):" << endl;
  Kid_v k_v;
  k_v.print_s();// 33 due to the last triggering by Mon(...) constructor
  k_v.print();// !!! (Diamond problem solved by virtual inheritance) 0 due to Grand()
  cout << "(parameterized construct):" << endl;
  Kid_v k_v_pa(333);
  k_v_pa.print_s();// 33 due to the last triggering by Mon(...) constructorㄋ
  k_v_pa.print();// !!! (Diamond problem solved by virtual inheritance) 1 due to Grand(int)

  cout << "\n";

  cout << "kid_v use dynamic allocate ..." << endl;
  cout << "(parameterized construct):" << endl;
  Grand* p = new Kid_v(333);// !!! remember to virtual deconstructor to avoid ambibuilty
  p->print_s();
  p->print();
  delete p;
}
