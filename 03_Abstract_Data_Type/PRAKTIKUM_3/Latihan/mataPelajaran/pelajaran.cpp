#include "pelajaran.h"
#include <iostream>

// Implementasi fungsi create_pelajaran
pelajaran create_pelajaran(std::string namaMapel, std::string kodeMapel)
{
    pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
}

// Implementasi fungsi tampil_pelajaran
void tampil_pelajaran(pelajaran pel)
{
    std::cout << "Nama Pelajaran: " << pel.namaMapel << std::endl;
    std::cout << "Kode Pelajaran: " << pel.kodeMapel << std::endl;
}
