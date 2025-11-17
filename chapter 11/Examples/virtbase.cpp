// virtbase.cpp
class Parent {
protected:
    int basedata;
};

class Child1 : virtual public Parent { }; // virtual base class
class Child2 : virtual public Parent { }; // virtual base class

class Grandchild : public Child1, public Child2 {
public:
    int getdata() {
        return basedata; // OK: only one copy of Parent
    }
};
