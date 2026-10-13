#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> barang = {
    {"Gula", 5000},
    {"Teh", 6000},
    {"Kopi", 7000},
    {"MSG", 3000},
    {"Lenovo Legon 5 16 Ultra 9", 29000000},
};

void input_barang(const std::string& item, int harga){
    barang.insert({item, harga});
}

void list_barang(){
    int number = 1;
    for(const auto& [key, value] : barang){
        std::cout << number << ". " << key << " : " << value << '\n';
        number++;
    }
}

void hitung_total(){
    std::cout << "Masukkan nama-nama item yang ingin ditotal lalu input angka 2 untuk menjumlahkan harga.\n";
    bool inputting = true;

    std::string item;

    std::vector<int> totalHarga;

    while(inputting == true){
        std::cout << "Masukkan nama item : ";
        std::cin >> item;
        if(item == "2"){
            inputting = false;
            break;
        }
        auto it = barang.find(item);
        if(it != barang.end()){
            totalHarga.push_back(barang.find(item)->second);
        }
        else{
            std::cout << "Item tidak ditemukan!";
        }
    }

    if(totalHarga.empty()){
        std::cout << "Masukkan setidaknya 1 item.";
        return;
    }

    int sum = 0;
    for(int num : totalHarga){
        sum += num;
    }

    std::cout << "Total harga : " << sum << "\n";
}

void hapus_barang(std::string item){
    auto it = barang.find(item);
    if(it != barang.end()){
        barang.erase(it);
        std::cout << "Item berhasil dihapus.\n";
    }
    else{
        std::cout << "Item tidak ditemukan.\n";
    }
}

int main(){
    std::cout << "===== ============== =====\n";
    std::cout << "===== APLIKASI KASIR =====\n";
    std::cout << "===== ============== =====\n";

    int option;

    std::cout << "===== ============== =====\n";
    std::cout << "Pilih aksi : \n";
    std::cout << "1. Input Barang \n";
    std::cout << "2. Hitung Total Harga \n";
    std::cout << "3. List Barang \n";
    std::cout << "4. Hapus Barang \n";
    std::cout << "5. Keluar \n";
    std::cout << "===== ============== =====\n";

    while(option != 5){

        std::cout << "Masukkan Input Menu : ";
        std::cin >> option;
        std::cin.ignore();

        if (option == 1){
            std::string item;
            int harga;
            std::cout << "Masukkan Nama Item : ";
            std::getline(std::cin, item);
            std::cout << "Masukkan Harga Item : ";
            std::cin >> harga;
            input_barang(item, harga);
        }
        if (option == 2){
            hitung_total();
        }
        if (option == 3){
            list_barang();
        }
        if (option == 4){
            std::string item;
            std::cout << "Masukkan nama item yang ingin dihapus : ";
            std::cin >> item;

            hapus_barang(item);
        }
    }

    return 0;
}