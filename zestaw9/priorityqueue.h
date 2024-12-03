#include <vector>
#include <algorithm> 
#include <iostream>  

template <typename T>
class MyPriorityQueue {
    std::vector<T> lst;
public:
    // Konstruktor z rezerwacją miejsca
    MyPriorityQueue(std::size_t s = 10) { lst.reserve(s); }
    
    // Destruktor
    ~MyPriorityQueue() { lst.clear(); }
    
    // Konstruktor kopiujący
    MyPriorityQueue(const MyPriorityQueue& other) : lst(other.lst) {}
    
    // Konstruktor przenoszący
    MyPriorityQueue(MyPriorityQueue&& other) noexcept : lst(std::move(other.lst)) {}
    
    // Operator przypisania kopiującego
    MyPriorityQueue& operator=(const MyPriorityQueue& other) {
        if (this != &other) {
            lst = other.lst;
        }
        return *this;
    }
    
    // Operator przypisania przenoszącego
    MyPriorityQueue& operator=(MyPriorityQueue&& other) noexcept {
        if (this != &other) {
            lst = std::move(other.lst);
        }
        return *this;
    }
    
    // Sprawdzenie, czy kolejka jest pusta
    bool empty() const { return lst.empty(); }
    
    // Rozmiar kolejki
    std::size_t size() const { return lst.size(); }
    
    // Dodanie elementu do kolejki (kopiowanie)
    void push(const T& item) {
        lst.push_back(item);
        std::push_heap(lst.begin(), lst.end());
    }
    
    // Dodanie elementu do kolejki (przenoszenie)
    void push(T&& item) {
        lst.push_back(std::move(item));
        std::push_heap(lst.begin(), lst.end());
    }
    
    // Zwrócenie największego elementu
    T& top() { return lst.front(); }
    
    // Usunięcie największego elementu
    void pop() {
        std::pop_heap(lst.begin(), lst.end());
        lst.pop_back();
    }
    
    // Czyszczenie kolejki
    void clear() { lst.clear(); }
    
    // Wyświetlenie kolejki
    void display() {
        for (const auto& elem : lst) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
};
