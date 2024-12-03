#include <iostream>
#include <cassert>
#include <utility>

template <typename T>
class MyQueue {
    T* tab;
    std::size_t msize; 
    std::size_t head;  
    std::size_t tail;  

public:
    // Konstruktor domyślny
    MyQueue(std::size_t s = 10) : msize(s + 1), head(0), tail(0) {
        tab = new T[msize];
        assert(tab != nullptr);
    }

    // Destruktor
    ~MyQueue() { delete[] tab; }

    // Konstruktor kopiujący
    MyQueue(const MyQueue& other) : msize(other.msize), head(other.head), tail(other.tail) {
        tab = new T[msize];
        assert(tab != nullptr);
        for (std::size_t i = 0; i < msize; ++i) {
            tab[i] = other.tab[i];
        }
    }

    // Konstruktor przenoszący
    MyQueue(MyQueue&& other) noexcept : tab(other.tab), msize(other.msize), head(other.head), tail(other.tail) {
        other.tab = nullptr;
        other.msize = 1;
        other.head = other.tail = 0;
    }

    // Operator przypisania kopiujący
    MyQueue& operator=(const MyQueue& other) {
        if (this != &other) {
            delete[] tab;

            msize = other.msize;
            head = other.head;
            tail = other.tail;
            tab = new T[msize];
            assert(tab != nullptr);

            for (std::size_t i = 0; i < msize; ++i) {
                tab[i] = other.tab[i];
            }
        }
        return *this;
    }

    // Operator przypisania przenoszący
    MyQueue& operator=(MyQueue&& other) noexcept {
        if (this != &other) {
            delete[] tab;

            tab = other.tab;
            msize = other.msize;
            head = other.head;
            tail = other.tail;

            other.tab = nullptr;
            other.msize = 1;
            other.head = other.tail = 0;
        }
        return *this;
    }

    // Sprawdzenie, czy kolejka jest pusta
    bool empty() const { return head == tail; }

    // Sprawdzenie, czy kolejka jest pełna
    bool full() const { return (head + msize - 1) % msize == tail; }

    // Rozmiar aktualnej kolejki
    std::size_t size() const { return (tail - head + msize) % msize; }

    // Maksymalny rozmiar kolejki
    std::size_t max_size() const { return msize - 1; }

    // Dodanie elementu na koniec (kopiowanie)
    void push(const T& item) {
        if (full()) {
            throw std::overflow_error("Kolejka jest pełna");
        }
        tab[tail] = item;
        tail = (tail + 1) % msize;
    }

    // Dodanie elementu na koniec (przenoszenie)
    void push(T&& item) {
        if (full()) {
            throw std::overflow_error("Queue is full");
        }
        tab[tail] = std::move(item);
        tail = (tail + 1) % msize;
    }

    // Zwraca pierwszy element w kolejce
    T& front() {
        if (empty()) {
            throw std::underflow_error("Kolejka jest pusta");
        }
        return tab[head];
    }

    // Zwraca ostatni element w kolejce
    T& back() {
        if (empty()) {
            throw std::underflow_error("Kolejka jest pusta");
        }
        return tab[(tail + msize - 1) % msize];
    }

    // Usuwa pierwszy element w kolejce
    void pop() {
        if (empty()) {
            throw std::underflow_error("Kolejka jest pusta");
        }
        head = (head + 1) % msize;
    }

    // Czyszczenie kolejki
    void clear() {
        head = 0;
        tail = 0;
    }

    // Wyświetlanie elementów w kolejce
    void display() {
        if (empty()) {
            std::cout << "Kolejka jest pełna\n";
            return;
        }
        std::cout << "Elementy kolejki: ";
        for (std::size_t i = head; i != tail; i = (i + 1) % msize) {
            std::cout << tab[i] << " ";
        }
        std::cout << "\n";
    }
};
