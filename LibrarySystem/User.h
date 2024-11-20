#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include <fstream>

class User {
private:
    std::list<std::string> searchHistory;

    // Load history from file
    void loadHistory(const std::string& userId) {
        std::ifstream file(userId + "/DATA STRUCT/LibrarySystem/_history.txt");
        if (file.is_open()) {
            std::string term;
            while (std::getline(file, term)) {
                searchHistory.push_back(term);
            }
            file.close();
        }
    }

    // Save history to file
    void saveHistory(const std::string& userId) {
        std::ofstream file(userId + "/DATA STRUCT/LibrarySystem/_history.txt");
        for (const auto& term : searchHistory) {
            file << term << "\n";
        }
        file.close();
    }

public:
    // Default constructor 
    User() = default;

    // Constructor to load history for a specific user ID
    User(const std::string& userId) {
        loadHistory(userId);
    }

    // Add a search term to history and save
    void addSearchHistory(const std::string& searchTerm) {
        searchHistory.push_back(searchTerm);
    }

    // Retrieve search history
    std::list<std::string> getSearchHistory() const {
        return searchHistory;
    }
};

#endif 
