// static_declaration_definition.cpp
// Demonstrating separate declaration and definition of static data

#include <iostream>
using namespace std;

class Foo
{
private:
    static int count; // DECLARATION (only tells compiler about it)
public:
    Foo() { count++; } // increases count
    int getCount() { return count; }
};

// DEFINITION (actually allocates memory for static variable)
int Foo::count = 0;

int main()
{
    Foo f1, f2;  // two objects
    cout << "Count is " << f1.getCount() << endl;
    cout << "Count is " << f2.getCount() << endl;

    return 0;
}
/*Key Takeaways

Declaration of static member → inside class.

Definition of static member → outside class using ClassName::variable.

If you forget the definition, compiler won’t warn you — linker will complain later.

Static data = one copy shared by all objects.*/