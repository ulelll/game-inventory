#include <iostream>
#include <string>
using namespace std; 

const int MAX_ITEMS = 10;
string namagame = "INVENTORY GAME";

void additem(string inventory[], int &jumlahitem, string itemBaru){
  if(jumlahitem < MAX_ITEMS){
    inventory[jumlahitem] = itemBaru;
    jumlahitem++;
    cout << "Berhasil menambahkan Item : " << itemBaru << endl;
  }else {
    cout << "Inventory penuh " << MAX_ITEMS << " Item." << endl;
  }
}
int main(){
    string inventory[MAX_ITEMS];
    int jumlahitem = 0;
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
         \  \____________/  /
          \________________/

       "SMALL STEPS, BIG ADVENTURES"
    )";
    cout << "Masukan pilihan anda ( 1 - 5 ) : ";
    cin >> pilihan;
    cin.ignore();

switch (pilihan) {
    case 1:
        // Inventory
        break;

    case 2:
        cout << "Masukkan nama item baru: ";
        getline(cin, itemBaru);

        additem(inventory, jumlahitem, itemBaru);
        break;

    case 3:
        // Use Item
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
    } while( pilihan != 5);
return 0; 
}
