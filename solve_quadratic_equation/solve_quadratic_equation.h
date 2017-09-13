#ifndef SOLVE_QUADRATIC_EQUATION_H_INCLUDED
#define SOLVE_QUADRATIC_EQUATION_H_INCLUDED

struct Pair
{
    double first, second;
};

//  input a, b, c, return whether the equation is solvable.
bool solve_quadratic_equation(const double& a, const double& b, const double& c,
                              double* root1, double* root2);

//  input a, b, c, referance return two roots if the equation is solvable,
//  return whether it is solvable.
bool solve_quadratic_equation(const double& a, const double& b, const double& c,
                              double& root1, double& root2);

//  input a, b, c, referance return the solve if the equation is solvable,
//  return whether it is solvable.
bool solve_quadratic_equation(const double& a, const double& b, const double& c,
                              Pair& root);

//  input a, b, c, return the solution,
//  referance return whether the equation is solvable.
Pair solve_quadratic_equation(const double& a, const double& b, const double& c,
                              bool& is_solvable);
#endif // SOLVE_QUADRATIC_EQUATION_H_INCLUDED

