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

public:
    A()
    {
        x = 1;
        y = 2;
        z = 3;
        cout << __FUNCTION__ << std::endl;
    }

    friend class C;
    friend void print();

    ~A()
    {
        cout << __FUNCTION__ << std::endl;
    }
};

void print()
{
    A a;
    cout << a.z << " " << a.x << "\n";
}

class B : public A
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

//STRUCT
//==========================================================

struct SA 
{
    int x;
public:
    SA()
    {
        x = 1;
    }
};

// VIRTUAL DESTRUCTOR
//============================================================
class VA
{
    int x;
public:
    VA()
    {
        x = 1;
    }

public:
    void fcn()
    {
        cout << "call:" << __FUNCTION__ << std::endl;
    };
    virtual void pvfcn() = 0;
    virtual void vfcn()
    {
        cout << __FUNCTION__ << std::endl;
    };
    virtual void vfcn2()
    {
        cout << __FUNCTION__ << std::endl;
    };
};

class VB : public VA
{
public:
    void pvfcn()
    {
        cout << __FUNCTION__ << std::endl;
    }
    void vfcn()
    {
        cout << __FUNCTION__ << std::endl;
    }
};

struct SB : public SA
{
    void print()
    {
        cout << x << std::endl;
    }
};

void fcn(int &i)
{
    i = 123;
}

int main()
{
    std::cout << "Example application has started\n";

    B b;
    b.y = 4;
    b.print();
    print();

    C c;
    c.print();

    SA sa;
    sa.x = 2;
    SB sb;
    sb.x = 1;
    sb.print();

    cout << "sizeof(VA): " << sizeof(VA) << std::endl;
    VB vb;
    vb.pvfcn();
    vb.vfcn();

    VA* vab = new VB();
    vab->vfcn();

    int x = 1;
    fcn(x);

    A* pa = new A[10];
    delete []pa;

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
