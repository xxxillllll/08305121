#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
class Vector
{
public:
    Vector(int dimension = 0);                                 // initialization
    Vector(const Vector& vec);                                 // copy from a vector
    Vector& operator=(const Vector& vec);                      // assignment
    virtual ~Vector();                                         // destructor
    void Set();                                                // Set the coordinates
    int GetDim() const;                                        // Get the dimension
    friend ostream& operator<<(ostream& out, Vector& vec);     // Print the vector like (x,y,...)
    friend Vector operator+(const Vector& A, const Vector& B); // addition
    friend Vector operator-(const Vector& A, const Vector& B); // subtraction
    friend Vector operator^(const Vector& A, const Vector& B); // cross product
    friend double operator*(const Vector& A, const Vector& B); // inner product
    double Norm();                                             // length
    //  etc...
private:
    int dimension;     // dimension
    double* member; // coordinates
};

#endif // VECTOR_H
