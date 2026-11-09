#ifndef FILEMANAGER_H
#define FILEMANAGER_H

/**
 * @file FileManager.h
 * @brief Deklaracja klasy FileManager do obsługi operacji plikowych (binarnych i tekstowych).
 */

#include "BST.h"
#include <string>

 /**
  * @class FileManager
  * @brief Klasa odpowiedzialna za serializację binarną drzewa oraz import danych tekstowych.
  */
class FileManager {
private:
    static void serializeBinary(Node* current, std::ofstream& outFile);
    static Node* deserializeBinary(std::ifstream& inFile);

public:
    /**
     * @brief Zapisuje drzewo w formacie binarnym do pliku.
     * @param filename Nazwa pliku binarnego.
     * @param bst Referencja na drzewo BST do zapisu.
     */
    static void saveBinary(const std::string& filename, const BST& bst);

    /**
     * @brief Odczytuje drzewo z pliku binarnego.
     * @param filename Nazwa pliku binarnego.
     * @param bst Referencja na drzewo BST, do którego zostanie wczytana struktura.
     */
    static void loadBinary(const std::string& filename, BST& bst);

    /**
     * @brief Wczytuje liczby z pliku tekstowego i dodaje je do drzewa.
     * @param filename Nazwa pliku tekstowego.
     * @param bst Referencja na drzewo BST, do którego zostaną wstawione liczby.
     */
    static void loadTextToBST(const std::string& filename, BST& bst);
};

#endif