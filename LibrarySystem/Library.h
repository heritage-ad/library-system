#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>

// Book struct to store basic information about each book
struct Book {
    std::string title;
    std::string author;
    std::string genre;
    bool isAvailable;
};

// Library class to manage the catalog of books
class Library {
private:
    std::unordered_map<std::string, Book> catalog; // Book catalog

    // Helper method to load catalog from file
    void loadCatalog() {
        std::ifstream file("/DATA STRUCT/LibrarySystem/catalog.txt");
        if (file.is_open()) {
            std::string title, author, genre;
            bool isAvailable;
            while (file >> std::ws, std::getline(file, title)) {  // Read title with whitespace handling
                std::getline(file, author);
                std::getline(file, genre);
                file >> isAvailable;
                catalog[title] = {title, author, genre, isAvailable};
            }
            file.close();
        }
    }

    // Helper method to save catalog to file
    void saveCatalog() {
        std::ofstream file("/DATA STRUCT/LibrarySystem/catalog.txt");
        for (const auto& pair : catalog) {
            file << pair.second.title << "\n" 
                 << pair.second.author << "\n" 
                 << pair.second.genre << "\n" 
                 << pair.second.isAvailable << "\n";
        }
        file.close();
    }

public:
    // Constructor to load catalog at start
    Library() {
        loadCatalog();
    }

    // Destructor to save catalog on exit
    ~Library() {
        saveCatalog();
    }

    // Method to add a book to the catalog
    void addBook(const std::string& title, const std::string& author, const std::string& genre) {
        catalog[title] = {title, author, genre, true};
        saveCatalog();
    }

    // Method to remove a book from the catalog
    void removeBook(const std::string& title) {
        catalog.erase(title);
        saveCatalog();
    }

    // Method to search for a book by title
    bool searchBook(const std::string& title) {
        return catalog.find(title) != catalog.end();
    }

    // Method to display all available books
    void displayBooks() {
        for (const auto& pair : catalog) {
            std::cout << "Title: " << pair.second.title 
                      << ", Author: " << pair.second.author 
                      << ", Genre: " << pair.second.genre 
                      << ", Available: " << (pair.second.isAvailable ? "Yes" : "No") << std::endl;
        }
    }

    // Getter for the catalog 
    const std::unordered_map<std::string, Book>& getCatalog() const {
        return catalog;
    }
};

#endif 









