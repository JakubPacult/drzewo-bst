/**
 * @file main.cpp
 * @brief Główny plik programu obsługujący menu użytkownika.
 * @details Commit: f7c4e2a - dodano obsługę plików binarnych i tekstowych oraz menu interaktywne.
 */

#include <iostream>
#include <vector>
#include "BST.h"
#include "FileManager.h"

 /**
  * @brief Główna funkcja programu.
  * @return int Kod wyjścia programu.
  */
int main() {
<<<<<<< HEAD
	std::cout << "=== Program do zarządzania drzewem BST ===\n"; 
=======
    // Informacja o wersji / commitcie widoczna przy starcie
    std::cout << "[Wersja / Commit: f7c4e2a - BST App v1.2]\n";

>>>>>>> main
    BST drzewo;
    int wybór;

    do {
        std::cout << "\n=== MENU DRZEWA BST ===\n";
        std::cout << "1. Dodaj element\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Usun cale drzewo\n";
        std::cout << "4. Szukaj drogi do elementu\n";
        std::cout << "5. Wyswietl drzewo\n";
        std::cout << "6. Zapisz drzewo do pliku tekstowego\n";
        std::cout << "7. Wczytaj liczby z pliku tekstowego do drzewa\n";
        std::cout << "8. Zapisz drzewo do pliku binarnego\n";
        std::cout << "9. Odczytaj drzewo z pliku binarnego\n";
        std::cout << "0. Wyjście\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> wybór;

        switch (wybór) {
        case 1: {
            int val;
            std::cout << "Podaj liczbe do dodania: ";
            std::cin >> val;
            drzewo.insert(val);
            std::cout << "Dodano.\n";
            break;
        }
        case 2: {
            int val;
            std::cout << "Podaj liczbe do usuniecia: ";
            std::cin >> val;
            drzewo.remove(val);
            std::cout << "Usunieto (jesli istniala).\n";
            break;
        }
        case 3:
            drzewo.clear();
            std::cout << "Drzewo zostalo wyczyszczone.\n";
            break;
        case 4: {
            int val;
            std::cout << "Podaj element do znalezienia: ";
            std::cin >> val;
            std::vector<int> path;
            if (drzewo.findPath(val, path)) {
                std::cout << "Znaleziono droge: ";
                for (int v : path) {
                    std::cout << v << " ";
                }
                std::cout << "\n";
            }
            else {
                std::cout << "Element nie znajduje sie w drzewie.\n";
            }
            break;
        }
        case 5: {
            int method;
            std::cout << "Wybierz metode:\n1. Preorder\n2. Inorder\n3. Postorder\nWybor: ";
            std::cin >> method;
            drzewo.display(method);
            break;
        }
        case 6: {
            std::string filename;
            std::cout << "Podaj nazwe pliku tekstowego (np. drzewo.txt): ";
            std::cin >> filename;
            drzewo.saveToFileText(filename);
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "Podaj nazwe pliku tekstowego z cyframi (np. dane.txt): ";
            std::cin >> filename;
            FileManager::loadTextToBST(filename, drzewo);
            break;
        }
        case 8: {
            std::string filename;
            std::cout << "Podaj nazwe pliku binarnego (np. drzewo.bin): ";
            std::cin >> filename;
            FileManager::saveBinary(filename, drzewo);
            break;
        }
        case 9: {
            std::string filename;
            std::cout << "Podaj nazwe pliku binarnego (np. drzewo.bin): ";
            std::cin >> filename;
            FileManager::loadBinary(filename, drzewo);
            break;
        }
        case 0:
            std::cout << "Zamykanie programu...\n";
            break;
        default:
            std::cout << "Nieznana opcja. Spróbuj ponownie.\n";
        }
    } while (wybór != 0);

    return 0;
}