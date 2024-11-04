#include <iostream>
#include <vector>

using namespace std;

// NextValue function to find the next valid color for vertex `k`
bool NextValue(int k, vector<vector<int>>& graph, int m, vector<int>& colors) {
    int n = graph.size();
    while (true) {
        colors[k] = (colors[k] + 1) % (m + 1);  // Try the next color
        if (colors[k] == 0) {
            return false;  // No color possible, backtrack
        }
        
        // Check if the color assignment is valid
        bool valid = true;
        for (int j = 0; j < n; ++j) {
            if (graph[k][j] == 1 && colors[k] == colors[j]) {  // Adjacent vertex has the same color
                valid = false;
                break;
            }
        }
        
        if (valid) return true;  // Found a valid color
    }
}

// Recursive function to check if the m-coloring problem has a solution
bool mColoring(int k, vector<vector<int>>& graph, int m, vector<int>& colors) {
    int n = graph.size();
    while (true) {
        if (!NextValue(k, graph, m, colors)) return false;  // No color possible, backtrack
        
        if (k == n - 1) {
            return true;  // Solution found
        } else {
            if (mColoring(k + 1, graph, m, colors)) return true;  // Recurse for the next vertex
        }
    }
}

// Function to initialize the graph coloring process
bool graphColoring(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0);  // Initialize colors to 0 (no color assigned)
    return mColoring(0, graph, m, colors);
}

int main() {
    // Define the graph as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    
    int m = 3;  // Number of colors
    if (graphColoring(graph, m)) {
        cout << "It is possible to color the graph with " << m << " colors." << endl;
    } else {
        cout << "It is not possible to color the graph with " << m << " colors." << endl;
    }
    
    return 0;
}
