#ifndef NEED_H
#define NEED_H

#include <iostream>
#include <string>
using namespace std;


// Use inline to avoid multiple definition errors
inline void clearScreen() {
    #ifdef _WIN32
        // Windows
        system("cls");
    #else
        // Unix/Linux/Mac - try multiple methods
        cout << "\033[2J\033[1;1H";  // Clear screen and move to top
        cout.flush();
        
        // If above doesn't work, try system clear
        int result = system("clear");
        if (result == -1) {
            // System call failed, use newlines as fallback
            for(int i = 0; i < 100; i++) cout << "\n";
        }
    #endif
}

inline void displayHeader() {
    cout << "==================================================\n";
    cout << "      PUZZLE MAN ALGORITHM CHALLENGE\n";
    cout << "        Can You Beat The Village Champion?\n";
    cout << "      Featuring: Maij vs Lumihs vs Puzzle Man\n";
    cout << "==================================================\n\n";
}

inline void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}


// Main menu
void displayMenu() {
    cout << "MAIN MENU\n";
    cout << "==================================================\n";
    cout << "1. View Contestants\n";
    cout << "2. View Judges & Rules\n";
    cout << "3. Test Algorithms\n";
    cout << "4. Start Competition\n";
    cout << "5. View Algorithm Details\n";
    cout << "6. Village Chief's Problem\n";
    cout << "7. Exit & See Winner\n";
    cout << "==================================================\n";
    cout << "8. About Us\n";
    cout << "==================================================\n";
}

// 7. Exit with Winner Announcement
void showWinner() {
    clearScreen();
    displayHeader();
    
    cout << "FINAL RESULTS\n";
    cout << "==================================================\n\n";

    cout << "Maij: 27/40 - 3rd\n";
    cout << "Lumihs: 28/40 - 2nd\n";
    cout << "Puzzle Man: 36/40 - 1st\n\n";
    cout << "🏆 DLOG MEDALIST: PUZZLE MAN\n\n";

    cout << "THANK YOU FOR JOIN WITH US.\n";
    waitForEnter();
}


// 1. Display Contestants 
void showContestants() {
    clearScreen();
    displayHeader();
    
    cout << "CONTESTANTS\n";
    cout << "==================================================\n\n";
    
    cout << "1. MAIJ\n";
    cout << "2. LUMIHS\n";
    cout << "3. THE PUZZLE MAN\n";
    
    waitForEnter();
}

// 2. Display Judges & Rules -> need.h
void showJudgesRules() {
    clearScreen();
    displayHeader();
    
    cout << "JUDGES & RULES\n";
    cout << "==================================================\n\n";
    
    cout << "JUDGES:\n";
    cout << "1. Dihut - Wisest person in Gorithm Algo village\n";
    cout << "2. Zifan - Dihut's trusted subordinate\n\n";
    
    cout << "COMPETITION RULES:\n";
    cout << "1. 4 Rounds, each with 3 different problems\n";
    cout << "2. Evaluation based on time complexity\n";
    cout << "3. Lower complexity = Higher marks (0-10)\n";
    cout << "4. Highest total marks wins 'Dlog Medal'\n\n";
    
    waitForEnter();
}


#endif // NEED_H