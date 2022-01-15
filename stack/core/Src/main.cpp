#include "../Inc/stack.hpp"

int main(){

    stack<int> s;

    // s.push(1);
    // s.print();

    // s.push(2);
    // s.print();

    // s.push(3);
    // s.print();


    // s.pop();
    // s.print();

    // s.pop();
    // s.print();


    s.push(13);
    s.print();
    s.push(42);
    s.print();
    s.push(99);
    s.print();
    s.push(34);
    s.print();
    s.push(12);
    s.print();
    s.push(5);
    s.print();
    s.push(22);
    s.print();

    std::cout << "top element of the stack : " << s.peek() << std::endl;

    return 0;
}