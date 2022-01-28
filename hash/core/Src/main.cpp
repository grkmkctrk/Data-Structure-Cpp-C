#include "../Inc/hash.hpp"

int main(){
    
    // create a hash table with size 10
    Hash<int> hash(10);

    // insert some values
    hash.insert(21);
    hash.insert(31);
    hash.insert(52);
    hash.insert(27);
    hash.insert(87);
    hash.insert(21);
    hash.insert(40);


    // print the hash table
    hash.print();

    

    return 0;
}