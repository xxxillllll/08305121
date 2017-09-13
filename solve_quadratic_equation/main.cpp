#include "solve_quadratic_equation.h"
#include <iostream>

inline bool input();  //  return whether it is a quadratic equation
inline void output(); //  Output the solution
void Scheme1();       //  Pointer formal parameters
void Scheme2();       //  Referance formal parameters
void Scheme3();       //  Struct referance formal parameters
void Scheme4();       //  Return a struct

int main()
{
    int user_input;
    std::cout << "******************************" << std::endl;
    std::cout << "*  Solve Quadratic Equation  *" << std::endl;
    std::cout << "*      ax^2 + bx +c = 0      *" << std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "Choose a scheme:" << std::endl;
    std::cout << "1. Pointer formal parameters" << std::endl;
    std::cout << "2. Referance formal parameters" << std::endl;
    std::cout << "3. Struct referance formal parameters" << std::endl;
    std::cout << "4. Return a struct" << std::endl;
    std::cout << "0. Exit" << std::endl;
    do
    {
        std::cout << "Input a number:";
        std::cin >> user_input;
        switch (user_input)
        {
        case 1: Scheme1(); break;
        case 2: Scheme2(); break;
        case 3: Scheme3(); break;
        case 4: Scheme4(); break;
        case 0: break;
        default:
            std::cout << "Invalid input" << std::endl;
        }
    } while (user_input);
    return 0;
}

inline bool input(double& a, double& b, double& c)
{
    std::cout << "Please Input a, b, c" << std::endl;
    std::cin >> a >> b >> c;
    return a == 0;
}

inline void output(const double& root1, const double& root2)
{
    std::cout << "The roots are ";
    std::cout << root1 << " and " << root2 << std::endl;
}

void Scheme1()
{
    double a, b, c;
    while (input(a, b, c)) std::cout << "Invalid input" << std::endl;
    double root1, root2;
    if (solve_quadratic_equation(a, b, c, &root1, &root2))
        output(root1, root2);
    else
        std::cout << "No real root" << std::endl;
}

void Scheme2()
{
    double a, b, c;
    while (input(a, b, c)) std::cout << "Invalid input" << std::endl;
    double root1, root2;
    if (solve_quadratic_equation(a, b, c, root1, root2))
        output(root1, root2);
    else
        std::cout << "No real root" << std::endl;
}

void Scheme3()
{
    double a, b, c;
    while (input(a, b, c)) std::cout << "Invalid input" << std::endl;
    Pair root;
    if (solve_quadratic_equation(a, b, c, root))
        output(root.first, root.second);
    else
        std::cout << "No real root" << std::endl;
}

void Scheme4()
{
    double a, b, c;
    while (input(a, b, c)) std::cout << "Invalid input" << std::endl;
    bool is_solvable;
    Pair root = solve_quadratic_equation(a, b, c, is_solvable);
    if (is_solvable)
        output(root.first, root.second);
    else
        std::cout << "No real root" << std::endl;
}
