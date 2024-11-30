#include <iostream>
#include <queue>
#include <limits>
using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;

void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

Pohon *cariNode(Pohon *node, char data)
{
    if (!node)
        return NULL;
    if (node->data == data)
        return node;

    Pohon *found = cariNode(node->left, data);
    if (found)
        return found;

    return cariNode(node->right, data);
}

Pohon *insertLeft(char data, Pohon *parent)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
        return NULL;
    }
    if (!parent)
    {
        cout << "\nParent tidak ditemukan." << endl;
        return NULL;
    }
    if (parent->left != NULL)
    {
        cout << "\nNode " << parent->data << " sudah ada child kiri." << endl;
        return NULL;
    }
    Pohon *baru = new Pohon{data, NULL, NULL, parent};
    parent->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << parent->data << endl;
    return baru;
}

Pohon *insertRight(char data, Pohon *parent)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
        return NULL;
    }
    if (!parent)
    {
        cout << "\nParent tidak ditemukan." << endl;
        return NULL;
    }
    if (parent->right != NULL)
    {
        cout << "\nNode " << parent->data << " sudah ada child kanan." << endl;
        return NULL;
    }
    Pohon *baru = new Pohon{data, NULL, NULL, parent};
    parent->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << parent->data << endl;
    return baru;
}

void tampilkanAnak(Pohon *node)
{
    if (!node)
    {
        cout << "\nNode tidak ditemukan" << endl;
        return;
    }
    cout << "\nAnak-anak dari node " << node->data << ": ";
    if (node->left)
        cout << "Kiri: " << node->left->data << " ";
    else
        cout << "Kiri: (tidak ada) ";
    if (node->right)
        cout << "Kanan: " << node->right->data << " ";
    else
        cout << "Kanan: (tidak ada) ";
    cout << endl;
}

void tampilkanDescendant(Pohon *node)
{
    if (!node)
        return;
    if (node->left)
    {
        cout << node->left->data << " ";
        tampilkanDescendant(node->left);
    }
    if (node->right)
    {
        cout << node->right->data << " ";
        tampilkanDescendant(node->right);
    }
}

bool is_valid_bst(Pohon *node, char min_val, char max_val)
{
    if (!node)
        return true;
    if (node->data <= min_val || node->data >= max_val)
        return false;
    return is_valid_bst(node->left, min_val, node->data) && is_valid_bst(node->right, node->data, max_val);
}

int cari_simpul_daun(Pohon *node)
{
    if (!node)
        return 0;
    if (!node->left && !node->right)
        return 1;
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
        return;
    }
    if (!node)
    {
        cout << "\nNode yang ingin diganti tidak ada." << endl;
        return;
    }
    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

void menu()
{
    int pilihan;
    char data, parentData;
    do
    {
        cout << "\nMenu: \n1. Buat Node Root\n2. Tambah Node Kiri\n3. Tambah Node Kanan";
        cout << "\n4. Tampilkan Anak\n5. Tampilkan Descendant";
        cout << "\n6. Tampilkan Anak (spesifik)\n7. Tampilkan Descendant (spesifik)";
        cout << "\n8. Cek Valid BST\n9. Hitung Jumlah Daun\n0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan data root: ";
            cin >> data;
            buatNode(data);
            break;
        case 2:
            cout << "Masukkan data parent: ";
            cin >> parentData;
            cout << "Masukkan data node kiri: ";
            cin >> data;
            insertLeft(data, cariNode(root, parentData));
            break;
        case 3:
            cout << "Masukkan data parent: ";
            cin >> parentData;
            cout << "Masukkan data node kanan: ";
            cin >> data;
            insertRight(data, cariNode(root, parentData));
            break;
        case 4:
            cout << "Masukkan data node: ";
            cin >> data;
            tampilkanAnak(cariNode(root, data));
            break;
        case 5:
            cout << "Masukkan data node: ";
            cin >> data;
            cout << "\nDescendant dari node " << data << ": ";
            tampilkanDescendant(cariNode(root, data));
            cout << endl;
            break;
        case 6:
            cout << "Masukkan data node: ";
            cin >> data;
            tampilkanAnak(cariNode(root, data));
            break;
        case 7:
            cout << "Masukkan data node: ";
            cin >> data;
            cout << "\nDescendant dari node " << data << ": ";
            tampilkanDescendant(cariNode(root, data));
            cout << endl;
            break;
        case 8:
            cout << "\nApakah pohon ini BST? ";
            cout << (is_valid_bst(root, CHAR_MIN, CHAR_MAX) ? "Ya" : "Tidak") << endl;
            break;
        case 9:
            cout << "\nJumlah simpul daun: " << cari_simpul_daun(root) << endl;
            break;
        case 0:
            cout << "Keluar." << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
}

int main()
{
    init();
    menu();
    return 0;
}