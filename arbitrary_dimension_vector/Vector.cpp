#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int dimension)
{
    if (dimension <= 0)
    {
        n = 0;
        x = NULL;
        return;
    }
    x = new double[n = dimension];
    for (int i = 0; i < n; i++)
        x[i] = 0;
}

Vector::Vector(const Vector& vec)
{
    x = NULL;
    if ((n = vec.n) != 0)
    {
        x = new double[n];
        for (int i = 0; i < n; i++)
            x[i] = vec.x[i];
    }
}

Vector& Vector::operator=(const Vector& vec)
{
    if (&vec == this) return *this;
    if (x != NULL) delete[] x;
    x = NULL;
    if ((n = vec.n) != 0)
    {
        x = new double[n];
        for (int i = 0; i < n; i++)
            x[i] = vec.x[i];
    }
    return *this;
}

Vector::~Vector()
{
    if (x != NULL) delete[] x;
}

void Vector::Set()
{
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

int Vector::GetDim() const
{
    return n;
}

ostream& operator<<(ostream& out, Vector& vec)
{
    int n = vec.n;
    if (n == 0) return out;
    out << "(" << vec.x[0];
    for (int i = 1; i < n; i++)
        out << ", " << vec.x[i];
    out << ")";
    return out;
}

Vector operator+(const Vector& A, const Vector& B)
{
    int n = max(A.n, B.n);
    Vector result(n);
    for (int i = 0; i < n; i++)
    {
        if (i < A.n) result.x[i] += A.x[i];
        if (i < B.n) result.x[i] += B.x[i];
    }
    return result;
}

Vector operator-(const Vector& A, const Vector& B)
{
    int n = max(A.n, B.n);
    Vector result(n);
    for (int i = 0; i < n; i++)
    {
        if (i < A.n) result.x[i] += A.x[i];
        if (i < B.n) result.x[i] -= B.x[i];
    }
    return result;
}
