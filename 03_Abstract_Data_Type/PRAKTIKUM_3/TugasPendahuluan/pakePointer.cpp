#include <iostream>
using namespace std;

int main()
{
    int oh = 75;
    int *ptr = &oh;
    cout << "Nilai 'oh' melalui pointer: " << *ptr << endl;
    return 0;
}
