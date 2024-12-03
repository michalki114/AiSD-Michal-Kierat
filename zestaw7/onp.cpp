//Zadanie 7.1

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>
#include <cstdlib>
#include <cassert>

int rpn(const std::vector<std::string>& input) {
    std::stack<int> S;

    for (const auto& item : input) {
        if (item == "+" || item == "-" || item == "*" || item == "/") {
            
            if (S.size() < 2) {
                throw std::invalid_argument("Niepoprawnie wyrażone działanie w ONP");
            }

            // Pobranie dwóch liczb
            int a = S.top(); 
            S.pop();
            int b = S.top(); 
            S.pop();

            // Wykonanie operacji
            if (item == "+") {
                S.push(b + a);
            } else if (item == "-") {
                S.push(b - a);
            } else if (item == "*") {
                S.push(b * a);
            } else if (item == "/") {
                if (a == 0) {
                    throw std::invalid_argument("Dzielenie przez zero");
                }
                S.push(b / a);
            }
        } else {
            // item jest liczbą
            try {
                int number = std::stoi(item);
                S.push(number);
            } catch (const std::invalid_argument&) {
                throw std::invalid_argument("Niedozwolony znak");
            }
        }
    }

    // Musi być jedna liczba na stosie
    if (S.size() != 1) {
        throw std::invalid_argument("Niepoprawne wyrażenie w ONP");
    }

    return S.top();
}

void test1() {
    std::vector<std::string> input = { "2", "3", "+", "6", "*" }; // (2 + 3) * 6 = 30
    assert(rpn(input) == 30);
}

void test2() {
    std::vector<std::string> input = { "6", "2", "/" }; // 6/2  = 3
    assert(rpn(input) == 3);
}

void test3() {
    std::vector<std::string> input = { "5", "1", "2", "+", "4", "*", "+", "3", "-" };  // 5 + ((1 + 2) * 4) - 3 = 14
     assert(rpn(input) == 14);
}

void test4() {
    std::vector<std::string> input = { "3", "4", "+", "2", "*", "7", "/" }; // ((3+4)*2)/7 = 2
    assert(rpn(input) == 2);
}

void test5() {
    try {
        std::vector<std::string> input = { "4", "0", "/" }; // Dzielenie przez 0
        rpn(input);
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Dzielenie przez zero");
    }
}

void test6() {
    try {
        std::vector<std::string> input = {"3", "&" , "4" }; // Niedozwolony znak
        rpn(input);
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Niedozwolony znak");
    }
}

void test7() {
    try {
        std::vector<std::string> input = {"3", "9" , "4" ,"5" ,"+"}; // Pozostanie więcej niż jedna liczba na stosie
        rpn(input);
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(std::string(e.what()) == "Niepoprawne wyrażenie w ONP");
}
}

int main() {
    
    test1();
    test2();
    test3();
    test4();
    test5();   
    test6();
    test7();
        
    std::cout << "Wszystkie testy wykonane pomyślnie" << std::endl;
    

    return 0;
}
