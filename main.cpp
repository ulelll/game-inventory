#include <iostream> 
using namespace std; 

const int MAX_ITEMS = 10;
string namagame = "INVENTORY GAME";

void additem(string inventory[], int &jumlahItem, string itemBaru){
  if (jumlahItem < MAX_ITEMS) {
    inventory[jumlahItem] = itemBaru;
    jumlahItem++;
    cout << "Berhasil menambahkan item: " << itemBaru << endl;
  } else {
    cout << "Inventory penuh! Maksimal " << MAX_ITEMS << " item." << endl;
  }
}
int main(){

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

return 0; 
}
