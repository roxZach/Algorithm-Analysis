#ifndef SHOW_PROBLEMS_H_H
#define SHOW_PROBLEMS_H_H

#include <iostream>
#include <string>
#include "need.h"
using namespace std;

inline void showProblem() {
    int roundChoice;
    
    do {
        clearScreen();
        displayHeader();
        
        cout << "SELECT ROUND TO VIEW PROBLEM\n";
        cout << "==================================================\n\n";
        
        cout << "1. Round 1 - Village Register Search\n";
        cout << "2. Round 2 - Village Infrastructure Problems\n";
        cout << "3. Round 3 - Noya's Knapsack Problem\n";
        cout << "4. Round 4 - Village Path Finding\n";
        cout << "5. Back to Main Menu\n";
        cout << "==================================================\n\n";
        
        cout << "Enter your choice (1-5): ";
        cin >> roundChoice;
        cin.ignore();
        
        if (roundChoice == 5) {
            return;
        }
        
        clearScreen();
        displayHeader();
        
        switch(roundChoice) {
            case 1:
                cout << "ROUND 1: VILLAGE REGISTER SEARCH\n";
                cout << "========================================\n\n";
                cout << "Problem: Names in register without spaces\n";
                cout << "Example: Find 'ihsin' in 'maijlumihs...'\n";
                cout << "Task: Fastest string search algorithm\n";
                break;
                
            case 2:
                cout << "ROUND 2: VILLAGE INFRASTRUCTURE\n";
                cout << "========================================\n\n";
                cout << "Problem: Connect houses with minimum wire cost\n";
                cout << "Constraint: Limited budget\n";
                cout << "Task: Minimum spanning tree algorithm\n";
                break;
                
            case 3:
                cout << "ROUND 3: NOYA'S KNAPSACK PROBLEM\n";
                cout << "========================================\n\n";
                cout << "Problem: Maximize value in limited cart\n";
                cout << "Cart capacity: 50kg\n";
                cout << "Task: Knapsack algorithm solution\n";
                break;
                
            case 4:
                cout << "ROUND 4: VILLAGE PATH FINDING\n";
                cout << "========================================\n\n";
                cout << "Problem: Shortest path Hilltop→Lotus Garden\n";
                cout << "Map: 8 village locations with distances\n";
                cout << "Task: Dijkstra/Bellman-Ford/A* algorithm\n";
                break;
                
            default:
                cout << "Invalid choice! Please try again.\n";
                continue;
        }
        
        cout << "\n==================================================\n";
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        
    } while (true);
}

#endif // SHOW_PROBLEMS_H_H