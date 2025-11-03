
/*String words Reverse
Your task is to implement a function that receives a string and reverses each word in it using stack. You can assume that
the string only consists of alphabets and spaces. The order of the words should remain same but characters within each
word should get reversed.

For example:
String: “Welcome to DSA”
Modified string: “emocleW ot ASD”*/

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
private:
    T *arr;
    int top;
    int capacity;

public:
    int getcapacity() { return capacity; }

    // Default constructor
    Stack()
    {
        arr = nullptr;
        top = 0;
        capacity = 0;
    }

    // Parameterized constructor
    Stack(int c)
    {
        if (c <= 0)
        {
            cout << "Invalid size";
            exit(0);
        }
        capacity = c;
        top = 0;
        arr = new T[capacity];
    }

    // Copy constructor
    Stack(const Stack &ref)
    {
        capacity = ref.capacity;
        top = ref.top;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = ref.arr[i];
        }
    }

    // Check if full
    bool isFull()
    {
        return (top == capacity);
    }

    // Check if empty
    bool isEmpty()
    {
        return (top == 0);
    }

    // Push element
    void push(T a)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            exit(0);
        }
        arr[top++] = a;
    }

    // Pop element
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            exit(0);
        }
        return arr[--top];
    }

    // Assignment operator
    Stack &operator=(const Stack &ref)
    {
        if (this == &ref)
            return *this; // self-assignment check

        delete[] arr; // free old memory

        capacity = ref.capacity;
        top = ref.top;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr[i] = ref.arr[i];
        }

        return *this;
    }

    int getTop()
    {
        return top;
    }

    T getStackTop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            exit(0);
        }
        return arr[top - 1];
    }

    const T &operator[](int index) const
    {
        if (index < 0 || index > top)
        {
            cout << "Index out of bounds!" << endl;
            exit(0);
        }
        return arr[index];
    }
    ~Stack()
    {
        delete[] arr;
    }
};

string reversewords(const string &str)
{
    string s;
    Stack<char> a(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            a.push(str[i]);
        }
        else
        {
            int q = a.getTop();
            for (int i = 0; i < q; i++)
            {
cout<<"ooooo";
                s[i] = a.pop();
                cout << s[i];
            }
        }
    }

    return s;
}

int main()
{

    string a = {"welcome to dsa"};

    reversewords(a);

    return 0;
}