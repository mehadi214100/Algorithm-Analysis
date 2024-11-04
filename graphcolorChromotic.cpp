#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if it's possible to color the graph with m colors
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

// Wrapper function to check if the graph can be colored with `m` colors
bool canColorWithMColors(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0);  // Initialize colors to 0 (no color assigned)
    return mColoring(0, graph, m, colors);
}

// Function to find the chromatic number of the graph
int findChromaticNumber(vector<vector<int>>& graph) {
    int n = graph.size();
    int left = 1, right = n;
    int chromaticNumber = n;

    // Binary search to find the minimum number of colors
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (canColorWithMColors(graph, mid)) {
            chromaticNumber = mid;  // Found a valid coloring with `mid` colors
            right = mid - 1;        // Try for fewer colors
        } else {
            left = mid + 1;         // Need more colors
        }
    }

    return chromaticNumber;
}

int main() {
    // Define the graph as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int chromaticNumber = findChromaticNumber(graph);
    cout << "The chromatic number of the graph is: " << chromaticNumber << endl;

    return 0;
}
