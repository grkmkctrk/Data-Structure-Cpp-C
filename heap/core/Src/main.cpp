#include "../Inc/heap.hpp"

int main(){
    
    Heap<int> h(HeapType::MIN_HEAP);

    h.insert(5);

    h.insert(28);
    h.insert(16);
    
    h.insert(37);
    h.insert(29);
    h.insert(28);
    h.insert(34);

    h.insert(42);
    h.insert(41);
    h.insert(63);
    h.insert(29);
    h.insert(72);
    h.insert(67);
    h.insert(70);
    h.insert(71);
    // h.remove();
    // h.remove();


    h.printHeap();


    return 0;
}