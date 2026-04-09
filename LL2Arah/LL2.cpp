#include <iostream>
using namespace std;

// ===================== DEKLARASI STRUKTUR & VARIABEL GLOBAL =====================

// Mendefinisikan struktur Node untuk doubly linked list
struct Node {
    int info;       // Menyimpan data/nilai dari node
    Node *next;     // Pointer ke node berikutnya (kanan)
    Node *prev;     // Pointer ke node sebelumnya (kiri)
};

Node *head;     // Pointer ke node pertama (paling depan)
Node *tail;     // Pointer ke node terakhir (paling belakang)
Node *newnode;  // Pointer sementara untuk node baru yang akan dibuat
Node *temp;     // Pointer sementara untuk traversal/penelusuran list
Node *del;      // Pointer sementara untuk node yang akan dihapus

// ===================== INISIALISASI LIST =====================

void createlist() {
    head = NULL;    // Set head ke NULL (list kosong)
    tail = NULL;    // Set tail ke NULL (list kosong)
}

// Mengecek apakah list kosong, return true jika head == NULL
bool isempty(){
    return head == NULL;
}

// ===================== FUNGSI INSERT =====================

// Menyisipkan node baru di DEPAN list (nilai harus <= head)
void insertdepan(int IB) {
    newnode = new Node();       // Alokasi memori untuk node baru
    newnode->info = IB;         // Isi data node baru dengan nilai IB
    newnode->next = NULL;       // next node baru awalnya NULL
    newnode->prev = NULL;       // prev node baru awalnya NULL

    if (isempty()) {            // Jika list masih kosong
        head = newnode;         // node baru langsung jadi head
        tail = newnode;         // node baru langsung jadi tail
    } else if (IB > head->info) {   // Jika nilai IB lebih besar dari head (tidak valid untuk insert depan)
        cout << "IB : " << IB << "lebih besar dari head->info " << head->info << endl;  // Tampilkan pesan error
    } else {                            // Jika nilai IB valid (<=head)
        newnode->next = head;           // next node baru menunjuk ke head lama
        head->prev = newnode;           // prev head lama menunjuk ke node baru
        head = newnode;                 // head sekarang berpindah ke node baru
    }
}

// Menyisipkan node baru di TENGAH list secara terurut
void insertmid(int IB) {
    newnode = new Node();       // Alokasi memori untuk node baru
    newnode->info = IB;         // Isi data node baru dengan nilai IB
    newnode->next = NULL;       // next node baru awalnya NULL
    newnode->prev = NULL;       // prev node baru awalnya NULL

    if (isempty()) {            // Jika list masih kosong
        head = newnode;         // node baru langsung jadi head
        tail = newnode;         // node baru langsung jadi tail
    } else {
        temp = head;            // Mulai traversal dari head
        // Terus geser temp selama next-nya ada DAN nilai next < IB (cari posisi yang tepat)
        while (temp->next != NULL && temp->next->info < IB) {
            temp = temp->next;  // Geser temp ke node berikutnya
        }
        newnode->next = temp->next;     // next node baru menunjuk ke node setelah temp
        if (temp->next != NULL) {       // Jika temp bukan node terakhir
            temp->next->prev = newnode; // prev node setelah temp menunjuk ke node baru
        }
        temp->next = newnode;           // next temp menunjuk ke node baru
        newnode->prev = temp;           // prev node baru menunjuk ke temp
    }
}

// Menyisipkan node baru di BELAKANG list (nilai harus >= tail)
void insertbelakang(int IB) {
    newnode = new Node();       // Alokasi memori untuk node baru
    newnode->info = IB;         // Isi data node baru dengan nilai IB
    newnode->next = NULL;       // next node baru awalnya NULL
    newnode->prev = NULL;       // prev node baru awalnya NULL

    if (isempty()) {            // Jika list masih kosong
        head = newnode;         // node baru langsung jadi head
        tail = newnode;         // node baru langsung jadi tail
    } else if (IB < tail->info) {   // Jika nilai IB lebih kecil dari tail (tidak valid untuk insert belakang)
        cout << "IB : " << IB << "lebih kecil dari tail->info " << tail->info << endl;  // Tampilkan pesan error
    } else {                        // Jika nilai IB valid (>=tail)
        newnode->prev = tail;       // prev node baru menunjuk ke tail lama
        tail->next = newnode;       // next tail lama menunjuk ke node baru
        tail = newnode;             // tail sekarang berpindah ke node baru
    }
}

// ===================== FUNGSI DISPLAY =====================

// Menampilkan list dari DEPAN ke BELAKANG (urutan ascending: kecil ke besar)
void displaydepan() {
    if (isempty()) {                    // Jika list kosong
        cout << "Tidak ada list" << endl;   // Tampilkan pesan
    } else {
        temp = head;                    // Mulai dari node head (depan)
        while (temp != NULL) {          // Selama temp masih ada (belum habis)
            cout << temp->info << " ";  // Cetak nilai node saat ini
            temp = temp->next;          // Geser ke node berikutnya
        }
    cout << endl;   // Pindah baris setelah semua node ditampilkan
    }
}

// Menampilkan list dari BELAKANG ke DEPAN (urutan descending: besar ke kecil)
void displaybelakang() {
    if (isempty()) {                    // Jika list kosong
        cout << "Tidak ada list" << endl;   // Tampilkan pesan
    } else {
        temp = tail;                    // Mulai dari node tail (belakang)
        while (temp != NULL) {          // Selama temp masih ada (belum habis)
            cout << temp->info << " ";  // Cetak nilai node saat ini
            temp = temp->prev;          // Geser ke node sebelumnya
        }
    cout << endl;   // Pindah baris setelah semua node ditampilkan
    }
}

// ===================== FUNGSI DELETE =====================

// Menghapus node paling DEPAN (head)
void deletedepan() {
    if (isempty()) {                    // Jika list kosong
        cout << "isi dulu bro" << endl; // Tampilkan pesan error
    } else {
        temp = head;        // Simpan alamat head lama ke temp
        head = head->next;  // Geser head ke node berikutnya
        head->prev = NULL;  // prev head baru di-set NULL (tidak ada node sebelumnya)
        delete temp;        // Bebaskan memori node lama (yang disimpan di temp)
    }
}

// Menghapus node paling BELAKANG (tail)
void deletebelakang() {
    if (isempty()) {                    // Jika list kosong
        cout << "isi dulu bro" << endl; // Tampilkan pesan error
    } else {
        temp = tail;        // (Baris ini tidak efektif, tail tetap sama) — kemungkinan bug
        tail = tail->prev;  // Geser tail ke node sebelumnya
        tail->next = NULL;  // next tail baru di-set NULL (tidak ada node sesudahnya)
        delete temp;        // Hapus node (BUG: seharusnya menyimpan tail lama dulu, bukan pakai temp)
    }
}

// Menghapus node di TENGAH berdasarkan nilai IH yang dicari
void hapustengah(int IH) {
    if (isempty()) {                        // Jika list kosong
        cout << "isi dulu bro" << endl;     // Tampilkan pesan error
    } else if (IH == head->info) {          // Jika nilai yang dicari ada di head
        del = head;                         // Simpan alamat head ke del (untuk dihapus nanti)
        if (head == tail){                  // Jika hanya ada 1 node di list
            head = NULL;                    // Head jadi NULL (list kosong)
            tail = NULL;                    // Tail jadi NULL (list kosong)
        } else {                            // Jika ada lebih dari 1 node
            head = head->next;              // Geser head ke node berikutnya
            head->prev = NULL;              // prev head baru di-set NULL
        }
        delete del;                         // Bebaskan memori node yang dihapus
    } else {                                // Jika nilai bukan di head, cari di tengah/belakang
        temp = head;                        // Mulai traversal dari head
        // Terus geser temp selama belum sampai tail DAN nilai next-nya bukan IH
        while (temp != tail && temp->next->info != IH) {
            temp = temp->next;              // Geser ke node berikutnya
        }
        if (temp != tail && temp->next->info == IH) {   // Jika node dengan nilai IH ditemukan
            del = temp->next;               // Simpan node yang akan dihapus ke del
            if (del == tail) {              // Jika node yang dihapus adalah tail
                tail = temp;               // tail berpindah ke node sebelumnya (temp)
                tail->next = NULL;          // next tail baru di-set NULL
            } else {                        // Jika node yang dihapus berada di tengah
                temp->next = del->next;     // next temp langsung menunjuk ke node setelah del
                del->next->prev = temp;     // prev node setelah del menunjuk balik ke temp
            }
            delete del;                     // Bebaskan memori node yang dihapus
        } else {                            // Jika nilai IH tidak ditemukan di list
            cout << "Node dengan IH : " << IH << "tidak ditemukan" << endl;    // Tampilkan pesan error
        }
    }
}

// ===================== FUNGSI MAIN =====================

int main() {
    createlist();       // Inisialisasi list (head & tail = NULL)

    insertdepan(5);     // Sisipkan 5 di depan  → list: [5]
    insertdepan(4);     // Sisipkan 4 di depan  → list: [4, 5]
    displaybelakang();  // Tampilkan dari belakang → output: 5 4
    displaydepan();     // Tampilkan dari depan   → output: 4 5
    cout << endl;       // Baris kosong pemisah

    insertbelakang(7);  // Sisipkan 7 di belakang → list: [4, 5, 7]
    insertmid(6);       // Sisipkan 6 di tengah   → list: [4, 5, 6, 7]
    displaybelakang();  // Tampilkan dari belakang → output: 7 6 5 4
    displaydepan();     // Tampilkan dari depan   → output: 4 5 6 7
    cout << endl;       // Baris kosong pemisah

    return 0;           // Program selesai, return 0 menandakan sukses
}