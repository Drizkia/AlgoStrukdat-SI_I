#include <iostream>          // Library untuk input/output (cout, cin)
using namespace std;         // Agar tidak perlu menulis std:: setiap saat

struct Node {                // Mendefinisikan struktur/blueprint untuk setiap node
    int info;                // Bagian data: menyimpan nilai integer
    Node *next;              // Bagian pointer: menunjuk ke node berikutnya
};

// Deklarasi pointer global yang akan digunakan di seluruh program
Node *head;     // Pointer ke node pertama (kepala list)
Node *tail;     // Pointer ke node terakhir (ekor list)
Node *cur;      // Pointer sementara untuk traversal/penelusuran
Node *del;      // Pointer sementara untuk node yang akan dihapus
Node *newnode;  // Pointer untuk node baru yang akan ditambahkan

// Fungsi inisialisasi: menyiapkan linked list kosong
void creatlinklist() {
    head = NULL;    // Head diset NULL karena list masih kosong
    tail = NULL;    // Tail diset NULL karena list masih kosong
}

// Fungsi menambahkan node baru di bagian depan (sebelum head)
void sisipDepan(int b) {
    newnode = new Node();               // Alokasi memori baru untuk node baru
    newnode->info = b;                  // Isi data node baru dengan nilai b
    newnode->next = NULL;               // Next node baru diset NULL dulu

    if (head == NULL) {                 // Kondisi: jika list masih kosong
        head = newnode;                 // Node baru langsung jadi head
        tail = newnode;                 // Node baru juga langsung jadi tail
    } else if (head->info < newnode->info) {    // Kondisi: jika nilai baru lebih besar dari head (melanggar urutan descending)
        cout << "Input anda tidak valid" << endl;   // Tolak karena list harus terurut descending dari depan
    } else {                            // Kondisi: nilai baru valid (lebih kecil/sama dengan head)
        newnode->next = head;           // Next dari node baru diarahkan ke head lama
        head = newnode;                 // Node baru resmi menjadi head yang baru
    }
}

// Fungsi mencari nilai tertentu dalam list dan menampilkan posisinya
void search(int cari) {
    cur = head;             // Mulai penelusuran dari head
    int posisi = 1;         // Pencacah posisi dimulai dari 1
    bool ditemukan = false; // Flag penanda apakah nilai ditemukan

    while (cur != NULL) {               // Terus loop selama belum mencapai akhir list
        if (cur->info == cari) {        // Jika nilai node saat ini sama dengan yang dicari
            cout << "Nilai " << cari << " ditemukan pada urutan ke-" << posisi << endl;  // Tampilkan posisi
            ditemukan = true;           // Tandai bahwa nilai ditemukan
            break;                      // Hentikan loop karena sudah ketemu
        }
        cur = cur->next;    // Geser cur ke node berikutnya
        posisi++;           // Tambah penghitung posisi
    }

    if (!ditemukan) {       // Jika setelah loop nilai tidak ditemukan
        cout << "Nilai " << cari << " tidak ditemukan dalam list." << endl;  // Tampilkan pesan gagal
    }
}

// Fungsi mengubah nilai lama menjadi nilai baru dalam list
void update(int lama, int baru) {
    cur = head;             // Mulai penelusuran dari head
    bool ditemukan = false; // Flag penanda apakah nilai ditemukan

    while (cur != NULL) {               // Terus loop selama belum mencapai akhir list
        if (cur->info == lama) {        // Jika nilai node saat ini sama dengan nilai lama yang dicari
            cur->info = baru;           // Ganti nilai node tersebut dengan nilai baru
            cout << "Nilai " << lama << " berhasil diubah menjadi " << baru << endl;  // Tampilkan konfirmasi
            ditemukan = true;           // Tandai bahwa nilai ditemukan dan diupdate
            break;                      // Hentikan loop
        }
        cur = cur->next;    // Geser cur ke node berikutnya
    }

    if (!ditemukan) {       // Jika nilai lama tidak ditemukan sama sekali
        cout << "Gagal update: Nilai " << lama << " tidak ditemukan." << endl;  // Tampilkan pesan gagal
    }
}

// Fungsi menambahkan node baru di bagian belakang (setelah tail)
void sisipBelakang(int b) {
    newnode = new Node();               // Alokasi memori baru untuk node baru
    newnode->info = b;                  // Isi data node baru dengan nilai b
    newnode->next = NULL;               // Next node baru diset NULL (akan jadi ekor)

    if (head == NULL) {                 // Kondisi: jika list masih kosong
        head = newnode;                 // Node baru langsung jadi head
        tail = newnode;                 // Node baru juga langsung jadi tail
    } else if (tail->info > newnode->info) {    // Kondisi: jika nilai baru lebih kecil dari tail (melanggar urutan ascending)
        cout << "Input tidak valid" << endl;    // Tolak karena list harus terurut ascending dari belakang
    } else {                            // Kondisi: nilai baru valid (lebih besar/sama dengan tail)
        tail->next = newnode;           // Next dari tail lama diarahkan ke node baru
        tail = newnode;                 // Node baru resmi menjadi tail yang baru
    }
}

// Fungsi menampilkan seluruh isi linked list
void display() {
    cur = head;                 // Mulai dari head
    while (cur != NULL) {       // Loop selama cur belum NULL (belum melewati tail)
        cout << cur->info << " | ";  // Tampilkan nilai node saat ini
        cur = cur->next;        // Geser cur ke node berikutnya
    }
}

// Fungsi menyisipkan node baru di posisi tengah sesuai urutan ascending
void sisipTengah(int b) {
    newnode = new Node();       // Alokasi memori baru untuk node baru
    newnode->info = b;          // Isi data node baru dengan nilai b
    newnode->next = NULL;       // Next node baru diset NULL sementara

    cur = head;                                                 // Mulai penelusuran dari head
    while (cur->next != NULL && cur->next->info < b) {         // Cari posisi yang tepat: selama next ada dan nilai next masih lebih kecil dari b
        cur = cur->next;                                        // Geser cur ke node berikutnya
    }
    // Setelah loop: cur berada tepat SEBELUM posisi sisip
    newnode->next = cur->next;  // Next node baru diarahkan ke node yang ada di kanan posisi sisip
    cur->next = newnode;        // Next dari cur diarahkan ke node baru (node baru masuk di tengah)
}

// Fungsi menghapus node di bagian depan (head)
void deletDepan() {
    if (head == NULL) {             // Cek apakah list kosong
        cout << "List Masih Kosong" << endl;    // Tampilkan pesan jika kosong
    } else {
        cur = head;                 // Simpan alamat head lama ke cur
        head = head->next;          // Head baru adalah node kedua
        delete cur;                 // Bebaskan memori head lama
    }
}

// Fungsi menghapus node di bagian belakang (tail)
void deletBelakang() {
    if (head == NULL) {             // Cek apakah list kosong
        cout << "List Masih Kosong" << endl;    // Tampilkan pesan jika kosong
    } else {
        cur = head;                     // Mulai dari head
        while (cur->next != tail) {     // Loop sampai cur berada tepat SEBELUM tail
            cur = cur->next;            // Geser cur ke node berikutnya
        }
        delete tail;        // Bebaskan memori tail lama
        tail = cur;         // Cur (node sebelum tail lama) menjadi tail baru
        tail->next = NULL;  // Next tail baru diset NULL karena sudah jadi ekor
    }
}

// Fungsi menghapus node di tengah berdasarkan nilai tertentu
void hapusTengah(int H) {
    cur = head;                                             // Mulai dari head
    while (cur->next != NULL && cur->next->info != H) {    // Cari posisi: selama next ada dan nilai next belum sama dengan H
        cur = cur->next;                                    // Geser cur ke node berikutnya
    }
    // Setelah loop: cur berada tepat SEBELUM node yang ingin dihapus

    if (cur->next == NULL) {                // Jika next NULL berarti nilai H tidak ditemukan
        cout << "Tidak ada nilai " << H << " di dalam data" << endl;  // Tampilkan pesan gagal
    } else {
        del = cur->next;            // Simpan pointer ke node yang akan dihapus
        cur->next = del->next;      // Hubungkan cur langsung ke node setelah node yang dihapus (skip node del)
        if (del == tail) {          // Cek apakah node yang dihapus adalah tail
            tail = cur;             // Jika iya, perbarui tail menjadi cur
        }
        delete del;                 // Bebaskan memori node yang dihapus
    }
}

int main() {
    creatlinklist();        // Inisialisasi linked list (head & tail = NULL)

    sisipDepan(5);          // Sisip 5 di depan → list: [5]
    sisipDepan(4);          // Sisip 4 di depan → list: [4][5]  (4 < 5, valid)

    sisipBelakang(2);       // Sisip 2 di belakang → INVALID karena 2 < tail(5), ditolak
    sisipBelakang(10);      // Sisip 10 di belakang → list: [4][5][10] (10 > tail(5), valid)
        display();          // Output: 4 | 5 | 10 |

    sisipTengah(8);         // Sisip 8 di tengah → list: [4][5][8][10]
        display();          // Output: 4 | 5 | 8 | 10 |

    cout << endl;
    cout << "Setelah di Delete depan" << endl;
    deletDepan();           // Hapus head (4) → list: [5][8][10]
        display();          // Output: 5 | 8 | 10 |

    cout << endl;
    cout << "Setelah di Delete belakang" << endl;
    deletBelakang();        // Hapus tail (10) → list: [5][8]
        display();          // Output: 5 | 8 |

    cout << endl;
    cout << "Setelah di Delete Tengah" << endl;
    sisipDepan(4);          // Sisip 4 di depan → list: [4][5][8]
    sisipBelakang(10);      // Sisip 10 di belakang → list: [4][5][8][10]
    hapusTengah(8);         // Hapus node bernilai 8 → list: [4][5][10]
        display();          // Output: 4 | 5 | 10 |
}