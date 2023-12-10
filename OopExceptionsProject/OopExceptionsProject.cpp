#include <iostream>

class Exc
{

};

double Div(double x, double y)
{
    if (y == 0.0)
        throw -1;
    return x / y;
}

void Func(float x)
{
    if (x < 0)
        throw "negative!";
}

void func3()
{
    std::cout << "f3 start\n";

    try
    {
        throw 0;
    }
    catch (int e)
    {
        std::cout << "Error: " << e << "\n";
        throw;
    }

    std::cout << "f3 finish\n";
}

void func2()
{
    std::cout << "f2 start\n";
    
    try
    {
        func3();
    }
    catch (int e)
    {
        std::cout << "Error: " << e << "\n";
    }
    

    std::cout << "f2 finish\n";
}

void func1()
{
    std::cout << "f1 start\n";
    func2();
    std::cout << "f1 finish\n";
}


int main()
{

    try
    {
        //std::cout << Div(10, 0);
        Func(-5);
    }
    catch (int e)
    {
        if (e == -1)
            std::cout << "Divide by zero!\n";
    }
    catch (const char* e)
    {
        std::cout << "Error: " << e << "\n";
    }
    catch (...)
    {
        // for all types exceptions
    }
    
    func1();


    std::cout << "Prog run...\n";
}
