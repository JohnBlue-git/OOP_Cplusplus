/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: Encapsulation

private:
only itshelef can use

protected:
only itshlef and its child class can use

public:
all class and other function can use

static:
only in the scope can use

friend:
to define classes or functions that can utilize the memeber in this class
*/


#include <iostream>
using namespace std;

class FriendClass;

class EncapsulationExample
{
    public: explicit EncapsulationExample(int i = 0): privateVariable(i), constVariable(i) {
      //constVariable = i;// const variable not allow to assign here
    };
    public: virtual ~EncapsulationExample() {}

    private: int privateVariable;
    protected: int protectedVariable;
    public: int publicVariable;
    public: const int constVariable;
    static int staticVariable;
    static const int constStaticVariable;
    //int packageVariable;// default as private

    private: void privateObjectMethod() { }
    protected: void protectedObjectMethod() { }
    public: void publicObjectMethod() {
      cout << "non static item = " << privateVariable << endl;
    }
    //void packageObjectMethod() { }// default as private

    private: static void privateClassMethod() { }
    protected: static void protectedClassMethod() { }
    public: static void publicClassMethod() {
      cout << "static item = " << staticVariable << endl;
    }
    //static void static packageClassMethod() { }// default as private

    friend FriendClass;
};

// !!! must initialize static var
int EncapsulationExample::staticVariable = 0;
//EncapsulationExample::staticVariable = 0;// not allowed
const int EncapsulationExample::constStaticVariable = - 1;

int main() {
  EncapsulationExample Example(3);
  //EncapsulationExample Example = 3;// not work, since explicit type restrict the implicit conversion
  Example.publicObjectMethod();
  EncapsulationExample::publicClassMethod();
}
