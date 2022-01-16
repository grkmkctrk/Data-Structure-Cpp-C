#include "../Inc/queue.hpp"

int main(){

    Queue<int> q1(5);

    // q1.enqueue(1);
    // q1.enqueue(2);
    // q1.enqueue(3);
    // q1.enqueue(4);
    // q1.enqueue(5);
    // q1.print(print_type::PRINT_STRAIGHT);

    // q1.dequeue();
    // q1.dequeue();
    // q1.print(print_type::PRINT_STRAIGHT);
    // q1.reverseQueue();
    // q1.print(print_type::PRINT_STRAIGHT);
    // q1.print(print_type::PRINT_PRETTY);

    // std::cout << "front: " << q1.getFront() <<
    // "\nrear: " << q1.getRear() << 
    // "\nsize: " << q1.getSize() <<
    // "\ncapacity: " << q1.getCapacity() << std::endl;

    // ==

    // q1.enqueue(1);
    // q1.print(print_type::PRINT_PRETTY);
    // q1.enqueue(2);
    // q1.print(print_type::PRINT_PRETTY);
    // q1.enqueue(3);
    // q1.print(print_type::PRINT_PRETTY);
    // q1.enqueue(4);
    // q1.print(print_type::PRINT_PRETTY);
    // q1.enqueue(5);
    // q1.print(print_type::PRINT_PRETTY);

    // q1.dequeue();
    // q1.print(print_type::PRINT_PRETTY);
    // q1.dequeue();
    // q1.print(print_type::PRINT_PRETTY);

    // q1.reverseQueue();
    // q1.print(print_type::PRINT_PRETTY);

    q1.enqueue(21);
    // q1.print(print_type::PRINT_PRETTY);
    q1.enqueue(76);
    // q1.print(print_type::PRINT_PRETTY);
    q1.enqueue(12);
    // q1.print(print_type::PRINT_PRETTY);
    q1.enqueue(45);
    // q1.print(print_type::PRINT_PRETTY);
    q1.enqueue(89);
    q1.print(print_type::PRINT_PRETTY);

    q1.dequeue();
    q1.print(print_type::PRINT_PRETTY);
    q1.dequeue();
    q1.print(print_type::PRINT_PRETTY);


    q1.queueInfo();


    return 0;
}