#include<iostream>
#include<string>

using namespace std;

string gewei[10] = {"", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    int num;
    while (cin >> num)
    {
        if (num >= 1000)
            continue;

        string result;
        if (num < 100)
        {
            if (num < 20)
            {
                if (num == 0)
                {
                    cout << "ling" << endl;
                    break;
                }
                if (num < 10) // 0 < num < 10
                {
                    cout << gewei[num] << endl;
                    break;
                }
                else    // 10 <= num < 20
                {
                    result += "shi";
                    result += gewei[num%10];
                    cout << result << endl;
                    break;
                }
            }
            else    // 20 <= num < 100
            {
                int shi = num / 10;
                int ge = num % 10;
                result += gewei[shi] + "shi" + gewei[ge];

                cout << result << endl;
                break;
            }
        }
        else
        {
            int bai = num / 100;
            int shi = (num % 100) / 10;
            int ge = num % 10;

            result += gewei[bai] + "bai";

            if (shi == 0 && ge == 0)
            {
                cout << result << endl;
                break;
            }

            if (shi == 0 && ge != 0)
            {
                result += "ling";
                result += gewei[ge];
                cout << result << endl;
                break;
            }
            else
            {
                result += gewei[shi] + "shi";
                result += gewei[ge];
                cout << result << endl;
                break;
            }
        }
    }
}

