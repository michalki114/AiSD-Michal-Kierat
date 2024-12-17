// Zadanie 10.5

#include <cassert>
#include <stack>
#include <cstdlib> // std::rand(), std::srand()

// Węzeł drzewa binarnego
template <typename T>
struct BSTNode {
    T value;
    BSTNode *left, *right;
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    BSTNode(const T& item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode() { delete left; delete right; }
};

// Drzewo binarne
template <typename T>
class RandomBinaryTree {
    BSTNode<T> *root;

public:
    RandomBinaryTree() : root(nullptr) {}
    ~RandomBinaryTree() { delete root; }

    void clear() { delete root; root = nullptr; }
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; }

    // Publiczne metody obliczania liczby węzłów
    int calc_nodes_recursive() const {
        return calc_nodes_recursive(root);
    }
    int calc_nodes_iterative() const {
        return calc_nodes_iterative(root);
    }

    // Wstawianie elementów
    void insert(const T& item) {
        root = insert(root, item);
    }

private:
    // Rekurencyjne obliczanie liczby węzłów
    int calc_nodes_recursive(BSTNode<T>* node) const {
        if (node == nullptr) return 0;
        return 1 + calc_nodes_recursive(node->left) + calc_nodes_recursive(node->right);
    }
    //Iteracyjne obliczanie liczby węzłów
    int calc_nodes_iterative(BSTNode<T>* node) const {
        if (node == nullptr) return 0;

        std::stack<BSTNode<T>*> stack;
        stack.push(node);
        int count = 0;

        while (!stack.empty()) {
            BSTNode<T> *current = stack.top();
            stack.pop();
            ++count;

            if (current->left) stack.push(current->left);
            if (current->right) stack.push(current->right);
        }
        return count;
    }

    // Losowe wstawianie elementów
    BSTNode<T>* insert(BSTNode<T>* node, const T& item) {
        if (node == nullptr) {
            return new BSTNode<T>(item);
        }
        if (std::rand() % 2) { 
            node->left = insert(node->left, item);
        } else {
            node->right = insert(node->right, item);
        }
        return node; 
    }
};


