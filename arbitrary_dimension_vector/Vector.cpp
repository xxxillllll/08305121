#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int dimension)
{
    if (dimension <= 0)
    {
        this->dimension = 0;
        member = NULL;
        return;
    }
    member = new double[this->dimension = dimension];
    for (int i = 0; i < dimension; i++)
        member[i] = 0;
}

Vector::Vector(const Vector& vec)
{
    member = NULL;
    if ((dimension = vec.dimension) != 0)
    {
        member = new double[dimension];
        for (int i = 0; i < dimension; i++)
            member[i] = vec.member[i];
    }
}

Vector& Vector::operator=(const Vector& vec)
{
    if (&vec == this) return *this;
    if (member != NULL) delete[] member;
    member = NULL;
    if ((dimension = vec.dimension) != 0)
    {
        member = new double[dimension];
        for (int i = 0; i < dimension; i++)
            member[i] = vec.member[i];
    }
    return *this;
}

Vector::~Vector()
{
    if (member != NULL) delete[] member;
}

int Vector::GetDim() const
{
    return dimension;
}

bool operator==(const Vector& A, const Vector& B)
{
    int n = min(A.dimension, B.dimension);
    for (int i = 0; i < n; i++)
        if (A.member[i] != B.member[i]) return false;
    for (int i = n; i < A.dimension; i++)
        if (A.member[i] != 0) return false;
    for (int i = n; i < B.dimension; i++)
        if (B.member[i] != 0) return false;
    return true;
}

istream& operator>>(istream& is, const Vector& vec)
{
    int n = vec.dimension;
    if (n == 0) return is;
    for (int i = 0; i < n; i++)
        is >> vec.member[i];
    return is;
}

ostream& operator<<(ostream& os, const Vector& vec)
{
    int n = vec.dimension;
    if (n == 0) return os;
    os << "(" << vec.member[0];
    for (int i = 1; i < n; i++)
        os << ", " << vec.member[i];
    os << ")";
    return os;
}

Vector operator+(const Vector& A, const Vector& B)
{
    int n = max(A.dimension, B.dimension);
    Vector result(n);
    for (int i = 0; i < n; i++)
    {
        if (i < A.dimension) result.member[i] += A.member[i];
        if (i < B.dimension) result.member[i] += B.member[i];
    }
    return result;
}

Vector operator^(const Vector& A, const Vector& B)
{
    Vector inner_A(3), inner_B(3); // default all 0 vector
    if (A.dimension > 3 || B.dimension > 3)
        throw("any vector with a 3+ dimension can not do cross product!");
    for (int i = 0; i < A.dimension; i++)
        inner_A.member[i] = A.member[i];
    for (int i = 0; i < B.dimension; i++)
        inner_B.member[i] = B.member[i];

    // math formula
    // a = (X1,Y1,Z1),b=(X2,Y2,Z2),
    //a * b=(Y1Z2-Y2Z1,Z1X2-Z2X1,X1Y2-X2Y1)
    Vector result(3);
    result.member[0] = inner_A.member[1] * inner_B.member[2] - inner_B.member[1] * inner_A.member[2];
    result.member[1] = inner_A.member[2] * inner_B.member[0] - inner_B.member[2] * inner_A.member[1];
    result.member[2] = inner_A.member[0] * inner_B.member[1] - inner_B.member[0] * inner_A.member[1];

    return result;
}

double operator*(const Vector& A, const Vector& B)
{
    int n = min(A.dimension, B.dimension);
    double result = 0;
    for (int i = 0; i < n; i++)
        result += (A.member[i] * B.member[i]);
    return result;
}

Vector operator*(const double& m, const Vector& A)
{
    int n = A.dimension;
    Vector result(n);
    for (int i = 0; i < n; i++)
        result.member[i] = m * A.member[i];
    return result;
}

Vector Vector::operator*(const double& m)
{
    int n = this->dimension;
    Vector result(n);
    for (int i = 0; i < n; i++)
        result.member[i] = m * this->member[i];
    return result;
}
