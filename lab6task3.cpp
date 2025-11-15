#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node() { data = 0; next = nullptr; }
    Node(T val) { data = val; next = nullptr; }
};

template <class T>
class LSLL {
private:
    Node<T>* head;

public:
    LSLL() { head = nullptr; }

    // ---------- INSERT FUNCTIONS ----------
    void insertAtHead(T val) {
        Node<T>* t = new Node<T>(val);
        t->next = head;
        head = t;
    }

    void insertAtTail(T val) {
        Node<T>* t = new Node<T>(val);
        if (!head) { head = t; return; }
        Node<T>* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = t;
    }

    void insertBefore(T key, T val) {
        if (!head) return;

        Node<T>* t = new Node<T>(val);

        if (head->data == key) {
            t->next = head;
            head = t;
            return;
        }

        Node<T>* temp = head->next;
        Node<T>* prev = head;

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Key not found\n";
            delete t;
            return;
        }

        t->next = temp;
        prev->next = t;
    }

    void insertAfter(T key, T val) {
        Node<T>* temp = head;
        while (temp != nullptr && temp->data != key)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Key not found\n";
            return;
        }

        Node<T>* t = new Node<T>(val);
        t->next = temp->next;
        temp->next = t;
    }

    // ---------- DELETE FUNCTIONS ----------
    void removeAtHead() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void removeAtTail() {
        if (!head) return;
        if (head->next == nullptr) { delete head; head = nullptr; return; }

        Node<T>* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void remove(T val) {
        if (!head) return;

        if (head->data == val) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* prev = head;
        Node<T>* curr = head->next;

        while (curr != nullptr) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Value not found in list.\n";
    }

    void removeBefore(T val) {
        if (!head || !head->next) return;

        if (head->next->data == val) {
            Node<T>* del = head;
            head = head->next;
            delete del;
            return;
        }

        Node<T>* bef1 = head;
        Node<T>* bef = head->next;
        Node<T>* temp = head->next->next;

        while (temp != nullptr) {
            if (temp->data == val) {
                bef1->next = temp;
                delete bef;
                return;
            }

            bef1 = bef;
            bef = temp;
            temp = temp->next;
        }

        cout << "Value not found\n";
    }

    void removeAfter(T val) {
        Node<T>* temp = head;

        while (temp != nullptr) {
            if (temp->data == val) {
                if (temp->next == nullptr) {
                    cout << "No node after the given value.\n";
                    return;
                }

                Node<T>* del = temp->next;
                temp->next = del->next;
                delete del;
                return;
            }
            temp = temp->next;
        }

        cout << "Value not found.\n";
    }

    // ---------- UTILITY FUNCTIONS ----------
    int search(T key) {
        if (!head) {
            cout << "Empty linked list\n";
            return -1;
        }

        Node<T>* temp = head;
        int i = 1;

        while (temp != nullptr) {
            if (temp->data == key) return i;
            temp = temp->next;
            i++;
        }
        return -1;
    }

    void update(T key, T val) {
        if (!head) return;

        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                temp->data = val;
                cout << "Value updated\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found\n";
    }

    int countNodes() {
        if (!head) return 0;
        int i = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            i++;
            temp = temp->next;
        }
        return i;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // ---------- DESTRUCTOR ----------
    ~LSLL() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }


void reverse() {
    if (!head || !head->next) {
        // list empty or has only one node
        return;
    }

    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse pointer
        prev = curr;         // move prev forward
        curr = next;         // move curr forward
    }

    head = prev;  // new head is the previous tail
    cout << "List reversed successfully\n";
}
void sort() {
    if (!head || !head->next)
        return; // empty or single-node list

    Node<T>* temp = head;
    Node<T>* aft = nullptr;

    while (temp != nullptr) {
        aft = temp->next;
        while (aft != nullptr) {
            if (temp->data > aft->data) {
                // swap data
                T val = temp->data;
                temp->data = aft->data;
                aft->data = val;
            }
            aft = aft->next; // move aft forward
        }
        temp = temp->next; // move temp forward
    }

    cout << "List sorted successfully\n";
}


T midval() {
    if (!head)
        return T(); // return default value for empty list

    int a = countNodes();
    Node<T>* temp = head;
    int i = 0;

    // For lists of size 1 or 2
    if (a == 1 || a == 2) {
        return temp->data;
    }

    // Move to middle node
    while (i < a / 2) {
        temp = temp->next;
        i++;
    }

    return temp->data;
}

void shufflemerge(LSLL&list1,LSLL&list2){

Node<T>*head1=list1.head;
Node<T>*head2=list2.head;
while(head1!=nullptr || head2!=nullptr){

if(head1!=nullptr){
    this->head->next=head1;
    head1=head1->next;
}
if(head2!=nullptr){
   this-> head->next=head2;
   head2=head2->next;
}
head=head->next;




}


    
}
    
};

int main()
{
LSLL<int> list1;
list1.insertAtHead(10);
list1.insertAtTail(20);

list1.display();
LSLL<int>list2;
list2.insertAtHead(8);
list2.insertAtTail(9);
list2.display();
LSLL<int>list3;
list3.shufflemerge(list1,list2);
list3.display();
list1.display();
list2.display();

return 0;
}