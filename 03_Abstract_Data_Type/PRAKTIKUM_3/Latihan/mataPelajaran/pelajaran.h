#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string> // Jangan lupa untuk menyertakan string

struct pelajaran
{
    std::string namaMapel;
    std::string kodeMapel;
};

// Deklarasi fungsi
pelajaran create_pelajaran(std::string namaMapel, std::string kodeMapel);
void tampil_pelajaran(pelajaran pel);

#endif
