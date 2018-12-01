/*************************************************************************
        > File Name: hello.cc
        > Author: Ma Haicheng
        > Mail: hchma@outlook.com
        > Created Time: 2016年07月21日 星期四 23时40分53秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

enum class Sex { MAN, WOMAN, SECRECT };

class Person {
  friend ostream &operator<<(ostream &, const Person &);

 public:
  Person(string name, int age, Sex sex = Sex::SECRECT)
      : m_name(name), m_age(age), m_sex(sex) {}
  virtual ~Person() { cout << m_name << " say bye-bye to you..." << endl; }

 private:
  string m_name;
  int m_age;
  Sex m_sex;
};

ostream &operator<<(ostream &os, const Person &person) {
  os << person.m_name << ", " << person.m_age
     << (person.m_age == 1 ? " year" : " years") << " old "
     << (person.m_sex == Sex::MAN
             ? ", man"
             : (person.m_sex == Sex::WOMAN ? ", woman" : ""));
  return os;
}

int main() {
  cout << "Input your name: ";
  string name;
  getline(cin, name);
  cout << "Welcome to the C++ world, " << name << endl;

  cout << "Now Input your age: ";
  int age = 0;
  cin >> age;

  Sex sex = Sex::SECRECT;
  cout << "Do you want to tell me your sex?[Y/N]:";
  string answer;
  cin >> answer;
  if (answer == "Y" || answer == "y") {
    cout << "Are you a man?[Y/N]:";
    cin >> answer;
    if (answer == "Y" || answer == "y") {
      sex = Sex::MAN;
    } else {
      sex = Sex::WOMAN;
    }
  }

  Person MHC(name, age, sex);

  cout << endl << MHC << endl;
}
