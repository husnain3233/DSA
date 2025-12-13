#include <iostream>
#include <climits>
using namespace std;

class HashTable {
private:
    static const int SIZE = 10;

    // ================================
    // Separate Chaining (manual linked list)
    // ================================
    struct Node {
        int key;
        Node* next;
    };

    Node* chainTable[SIZE];

    // ================================
    // Linear Probing Table
    // -1 empty, -2 deleted
    // ================================
    int probeTable[SIZE];

public:

    // ================================
    // Constructor
    // ================================
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            chainTable[i] = nullptr;
            probeTable[i] = -1;
        }
    }

    // ================================
    // Hash function
    // ================================
    int hash1(int key) { return key % SIZE; }

    // ============================================================
    // 1. Separate Chaining
    // ============================================================

    void insertChaining(int key) {
        int idx = hash1(key);
        Node* newNode = new Node{key, nullptr};

        // insert at head of linked list
        newNode->next = chainTable[idx];
        chainTable[idx] = newNode;
    }

    bool searchChaining(int key) {
        int idx = hash1(key);
        Node* temp = chainTable[idx];

        while (temp != nullptr) {
            if (temp->key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void deleteChaining(int key) {
        int idx = hash1(key);
        Node* temp = chainTable[idx];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr)
                    chainTable[idx] = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void displayChaining() {
        cout << "\n=== Separate Chaining ===\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            Node* t = chainTable[i];
            while (t != nullptr) {
                cout << t->key << " -> ";
                t = t->next;
            }
            cout << "NULL\n";
        }
    }

    // ============================================================
    // 2. Linear Probing
    // ============================================================

    void insertLinear(int key) {
        int idx = hash1(key);
        int start = idx;

        while (probeTable[idx] != -1 && probeTable[idx] != -2) {
            idx = (idx + 1) % SIZE;
            if (idx == start) {
                cout << "Table Full (Linear)\n";
                return;
            }
        }
        probeTable[idx] = key;
    }

    bool searchLinear(int key) {
        int idx = hash1(key);
        int start = idx;

        while (probeTable[idx] != -1) {
            if (probeTable[idx] == key) return true;

            idx = (idx + 1) % SIZE;
            if (idx == start) break;
        }
        return false;
    }

    void deleteLinear(int key) {
        int idx = hash1(key);
        int start = idx;

        while (probeTable[idx] != -1) {
            if (probeTable[idx] == key) {
                probeTable[idx] = -2;
                return;
            }
            idx = (idx + 1) % SIZE;
            if (idx == start) break;
        }
    }

    void displayLinear() {
        cout << "\n=== Linear Probing ===\n";
        for (int i = 0; i < SIZE; i++)
            cout << i << ": " << probeTable[i] << "\n";
    }

    // ============================================================
    // Classic Hash Problems (Chaining Only)
    // ============================================================

    int countOccurrencesChaining(int key) {
        int idx = hash1(key);
        int count = 0;

        Node* t = chainTable[idx];
        while (t != nullptr) {
            if (t->key == key) count++;
            t = t->next;
        }
        return count;
    }

    bool hasDuplicateChaining() {
        for (int i = 0; i < SIZE; i++) {
            for (Node* a = chainTable[i]; a != nullptr; a = a->next) {
                for (int j = 0; j < SIZE; j++) {
                    Node* b = chainTable[j];
                    while (b != nullptr) {
                        if (b != a && b->key == a->key)
                            return true;
                        b = b->next;
                    }
                }
            }
        }
        return false;
    }

    int firstUniqueChaining() {
        for (int i = 0; i < SIZE; i++) {
            for (Node* a = chainTable[i]; a != nullptr; a = a->next) {

                bool unique = true;

                for (int j = 0; j < SIZE; j++) {
                    Node* b = chainTable[j];
                    while (b != nullptr) {
                        if (b != a && b->key == a->key)
                            unique = false;
                        b = b->next;
                    }
                }

                if (unique)
                    return a->key;
            }
        }
        return -1;
    }

    int countDistinctChaining() {
        int count = 0;

        for (int i = 0; i < SIZE; i++) {
            for (Node* a = chainTable[i]; a != nullptr; a = a->next) {

                bool foundEarlier = false;

                // check all previous buckets
                for (int j = 0; j < SIZE; j++) {
                    Node* b = chainTable[j];
                    while (b != nullptr) {
                        if (b == a) break;
                        if (b->key == a->key) foundEarlier = true;
                        b = b->next;
                    }
                    if (j == i) break;
                }

                if (!foundEarlier) count++;
            }
        }

        return count;
    }

    int maxChaining() {
        int mx = INT_MIN;
        for (int i = 0; i < SIZE; i++) {
            for (Node* t = chainTable[i]; t != nullptr; t = t->next)
                if (t->key > mx) mx = t->key;
        }
        return mx;
    }

    int minChaining() {
        int mn = INT_MAX;
        for (int i = 0; i < SIZE; i++) {
            for (Node* t = chainTable[i]; t != nullptr; t = t->next)
                if (t->key < mn) mn = t->key;
        }
        return mn;
    }

    int totalChaining() {
        int total = 0;
        for (int i = 0; i < SIZE; i++) {
            Node* t = chainTable[i];
            while (t != nullptr) {
                total++;
                t = t->next;
            }
        }
        return total;
    }

    bool twoSumChaining(int target) {
        for (int i = 0; i < SIZE; i++) {
            for (Node* a = chainTable[i]; a != nullptr; a = a->next) {

                for (int j = 0; j < SIZE; j++) {
                    for (Node* b = chainTable[j]; b != nullptr; b = b->next) {

                        if (a != b && a->key + b->key == target)
                            return true;
                    }
                }
            }
        }
        return false;
    }

    void removeDuplicatesChaining() {

        for (int i = 0; i < SIZE; i++) {
            Node* a = chainTable[i];

            while (a != nullptr) {

                Node* prev = a;
                Node* b = a->next;

                while (b != nullptr) {
                    if (b->key == a->key) {
                        prev->next = b->next;
                        delete b;
                        b = prev->next;
                    }
                    else {
                        prev = b;
                        b = b->next;
                    }
                }

                a = a->next;
            }
        }
    }
};



// ============================================================
// MAIN
// ============================================================
int main() {

    HashTable ht;

    int arr[] = {15, 25, 35, 15, 5, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insert chaining
    for (int i = 0; i < n; i++)
        ht.insertChaining(arr[i]);

    ht.displayChaining();

    cout << "\nCount of 15: " << ht.countOccurrencesChaining(15);
    cout << "\nHas duplicates? " << (ht.hasDuplicateChaining() ? "Yes" : "No");
    cout << "\nFirst unique: " << ht.firstUniqueChaining();
    cout << "\nDistinct count: " << ht.countDistinctChaining();
    cout << "\nMax: " << ht.maxChaining();
    cout << "\nMin: " << ht.minChaining();
    cout << "\nTotal elements: " << ht.totalChaining();
    cout << "\nTwo-sum 30 exists? " << (ht.twoSumChaining(30) ? "Yes" : "No");

    cout << "\n\nAfter removing duplicates:\n";
    ht.removeDuplicatesChaining();
    ht.displayChaining();

    // Linear probing demo
    cout << "\n--- Linear Probing Demo ---\n";
    HashTable h2;
    for (int i = 0; i < n; i++)
        h2.insertLinear(arr[i]);

    h2.displayLinear();

    return 0;
}
