#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(const string &str)
{
    stack<char> s;
    for (char ch : str)
    {
        s.push(ch);
    }

    string reversedStr;
    while (!s.empty())
    {
        reversedStr += s.top();
        s.pop();
    }

    return str == reversedStr;
}

int main()
{
    string input;
    cout << "Masukkan Kalimat: ";
    cin >> input;

    if (isPalindrome(input))
    {
        cout << "Palindrom" << endl;
    }
    else
    {
        cout << "Bukan Palindrom" << endl;
    }

    return 0;
}
