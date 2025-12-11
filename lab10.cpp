#include <iostream>
#include <string>
using namespace std;

class HashTable{
private: 
string* table; 
int S; // Table size 
int n; // Current number of elements 
public: 
HashTable(int size){
S=size;
n=0;
table=new string [S];
for(int i=0;i<S;i++){

table[i]="0";

}}
~HashTable()

{
    delete [] table;
}


bool isEmpty(){

return n==0;

}  
bool isFull(){

    return n==S;
}    
double loadFactor()
{double load =n/S;
    return load;}

int getHashValue(string name){
int a=0;
int size=name.size();
for(int i=0;i<size;i++){
char c=name[i];
a+=(int)c;


}

return a%S;

} 


 bool insert(string name) {
        if (isFull()) {
            cout << "Table is FULL. Cannot insert.\n";
            return false;
        }

        int index = getHashValue(name);
        cout << "Probing sequence: ";

        if(table[index] == "0"){

            table[index]=name;
        };

        for (int i = 0; i < S; i++) {
            int newIndex = (index + i) % S;
            cout << newIndex << " ";

            if (table[newIndex] == "0"|| table[newIndex]=="#") {
                table[newIndex] = name;
                n++;
                cout << "\nInserted at index " << newIndex << endl;
                return true;
            }
        }

        cout << "\nNO EMPTY SLOT FOUND.\n";
        return false;
    }

 bool search(string name) {
        int index = getHashValue(name);
        cout << "Probing sequence: ";

        for (int i = 0; i < S; i++) {
            int newIndex = (index + i) % S;
            cout << newIndex << " ";

            if (table[newIndex] == "0") {
                cout << " NOT FOUND.\n";
                return false;
            }

            if (table[newIndex] == name) {
                cout << "\nFOUND at index " << newIndex << endl;
                return true;
            }
        }

        cout << "\nName NOT FOUND.\n";
        return false;
    }

    
    bool remove(string name) {
        int index = getHashValue(name);

        for (int i = 0; i < S; i++) {
            int newIndex = (index + i) % S;

            if (table[newIndex] == "0") {
                return false; 
            }

            if (table[newIndex] == name) {
                table[newIndex] = "#";
                n--;
                return true;
            }
        }
        return false;
    }

   
    void display() {
        cout << "\n----- Hash Table -----\n";
        for (int i = 0; i < S; i++) {
            cout << i << ": ";
            if (table[i] == "0")
                cout << "EMPTY";
            else if (table[i] == "#")
                cout << "DELETED";
            else
                cout << table[i];
            cout << endl;
        }
        cout << "----------------------\n";
    }
};



int main (){

    int size;
    cout << "Enter the size of Hash Table: ";
    cin >> size;

    HashTable ht(size);

    while (true) {
        cout << "\n1. Insert a name\n";
        cout << "2. Search for a name\n";
        cout << "3. Remove a name\n";
        cout << "4. Display the Hash Table\n";
        cout << "5. Display Load Factor of the table\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        string name;

        switch (choice) {
        case 1:
            cout << "Enter name to insert: ";
            cin >> name;
            ht.insert(name);
            break;

        case 2:
            cout << "Enter name to search: ";
            cin >> name;
            ht.search(name);
            break;

        case 3:
            cout << "Enter name to remove: ";
            cin >> name;
            if (ht.remove(name))
                cout << "Name removed successfully.\n";
            else
                cout << "Name NOT found.\n";
            break;

        case 4:
            ht.display();
            break;

        case 5:
            cout << "Load Factor = " << ht.loadFactor() << endl;
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }







    return 0;
}