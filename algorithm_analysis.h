#ifndef ALGORITHM_ANALYSIS_H
#define ALGORITHM_ANALYSIS_H

#include <iostream>
#include <string>
#include <vector>
#include "need.h"
using namespace std;

// ==================== ROUND 1 ALGORITHMS ====================
inline void showRound1Algorithms() {
    clearScreen();
    displayHeader();
    
    cout << "ROUND 1: STRING SEARCH ALGORITHMS\n";
    cout << "==================================================\n\n";
    
    cout << "Problem: Search names in village register\n\n";
    
    int algoChoice;
    cout << "Choose algorithm to analyze:\n";
    cout << "1. Naive Pattern Matching\n";
    cout << "2. KMP Algorithm\n";
    cout << "3. Sunday Algorithm\n";
    cout << "4. Back\n\n";
    cout << "Choice: ";
    cin >> algoChoice;
    cin.ignore();
    
    if (algoChoice == 4) return;
    
    clearScreen();
    displayHeader();
    
    switch(algoChoice) {
        case 1:
            cout << "NAIVE PATTERN MATCHING\n";
            cout << "======================\n\n";
            cout << "Complexity: O(n*m) worst case\n";
            cout << "Memory: O(1)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Simple to implement\n";
            cout << "• No preprocessing needed\n";
            cout << "• No extra memory\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Very slow for large texts\n";
            cout << "• Redundant comparisons\n";
            cout << "• Poor worst-case\n\n";
            
            cout << "Best for: Small texts, learning\n";
            break;
            
        case 2:
            cout << "KMP (Knuth-Morris-Pratt)\n";
            cout << "========================\n\n";
            cout << "Complexity: O(n+m) guaranteed\n";
            cout << "Memory: O(m) for LPS array\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Linear time guaranteed\n";
            cout << "• No backtracking in text\n";
            cout << "• Good for repetitive patterns\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Complex implementation\n";
            cout << "• Needs preprocessing\n";
            cout << "• Extra memory needed\n\n";
            
            cout << "Best for: DNA sequences, repetitive text\n";
            break;
            
        case 3:
            cout << "SUNDAY ALGORITHM\n";
            cout << "================\n\n";
            cout << "Complexity: Average O(n), Worst O(n*m)\n";
            cout << "Memory: O(alphabet_size)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Fastest in practice\n";
            cout << "• Simple shift table\n";
            cout << "• Excellent for names\n";
            cout << "• Large skips possible\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Poor worst-case\n";
            cout << "• Needs shift table\n";
            cout << "• Less known\n\n";
            
            cout << "Best for: Village names, natural language\n";
            break;
            
        default:
            return;
    }
    
    cout << "\n==================================================\n";
    waitForEnter();
}

// ==================== ROUND 2 ALGORITHMS ====================
inline void showRound2Algorithms() {
    clearScreen();
    displayHeader();
    
    cout << "ROUND 2: MINIMUM SPANNING TREE\n";
    cout << "==================================================\n\n";
    
    cout << "Problem: Connect houses with min wire cost\n\n";
    
    int algoChoice;
    cout << "Choose MST algorithm:\n";
    cout << "1. Prim's Algorithm\n";
    cout << "2. Kruskal's Algorithm\n";
    cout << "3. Boruvka's Algorithm\n";
    cout << "4. Back\n\n";
    cout << "Choice: ";
    cin >> algoChoice;
    cin.ignore();
    
    if (algoChoice == 4) return;
    
    clearScreen();
    displayHeader();
    
    switch(algoChoice) {
        case 1:
            cout << "PRIM'S ALGORITHM\n";
            cout << "================\n\n";
            cout << "Complexity: O(V²) or O(E log V)\n";
            cout << "Memory: O(V)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Simple greedy approach\n";
            cout << "• Good for dense graphs\n";
            cout << "• Starts from any node\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Slower for sparse graphs\n";
            cout << "• Not parallelizable\n\n";
            
            cout << "Best for: Dense village layouts\n";
            break;
            
        case 2:
            cout << "KRUSKAL'S ALGORITHM\n";
            cout << "===================\n\n";
            cout << "Complexity: O(E log E)\n";
            cout << "Memory: O(E)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Excellent for sparse graphs\n";
            cout << "• Easy with Union-Find\n";
            cout << "• Can be parallelized\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Needs sorting all edges\n";
            cout << "• Slower for dense graphs\n\n";
            
            cout << "Best for: Sparse connections\n";
            break;
            
        case 3:
            cout << "BORUVKA'S ALGORITHM\n";
            cout << "===================\n\n";
            cout << "Complexity: O(E log V)\n";
            cout << "Memory: O(V + E)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Good for parallel processing\n";
            cout << "• First known MST algorithm\n";
            cout << "• Works well with dense graphs\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Complex implementation\n";
            cout << "• Not widely used\n\n";
            
            cout << "Best for: Parallel computing\n";
            break;
    }
    
    cout << "\nVillage use: All find optimal (13 coins)\n";
    waitForEnter();
}

// ==================== ROUND 3 ALGORITHMS ====================
inline void showRound3Algorithms() {
    clearScreen();
    displayHeader();
    
    cout << "ROUND 3: KNAPSACK ALGORITHMS\n";
    cout << "==================================================\n\n";
    
    cout << "Problem: Noya's cart (50kg capacity)\n\n";
    
    int algoChoice;
    cout << "Choose knapsack algorithm:\n";
    cout << "1. Greedy Fractional\n";
    cout << "2. Greedy 0/1\n";
    cout << "3. Dynamic Programming\n";
    cout << "4. Back\n\n";
    cout << "Choice: ";
    cin >> algoChoice;
    cin.ignore();
    
    if (algoChoice == 4) return;
    
    clearScreen();
    displayHeader();
    
    switch(algoChoice) {
        case 1:
            cout << "GREEDY FRACTIONAL\n";
            cout << "=================\n\n";
            cout << "Complexity: O(n log n)\n";
            cout << "Memory: O(n)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Optimal for fractional\n";
            cout << "• Very fast\n";
            cout << "• Simple to implement\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Not for 0/1 knapsack\n";
            cout << "• Takes fractions of items\n\n";
            
            cout << "Best for: Items can be divided\n";
            break;
            
        case 2:
            cout << "GREEDY 0/1\n";
            cout << "==========\n\n";
            cout << "Complexity: O(n log n)\n";
            cout << "Memory: O(n)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Very fast\n";
            cout << "• Low memory\n";
            cout << "• Simple\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Not always optimal\n";
            cout << "• No guarantee\n\n";
            
            cout << "Example fail: [30:120] vs [20:100]+[20:100]\n";
            cout << "Best for: Large datasets, approximate solutions\n";
            break;
            
        case 3:
            cout << "DYNAMIC PROGRAMMING (0/1)\n";
            cout << "========================\n\n";
            cout << "Complexity: O(n*W)\n";
            cout << "Memory: O(n*W) or O(W)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Guaranteed optimal\n";
            cout << "• Works for 0/1\n";
            cout << "• Handles constraints\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Pseudo-polynomial time\n";
            cout << "• High memory for large W\n";
            cout << "• Slower than greedy\n\n";
            
            cout << "Best for: Guaranteed optimal solutions\n";
            break;
    }
    
    cout << "\nFor Noya: DP gives 230 coins optimal\n";
    waitForEnter();
}

// ==================== ROUND 4 ALGORITHMS ====================
inline void showRound4Algorithms() {
    clearScreen();
    displayHeader();
    
    cout << "ROUND 4: SHORTEST PATH\n";
    cout << "==================================================\n\n";
    
    cout << "Problem: Hilltop → Lotus Garden\n\n";
    
    int algoChoice;
    cout << "Choose shortest path algorithm:\n";
    cout << "1. Dijkstra's Algorithm\n";
    cout << "2. Bellman-Ford Algorithm\n";
    cout << "3. A* Search Algorithm\n";
    cout << "4. Back\n\n";
    cout << "Choice: ";
    cin >> algoChoice;
    cin.ignore();
    
    if (algoChoice == 4) return;
    
    clearScreen();
    displayHeader();
    
    switch(algoChoice) {
        case 1:
            cout << "DIJKSTRA'S ALGORITHM\n";
            cout << "====================\n\n";
            cout << "Complexity: O((V+E) log V)\n";
            cout << "Memory: O(V)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Guaranteed shortest path\n";
            cout << "• Efficient with heap\n";
            cout << "• Reliable\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• No negative weights\n";
            cout << "• Can be slow for dense graphs\n\n";
            
            cout << "Best for: Non-negative weights\n";
            break;
            
        case 2:
            cout << "BELLMAN-FORD ALGORITHM\n";
            cout << "======================\n\n";
            cout << "Complexity: O(V*E)\n";
            cout << "Memory: O(V)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Handles negative weights\n";
            cout << "• Detects negative cycles\n";
            cout << "• Works for all graphs\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Slower than Dijkstra\n";
            cout << "• Not efficient for dense graphs\n\n";
            
            cout << "Best for: Graphs with negative weights\n";
            break;
            
        case 3:
            cout << "A* SEARCH ALGORITHM\n";
            cout << "===================\n\n";
            cout << "Complexity: Depends on heuristic\n";
            cout << "Memory: O(V)\n\n";
            
            cout << "✅ PROS:\n";
            cout << "• Very fast with good heuristic\n";
            cout << "• Optimal with admissible h(n)\n";
            cout << "• Great for maps\n\n";
            
            cout << "❌ CONS:\n";
            cout << "• Needs good heuristic\n";
            cout << "• Can use lots of memory\n\n";
            
            cout << "Best for: Village navigation with distance estimates\n";
            break;
    }
    
    cout << "\nFor village: A* is fastest (1250 units)\n";
    waitForEnter();
}

// ==================== COMPACT SUMMARY ====================
inline void showAllRoundsCompact() {
    clearScreen();
    displayHeader();
    
    cout << "ALGORITHM SUMMARY\n";
    cout << "==================\n\n";
    
    cout << "ROUND 1 - STRING SEARCH:\n";
    cout << "• Naive: O(n*m) - Simple, slow\n";
    cout << "• KMP: O(n+m) - Reliable, complex\n";
    cout << "• Sunday: Avg O(n) - Fastest for names\n\n";
    
    cout << "ROUND 2 - MST:\n";
    cout << "• Prim's: O(E log V) - Dense graphs\n";
    cout << "• Kruskal's: O(E log E) - Sparse graphs\n";
    cout << "• Boruvka's: O(E log V) - Parallel\n\n";
    
    cout << "ROUND 3 - KNAPSACK:\n";
    cout << "• Greedy Frac: O(n log n) - Fractional\n";
    cout << "• Greedy 0/1: O(n log n) - Fast, not optimal\n";
    cout << "• DP: O(n*W) - Guaranteed optimal\n\n";
    
    cout << "ROUND 4 - SHORTEST PATH:\n";
    cout << "• Dijkstra: O((V+E) log V) - Non-negative\n";
    cout << "• Bellman-Ford: O(V*E) - Handles negatives\n";
    cout << "• A*: Heuristic-based - Fastest for maps\n";
    
    waitForEnter();
}

// ==================== MAIN INTERACTIVE MENU ====================
inline void showRoundsAlgorithms() {
    int choice;
    
    do {
        clearScreen();
        displayHeader();
        
        cout << "ALGORITHM ANALYSIS\n";
        cout << "==================\n\n";
        
        cout << "Select round for detailed analysis:\n";
        cout << "1. Round 1 - String Search\n";
        cout << "2. Round 2 - Minimum Spanning Tree\n";
        cout << "3. Round 3 - Knapsack\n";
        cout << "4. Round 4 - Shortest Path\n";
        cout << "5. View All (Summary)\n";
        cout << "6. Back\n\n";
        
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 6) return;
        
        switch(choice) {
            case 1: showRound1Algorithms(); break;
            case 2: showRound2Algorithms(); break;
            case 3: showRound3Algorithms(); break;
            case 4: showRound4Algorithms(); break;
            case 5: showAllRoundsCompact(); break;
            default: continue;
        }
        
    } while (true);
}

// Main menu function 
inline void showAlgorithmDetails() {
    showRoundsAlgorithms();
}

#endif // ALGORITHM_ANALYSIS_H