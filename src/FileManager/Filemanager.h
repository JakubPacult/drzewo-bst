#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "../BST/BST.h"
#include <string>

class FileManager {
private:
    static void serializeBinary(Node* current, std::ofstream& outFile);
    static Node* deserializeBinary(std::ifstream& inFile);

public:
    static void saveBinary(const std::string& filename, const BST& bst);
    static void loadBinary(const std::string& filename, BST& bst);
    static void loadTextToBST(const std::string& filename, BST& bst);
};

#endif