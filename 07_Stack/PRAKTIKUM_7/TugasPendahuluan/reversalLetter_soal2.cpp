#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

string reverseWord(const string &word)
{
    stack<char> s;
    for (char ch : word)
    {
        s.push(ch);
    }

    string reversedWord;
    while (!s.empty())
    {
        reversedWord += s.top();
        s.pop();
    }
    return reversedWord;
}

int main()
{
    string input;
    cout << "Masukkan Kalimat: ";
    getline(cin, input);

    istringstream iss(input);
    string word, result;
    while (iss >> word)
    {
        result += reverseWord(word) + " ";
    }

    cout << "Hasil: " << result << endl;
    return 0;
}
