#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visited[7][7];
string path_desc;
int total_paths = 0;

// Coordinate offsets for U, D, L, R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, int steps) {
    // Base Case: Reached target
    if (r == 6 && c == 0) {
        if (steps == 48) total_paths++;
        return;
    }
    
    // Pruning 1: Reached destination early
    if (steps == 48) return;

    // Pruning 2: Wall / visited splitting (Up/Down wall split)
    if ((r == 0 || r == 6 || (visited[r-1][c] && visited[r+1][c])) && c > 0 && c < 6 && !visited[r][c-1] && !visited[r][c+1]) return;
    // Pruning 3: Wall / visited splitting (Left/Right wall split)
    if ((c == 0 || c == 6 || (visited[r][c-1] && visited[r][c+1])) && r > 0 && r < 6 && !visited[r-1][c] && !visited[r+1][c]) return;

    visited[r][c] = true;

    // Determine allowed direction(s)
    if (path_desc[steps] != '?') {
        int dir = 0;
        if (path_desc[steps] == 'U') dir = 0;
        else if (path_desc[steps] == 'D') dir = 1;
        else if (path_desc[steps] == 'L') dir = 2;
        else if (path_desc[steps] == 'R') dir = 3;

        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (nr >= 0 && nr < 7 && nc >= 0 && nc < 7 && !visited[nr][nc]) {
            dfs(nr, nc, steps + 1);
        }
    } else {
        // Try all 4 directions if wildcard '?'
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < 7 && nc >= 0 && nc < 7 && !visited[nr][nc]) {
                dfs(nr, nc, steps + 1);
            }
        }
    }

    visited[r][c] = false; // Backtrack
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (cin >> path_desc) {
        dfs(0, 0, 0);
        cout << total_paths << "\n";
    }
    return 0;
}