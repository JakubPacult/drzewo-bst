#ifndef NODE_H
#define NODE_H

/**
 * @file Node.h
 * @brief Definicja struktury węzła drzewa BST.
 */

 /**
  * @struct Node
  * @brief Reprezentuje pojedynczy węzeł w drzewie poszukiwań binarnych (BST).
  */
struct Node {
    int data;       ///< Wartość przechowywana w węźle.
    Node* left;     ///< Wskaźnik na lewe poddrzewo.
    Node* right;    ///< Wskaźnik na prawe poddrzewo.

    /**
     * @brief Konstruktor węzła.
     * @param val Wartość inicjalizująca węzeł.
     */
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

#endif