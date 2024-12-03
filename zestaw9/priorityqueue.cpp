#include <cassert>
#include <iostream>
#include "priorityqueue.h"


// Test 1 - dodawanie i sprawdzanie największego elementu
void test1() {
    MyPriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(15);
    assert(pq.top() == 20);
    assert(pq.size() == 3);
}

// Test 2 - usuwanie elementów
void test2() {
    MyPriorityQueue<int> pq;
    pq.push(5);
    pq.push(25);
    pq.push(10);
    pq.pop();
    assert(pq.top() == 10);
    assert(pq.size() == 2);
}

// Test 3 - sprawdzenie, czy kopiec jest pusty
void test3() {
    MyPriorityQueue<int> pq;
    assert(pq.empty());
    pq.push(42);
    assert(!pq.empty());
    pq.pop(); 
    assert(pq.empty());
}

// Test 4 - większa ilość elementów
void test4() {
    MyPriorityQueue<int> pq(20);
    for (int i = 0; i < 10; ++i) {
        pq.push(i);
    }
    assert(pq.size() == 10);
    assert(pq.top() == 9); 
    pq.display(); 
}
// Test 5 - przenoszenie
void test5() {
    MyPriorityQueue<int> pq1;
    pq1.push(100);
    pq1.push(200);

    MyPriorityQueue<int> pq2 = std::move(pq1); 
    assert(pq1.empty()); 
    assert(pq2.size() == 2); 
    assert(pq2.top() == 200); 
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    std::cout << "Wszystkie testy zaliczone" << std::endl;
    return 0;
}
