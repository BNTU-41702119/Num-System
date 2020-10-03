#include <iostream>
#include <string>
#include <stack>

using namespace std;

char singleDigitPreprocees(int number)
{
    if (number < 10)
    {
        return number + '0';
    }
    else if (number >= 10)
    {
        return 'A' + (number - 10);
    }
}

string decimalTo(int decimal, int base = 16)
{
    int tempDecimal = decimal;
    stack<char> remainders;

    if (tempDecimal == 0)
    {
        return "0";
    }

    while (tempDecimal > 0)
    {
        char rem = singleDigitPreprocees(tempDecimal % base);
        tempDecimal = tempDecimal / base;
        remainders.push(rem);
    }

    string anyBase = "";

    while (!remainders.empty())
    {
        anyBase += remainders.top();
        remainders.pop();
    }

    return anyBase;
}

class Num
{
protected:
    int num;

public:
    Num(int num)
    {
        this->num = num;
    }

public:
    virtual void showNum()
    {
        cout << num << endl;
    }
};

class Outhex : public Num
{
public:
    Outhex(int num) : Num(num) {}

public:
    void showNum()
    {
        cout << decimalTo(Num::num, 16) << endl;
    }
};

class Outoct : public Num
{
public:
    Outoct(int num) : Num(num) {}

public:
    void showNum()
    {
        cout << decimalTo(Num::num, 8) << endl;
    }
};

int main()
{
    Num num = Num(20);
    num.showNum();

    Outhex outhex = Outhex(20);
    outhex.showNum();

    Outoct outoct = Outoct(20);
    outoct.showNum();
}
