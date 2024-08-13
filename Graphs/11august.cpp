#include <iostream>
#include <vector>


using namespace std;

int m, n;

void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) {
        return;
    }
    visited[i][j] = true;

    DFS(grid, i + 1, j, visited);
    DFS(grid, i - 1, j, visited);
    DFS(grid, i, j + 1, visited);
    DFS(grid, i, j - 1, visited);
}

int num_of_islands(vector<vector<int>>& grid) {
    int islands = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                DFS(grid, i, j, visited);
                islands++;
            }
        }
    }

    return islands;
}

int minDays(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();

    int islands = num_of_islands(grid);
    if (islands > 1 || islands == 0) {
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0; // change cell to water

                // Recalculate islands after changing the grid
                if (num_of_islands(grid) != 1) {
                    return 1;
                }

                grid[i][j] = 1; // restore the cell
            }
        }
    }

    return 2; // if no single cell can disconnect the island
}


int main(){

    return 0;
}