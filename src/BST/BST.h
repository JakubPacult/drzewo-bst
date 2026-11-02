#ifndef BST_H
#define BST_H

#include "../Node/Node.h"
#include <vector>
#include <string>

class BST {
private:
    Node* root;

    // Metody pomocnicze (rekurencyjne)
    Node* insertRecursive(Node* current, int value);
    Node* removeRecursive(Node* current, int value);
    Node* findMin(Node* current);
    void destroyRecursive(Node* current);
    bool findPathRecursive(Node* current, int value, std::vector<int>& path);

    // Metody wyświetlania
    void preorderRecursive(Node* current);
    void inorderRecursive(Node* current);
    void postorderRecursive(Node* current);
    void saveTextRecursive(Node* current, std::ofstream& outFile);

public:
    BST();
    ~BST();

    void insert(int value);
    void remove(int value);
    void clear();
    bool findPath(int value, std::vector<int>& path);
    void display(int method); // 1: Preorder, 2: Inorder, 3: Postorder
    void saveToFileText(const std::string& filename);
    bool isEmpty() const;

    // Dostęp do korzenia (przydatne np. dla managera plików binarnych)
    Node* getRoot() const;
    void setRoot(Node* newRoot);
};

#endif