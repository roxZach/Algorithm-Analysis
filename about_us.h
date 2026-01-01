#ifndef ABOUT_US_H
#define ABOUT_US_H

#include <iostream>
#include <string>
#include "need.h"
using namespace std;

inline void showAboutUs() {
    clearScreen();
    displayHeader();
    
    cout << "ABOUT THIS PROJECT\n";
    cout << "==================\n\n";
    
    cout << "Title: PUZZLE MAN ALGORITHM CHALLENGE\n";
    cout << "Purpose: To solve village problems.\n\n";
    
    cout << "Features:\n";
    cout << "• 4 algorithm competition rounds\n";
    cout << "• Interactive testing\n";
    cout << "• Complexity analysis\n";
    cout << "• Competition results\n\n";
    
    cout << "Algorithms covered:\n";
    cout << "1. String Search (Naive, KMP, Sunday)\n";
    cout << "2. MST (Prim's, Kruskal's, Boruvka's)\n";
    cout << "3. Knapsack (Greedy, DP)\n";
    cout << "4. Shortest Path (Dijkstra, Bellman-Ford, A*)\n\n";
    
    cout << "Language: C++ \n";
    cout << "For EWU Algorithm Course\n\n";

    cout << "SHOiSHOb - 2023-3-60-157\n";
    cout << "Jiam     - 2023-3-60-166\n";
    cout << "Nishi    - 2023-1-60-256\n";
    cout << "Farzia   - 2022-3-60-222\n";

    
    
    waitForEnter();
}

#endif // ABOUT_US_H