#include <iostream>
using namespace std;
#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
public:
    Vector(int dimension = 0);                                       // initialization
    Vector(const Vector<T>& vec);                                    // copy from a vector
    Vector& operator=(const Vector<T>& vec);                         // assignment
    virtual ~Vector();                                               // destructor
    void Set();                                                      // Set the coordinates
    int GetDim() const;                                              // Get the dimension
    void Print() const;                                              // Print the vector like (x,y,...)
    friend Vector operator+(const Vector<T>& A, const Vector<T>& B); // addition
    friend Vector operator-(const Vector<T>& A, const Vector<T>& B); // subtraction
    friend Vector operator^(const Vector<T>& A, const Vector<T>& B); // cross product
    friend T operator*(const Vector<T>& A, const Vector<T>& B);      // inner product
    //  etc...
private:
    int n; // dimension
    T* x;  // coordinates
};

template <typename T>
Vector<T>::Vector(int dimension)
{
    if (dimension <= 0)
    {
        n = 0;
        x = NULL;
        return;
    }
    x = new T[n = dimension];
    for (int i = 0; i < n; i++)
        x[i] = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vec)
{
    x = NULL;
    if (n = vec.n)
    {
        x = new T[n];
        for (int i = 0; i < n; i++)
            x[i]=vec.x[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
    if (&vec == this) return *this;
    if (x != NULL) delete[] x;
    x = NULL;
    if (n = vec.n)
    {
        x = new T[n];
        for (int i = 0; i < n; i++)
            x[i]=vec.x[i];
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    if (x != NULL) delete[] x;
}

#endif // VECTOR_H
