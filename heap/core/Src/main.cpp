#include "../Inc/heap.hpp"

int main(){
    
    Heap<int> h(HeapType::MAX_HEAP);

    h.insert(5);

    return 0;
}