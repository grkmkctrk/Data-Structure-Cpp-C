#include "../Inc/stack.hpp"

int main(){

    // stack<int> s;

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


    // s.push(13);
    // s.print();
    // s.push(42);
    // s.print();
    // s.push(99);
    // s.print();
    // s.push(34);
    // s.print();
    // s.push(12);
    // s.print();
    // s.push(5);
    // s.print();
    // s.push(22);
    // s.print();

    // std::cout << "top element of the stack : " << s.peek() << std::endl;


    // // pushing elements to the stack
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // std::cout << "pushing to stack" << std::endl;
    // s.print();

    // std::cout << "top element of the stack : " << s.peek() << std::endl;

    // // if reverse it peek() will return 4
    // std::cout << "reversing stack" << std::endl;
    // s.reverse();
    // std::cout << "top element of the stack : " << s.peek() << std::endl;
    // std::cout << '\n';

    // stack<char> s2;

    // s2.push('h');
    // s2.push('e');
    // s2.push('l');
    // s2.push('l');
    // s2.push('o');

    // s2.print();
    // s2.reverse();
    // s2.print();


    // s.push(63);
    // s.push(42);
    // s.push(99);
    // s.push(34);
    // s.push(12);

    // s.print();
    // s.prettyPrint();
    // s.pop();
    // s.prettyPrint();

    // // std::cout << 
    // // "next greater element of nth element : " 
    // // << s.getNGE(4) << std::endl;

    // s.push(3);
    // s.push(4);
    // s.push(1);
    // s.push(6);
    // s.push(2);

    // s.print();
    // s.sort();
    // s.print();

    // after size capacity implementation

    stack<int> s(5);
    s.push(1);
    s.push(2);
    
    
    s.print();
    std::cout << 
    "Remined space : " << 
    s.getSpace() << std::endl;

    // std::cout <<
    // "is stack full : " << 
    // s.isFull() << std::endl;

    return 0;
}