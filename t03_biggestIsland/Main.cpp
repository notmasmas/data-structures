#include <iostream>
#include <vector>
#include <stack>

struct Cell {
    int row;
    int column;
};

void read_input(std::vector<std::vector<char>> &matrix)
{
    std::string line;

    while (std ::cin >> line)
    {
        std ::vector<char> aux(line.cbegin(), line.cend());
        matrix.push_back(aux);
    }
}

std::vector<std::vector<bool>> create_visited_matrix(int rows, int columns)
{

    std::vector<std::vector<bool>> visited_matrix(rows, std::vector<bool>(columns, false));
    return visited_matrix;
}

bool is_valid_neighbor(Cell cell, std::vector<std::vector<char>>& matrix, std::vector<std::vector<bool>>& visited_matrix) {

    int matrix_rows = matrix.size();
    int matrix_columns = matrix[0].size();

    bool check_row = cell.row >= 0 && cell.row < matrix_rows;
    bool check_column = cell.column >= 0 && cell.column < matrix_columns;

    if (!check_row || !check_column) { // to avoid crashing when checking outbouts coords in visited matrix or normal matrix
        return false;
    }

    bool check_visited = visited_matrix[cell.row][cell.column];
    bool check_island = matrix[cell.row][cell.column] == '1';

    if(!check_visited && check_island) {
        return true;
    }

    return false;
}

int main() {

    std::vector<std::vector<char>> matrix;
    read_input(matrix);
    int matrix_rows = matrix.size();
    int matrix_columns = matrix[0].size();
    std::vector<std::vector<bool>> visited_matrix = create_visited_matrix(matrix_rows, matrix_columns);
    std::stack<Cell> island_stack;

    int biggest_island = 0;

    for (int r = 0; r < matrix_rows; r++) {
        for (int c = 0; c < matrix_columns; c++) {

            int size_island = 0;

            char cell = matrix[r][c];
            
            if (cell == '1' && !visited_matrix[r][c]) { // if cell is an island and hasn't been visited

                visited_matrix[r][c] = true; // now it has been visited
                size_island++;
                Cell cell = {r, c};
                island_stack.push(cell);

                do {

                    Cell current_cell = island_stack.top();
                    island_stack.pop();

                    std::stack<Cell> neighbors;

                    neighbors.push({current_cell.row + 1, current_cell.column}); // bottom
                    neighbors.push({current_cell.row - 1, current_cell.column}); // top
                    neighbors.push({current_cell.row, current_cell.column - 1}); // left
                    neighbors.push({current_cell.row, current_cell.column + 1}); // right

                    while (!neighbors.empty()) {
                        Cell cell = neighbors.top();
                        neighbors.pop();

                        bool is_valid = is_valid_neighbor(cell, matrix, visited_matrix);

                        if (is_valid) {
                            island_stack.push(cell);
                            size_island++;
                            visited_matrix[cell.row][cell.column] = true;
                        }
                    }

                } while (!island_stack.empty());

                if (size_island > biggest_island) {
                    biggest_island = size_island;
                }
            }
        }
    }

    std::cout << biggest_island << std::endl;
}
