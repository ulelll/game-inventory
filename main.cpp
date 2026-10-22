
#include <iostream>
#include <string>
#include <limits>

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

bool waitNext() {
    char choiceContinue; 

    cout << "\n================================\n"; 
    cout << "1. Kembali ke menu utama\n"; 
    cout << "2. keluar dari game\n";
    cout << "pilihan kamu: ";

    cin >> choiceContinue; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    while (choiceContinue != '1' && choiceContinue != '2'){
        cout << "pilihan tidak valid!, masukkan 1 atau 2: "; 
        cin >> choiceContinue; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (choiceContinue == '1') {
        cout << "tekan Enter untuk kembali ke menu...."; 
        cin.get();
        return true; 
    }
        return false; 
        
}

int main() {
    string inventory[MAX_ITEMS];
    int jumlahItem = 0;
    string itemBaru;
    int pilihan;

    bool lanjut = true; 

    do {
        cout << R"(

.------..------..------..------..------.
|H.--. ||E.--. ||L.--. ||L.--. ||O.--. |
| :/\: || (\/) || :/\: || :/\: || :/\: |
| (__) || :\/: || (__) || (__) || :\/: |
| '--'H|| '--'E|| '--'L|| '--'L|| '--'O|
 `------'`------'`------'`------'`------'
            _______________
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
        \  \_______________/  /
         \__________________ /

 "=========== Poker Dungeons ============"
    )";

        cout << "Masukkan pilihan Anda (1 - 5): ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
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
                 if (jumlahItem == 0) {
                    cout << "Inventory kosong. Tidak ada item untuk dicari." << endl;
                } else {
                    string katakunci;
                    cout << "Masukkan kata kunci untuk mencari item: ";
                    getline(cin, katakunci);

                    bool ditemukan = false;
                    cout << "\n=== HASIL PENCARIAN ===" << endl;
                    for (int i = 0; i < jumlahItem; i++) {
                        if (inventory[i].find(katakunci) != string::npos) {
                            cout << i + 1 << ". " << inventory[i] << endl;
                            ditemukan = true;
                        }
                    }
                    if (!ditemukan) {
                        cout << "Item tidak ditemukan dalam inventory." << endl;
                    }
                }
                break;

            case 5:
                cout << "Keluar dari game..." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

    if (pilihan != 5){
        lanjut = waitNext(); 
    }
    } while (pilihan != 5 && lanjut);

    cout << R"(
 ________  _______   _______               
|\   ____\|\  ___ \ |\  ___ \              
\ \  \___|\ \   __/|\ \   __/|             
 \ \_____  \ \  \_|/_\ \  \_|/__           
  \|____|\  \ \  \_|\ \ \  \_|\ \          
    ____\_\  \ \_______\ \_______\         
   |\_________\|_______|\|_______|         
   \|_________|                            
                                           
                                           
  ___    ___ ________  ___  ___  ___       
 |\  \  /  /|\   __  \|\  \|\  \|\  \      
 \ \  \/  / | \  \|\  \ \  \\\  \ \  \     
  \ \    / / \ \  \\\  \ \  \\\  \ \  \    
   \/  /  /   \ \  \\\  \ \  \\\  \ \__\   
 __/  / /      \ \_______\ \_______\|__|   
|\___/ /        \|_______|\|_______|   ___ 
\|___|/                               |\__\
                                      \|__|
    
    )"; 

    return 0;
}
