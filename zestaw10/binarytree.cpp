#include "binarytree.h"
#include <iostream>
#include <cassert>

//Test 1 - drzewo puste
void test1() {
    RandomBinaryTree<int> tree;
    assert(tree.calc_nodes_recursive() == 0); 
    assert(tree.calc_nodes_iterative() == 0); 
}

//Test 2 - jeden element
void test2() {
    RandomBinaryTree<int> tree;
    tree.insert(10);
    assert(tree.calc_nodes_recursive() == 1); 
    assert(tree.calc_nodes_iterative() == 1); 
}

//Test 3 - kilka elementów
void test3() {
    RandomBinaryTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    assert(tree.calc_nodes_recursive() == 5); 
    assert(tree.calc_nodes_iterative() == 5); 
}

//Test 4 - kilka elementów
void test4() {
    RandomBinaryTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    assert(tree.calc_nodes_recursive() == 7); 
    assert(tree.calc_nodes_iterative() == 7); 
}

int main() {
    test1();
    test2();
    test3();
    test4();

    std::cout << "Wszystkie testy przeszły pomyślnie!" << std::endl;
    return 0;
}
