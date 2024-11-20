#include "Library.h"
#include "User.h"
#include "RecommendationSystem.h"
#include <iostream>
#include <string>

int main() {
    Library library;
    std::string userId = "user1";  //  user ID
    User user(userId);
    RecommendationSystem recommender(&library);

    int choice;
    while (true) {
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Add a Book\n";
        std::cout << "2. Search for a Book\n";
        std::cout << "3. Display All Books\n";
        std::cout << "4. Get Recommendations\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string title, author, genre;
            std::cout << "Enter book title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter author name: ";
            std::getline(std::cin, author);
            std::cout << "Enter genre: ";
            std::getline(std::cin, genre);
            library.addBook(title, author, genre);
            std::cout << "Book added successfully!\n";

        } else if (choice == 2) {
            std::string searchTitle;
            std::cout << "Enter book title to search: ";
            std::cin.ignore();
            std::getline(std::cin, searchTitle);
            if (library.searchBook(searchTitle)) {
                std::cout << searchTitle << " is available in the library.\n";
                user.addSearchHistory(searchTitle);  // Save search history
            } else {
                std::cout << searchTitle << " is not available in the library.\n";
            }

        } else if (choice == 3) {
            library.displayBooks();

        } else if (choice == 4) {
            std::vector<std::string> recommendations = recommender.generateRecommendations(userId);
            std::cout << "Recommendations for " << userId << ":\n";
            for (const auto& rec : recommendations) {
                std::cout << "- " << rec << "\n";
            }

        } else if (choice == 5) {
            std::cout << "Exiting the program.\n";
            break;

        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
