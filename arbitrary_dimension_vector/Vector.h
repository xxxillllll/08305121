#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
class Vector
{
public:
    Vector(int dimension = 0);                                  // initialization
    Vector(const Vector& vec);                                  // copy from a vector
    Vector& operator=(const Vector& vec);                       // assignment
    virtual ~Vector();                                          // destructor
    int GetDim() const;                                         // Get the dimension
    friend istream& operator>>(istream& is, const Vector& vec); // Set the coordinates
    friend ostream& operator<<(ostream& os, const Vector& vec); // Print the vector like (x,y,...)
    friend bool operator==(const Vector& A, const Vector& B);   // judge equation
    friend Vector operator+(const Vector& A, const Vector& B);  // addition
    friend Vector operator-(const Vector& A, const Vector& B);  // subtraction
    friend Vector operator^(const Vector& A, const Vector& B);  // cross product
    friend double operator*(const Vector& A, const Vector& B);  // inner product
    friend Vector operator*(const double& m, const Vector& A);  // scalar multiplication
    Vector operator*(const double& m);                          // scalar multiplication
    Vector& operator+=(const Vector& rhs);                      // addition and assignment
    Vector& operator-=(const Vector& rhs);                      // subtraction and assignment
    Vector& operator^=(const Vector& rhs);                      // cross product and assignment
    Vector& operator*=(const double& m);                        // scalar multiplication and assignment
    double Norm();                                              // length
    //  etc...
private:
    int dimension;  // dimension
    double* member; // coordinates
};

#endif // VECTOR_H
