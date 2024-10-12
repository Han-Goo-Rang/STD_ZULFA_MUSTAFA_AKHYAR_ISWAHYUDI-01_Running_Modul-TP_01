#include <iostream>
#include <math.h>
using namespace std;

class Kerucut
{
private:
    float jari;
    float t;

public:
    Kerucut(float r, float t) : jari(r), t(t) {}

    float hitungVolume()
    {
        return (3.14 * jari * jari * t) / 3;
    }

    float hitungLuasPermukaan()
    {
        float s = sqrt((jari * jari) + (t * t));
        return 3.14 * jari * (jari + s);
    }
};

int main()
{
    Kerucut kerucut1(10, 8);
    cout << "Volumenya : " << kerucut1.hitungVolume() << endl;
    cout << "Luas permukaannya : " << kerucut1.hitungLuasPermukaan() << endl;
    return 0;
}
