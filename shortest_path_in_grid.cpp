#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid.at(0).at(0) != 0 || grid.at(grid.size() - 1).at(grid.size() - 1) != 0) return -1;

    if (grid.size() == 1) return 1;

    vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));

    vector<vector<pair<int, int>>> previous(grid.size(), vector<pair<int, int>>(grid.size(), make_pair(-1, -1)));

    int x[] = { 1, 0, 1, 1, 0, -1, -1, -1 };
    int y[] = { 1, 1, 0, -1, -1, -1, 1, 0 };

    queue<pair<int, int>> queue;

    queue.push(make_pair(0, 0));

    visited[0][0] = true;

    while (!queue.empty())
    {
        pair<int, int> cell = queue.front();

        queue.pop();

        for (int i = 0; i < 8; i++)
        {
            pair<int, int> nextCell = make_pair(cell.first + y[i], cell.second + x[i]);

            if (nextCell.first >= 0 &&
                nextCell.first < grid.size() &&
                nextCell.second >= 0 &&
                nextCell.second < grid.size() &&
                grid.at(nextCell.second).at(nextCell.first) == 0 &&
                !visited.at(nextCell.second).at(nextCell.first))
            {
                queue.push(nextCell);
                visited[nextCell.second][nextCell.first] = true;
                previous[nextCell.second][nextCell.first] = cell;
            }
        }
    }

    if (previous.at(grid.size() - 1).at(grid.size() - 1) == make_pair(-1, -1)) return -1;

    pair<int, int> coords = previous.at(grid.size() - 1).at(grid.size() - 1);

    int count = 1;

    while (coords != make_pair(-1, -1))
    {
        count++;
        coords = previous[coords.second][coords.first];
    }

    return count;
}

int main()
{
    vector<vector<int>> test = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    cout << shortestPathBinaryMatrix(test) << endl;
}
