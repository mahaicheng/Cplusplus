#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void reverseStr(string &);
void reverseChar(string &);

    string trans(string s) {
        if(s.empty())
            return string();

        reverseStr(s);
        reverseChar(s);

        return s;
    }
    void reverseStr(string &str){
        if(str.empty())
            return;

        reverse(str.begin(), str.end());

        int start = 0;
        int end = 0;
        while(start != string::npos){
            start = str.find_first_not_of(' ', start);
            end = str.find_first_of(' ', start);

            if(start == string::npos)
                break;
            if(end == string::npos){
                reverse(next(str.begin(), start), str.end());
                break;
            }
            else{
                reverse(next(str.begin(), start), next(str.begin(), end));
                start = end + 1;
            }
        }
    }
    void reverseChar(string &str){
        if(str.empty())
            return;

        for(int i = 0; i < str.size(); ++i){
            auto c = str[i];
            if(c >= 'a' && c <= 'z')
                str[i] = toupper(c);
            else if(c >= 'A' && c <= 'Z')
                str[i] = tolower(c);
        }
    }

int main()
{
    string str("Hello World");
    cout << trans(str) << endl;
}
