/**
 * @file BST.cpp
 * @brief Implementacja metod klasy BST.
 */

#include "BST.h"
#include <iostream>
#include <fstream>

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

bool BST::isEmpty() const {
    return root == nullptr;
}

Node* BST::getRoot() const {
    return root;
}

void BST::setRoot(Node* newRoot) {
    root = newRoot;
}

Node* BST::insertRecursive(Node* current, int value) {
    if (current == nullptr) {
        return new Node(value);
    }
    if (value < current->data) {
        current->left = insertRecursive(current->left, value);
    }
    else if (value > current->data) {
        current->right = insertRecursive(current->right, value);
    }
    return current;
}

void BST::insert(int value) {
    root = insertRecursive(root, value);
}

Node* BST::findMin(Node* current) {
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* BST::removeRecursive(Node* current, int value) {
    if (current == nullptr) return nullptr;

    if (value < current->data) {
        current->left = removeRecursive(current->left, value);
    }
    else if (value > current->data) {
        current->right = removeRecursive(current->right, value);
    }
    else {
        if (current->left == nullptr) {
            Node* temp = current->right;
            delete current;
            return temp;
        }
        else if (current->right == nullptr) {
            Node* temp = current->left;
            delete current;
            return temp;
        }

        Node* temp = findMin(current->right);
        current->data = temp->data;
        current->right = removeRecursive(current->right, temp->data);
    }
    return current;
}

void BST::remove(int value) {
    root = removeRecursive(root, value);
}

void BST::destroyRecursive(Node* current) {
    if (current != nullptr) {
        destroyRecursive(current->left);
        destroyRecursive(current->right);
        delete current;
    }
}

void BST::clear() {
    destroyRecursive(root);
    root = nullptr;
}

bool BST::findPathRecursive(Node* current, int value, std::vector<int>& path) {
    if (current == nullptr) return false;

    path.push_back(current->data);

    if (current->data == value) return true;

    if (value < current->data) {
        if (findPathRecursive(current->left, value, path)) return true;
    }
    else {
        if (findPathRecursive(current->right, value, path)) return true;
    }

    path.pop_back();
    return false;
}

bool BST::findPath(int value, std::vector<int>& path) {
    path.clear();
    return findPathRecursive(root, value, path);
}

void BST::preorderRecursive(Node* current) {
    if (current != nullptr) {
        std::cout << current->data << " ";
        preorderRecursive(current->left);
        preorderRecursive(current->right);
    }
}

void BST::inorderRecursive(Node* current) {
    if (current != nullptr) {
        inorderRecursive(current->left);
        std::cout << current->data << " ";
        inorderRecursive(current->right);
    }
}

void BST::postorderRecursive(Node* current) {
    if (current != nullptr) {
        postorderRecursive(current->left);
        postorderRecursive(current->right);
        std::cout << current->data << " ";
    }
}

void BST::display(int method) {
    if (isEmpty()) {
        std::cout << "Drzewo jest puste.\n";
        return;
    }
    std::cout << "Drzewo: ";
    if (method == 1) preorderRecursive(root);
    else if (method == 2) inorderRecursive(root);
    else if (method == 3) postorderRecursive(root);
    std::cout << "\n";
}

void BST::saveTextRecursive(Node* current, std::ofstream& outFile) {
    if (current != nullptr) {
        outFile << current->data << " ";
        saveTextRecursive(current->left, outFile);
        saveTextRecursive(current->right, outFile);
    }
}

void BST::saveToFileText(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        saveTextRecursive(root, outFile);
        outFile.close();
        std::cout << "Zapisano drzewo do pliku tekstowego.\n";
    }
    else {
        std::cout << "Blad otwarcia pliku tekstowego!\n";
    }
}