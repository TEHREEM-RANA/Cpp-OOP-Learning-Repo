
// 10. A matrix is a two-dimensional array. Create a class matrix that provides the same safety
// feature as the array class in Exercise 7; that is, it checks to be sure no array index is out
// of bounds. Make the member data in the matrix class a 10-by-10 array. A constructor
// should allow the programmer to specify the actual dimensions of the matrix (provided
// they’re less than 10 by 10). The member functions that access data in the matrix will now
// need two index numbers: one for each dimension of the array. Here’s what a fragment of
// a main() program that operates on such a class might look like:
// matrix m1(3, 4); // define a matrix object
// int temp = 12345; // define an int value
// m1.putel(7, 4, temp); // insert value of temp into matrix at 7,4
// temp = m1.getel(7, 4); // obtain value from matrix at 7,4
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 10;

class Matrix {
private:
    int mat[MAX_SIZE][MAX_SIZE];
    int rows, cols;

public:
    // Constructor
    Matrix(int r = 10, int c = 10) {
        if (r > MAX_SIZE || c > MAX_SIZE || r <= 0 || c <= 0) {
            cout << "Invalid matrix size!\n";
            exit(1);
        }
        rows = r;
        cols = c;

        // Initialize all elements to 0
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                mat[i][j] = 0;
    }

    // Destructor
    ~Matrix() {
        cout << "Matrix destroyed.\n";
    }

    // Setter
    void putel(int r, int c, int value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Matrix index out of bounds!\n";
            exit(1);
        }
        mat[r][c] = value;
    }

    // Getter
    int getel(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Matrix index out of bounds!\n";
            exit(1);
        }
        return mat[r][c];
    }

    // Display entire matrix
    void display() const {
        cout << "Matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << mat[i][j] << "\t";
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(3, 4);
    int temp = 12345;

    m1.putel(2, 3, temp);
    cout << "Element at (2,3): " << m1.getel(2, 3) << endl;

    m1.display();

    return 0;
}
