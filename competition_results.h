#ifndef COMPETITION_RESULTS_H
#define COMPETITION_RESULTS_H

#include <iostream>
#include "need.h"
using namespace std;

inline void runCompetition() {
    int choice;
    
    do {
        clearScreen();
        displayHeader();
        
        cout << "COMPETITION RESULTS\n";
        cout << "==================\n\n";
        
        cout << "1. Round 1\n";
        cout << "2. Round 2\n";
        cout << "3. Round 3\n";
        cout << "4. Round 4\n";
        cout << "5. Final\n";
        cout << "6. Back\n\n";
        
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 6) return;
        
        clearScreen();
        displayHeader();
        
        switch(choice) {
            case 1:
                cout << "ROUND 1: STRING SEARCH\n";
                cout << "==================\n\n";
                cout << "Maij: 5/10 (Naive)\n";
                cout << "Lumihs: 7/10 (KMP)\n";
                cout << "Puzzle Man: 9/10 (Sunday)\n\n";
                cout << "Winner: Puzzle Man\n";
                break;
                
            case 2:
                cout << "ROUND 2: MST\n";
                cout << "==================\n\n";
                cout << "Maij: 8/10 (Prim's)\n";
                cout << "Lumihs: 8/10 (Kruskal's)\n";
                cout << "Puzzle Man: 9/10 (Boruvka's)\n\n";
                cout << "All: 13 coins\n";
                cout << "Winner: Puzzle Man\n";
                break;
                
            case 3:
                cout << "ROUND 3: KNAPSACK\n";
                cout << "==================\n\n";
                cout << "Maij: 6/10 (Greedy 0/1)\n";
                cout << "Lumihs: 7/10 (Greedy Frac)\n";
                cout << "Puzzle Man: 9/10 (DP)\n\n";
                cout << "Optimal: 230 coins\n";
                cout << "Winner: Puzzle Man\n";
                break;
                
            case 4:
                cout << "ROUND 4: PATH FINDING\n";
                cout << "==================\n\n";
                cout << "Maij: 8/10 (Dijkstra)\n";
                cout << "Lumihs: 6/10 (Bellman)\n";
                cout << "Puzzle Man: 9/10 (A*)\n\n";
                cout << "Distance: 1250 units\n";
                cout << "Winner: Puzzle Man\n";
                break;
                
            case 5:
                cout << "FINAL RESULTS\n";
                cout << "==================\n\n";
                cout << "Maij: 27/40 - 3rd\n";
                cout << "Lumihs: 28/40 - 2nd\n";
                cout << "Puzzle Man: 36/40 - 1st\n\n";
                cout << "🏆 DLOG MEDALIST: PUZZLE MAN\n";
                break;
                
            default: continue;
        }
        
        waitForEnter();
        
    } while (true);
}

#endif // COMPETITION_RESULTS_H