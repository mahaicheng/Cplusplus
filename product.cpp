#include<iostream>
#include<string>

using namespace std;

int product(int n)
{
    int result = 0;
    while(n > 0)
    {
        int tmp = n % 10;
        result += tmp * tmp;
        n /= 10;
    }

    if(result < 0)  //overflow
        return -1;
    else
        return result;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n < 0)   //invalid input, try again
            continue;

        while(n > 0 && n != 1)
        {
            n = product(n);
        }

        if(n < 0)   //overflow
            cout << "False" << endl;
        else
            cout << "True" << endl;
    }
}

