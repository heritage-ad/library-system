#ifndef RECOMMENDATIONSYSTEM_H
#define RECOMMENDATIONSYSTEM_H

#include "User.h"
#include "Library.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

// Recommendation system class to suggest books based on user search history
class RecommendationSystem {
private:
    Library* library; // Pointer to library for accessing catalog
    std::unordered_map<std::string, User> userProfiles; // Store each user's profile

public:
    // Constructor with library dependency
    RecommendationSystem(Library* lib) : library(lib) {}

    // Method to generate recommendations for a user based on search history
    std::vector<std::string> generateRecommendations(const std::string& userId) {
    std::vector<std::string> recommendations;
    std::set<std::string> genresSearched; // Store genres searched by the user

    // Retrieve user's search history
    auto history = userProfiles[userId].getSearchHistory();
    for (const auto& term : history) {
        // Check if the book exists in the catalog, and get its genre if it does
        const auto& catalog = library->getCatalog(); // Access the catalog
        if (catalog.find(term) != catalog.end()) {
            genresSearched.insert(catalog.at(term).genre); // Add genre to the set
        }
    }

    // Find books in similar genres
    const auto& catalog = library->getCatalog();
    for (const auto& genre : genresSearched) {
        for (const auto& book : catalog) {
            if (book.second.genre == genre && std::find(history.begin(), history.end(), book.first) == history.end()) {
                recommendations.push_back(book.second.title + " by " + book.second.author + " - " + genre);
            }
        }
    }

    return recommendations;
}
 // Method to add user search term for history tracking
    void addUserSearch(const std::string& userId, const std::string& searchTerm) {
        userProfiles[userId].addSearchHistory(searchTerm);
    }
};

#endif
 