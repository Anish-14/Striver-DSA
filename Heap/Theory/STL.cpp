#include <iostream>
#include <queue>
using namespace std;

// Heaps are binary trees only with some rules to it. They are also said to be complete binary tree.
// all levels should be filled except the last level and nodes will always be filled from left to right at a level.
// heap array me bnai jaati hai.

// MAX HEAP
// parent node's value is always bigger than the child nodes.

// MIN HEAP
// parent node's value is always smaller than the child nodes.

// Max Heap implementation.
// Some properties of heap.
// index of parent of a child node is = index/2
// index of left child of a parent is = 2*i
// index of right child of a parent is = 2*i + 1

class heap{
public:
    int arr[100]; // array me 1 base indexing se value fill karenge so 0th index will be empty.
    int size;

    heap(){
        size = 0;
        arr[0] = -1;
    }

    void insert(int val){
        size = size + 1;
        arr[size] = val; // last me val ko put kar do, insert at end
        int index = size;

        while (index > 1){ // root node tak pahoche to bahr aa jaana loop se because root node tak pahoch gya means that is the biggest element in head
            int parent = index / 2; // parent node store so that we can compare with it.

            if (arr[parent] < arr[index]){ // element ko sahi jagah pahochao.
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        if (size == 0){
            return;
        }
        int i = 1;
        while (i <= size){
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }

    void deleteFromHeap(){   // we always delete the root node.
        if (size == 0){
            cout << "nothing to delete " << endl;
        }

        arr[1] = arr[size]; // root node me last element daal diya. Made a copy of last node in root node.
        size--;             // last element ko hata diya.

        int i = 1; // apna last element jo ki root per baitha hai usko sahi jagah lekar jaa rhe hai.
        while (i < size){
            int leftIndex = 2 * i; // accessing child Nodes.
            int rightIndex = 2 * i + 1;

            // condn 1.
            // left child node hona chahiye and uski value badi honi chahiye parent node se and
            // agar right node hai aur uski value bhi badi hai parent node se then max(leftValue,RightValue) ko parent node se swap kar denge.
            if (leftIndex <= size && arr[i] < arr[leftIndex]){
                if (rightIndex <= size && arr[i] < arr[rightIndex]){
                    if (arr[leftIndex] < arr[rightIndex]){
                        swap(arr[i], arr[rightIndex]);
                        i = rightIndex; // ab swap kar diya hai to uske liye jaake check karo ki shi jagaah pahucha hai ya nhi
                    }
                    else{
                        swap(arr[i], arr[leftIndex]);
                        i = leftIndex;
                    }
                }
                else{ // agar right child hai hi nhi || right child ki value chhoti hai to ye hoga.
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
            }

            // condn 2
            // yaha tabhi pahochenge jab (left child does not exist || left child's value is smaller than parent)
            // so direct right ke liye check maaro and swap if true.
            else if (rightIndex <= size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else{
                return; // agar uper me se kuchh bhi nhi hai matlab hum sahi jagah per hai.
            }
        }
    }
};

// heapify ek normal array ko heap me convert kar deta hai
// leaf node index in heap/CBT is from (n/2+1 se lekar n) tak hota hai.
// heapify function non leaf nodes ko unki sahi jagah pahocha deta hai because leaf node to khudme valid heap hai hi.
// logn me kaam karta hai, normal wala 'n' me karta hai.

void heapify(int arr[], int n, int i){ // array, its size ,index jisko shi jagah pahuchana hai
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // check karo ki heap hai ya nhi.
    if (left <= n && arr[largest] < arr[left]){
        if (right <= n && arr[largest] < arr[right]){
            if (arr[left] > arr[right]){
                largest = left;
            }
            else{
                largest = right;
            }
        }
        else{
            largest = left;
        }
    }
    else if (right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    // check ki largest change hua ya nhi, agar change hua hai then we need to update it.
    if (largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); // jiske saath bhi swap kiya ab apna root node waha pahoch gya hai (left ya right me) so we need to check ki vo right ya left bhi heap ho therefore largest index ko heap bnne bhej diya.
    }
}

// algo
// root node is largest so usko swap kar do so that vo last me chala jaaye, size ko ghata do taaki that largest value lock ho jaaye.
// jo node 1st node per hai usko sahi jagah le jaao
// n.logn is time complexity of heapsort algo.
void heapsort(int arr[], int n){
    int size = n;
    while (size > 1){
        // step 1: swap
        swap(arr[size], arr[1]);
        size--;

        // step 2: call heapify
        heapify(arr, size, 1);
    }
}

int main()
{
    heap h1;

    h1.insert(50); // insertion code is perfect.
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);

    h1.print();

    h1.deleteFromHeap(); // our deletion code is working perfectly.
    h1.print();
    h1.deleteFromHeap();
    h1.print();
    h1.deleteFromHeap();
    h1.print();
    h1.deleteFromHeap();
    h1.print();
    h1.deleteFromHeap();
    h1.print();
    h1.deleteFromHeap();
    h1.print();

    cout << "anish heapify start " << endl;
    // imlementing heapify algo.
    int arr[6] = {-1, 52, 55, 54, 56, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    // printing the array
    cout << "printing the array" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // heapsort function.
    heapsort(arr, n);

    cout << "printing the array" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
