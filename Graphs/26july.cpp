#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // Initialize the distance matrix with infinity
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Set the distance from a city to itself as 0
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    // Fill the initial distances from the edges
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Use the Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Find the city with the smallest number of neighbors within the distance threshold
    int minNeighbors = INT_MAX;
    int cityWithMinNeighbors = -1;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= distanceThreshold) {
                ++count;
            }
        }
        if (count <= minNeighbors) {
            minNeighbors = count;
            cityWithMinNeighbors = i;
        }
    }

    return cityWithMinNeighbors;
}


// Test case
int main() {

    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 3}
    };
    int n = 4;
    int distanceThreshold = 4;
    int result = findTheCity(n, edges, distanceThreshold);
    // Output should be 3, since city 3 can only reach 3 cities (0, 1, and 2) within a threshold of 4
    cout << "City with the smallest number of neighbors within threshold distance: " << result << endl;
    return 0;
}