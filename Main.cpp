#include <iostream>
#include <string>

using namespace std;

// Deklarasi kelas Buku
class Buku {
public:
    string judul, pengarang;
    int tahunTerbit;

    Buku* next;

    // Constructor
    Buku(const string& judul, const string& pengarang, int tahunTerbit)
        : judul(judul), pengarang(pengarang), tahunTerbit(tahunTerbit), next(nullptr) {}
};

// Deklarasi kelas LinkedList
class LinkedList {
private:
    Buku* head;
    Buku* tail;

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Method untuk membuat linked list
    void createSingleLinkedList(const string& judul, const string& pengarang, int tahunTerbit) {
        head = new Buku(judul, pengarang, tahunTerbit);
        tail = head;
    }

    // Method untuk menambahkan node di awal linked list
    void addFirst(const string& judul, const string& pengarang, int tahunTerbit) {
        Buku* newNode = new Buku(judul, pengarang, tahunTerbit);
        newNode->next = head;
        head = newNode;
    }

    // Method untuk menambahkan node di akhir linked list
    void addLast(const string& judul, const string& pengarang, int tahunTerbit) {
        Buku* newNode = new Buku(judul, pengarang, tahunTerbit);
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }

    // Method untuk menghapus node di awal linked list
    void removeFirst() {
        if (head == nullptr) {
            return; // List is already empty
        }

        Buku* del = head;
        head = head->next;
        delete del;
    }

    // Method untuk menghapus node di akhir linked list
    void removeLast() {
        if (head == nullptr) {
            return; // List is already empty
        }

        Buku* del = tail;
        Buku* cur = head;

        while (cur->next != tail) {
            cur = cur->next;
        }

        tail = cur;
        tail->next = nullptr;
        delete del;
    }

    // Method untuk mengubah data pada node pertama linked list
    void changeFirst(const string& judul, const string& pengarang, int tahunTerbit) {
        if (head != nullptr) {
            head->judul = judul;
            head->pengarang = pengarang;
            head->tahunTerbit = tahunTerbit;
        }
    }

    // Method untuk menampilkan linked list
    void printSingleLinkedList() const {
        Buku* cur = head;
        while (cur != nullptr) {
            cout << "Judul Buku : " << cur->judul << endl;
            cout << "Pengarang Buku : " << cur->pengarang << endl;
            cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

            cur = cur->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    linkedList.createSingleLinkedList("Kata", "Geez & Aan", 2018);
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    linkedList.addFirst("Dia adalah Kakakku", "Tere Liye", 2009);
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    linkedList.addLast("Aroma Karsa", "Dee Lestari", 2018);
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    linkedList.removeFirst();
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    linkedList.addLast("11.11", "Fiersa Besari", 2018);
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    linkedList.removeLast();
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    linkedList.changeFirst("Berhenti di Kamu", "Gia Pratama", 2018);
    linkedList.printSingleLinkedList();

    cout << "\n\n" << endl;

    return 0;
}
