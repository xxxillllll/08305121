#include "solve_quadratic_equation.h"
#include <cmath>

bool solve_quadratic_equation(const double& a, const double& b, const double& c,
                              double* root1, double* root2)
{
    double delta = b * b - 4 * a * c;
    if (delta < 0) return false;
    *root1 = (-b + sqrt(delta)) / (2 * a);
    *root2 = (-b - sqrt(delta)) / (2 * a);
    return true;
}

bool solve_quadratic_equation(const double& a, const double& b, const double& c,
                              double& root1, double& root2)
{
    double delta = b * b - 4 * a * c;
    if (delta < 0) return false;
    root1 = (-b + sqrt(delta)) / (2 * a);
    root2 = (-b - sqrt(delta)) / (2 * a);
    return true;
}

bool solve_quadratic_equation(const double& a, const double& b, const double& c,
                              Pair& root)
{
    double delta = b * b - 4 * a * c;
    if (delta < 0) return false;
    root.first = (-b + sqrt(delta)) / (2 * a);
    root.second = (-b - sqrt(delta)) / (2 * a);
    return true;
}

Pair solve_quadratic_equation(const double& a, const double& b, const double& c,
                              bool& is_solvable)
{
    Pair root;
    is_solvable = solve_quadratic_equation(a, b, c, root.first, root.second);
    return root;
}
