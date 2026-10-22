#include <iostream>
using namespace std;

class MyVector {
private:
    int* arr;
    int capacity;
    int current_size;

    void resize() {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        int* temp = new int[capacity];

        for (int i = 0; i < current_size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr; // Free old heap memory
        arr = temp;
    }

public:
    MyVector() {
        arr = nullptr;
        capacity = 0;
        current_size = 0;
    }

    ~MyVector() {
        delete[] arr; // Destructor frees memory when object goes out of scope
    }

    void push_back(int val) {
        if (current_size == capacity) {
            resize();
        }
        arr[current_size++] = val;
    }

    void pop_back() {
        if (current_size > 0) {
            current_size--;
        }
    }

    int size() const {
        return current_size;
    }

    int get_capacity() const {
        return capacity;
    }

    int& operator[](int index) {
        return arr[index];
    }
};

int main() {
    MyVector v;

    v.push_back(5);
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

    cout << "Size: " << v.size() << ", Capacity: " << v.get_capacity() << endl;

    return 0;
}