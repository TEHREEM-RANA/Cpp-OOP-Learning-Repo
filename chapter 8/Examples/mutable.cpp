#include <iostream>
#include <string>
using namespace std;

class scrollbar {
private:
    int size;              // normal const variable
    mutable string owner;  // can change even if object is const
public:
    scrollbar(int sz, string own) : size(sz), owner(own) { }

    void setSize(int sz) { size = sz; }
    void setOwner(string own) const { owner = own; } // OK: owner is mutable
    int getSize() const { return size; }
    string getOwner() const { return owner; }
};

int main() {
    const scrollbar sbar(60, "Window1");
    // sbar.setSize(100);    // ❌ not allowed (object is const)
    sbar.setOwner("Window2"); // ✅ allowed because 'owner' is mutable

    cout << sbar.getSize() << ", " << sbar.getOwner() << endl;
    return 0;
}
