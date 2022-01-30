#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Bank
{
public:
    Bank();
    void init();
    void deposit();
    void withdraw();
    void disp_det();

private:
    string name;
    int acno;
    string actype;
    float balance;
};