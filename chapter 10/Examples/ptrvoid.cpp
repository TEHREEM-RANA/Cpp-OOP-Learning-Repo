// ptrvoid.cpp
#include <iostream>
using namespace std;

int main() {
    int intvar;          // integer variable
    float flovar;        // float variable
    int* ptrint;         // pointer to int
    float* ptrflo;       // pointer to float
    void* ptrvoid;       // pointer to void

    ptrint = &intvar;    // ✅ ok: int* to int*
    // ptrint = &flovar; // ❌ error: float* to int*
    // ptrflo = &intvar; // ❌ error: int* to float*
    ptrflo = &flovar;    // ✅ ok: float* to float*
    ptrvoid = &intvar;   // ✅ ok: int* to void*
    ptrvoid = &flovar;   // ✅ ok: float* to void*

    return 0;
}
// If you really want to assign one pointer type to another, you can use:
// ptrint = reinterpret_cast<int*>(&flovar);
// Avoid reinterpret_cast unless absolutely necessary — it can make code unsafe.