#ifndef __CIRCULARLL_HPP__
#define __CIRCULARLL_HPP__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <math.h>

// Decleration
std::string operator*(std::string const &s, std::size_t n);
void print_list(std::string const &s, std::size_t n);

// Type of the heap
template<class T>
class Hash{
private:
    size_t Size;
    std::list<T> *Table;
public:
    Hash(int size) : Size(size){
        // yes list uses dynamic memory but we create a pointer to a list
        // which means we will use list array to store indexes 
        Table = new std::list<T>[Size];
    }

    ~Hash(){
        delete [] Table;
    }

    T indexing(T const& value);
    void insert(T const& key);
    void remove(T key);
    void print();
};

template<class T>
T Hash<T>::indexing(T const& value){
    // return the index of the value
    return value % Size;
}

template<class T>
void Hash<T>::insert(T const& key){
    // insert the value to the index
    Table[indexing(key)].push_back(key);
}

template<class T>
void Hash<T>::remove(T key){
    // There may be multiple values in the same index
    // so we need check all of them

    // get the index of the value
    int index = indexing(key);

    // to traverse we nee iterator
    typename std::list<T>::iterator it = Table[index].begin();
    for(; it != Table[index].end(); it++){ if(*it == key) break; }

    // if the value is found then remove it
    // we checked end because the end of the list is always nullptr
    if(it != Table[index].end()){ Table[index].erase(it); }
}

template<class T>
void Hash<T>::print(){
    // print the hash table
    for(int i = 0; i < Size; i++){
        std::cout << "(" << i << ") :";
        for(auto it = Table[i].begin(); it != Table[i].end(); it++){
            std::cout << " ("<< *it << ")";
        }
        std::cout << std::endl;
    }
}

#endif
