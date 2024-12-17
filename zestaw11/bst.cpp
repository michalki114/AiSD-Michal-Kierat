#include <iostream>
#include <cassert>
#include "bst.h"

// Test 1 - testowanie metody isBST
void test1(){
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);
    assert(tree.isBST());
}

// Test 2 - puste drzewo (zakładam że jest bst)
void test2(){
    BinarySearchTree<int> tree;
    assert(tree.isBST());
}

int main(){
    test1();
    test2();
    std::cout << "Wszystkie testy przeszły pomyślnie!" << std::endl;
    return 0;
}