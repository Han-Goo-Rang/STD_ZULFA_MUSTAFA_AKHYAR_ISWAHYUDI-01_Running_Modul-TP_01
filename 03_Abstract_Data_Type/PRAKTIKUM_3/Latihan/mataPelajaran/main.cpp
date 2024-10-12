#include "pelajaran.h" // Include header pelajaran
#include <iostream>

int main()
{
    std::string namapel = "Struktur Data";
    std::string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel); // Panggil create_pelajaran
    tampil_pelajaran(pel);                              // Panggil tampil_pelajaran

    return 0;
}
