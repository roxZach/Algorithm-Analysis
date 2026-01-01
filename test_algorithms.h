#ifndef TEST_ALGORITHMS_H
#define TEST_ALGORITHMS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include<math.h>
#include "need.h"
using namespace std;

// ========== map ==========:
void showFancyVillageMap() {
    cout << "\n";
    cout << "       🗺️  VILLAGE PATH MAP 🗺️\n";
    cout << "┌─────────────────────────────────────┐\n";
    cout << "│  (0) Hilltop                        │\n";
    cout << "│      │ 500                          │\n";
    cout << "│      ▼                              │\n";
    cout << "│  (1) School ───────────────┐        │\n";
    cout << "│   │ 100     │ 200     │ 300         │\n";
    cout << "│   ▼         ▼         ▼             │\n";
    cout << "│(2)Home-A (4)Home-C (5)Castle        │\n";
    cout << "│   │ 25   /  │         │             │\n";
    cout << "│   │    100  │ 50      │ 400         │\n";
    cout << "│   ▼   /     ▼         ▼             │\n";
    cout << "│(3)Home-B (6)Bank ◄─────┘            │\n";
    cout << "│              │ 500                  │\n";
    cout << "│              ▼                      │\n";
    cout << "│         (7) Lotus Garden            │\n";
    cout << "└─────────────────────────────────────┘\n";
}

// ==================== ROUND 1: STRING SEARCH ALGORITHMS ====================

// 1. Naive String Search
int naiveSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}

// 2. KMP Algorithm
vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmpSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    if (m == 0) return 0;
    
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            return i - j;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

// 3. Sunday Algorithm
int sundaySearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    int shift[256];
    for (int i = 0; i < 256; i++)
        shift[i] = m + 1;
    
    for (int i = 0; i < m; i++)
        shift[(unsigned char)pattern[i]] = m - i;
    
    int pos = 0;
    
    while (pos <= n - m) {
        int j = 0;
        while (j < m && pattern[j] == text[pos + j])
            j++;
        
        if (j == m)
            return pos;
        
        if (pos + m >= n)
            break;
            
        pos += shift[(unsigned char)text[pos + m]];
    }
    return -1;
}

void testRound1() {
    clearScreen();
    displayHeader();
    
    cout << "TEST ROUND 1: STRING SEARCH ALGORITHMS\n";
    cout << "==================================================\n\n";
    
    string text, pattern;
    
    cout << "Enter register book text (default: maijlumihsdihutzifanaizrafametafihsin):\n";
    cout << "> ";
    getline(cin, text);
    
    if (text.empty()) {
        text = "maijlumihsdihutzifanaizrafametafihsin";
        cout << "Using default text\n";
    }
    
    cout << "\nEnter name to search (default: ihsin):\n";
    cout << "> ";
    getline(cin, pattern);
    
    if (pattern.empty()) {
        pattern = "ihsin";
        cout << "Using default pattern\n";
    }
    
    cout << "\n==================================================\n";
    cout << "TESTING ALL ALGORITHMS:\n\n";
    
    // Test Naive Search
    cout << "1. NAIVE SEARCH ALGORITHM:\n";
    int pos1 = naiveSearch(text, pattern);
    if (pos1 != -1) {
        cout << "   ✓ Found at position: " << pos1 << endl;
    } else {
        cout << "   ✗ Not found\n";
    }
    cout << "   Complexity: O(n*m) worst case\n\n";
    
    // Test KMP Search
    cout << "2. KMP ALGORITHM:\n";
    int pos2 = kmpSearch(text, pattern);
    if (pos2 != -1) {
        cout << "   ✓ Found at position: " << pos2 << endl;
    } else {
        cout << "   ✗ Not found\n";
    }
    cout << "   Complexity: O(n+m) guaranteed\n\n";
    
    // Test Sunday Search
    cout << "3. SUNDAY ALGORITHM:\n";
    int pos3 = sundaySearch(text, pattern);
    if (pos3 != -1) {
        cout << "   ✓ Found at position: " << pos3 << endl;
    } else {
        cout << "   ✗ Not found\n";
    }
    cout << "   Complexity: Average O(n)\n\n";
    
    cout << "==================================================\n";
    cout << "SUMMARY:\n";
    cout << "Text length: " << text.length() << " characters\n";
    cout << "Pattern length: " << pattern.length() << " characters\n";
    
    if (pos1 != -1) {
        cout << "All algorithms found the pattern!\n";
    } else {
        cout << "Pattern not found by any algorithm.\n";
    }
    
    waitForEnter();
}


// ==================== ROUND 2: MINIMUM SPANNING TREE ALGORITHMS ====================

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
    
    bool operator<(const Edge& other) const {
        return weight > other.weight; // For min-heap
    }
};

// Prim's Algorithm
int primMST(vector<vector<pair<int, int>>>& graph, int n) {
    vector<bool> inMST(n, false);
    priority_queue<Edge> pq;
    int totalWeight = 0;
    
    // Start from node 0
    inMST[0] = true;
    for (auto& neighbor : graph[0]) {
        pq.push(Edge(0, neighbor.first, neighbor.second));
    }
    
    int edgesUsed = 0;
    
    while (!pq.empty() && edgesUsed < n - 1) {
        Edge current = pq.top();
        pq.pop();
        
        if (inMST[current.v]) continue;
        
        inMST[current.v] = true;
        totalWeight += current.weight;
        edgesUsed++;
        
        for (auto& neighbor : graph[current.v]) {
            if (!inMST[neighbor.first]) {
                pq.push(Edge(current.v, neighbor.first, neighbor.second));
            }
        }
    }
    
    return totalWeight;
}

// Kruskal's Algorithm - UnionFind class
class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    
    UnionFind uf(n);
    int totalWeight = 0;
    int edgesUsed = 0;
    
    for (const Edge& edge : edges) {
        if (!uf.connected(edge.u, edge.v)) {
            uf.unite(edge.u, edge.v);
            totalWeight += edge.weight;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }
    
    return totalWeight;
}

// Boruvka's Algorithm
int boruvkaMST(vector<Edge>& edges, int n) {
    UnionFind uf(n);
    vector<int> cheapest(n, -1); // Stores index of cheapest edge for each component
    int numComponents = n;
    int totalWeight = 0;
    
    while (numComponents > 1) {
        // Initialize cheapest array
        fill(cheapest.begin(), cheapest.end(), -1);
        
        // Find cheapest edge for each component
        for (int i = 0; i < edges.size(); i++) {
            const Edge& edge = edges[i];
            int set1 = uf.find(edge.u);
            int set2 = uf.find(edge.v);
            
            if (set1 == set2) continue; // Same component
            
            // Update cheapest for set1
            if (cheapest[set1] == -1 || edges[cheapest[set1]].weight > edge.weight) {
                cheapest[set1] = i;
            }
            
            // Update cheapest for set2
            if (cheapest[set2] == -1 || edges[cheapest[set2]].weight > edge.weight) {
                cheapest[set2] = i;
            }
        }
        
        // Add cheapest edges to MST
        bool edgeAdded = false;
        for (int i = 0; i < n; i++) {
            if (cheapest[i] != -1) {
                const Edge& edge = edges[cheapest[i]];
                int set1 = uf.find(edge.u);
                int set2 = uf.find(edge.v);
                
                if (set1 != set2) {
                    uf.unite(set1, set2);
                    totalWeight += edge.weight;
                    numComponents--;
                    edgeAdded = true;
                }
            }
        }
        
        // If no edge was added, graph is disconnected
        if (!edgeAdded) {
            cout << "   Warning: Graph is disconnected!\n";
            break;
        }
    }
    
    return totalWeight;
}

void testRound2() {
    clearScreen();
    displayHeader();
    
    cout << "TEST ROUND 2: MINIMUM SPANNING TREE ALGORITHMS\n";
    cout << "==================================================\n\n";
    
    int choice;
    cout << "Choose input method:\n";
    cout << "1. Use default village (6 houses)\n";
    cout << "2. Enter custom graph\n";
    cout << "Enter choice (1-2): ";
    cin >> choice;
    cin.ignore();
    
    int n;  // Number of houses/nodes
    vector<vector<pair<int, int>>> graph;
    vector<Edge> edges;
    
    if (choice == 1) {
        // DEFAULT: 6 houses with given connections
        n = 6;
        graph.resize(n);
        
        // Village connections (same as problem statement)
        vector<tuple<int, int, int>> connections = {
            make_tuple(0, 1, 4), make_tuple(0, 2, 3), make_tuple(1, 2, 1),
            make_tuple(1, 3, 2), make_tuple(2, 3, 4), make_tuple(2, 4, 5),
            make_tuple(3, 4, 7), make_tuple(3, 5, 3), make_tuple(4, 5, 6)
        };
        
        // Build graph
        for (auto& conn : connections) {
            int u = get<0>(conn);
            int v = get<1>(conn);
            int w = get<2>(conn);
            
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
            edges.push_back(Edge(u, v, w));
        }
        
        cout << "\nUsing default village (6 houses):\n";
        cout << "Houses: 0-5\n";
        cout << "Connections with costs:\n";
        for (auto& conn : connections) {
            int u = get<0>(conn);
            int v = get<1>(conn);
            int w = get<2>(conn);
            cout << "  House " << u << " ↔ House " << v << " : " << w << " coins\n";
        }
        
    } else if (choice == 2) {
        // CUSTOM INPUT
        clearScreen();
        displayHeader();
        
        cout << "CUSTOM GRAPH INPUT\n";
        cout << "===================\n\n";
        
        // Get number of houses
        cout << "Enter number of houses (nodes): ";
        cin >> n;
        cin.ignore();
        
        if (n <= 0) {
            cout << "Invalid number of houses!\n";
            waitForEnter();
            return;
        }
        
        graph.resize(n);
        
        // Get number of connections
        int m;
        cout << "Enter number of connections (edges): ";
        cin >> m;
        cin.ignore();
        
        if (m <= 0) {
            cout << "Invalid number of connections!\n";
            waitForEnter();
            return;
        }
        
        cout << "\nEnter connections (house1 house2 cost):\n";
        cout << "Example: 0 1 4  (House 0 ↔ House 1 costs 4 coins)\n\n";
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cout << "Connection " << i+1 << ": ";
            cin >> u >> v >> w;
            cin.ignore();
            
            if (u < 0 || u >= n || v < 0 || v >= n) {
                cout << "Invalid house numbers! Must be 0 to " << n-1 << "\n";
                i--; // Retry this input
                continue;
            }
            
            if (w <= 0) {
                cout << "Cost must be positive!\n";
                i--; // Retry this input
                continue;
            }
            
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
            edges.push_back(Edge(u, v, w));
        }
        
        // Show entered graph
        clearScreen();
        displayHeader();
        cout << "YOUR VILLAGE GRAPH:\n";
        cout << "===================\n\n";
        cout << "Number of houses: " << n << "\n";
        cout << "Number of connections: " << m << "\n\n";
        cout << "Connections:\n";
        for (const auto& edge : edges) {
            cout << "  House " << edge.u << " ↔ House " << edge.v 
                << " : " << edge.weight << " coins\n";
        }
        
    } else {
        cout << "Invalid choice!\n";
        waitForEnter();
        return;
    }
    
    cout << "\n" << string(50, '=') << "\n";
    cout << "TESTING ALGORITHMS:\n";
    cout << string(50, '=') << "\n\n";
    
    // Run all algorithms
    int primResult = primMST(graph, n);
    int kruskalResult = kruskalMST(edges, n);
    int boruvkaResult = boruvkaMST(edges, n);
    
    // Display results
    cout << "PRIM'S ALGORITHM:\n";
    cout << "  Minimum cost: " << primResult << " coins\n";
    cout << "  Complexity: O(E log V)\n\n";
    
    cout << "KRUSKAL'S ALGORITHM:\n";
    cout << "  Minimum cost: " << kruskalResult << " coins\n";
    cout << "  Complexity: O(E log E)\n\n";
    
    cout << "BORUVKA'S ALGORITHM:\n";
    cout << "  Minimum cost: " << boruvkaResult << " coins\n";
    cout << "  Complexity: O(E log V)\n\n";
    
    cout << string(50, '-') << "\n";
    cout << "RESULTS SUMMARY:\n\n";
    
    if (primResult == kruskalResult && kruskalResult == boruvkaResult) {
        cout << "✓ ALL ALGORITHMS AGREE!\n";
        cout << "Minimum wire cost: " << primResult << " coins\n";
    } else {
        cout << "⚠ RESULTS DIFFER:\n";
        cout << "  Prim: " << primResult << " coins\n";
        cout << "  Kruskal: " << kruskalResult << " coins\n";
        cout << "  Boruvka: " << boruvkaResult << " coins\n";
    }
    
    // Algorithm comparison
    cout << "\n" << string(50, '-') << "\n";
    cout << "ALGORITHM COMPARISON:\n\n";
    cout << "• Prim's: Best for dense graphs\n";
    cout << "• Kruskal's: Best for sparse graphs\n";
    cout << "• Boruvka's: Best for parallel processing\n";
    
    // Budget check (for village context)
    int budget = 15; // Default village budget
    cout << "\n" << string(50, '-') << "\n";
    cout << "VILLAGE BUDGET ANALYSIS:\n\n";
    cout << "Village budget: " << budget << " coins\n";
    cout << "Minimum cost: " << primResult << " coins\n";
    
    if (primResult <= budget) {
        cout << "✓ Project is within budget!\n";
        cout << "Remaining: " << (budget - primResult) << " coins\n";
    } else {
        cout << "✗ Project exceeds budget by " << (primResult - budget) << " coins\n";
    }
    
    waitForEnter();
}

// ==================== ROUND 3: KNAPSACK ALGORITHMS ====================

// Greedy Fractional Knapsack
double greedyFractionalKnapsack(vector<pair<int, int>>& items, int capacity) {
    // Sort by value/weight ratio (descending)
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        double ratioA = (double)a.second / a.first;
        double ratioB = (double)b.second / b.first;
        return ratioA > ratioB;
    });
    
    double totalValue = 0.0;
    int remaining = capacity;
    
    for (auto& [weight, value] : items) {
        if (remaining >= weight) {
            totalValue += value;
            remaining -= weight;
        } else {
            totalValue += value * ((double)remaining / weight);
            break;
        }
    }
    
    return totalValue;
}

// Greedy 0/1 Knapsack
int greedy01Knapsack(vector<pair<int, int>>& items, int capacity) {
    // Sort by value/weight ratio (descending)
    sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        double ratioA = (double)a.second / a.first;
        double ratioB = (double)b.second / b.first;
        return ratioA > ratioB;
    });
    
    int totalValue = 0;
    int remaining = capacity;
    
    for (auto& [weight, value] : items) {
        if (remaining >= weight) {
            totalValue += value;
            remaining -= weight;
        }
    }
    
    return totalValue;
}

// Dynamic Programming 0/1 Knapsack
int dpKnapsack(vector<pair<int, int>>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        int weight = items[i-1].first;
        int value = items[i-1].second;
        
        for (int w = 0; w <= capacity; w++) {
            if (weight <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight] + value);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][capacity];
}
void testRound3() {
    clearScreen();
    displayHeader();
    
    cout << "TEST ROUND 3: KNAPSACK ALGORITHMS\n";
    cout << "==================================================\n\n";
    
    cout << "Noya's Cow-Cart Problem\n\n";
    
    // Default values
    vector<pair<int, int>> defaultItems = {
        {10, 60},  // Spices
        {20, 100}, // Cloth
        {30, 120}, // Pots
        {15, 70},  // Herbs
        {25, 90}   // Tools
    };
    int defaultCapacity = 50;
    
    vector<pair<int, int>> items;
    int capacity;
    
    int choice;
    cout << "Choose input method:\n";
    cout << "1. Use default values (Noya's problem)\n";
    cout << "2. Enter custom values\n";
    cout << "Enter choice (1-2): ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        // Use default values
        items = defaultItems;
        capacity = defaultCapacity;
        
        cout << "\nUsing default values:\n";
        cout << "Cart capacity: " << capacity << "kg\n";
        cout << "Available items:\n";
        int i = 1;
        for (auto& [weight, value] : items) {
            cout << i++ << ". Weight: " << weight << "kg, Value: " << value 
                 << " coins, Ratio: " << (double)value/weight << " coins/kg\n";
        }
    } else if (choice == 2) {
        // Get custom input
        clearScreen();
        displayHeader();
        
        cout << "CUSTOM KNAPSACK PROBLEM\n";
        cout << "==================================================\n\n";
        
        // Get capacity
        cout << "Enter cart capacity (kg): ";
        cin >> capacity;
        cin.ignore();
        
        // Get number of items
        int numItems;
        cout << "Enter number of items: ";
        cin >> numItems;
        cin.ignore();
        
        if (numItems <= 0) {
            cout << "Invalid number of items!\n";
            waitForEnter();
            return;
        }
        
        // Get items
        items.clear();
        cout << "\nEnter items (weight value):\n";
        for (int i = 1; i <= numItems; i++) {
            int weight, value;
            cout << "Item " << i << ": ";
            cin >> weight >> value;
            cin.ignore();
            
            if (weight <= 0 || value <= 0) {
                cout << "Weight and value must be positive!\n";
                i--; // Retry this item
                continue;
            }
            
            items.push_back({weight, value});
        }
        
        // Show entered items
        clearScreen();
        displayHeader();
        cout << "YOUR KNAPSACK PROBLEM:\n";
        cout << "==================================================\n\n";
        cout << "Cart capacity: " << capacity << "kg\n";
        cout << "Number of items: " << items.size() << "\n\n";
        cout << "Items:\n";
        int i = 1;
        for (auto& [weight, value] : items) {
            cout << i++ << ". Weight: " << weight << "kg, Value: " << value 
                 << " coins, Ratio: " << (double)value/weight << " coins/kg\n";
        }
    } else {
        cout << "Invalid choice!\n";
        waitForEnter();
        return;
    }
    
    cout << "\n==================================================\n";
    cout << "TESTING ALGORITHMS:\n\n";
    
    // Make copies for each algorithm (since they modify the items)
    vector<pair<int, int>> itemsFrac = items;
    vector<pair<int, int>> items01 = items;
    vector<pair<int, int>> itemsDP = items;
    
    // Test Greedy Fractional
    cout << "1. GREEDY FRACTIONAL KNAPSACK:\n";
    double greedyFracResult = greedyFractionalKnapsack(itemsFrac, capacity);
    cout << "   Maximum value: " << greedyFracResult << " coins\n";
    cout << "   Complexity: O(n log n)\n";
    cout << "   Approach: Sort by value/weight ratio, take fractions\n";
    
    // Show which items would be taken
    cout << "   Items taken (fractional allowed):\n";
    // Re-run to show selection
    sort(itemsFrac.begin(), itemsFrac.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (double)a.second / a.first > (double)b.second / b.first;
    });
    
    double remaining = capacity;
    double totalVal = 0;
    for (auto& [weight, value] : itemsFrac) {
        if (remaining >= weight) {
            cout << "     • Full item: " << weight << "kg, " << value << " coins\n";
            totalVal += value;
            remaining -= weight;
        } else if (remaining > 0) {
            double fraction = remaining / weight;
            double fracValue = value * fraction;
            cout << "     • Fraction: " << remaining << "/" << weight << "kg, " 
                 << fracValue << " coins (" << fraction * 100 << "%)\n";
            totalVal += fracValue;
            remaining = 0;
        }
    }
    cout << "   Total: " << totalVal << " coins\n\n";
    
    // Test Greedy 0/1
    cout << "2. GREEDY 0/1 KNAPSACK:\n";
    int greedy01Result = greedy01Knapsack(items01, capacity);
    cout << "   Maximum value: " << greedy01Result << " coins\n";
    cout << "   Complexity: O(n log n)\n";
    cout << "   Approach: Sort by value/weight ratio, take whole items only\n";
    
    // Show selection
    cout << "   Items taken (whole items only):\n";
    sort(items01.begin(), items01.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (double)a.second / a.first > (double)b.second / b.first;
    });
    
    int remaining01 = capacity;
    int totalVal01 = 0;
    for (auto& [weight, value] : items01) {
        if (remaining01 >= weight) {
            cout << "     • Item: " << weight << "kg, " << value << " coins\n";
            totalVal01 += value;
            remaining01 -= weight;
        }
    }
    cout << "   Space left: " << remaining01 << "kg\n";
    cout << "   Total: " << totalVal01 << " coins\n\n";
    
    // Test DP 0/1
    cout << "3. DYNAMIC PROGRAMMING (0/1):\n";
    int dpResult = dpKnapsack(itemsDP, capacity);
    cout << "   Maximum value: " << dpResult << " coins\n";
    cout << "   Complexity: O(n*capacity) = O(" << items.size() << "*" << capacity 
         << ") = O(" << items.size() * capacity << ")\n";
    cout << "   Approach: Build DP table, guaranteed optimal\n\n";
        cout << "\n--- RESULTS ---\n";
    cout << "Fractional (O(n log n)): " << greedyFracResult << " coins\n";
    cout << "Greedy 0/1 (O(n log n)): " << greedy01Result << " coins\n";
    cout << "DP 0/1 (O(n*W)):         " << dpResult << " coins\n\n";
    
    if (greedy01Result == dpResult) {
        cout << "✓ Greedy optimal\n";
    }
    waitForEnter();
}

// ==================== ROUND 4: SHORTEST PATH ALGORITHMS ====================
int dijkstra(vector<vector<pair<int, int>>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& [v, weight] : graph[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[end];
}

// Bellman-Ford Algorithm - KEEP ONLY ONE DEFINITION
int bellmanFord(vector<tuple<int, int, int>>& edges, int n, int start, int end) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;
    
    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int w = get<2>(edge);
            
            if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // Check for negative cycles
    for (auto& edge : edges) {
        int u = get<0>(edge);
        int v = get<1>(edge);
        int w = get<2>(edge);
        
        if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
            return -1; // Negative cycle
        }
    }
    
    return dist[end];
}

// A* Algorithm - KEEP ONLY ONE DEFINITION
struct AStarNode {
    int node;
    int f; // f = g + h
    int g; // cost from start
    int h; // heuristic to goal
    
    bool operator>(const AStarNode& other) const {
        return f > other.f;
    }
};

// Heuristic functions - KEEP ONLY ONE DEFINITION
int euclideanHeuristic(int node, int end, const vector<pair<int, int>>& coordinates) {
    if (coordinates.empty()) return 0;
    
    int dx = coordinates[node].first - coordinates[end].first;
    int dy = coordinates[node].second - coordinates[end].second;
    return sqrt(dx*dx + dy*dy) * 100;
}

int aStarSearch(vector<vector<pair<int, int>>>& graph, int start, int end, 
                const vector<pair<int, int>>& coordinates) {
    int n = graph.size();
    vector<int> gScore(n, numeric_limits<int>::max());
    vector<int> fScore(n, numeric_limits<int>::max());
    
    gScore[start] = 0;
    fScore[start] = euclideanHeuristic(start, end, coordinates);
    
    priority_queue<AStarNode, vector<AStarNode>, greater<AStarNode>> openSet;
    openSet.push({start, fScore[start], 0, fScore[start]});
    
    while (!openSet.empty()) {
        AStarNode current = openSet.top();
        openSet.pop();
        
        int u = current.node;
        
        if (u == end) {
            return gScore[end];
        }
        
        for (auto& [v, weight] : graph[u]) {
            int tentative_gScore = gScore[u] + weight;
            
            if (tentative_gScore < gScore[v]) {
                gScore[v] = tentative_gScore;
                fScore[v] = gScore[v] + euclideanHeuristic(v, end, coordinates);
                openSet.push({v, fScore[v], gScore[v], fScore[v] - gScore[v]});
            }
        }
    }
    
    return numeric_limits<int>::max();
}

// Test function for Round 4
void testRound4() {
    clearScreen();
    displayHeader();
    
    cout << "TEST ROUND 4: SHORTEST PATH ALGORITHMS\n";
    cout << "==================================================\n\n";
    
    cout << "Village Path Finding: Hilltop (0) → Lotus Garden (7)\n\n";
    
    // Default village map (8 locations)
    int n = 8;
    
    // Coordinates for A* heuristic (approximate positions)
    vector<pair<int, int>> coordinates = {
        {0, 0},   // 0: Hilltop
        {2, 0},   // 1: School
        {3, 1},   // 2: Home-A
        {4, 2},   // 3: Home-B
        {5, 1},   // 4: Home-C
        {1, 3},   // 5: Castle
        {4, 4},   // 6: Bank
        {6, 5}    // 7: Lotus Garden
    };
    
    // Adjacency list for Dijkstra and A*
    vector<vector<pair<int, int>>> graph(n);
    
    // Edge list for Bellman-Ford
    vector<tuple<int, int, int>> edges;
    
    // Village roads
    vector<tuple<int, int, int>> roads = {
        make_tuple(0, 1, 500),  // Hilltop ↔ School
        make_tuple(1, 2, 100),  // School ↔ Home-A
        make_tuple(2, 3, 25),   // Home-A ↔ Home-B
        make_tuple(3, 4, 100),  // Home-B ↔ Home-C
        make_tuple(1, 4, 200),  // School ↔ Home-C
        make_tuple(1, 5, 300),  // School ↔ Castle
        make_tuple(5, 6, 400),  // Castle ↔ Bank
        make_tuple(6, 4, 50),   // Bank ↔ Home-C
        make_tuple(6, 7, 500)   // Bank ↔ Lotus Garden
    };
    
    // Build graph (undirected)
    for (auto& road : roads) {
        int u = get<0>(road);
        int v = get<1>(road);
        int w = get<2>(road);
        
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        edges.push_back(make_tuple(u, v, w));
        edges.push_back(make_tuple(v, u, w));
    }
    
    // Show village information
    cout << "VILLAGE LOCATIONS:\n";
    cout << "╔══════╤════════════════╗\n";
    cout << "║ Index │ Location      ║\n";
    cout << "╠══════╪════════════════╣\n";
    cout << "║   0   │ Hilltop       ║\n";
    cout << "║   1   │ School        ║\n";
    cout << "║   2   │ Home-A        ║\n";
    cout << "║   3   │ Home-B        ║\n";
    cout << "║   4   │ Home-C        ║\n";
    cout << "║   5   │ Castle        ║\n";
    cout << "║   6   │ Bank          ║\n";
    cout << "║   7   │ Lotus Garden  ║\n";
    cout << "╚══════╧════════════════╝\n\n";
    
    
    vector<string> locations = {"Hilltop", "School", "Home-A", "Home-B", 
                                "Home-C", "Castle", "Bank", "Lotus Garden"};
    
    

    showFancyVillageMap(); // map
    
    // Get start and end from user
    int start, end;
    int useDefault;
    
    cout << "Choose:\n";
    cout << "1. Use default (Hilltop → Lotus Garden)\n";
    cout << "2. Choose custom start and end\n";
    cout << "Enter choice (1-2): ";
    cin >> useDefault;
    cin.ignore();
    
    if (useDefault == 1) {
        start = 0;
        end = 7;
        cout << "\nUsing: Hilltop (0) → Lotus Garden (7)\n";
    } else if (useDefault == 2) {
        cout << "\nEnter start node (0-7): ";
        cin >> start;
        cout << "Enter end node (0-7): ";
        cin >> end;
        cin.ignore();
        
        if (start < 0 || start >= n || end < 0 || end >= n) {
            cout << "Invalid node indices!\n";
            waitForEnter();
            return;
        }
        
        cout << "\nFinding path: " << locations[start] << " → " << locations[end] << "\n";
    } else {
        cout << "Invalid choice!\n";
        waitForEnter();
        return;
    }
    
    cout << "\n==================================================\n";
    cout << "TESTING ALGORITHMS:\n\n";
    
    // Test Dijkstra's Algorithm
    cout << "1. DIJKSTRA'S ALGORITHM:\n";
    int dijkstraResult = dijkstra(graph, start, end);

    
    // Test Bellman-Ford Algorithm
    cout << "2. BELLMAN-FORD ALGORITHM:\n";
    int bfResult = bellmanFord(edges, n, start, end);
    
    // Test A* Algorithm
    cout << "3. A* SEARCH ALGORITHM:\n";
    int aStarResult = aStarSearch(graph, start, end, coordinates);
    
        cout << "\n--- RESULTS ---\n";
    cout << "Dijkstra (O((V+E)logV)): " << dijkstraResult << " units\n";
    cout << "Bellman-Ford (O(V*E)):   " << (bfResult == -1 ? "Neg cycle" : to_string(bfResult)) << " units\n";
    cout << "A* Search:               " << aStarResult << " units\n";
    
    if (dijkstraResult == bfResult && bfResult == aStarResult) {
        cout << "\n✓ All agree: " << dijkstraResult << " units\n";
    }
    
    if (start == 0 && end == 7) {
        cout << "\nOptimal: Hilltop→School→Home-C→Bank→Lotus Garden (1250 units)\n";
    }
    
    cout << "\nBest: A* (fastest with heuristic)\n";

    waitForEnter();
}
// ==================== MAIN TEST FUNCTION ====================

inline void testAlgorithms() {
    int choice;
    
    do {
        clearScreen();
        displayHeader();
        
        cout << "TEST ALGORITHMS - SELECT ROUND\n";
        cout << "==================================================\n\n";
        
        cout << "1. Round 1 - String Search Algorithms\n";
        cout << "   • Naive Search, KMP, Sunday Algorithm\n\n";
        
        cout << "2. Round 2 - Minimum Spanning Tree Algorithms\n";
        cout << "   • Prim's, Kruskal's Algorithms\n\n";
        
        cout << "3. Round 3 - Knapsack Algorithms\n";
        cout << "   • Greedy Fractional, Greedy 0/1, Dynamic Programming\n\n";
        
        cout << "4. Round 4 - Shortest Path Algorithms\n";
        cout << "   • Dijkstra's, Bellman-Ford Algorithms\n\n";
        
        cout << "5. Back to Main Menu\n";
        cout << "==================================================\n\n";
        
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore();
        
        switch(choice) {
            case 1:
                testRound1();
                break;
            case 2:
                testRound2();
                break;
            case 3:
                testRound3();
                break;
            case 4:
                testRound4();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice!\n";
                waitForEnter();
        }
        
    } while (true);
}

#endif // TEST_ALGORITHMS_H
