#include "FileManager.h"
#include <fstream>
#include <iostream>

// Zapis binarny (używamy podejścia preorder: zapisz węzeł, potem lewe, potem prawe)
void FileManager::serializeBinary(Node* current, std::ofstream& outFile) {
    bool hasNode = (current != nullptr);
    outFile.write(reinterpret_cast<char*>(&hasNode), sizeof(hasNode));
    if (hasNode) {
        outFile.write(reinterpret_cast<char*>(&(current->data)), sizeof(current->data));
        serializeBinary(current->left, outFile);
        serializeBinary(current->right, outFile);
    }
}

void FileManager::saveBinary(const std::string& filename, const BST& bst) {
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile.is_open()) {
        serializeBinary(bst.getRoot(), outFile);
        outFile.close();
        std::cout << "Zapisano drzewo do pliku binarnego.\n";
    }
    else {
        std::cout << "Blad zapisu pliku binarnego!\n";
    }
}

// Odczyt binarny
Node* FileManager::deserializeBinary(std::ifstream& inFile) {
    bool hasNode;
    if (!inFile.read(reinterpret_cast<char*>(&hasNode), sizeof(hasNode)) || !hasNode) {
        return nullptr;
    }

    int value;
    inFile.read(reinterpret_cast<char*>(&value), sizeof(value));
    Node* node = new Node(value);
    node->left = deserializeBinary(inFile);
    node->right = deserializeBinary(inFile);
    return node;
}

void FileManager::loadBinary(const std::string& filename, BST& bst) {
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open()) {
        bst.clear(); // Czyszczenie starego drzewa przed wczytaniem
        Node* newRoot = deserializeBinary(inFile);
        bst.setRoot(newRoot);
        inFile.close();
        std::cout << "Wczytano drzewo z pliku binarnego.\n";
    }
    else {
        std::cout << "Blad odczytu pliku binarnego!\n";
    }
}

// Wczytywanie z pliku tekstowego (dodawanie do istniejącego lub pustego drzewa)
void FileManager::loadTextToBST(const std::string& filename, BST& bst) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        int value;
        while (inFile >> value) {
            bst.insert(value);
        }
        inFile.close();
        std::cout << "Wczytano liczby z pliku tekstowego do drzewa.\n";
    }
    else {
        std::cout << "Blad otwarcia pliku tekstowego!\n";
    }
}