#include <iostream>
#include <vector>

using namespace std;

// NextValue function to find the next valid color for vertex `k`
void NextValue(int k, vector<vector<int>>& graph, int m, vector<int>& colors) {
    int n = graph.size();
    while (true) {
        colors[k] = (colors[k] + 1) % (m + 1);  // Try the next color
        if (colors[k] == 0) {
            return;  // No color possible, backtrack
        }
        
        // Check if the color assignment is valid
        bool valid = true;
        for (int j = 0; j < n; ++j) {
            if (graph[k][j] == 1 && colors[k] == colors[j]) {  // Adjacent vertex has the same color
                valid = false;
                break;
            }
        }
        
        if (valid) return;  // Found a valid color
    }
}

// Recursive function to solve the m-coloring problem
void mColoring(int k, vector<vector<int>>& graph, int m, vector<int>& colors) {
    int n = graph.size();
    while (true) {
        NextValue(k, graph, m, colors);
        if (colors[k] == 0) return;  // No color possible, backtrack
        
        if (k == n - 1) {
            // A valid coloring is found, print the solution
            for (int i = 0; i < n; ++i) {
                cout << colors[i] << " ";
            }
            cout << endl;
        } else {
            mColoring(k + 1, graph, m, colors);  // Recurse for the next vertex
        }
    }
}

// Function to initialize the graph coloring process
void graphColoring(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0);  // Initialize colors to 0 (no color assigned)
    mColoring(0, graph, m, colors);
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
    cout << "Color assignments for the graph:\n";
    graphColoring(graph, m);
    
    return 0;
}
