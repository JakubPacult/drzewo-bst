#ifndef BST_H
#define BST_H

/**
 * @file BST.h
 * @brief Deklaracja klasy BST (Binary Search Tree).
 */

#include "Node.h"
#include <vector>
#include <string>

 /**
  * @class BST
  * @brief Klasa zarządzająca drzewem poszukiwań binarnych (BST).
  */
class BST {
private:
    Node* root; ///< Wskaźnik na korzeń drzewa.

    Node* insertRecursive(Node* current, int value);
    Node* removeRecursive(Node* current, int value);
    Node* findMin(Node* current);
    void destroyRecursive(Node* current);
    bool findPathRecursive(Node* current, int value, std::vector<int>& path);

    void preorderRecursive(Node* current);
    void inorderRecursive(Node* current);
    void postorderRecursive(Node* current);
    void saveTextRecursive(Node* current, std::ofstream& outFile);

public:
    /**
     * @brief Konstruktor domyślny. Tworzy puste drzewo.
     */
    BST();

    /**
     * @brief Destruktor. Zwalnia pamięć zajmowaną przez całe drzewo.
     */
    ~BST();

    /**
     * @brief Dodaje nowy element do drzewa BST.
     * @param value Wartość do dodania.
     */
    void insert(int value);

    /**
     * @brief Usuwa element z drzewa BST.
     * @param value Wartość do usunięcia.
     */
    void remove(int value);

    /**
     * @brief Usuwa całe drzewo i zwalnia pamięć.
     */
    void clear();

    /**
     * @brief Szuka drogi od korzenia do zadanego elementu.
     * @param value Szukana wartość.
     * @param path Referencja na wektor, do którego zostanie wpisana ścieżka.
     * @return true jeśli element znaleziono, false w przeciwnym razie.
     */
    bool findPath(int value, std::vector<int>& path);

    /**
     * @brief Wyświetla zawartość drzewa wybraną metodą.
     * @param method Metoda przechodzenia (1: Preorder, 2: Inorder, 3: Postorder).
     */
    void display(int method);

    /**
     * @brief Zapisuje drzewo do pliku tekstowego.
     * @param filename Nazwa pliku wyjściowego.
     */
    void saveToFileText(const std::string& filename);

    /**
     * @brief Sprawdza, czy drzewo jest puste.
     * @return true jeśli puste, false w przeciwnym razie.
     */
    bool isEmpty() const;

    /**
     * @brief Zwraca wskaźnik na korzeń drzewa.
     * @return Node* Wskaźnik do korzenia.
     */
    Node* getRoot() const;

    /**
     * @brief Ustawia nowy korzeń drzewa.
     * @param newRoot Wskaźnik do nowego korzenia.
     */
    void setRoot(Node* newRoot);
};

#endif