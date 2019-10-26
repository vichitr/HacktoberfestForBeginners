#include <iostream>

using namespace std;

class DynamicArray {
    
    private:
        int capacity, used;
        int* data;
        void resize(int new_capacity);
    public:
        static const int DEFAULT_CAPACITY = 1;
        DynamicArray(int initial_capacity = DEFAULT_CAPACITY);
        DynamicArray(const DynamicArray& src);
        ~DynamicArray();
        DynamicArray& operator=(const DynamicArray& rhs);
        int size() const;
        bool empty() const;
        void add(int anInt);
        void remove(int anInt);
        void print(ostream& out) const;
};

void DynamicArray::resize(int new_capacity)
{
    if (new_capacity < used)
        new_capacity = used;
    if (new_capacity < 1)
        new_capacity = 1;
    int* temp = new int[new_capacity];
    for(int x = 0; x < used; ++x)
    {
        temp[x] = data[x];
    }
    delete[] data;
    data = temp;
    capacity = new_capacity;
}

DynamicArray::DynamicArray(int initial_capacity) : capacity(initial_capacity), used(0)
{   
    if (initial_capacity < 1)
        initial_capacity = DEFAULT_CAPACITY;
    data = new int[initial_capacity];
}

DynamicArray::~DynamicArray() { delete[] data; }

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs)
{
    if (this != &rhs)
    {
        int* newData = new int[rhs.capacity];
        for (int x = 0; x < rhs.used; ++x)
            newData[x] = rhs.data[x];
        delete [] data;
        data = newData;
        capacity = rhs.capacity;
        used = rhs.used;
    }
    return *this;
}

int DynamicArray::size() const { return used; }

bool DynamicArray::empty() const { return used == 0; }

void DynamicArray::add(int anInt)
{
    if (used+1 > capacity)
        resize(1.5 * capacity + 1);
    data[used] = anInt;
    ++used;
}

void DynamicArray::remove(int anInt)
{
    int x = 0;
    while(data[x] != anInt)
        ++x;
    for(int y = x; y < used-1; ++y)
        data[y] = data[y + 1];
    --used;
}

void DynamicArray::print(ostream& out) const
{
    if (used > 0)
    {
        out << data[0];
        for (int x = 1; x < used; ++x)
            out << "  " << data[x];
    }
}

int main() 
{ 
    DynamicArray test; 
    test.add(10); 
    test.add(20); 
    test.add(30);

    cout << "\ntest.size() : " << test.size(); 
    cout << "\ntest.empty() : " << (test.empty() ? "true" : "false");
  
    cout << "\nThe dynamic array test is : "; 
    test.print(cout);
    test.remove(10);
    cout << "\nThe dynamic array test is : "; 
    test.print(cout);
    test.remove(30);
    cout << "\nThe dynamic array test is : "; 
    test.print(cout);
    test.remove(20);
    cout << "\ntest.size() : " << test.size(); 
    cout << "\ntest.empty() : " << (test.empty() ? "true" : "false"); 
    return 0;
}