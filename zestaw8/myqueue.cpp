#include <cassert>
#include <string>
#include "myqueue.h"

// Test 1 - dodawanie elementów do kolejki
void test1() {
    MyQueue<int> q(5); 
    assert(q.empty());
    q.push(10);
    q.push(20);
    q.push(30);
    assert(!q.empty());
    assert(q.size() == 3);
}

// Test 2 - usuwanie elementów z kolejki
void test2() {
    MyQueue<int> q(3); 
    q.push(1);
    q.push(2);
    q.push(3);
    assert(q.full());
    q.pop();
    assert(!q.full());
    assert(q.size() == 2);
    assert(q.front() == 2);
}

// Test 3 - front i back
void test3() {
    MyQueue<std::string> q(4);
    q.push("A");
    q.push("B");
    q.push("C");
    assert(q.front() == "A");
    assert(q.back() == "C");
    q.pop();
    assert(q.front() == "B");
    q.push("D");
    assert(q.back() == "D");
}

// Test 4 - obsługa błędów
void test4() {
    MyQueue<int> q(2);
    assert(q.empty());
    try {
        q.front(); 
        assert(false);
    } catch (const std::underflow_error&) {
        // Wyjątek
    }
    try {
        q.pop(); 
        assert(false);
    } catch (const std::underflow_error&) {
        // Wyjątek
    }
}

// Test 5 - konstruktory
void test5() {
    MyQueue<int> q1(4);
    q1.push(1);
    q1.push(2);
    q1.push(3);

    // Konstruktor kopiujący
    MyQueue<int> q2(q1);
    assert(q2.size() == 3);
    assert(q2.front() == 1);
    assert(q2.back() == 3);

    // Konstruktor przenoszący
    MyQueue<int> q3(std::move(q1));
    assert(q3.size() == 3);
    assert(q3.front() == 1);
    assert(q3.back() == 3);
    assert(q1.size() == 0); // Przeniesiony obiekt powinien być pusty
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
