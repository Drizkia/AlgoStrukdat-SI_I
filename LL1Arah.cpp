#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

//ini deklarasi apa yang mau dipake
Node *head, *tail, *cur, *del, *newnode; //kepala, buntut, cureent, delete, newnode

// inisiasi awal untuk link list diset kepala dan buntut NULL
void creatlinklist() {
    head = NULL;
    tail = NULL;
}

// Untuk ketika mau menambahkan node di depan
void sisipDepan (int b) {
    newnode = new Node(); // membuat ruang sementara menjadi newnode
    newnode->info = b; // info atau bagian kiri menjadi 5
    newnode->next = NULL; // next node menjadi NULL

    if (head == NULL) {
        head = newnode; // mengubah head menjadi 5
        tail = newnode; // mengubah tail menjadi 5
    } else if(head->info < newnode->info) { // jika newnode lebih besar dari head atau mau urut, dikasih ini
        cout << "Input anda tidak valid" << endl;
    } else {
        newnode->next = head; // Jika head tidak null maka ini berjalan dan isi baru maju ke next
        head = newnode; // kepala menjadi di belakang dan tail didepan
    }
    // ex jika inputan awal 5 dan ketua 6 maka akan menjadi [5][6] (sebelum urut)
    // ex jika inputan awal 5 dan kedua 6 maka akan menjadi [5] (karna 6 tidak valid)
}

void search(int cari) {
    cur = head;
    int posisi = 1;
    bool ditemukan = false;

    while (cur != NULL) {
        if (cur->info == cari) {
            cout << "Nilai " << cari << " ditemukan pada urutan ke-" << posisi << endl;
            ditemukan = true;
            break; // Berhenti jika sudah ketemu
        }
        cur = cur->next;
        posisi++;
    }

    if (!ditemukan) {
        cout << "Nilai " << cari << " tidak ditemukan dalam list." << endl;
    }
}

void update(int lama, int baru) {
    cur = head;
    bool ditemukan = false;

    while (cur != NULL) {
        if (cur->info == lama) {
            cur->info = baru;
            cout << "Nilai " << lama << " berhasil diubah menjadi " << baru << endl;
            ditemukan = true;
            break;
        }
        cur = cur->next;
    }

    if (!ditemukan) {
        cout << "Gagal update: Nilai " << lama << " tidak ditemukan." << endl;
    }
}

void sisipBelakang (int b) {
    newnode = new Node();
    newnode->info = b;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else if(tail->info > newnode->info){
        cout << "Input tidak valid" << endl;
    }else{
        tail->next = newnode;
        tail = newnode;
    }
}

void display() {
    cur = head;
    while (cur != NULL) {
        cout << cur->info << " | ";
        cur = cur->next;
    }
}

void sisipTengah(int b) {
    newnode = new Node();
    newnode->info = b;
    newnode->next = NULL;

    cur = head;
    while (cur->next != NULL && cur->next->info < b) { // cur->next->info itu 5 dari [4][5][10]
        cur = cur->next; 
    }
    
    newnode->next = cur->next;
    cur->next = newnode;
}

void deletDepan() {
    if (head == NULL) {
        cout << "List Masih Kosong" << endl;
    } else {
        cur = head;
        head = head->next;
        delete cur;
    }
    
}

void deletBelakang() {
    if (head == NULL) {
        cout << "List Masih Kosong" << endl;
    } else {
        cur = head;
        while (cur->next != tail) {
            cur = cur->next; // buat ngegeser cur kedepan/next
        }

        delete tail;
        tail = cur; // Cur dijadikan tail (digeser)
        tail->next = NULL; // Tail yang kemarin dijadiin NULL
    }
}

void hapusTengah(int H) {
    cur = head;
    while (cur->next != NULL && cur->next->info != H) {
        cur = cur->next;
    }
    
    if (cur->next == NULL) {
        cout << "Tidak ada nilai " << H << " di dalam data" << endl;
    } else {
        del = cur->next;
        cur->next = del->next;
        if (del == tail) {
            tail = cur;
        }
        delete del;
    }
    
}

int main () {
    creatlinklist();
    sisipDepan(5);                                                          // klo mau masukin sebelum head
    sisipDepan(4);
    // hasil sementara [head][tail] = [4][5]
    sisipBelakang(2);                                                       // kalo mau masukin setelah tail
    sisipBelakang(10);
    // hasilnya 2 tidak valid karna tail info(sekarang) > dari newnode
        display();
    // output 4 | 5 | 10 | (dia berenti karna cur itu udah nul)
    sisipTengah(8);                                                         // kalo mau masukin tengah
    // hasil sementara jadi [4][5][8][10]
        display();

    cout << endl;
    cout << "Setelah di Delete depan" << endl;
    deletDepan();                                                           // kalo mau dihapus depan/head
        display();

    cout << endl;
    cout << "Setelah di Delete belakang" << endl;
    deletBelakang();                                                        // kalo mau dihapus belakang/tail
        display();
    
    cout << endl;
    cout << "Setelah di Delete Tengah" << endl;
    sisipDepan(4);
    sisipBelakang(10);
    hapusTengah(8);                                                         // kalo mau dihapus tengah menurut nilai
        display();


}