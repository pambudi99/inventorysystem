#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
	vector<vector<string>> items{ { "pedang","5"},{ "panah","4" },{ "tombak","7" } ,{ "senapan","10" } }; //item pool
	vector<vector<string>> inventory; //vector untuk isi inventory
	vector<vector<string>>::iterator iter1; //iterator1 untuk isi inventory
	vector<string>::iterator iter2;//iterator2 untuk isi inventory

	unsigned int maksInventory = 0; //maksimal inventory yang dapat disimpan (user defined)
	long int maksItem = items.size(); //maksimal item adalah jumlah item di item pool
	unsigned int pilihan = 0; //pilihan menu utama Inventory System
	unsigned int itemTerpilih = 0; //untuk menyimpan item terpilih dari item pool
	unsigned int jumlahInventory = 0; //untuk menyimpan jumlah inventory saat ini
	unsigned int hapus = 0; //item nomor berapa yang dihapus
	char lagi = 'y'; //inventory system loop
	unsigned int sisainf = 0;


	cout << "\nsilahkan masukan max kapasitas inventory : ";
	cin >> maksInventory; //input maksimal kapasitas inventory
	cout << endl;
	while (lagi == 'y') { //inventory system loop
		hapus = 0; //selalu inisialisasi hapus dengan 0
				   //menu utama
		cout << "Inventory system : " << endl;
		cout << "1. Tampilkan inventory " << endl;
		cout << "2. Hapus item" << endl;
		cout << "3. Tambah item" << endl;
		cout << "4. Sisa Inventory" << endl;
		cout << "Masukkan pilihan Anda : ";
		cin >> pilihan; //baca pilihan user dari menu utama

		switch (pilihan) {
		case 1: //tampilkan inventory
		{
			//jika kosong
			if (inventory.empty()) {
				cout << "Inventory masih kosong." << endl;
			}
			else {
				//jika ada isinya
				cout << "\nIsi inventory : " << endl;
				for (iter1 = inventory.begin(); iter1 != inventory.end(); ++iter1) {
					for (iter2 = iter1->begin(); iter2 != iter1->end(); iter2++) {
						cout << *iter2 << " ";
					}
					cout << endl;
				}
			}

			break;
		}

		case 2: //hapus item dari inventory
		{
			//jika belum punya item
			if (jumlahInventory <= 0) {
				cout << "Anda belum punya item" << endl;
			}
			else {
				cout << "Hapus item ke - : ";
				cin >> hapus;//input item nomor berapa yang dihapus
							 //jika nomor item yang dihapus tidak ada
				if (hapus > jumlahInventory) {
					cout << "Item yang akan dihapus tidak ada." << endl;
				}
				else {
					//hapus item
					inventory.erase(inventory.begin() + (hapus - 1));
					jumlahInventory--; //kurangi jumlah inventory
					cout << "Jumlah inventory sekarang : " << jumlahInventory << endl; //tampilkan jumlah inventory
				}
			}
			break;
		}

		case 3://tambah item
		{
			//jika isi inventory penuh
			if (jumlahInventory >= maksInventory) {
				cout << "Inventory penuh ! " << endl;
			}
			else {
				//jika masih ada ruang di inventory

				//acak item terpilih dari item pool
				srand((unsigned)time(0));
				itemTerpilih = (rand() % maksItem);

				//tampilkan item yang diambil
				cout << "Anda mendapat : " << items[itemTerpilih][0] << " . Stat : " << items[itemTerpilih][1] << endl;

				//tambahkan item terpilih ke inventory
				inventory.push_back(vector<string>({ items[itemTerpilih][0] }));
				inventory[jumlahInventory].push_back(items[itemTerpilih][1]);
				jumlahInventory++;//tambah jumlah inventory
				cout << "Jumlah inventory sekarang : " << jumlahInventory << endl;//tampilkan jumlah inventory sekarang
			}
			break;
		}
			case 4://melihat sisa inventory
		{
            sisainf=maksInventory-jumlahInventory;
            cout << "inventory tersedia: " << sisainf << endl;
 		}
		}

		cout << "\nMasih ingin menggunakan menu inventory [y/n] ? ";
		cin >> lagi;
		cout << endl;

	} //end of inventory system loop

	cout << "Back to game..." << endl;
	char ch; cin >> ch;
	return 0;
}
