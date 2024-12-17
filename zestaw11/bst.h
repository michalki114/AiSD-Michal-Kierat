//Zadanie 11.4

template <typename T>
struct BSTNode {
    T value;
    BSTNode *left, *right;
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    BSTNode(const T& item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode() { delete left; delete right; }
};

template <typename T>
class BinarySearchTree {
    BSTNode<T> *root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() { delete root; }

    void clear() { delete root; root = nullptr; }
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; }

    void insert(const T& item) { root = insert(root, item); }
    bool isBST() const { return isBST(root, nullptr, nullptr); }

private:
    // Wstawianie elementów tak aby drzewo było BST
    BSTNode<T>* insert(BSTNode<T> *node, const T& item) {
        if (node == nullptr) {
            return new BSTNode<T>(item);
        }
        if (item < node->value) {
            node->left = insert(node->left, item);
        } else if (item > node->value) {
            node->right = insert(node->right, item);
        }
        return node;
    }

    // Rekurencyjne sprawdzenie czy drzewo jest BST
    bool isBST(BSTNode<T> *node, const T* minValue, const T* maxValue) const {
        if (node == nullptr) return true;

        // Sprawdzanie ograniczeń względem wartości rodziców
        if ((minValue != nullptr && node->value <= *minValue) ||
            (maxValue != nullptr && node->value >= *maxValue)) {
            return false;
        }

        return isBST(node->left, minValue, &(node->value)) &&
               isBST(node->right, &(node->value), maxValue);
    }

};