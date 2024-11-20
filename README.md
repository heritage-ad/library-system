The AI-Assisted Intelligent Library System is a C++ application designed to enhance library catalog management with AI-driven recommendations. Users can: 
•	Add books to the library catalog.
•	Search for books by title.
•	Display all books in the catalog.
•	Receive book recommendations based on search history. 
•	Ensure data persistence across sessions using file-based storage. 

This project demonstrates the use of hash maps for efficient catalog management, linked lists for user history tracking, and basic recommendation algorithms. 
 ## Features
1. **Add Book**: Users can add books to the catalog by providing a title, author, and genre. 
2. **Search Book**: Search for books in the library by title. 
3. **Display All Books**: View a list of all books in the catalog with details. 
4. **Get Recommendations**: Receive AI-generated book recommendations based on search history. 
5. **Data Persistence**: All catalog and user history data are saved to files for use across sessions.

## Setup Instructions
1. **Requirements**:
   - A C++ compiler that supports C++11 or higher.
   - Command-line tools (e.g., terminal, command prompt).

2. **Compilation**:
   - Ensure all files (`Main.cpp`, `Library.h`, `User.h`, `RecommendationSystem.h`) are in the same directory.
   - Run the following command: g++ -std=c++11 Main.cpp -o librarysystem

3. **Execution**:
   - Run the program with:
     ./librarysystem

4. **File Persistence**:
   - The program saves the catalog to `catalog.txt` and user history to `history.txt`.
