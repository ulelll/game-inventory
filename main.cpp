
#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 10;
string namagame = "INVENTORY GAME";

void additem(string inventory[], int &jumlahItem, string itemBaru) {
    if (jumlahItem < MAX_ITEMS) {
        inventory[jumlahItem] = itemBaru;
        jumlahItem++;
        cout << "Berhasil menambahkan item: " << itemBaru << endl;
    } else {
        cout << "Inventory penuh! Maksimal "
             << MAX_ITEMS << " item." << endl;
    }
}

int main() {
    string inventory[MAX_ITEMS];
    int jumlahItem = 0;
    string itemBaru;
    int pilihan;

    do {
        cout << R"(
              .       *        .        *
         *  \   |   /
          '.  .---.  .'
        --   (     )   --
          .'  '---'  '.
            /   |   \
       /\                   /\
      /  \       /\        /  \
     /    \     /  \  /\  /    \
    /      \   /    \/  \/      \
   /   /\   \ /      \   \  /\   \
  /___/__\___V________\___\/__\___\

              ||  ||  ||
           ___||__||__||___
          /                 \
         /   .-""""""""-.    \
        |   /  INVENTORY  \   |
        |  |  GAME MENU    |  |
        |  |---------------|  |
        |  | 1. Inventory  |  |
        |  | 2. Add Item   |  |
        |  | 3. Use Item   |  |
        |  | 4. Search     |  |
        |  | 5. Exit       |  |
        \  \_______________/ /
         \__________________/

       "SMALL STEPS, BIG ADVENTURES"
    )";

        cout << "Masukkan pilihan Anda (1 - 5): ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (jumlahItem == 0) {
                    cout << "Inventory kosong." << endl;
                } else {
                    cout << "\n=== INVENTORY ===" << endl;

                    for (int i = 0; i < jumlahItem; i++) {
                        cout << i + 1 << ". "
                             << inventory[i] << endl;
                    }

                    cout << "Kapasitas inventory: "
                         << jumlahItem << "/" << MAX_ITEMS
                         << endl;
                }
                break;

            case 2:
                cout << "Masukkan nama item baru: ";
                getline(cin, itemBaru);
                additem(inventory, jumlahItem, itemBaru);
                break;

            case 3:
                if (jumlahItem == 0) {
                    cout << "Inventory kosong. "
                         << "Tidak ada item untuk digunakan."
                         << endl;
                    break;
                }

                cout << "\n=== PILIH ITEM ===" << endl;

                for (int i = 0; i < jumlahItem; i++) {
                    cout << i + 1 << ". "
                         << inventory[i] << endl;
                }

                int nomorItem;
                cout << "Masukkan nomor item yang ingin digunakan: ";
                cin >> nomorItem;
                cin.ignore();

                if (nomorItem >= 1 && nomorItem <= jumlahItem) {
                    cout << "Item " << inventory[nomorItem - 1]
                         << " berhasil digunakan!" << endl;

                    for (int i = nomorItem - 1;
                         i < jumlahItem - 1; i++) {
                        inventory[i] = inventory[i + 1];
                    }

                    jumlahItem--;
                } else {
                    cout << "Nomor item tidak valid." << endl;
                }
                break;

            case 4:
                // Cari item
                break;

            case 5:
                cout << "Keluar dari game..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 5);

    return 0;
}
