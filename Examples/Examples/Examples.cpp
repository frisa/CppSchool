// Examples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class A;
void print();

class A
{
private:
    int x;
public:
    int y;
protected:
    int z;

    A()
    {
        x = 1;
        y = 2;
        z = 3;
    }

    friend class C;
    friend void print();
};

void print()
{
    A a;
    cout << a.z << " " << a.x << "\n";
}

class B : A
{
public:
    void print(void) const
    {
        cout << this->y << this->z;
    }
};

class C
{
    int x;

public:
    C()
    {
        x = 4;
    }

public:
    void print()
    {
        A a;
        cout << x << a.x << "\n";
    }
};

int main()
{
    std::cout << "Example application has started\n";

    B b;
    b.print();
    print();

    C c;
    c.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
