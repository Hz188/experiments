#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;
namespace std {
    template<>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            auto hash1 = hash<int>{}(p.first);
            auto hash2 = hash<int>{}(p.second);
            return hash1 * 31 + hash2;  // 使用质数31
        }
    };
}
class SparseMatrix {
public:
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}

    void add_value(int row, int col, int value) {
        if (value != 0) {
            data[{row, col}] = value;
        }
    }

    vector<vector<int>> to_dense() const {
        vector<vector<int>> dense(rows, vector<int>(cols, 0));
        for (const auto& [key, value] : data) {
            int row = key.first;
            int col = key.second;
            dense[row][col] = value;
        }
        return dense;
    }

    static SparseMatrix from_dense(const vector<vector<int>>& dense) {
        int rows = dense.size();
        int cols = dense[0].size();
        SparseMatrix sparse(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dense[i][j] != 0) {
                    sparse.add_value(i, j, dense[i][j]);
                }
            }
        }
        return sparse;
    }

    SparseMatrix operator*(const SparseMatrix& other) const {
        assert(cols == other.rows);
        SparseMatrix result(rows, other.cols);
        for (const auto& [key, value] : data) {
            int row = key.first;
            int col = key.second;
            for (int k = 0; k < other.cols; ++k) {
                if (other.data.find({col, k}) != other.data.end()) {
                    result.add_value(row, k, result.data[{row, k}] + value * other.data.at({col, k}));
                }
            }
        }
        return result;
    }

    void print() const {
        for (const auto& [key, value] : data) {
            cout << "(" << key.first << ", " << key.second << ") -> " << value << endl;
        }
    }

private:
    int rows, cols;
    unordered_map<pair<int, int>, int, hash<pair<int, int>>> data;
};



void test_sparse_matrix() {
    vector<vector<int>> dense1 = {
        {1, 0, 0},
        {0, 0, 2},
        {0, 3, 0}
    };

    vector<vector<int>> dense2 = {
        {0, 4, 0},
        {5, 0, 0},
        {0, 0, 6}
    };

    SparseMatrix sparse1 = SparseMatrix::from_dense(dense1);
    SparseMatrix sparse2 = SparseMatrix::from_dense(dense2);

    SparseMatrix result = sparse1 * sparse2;

    vector<vector<int>> result_dense = result.to_dense();

    cout << "Resultant Dense Matrix:" << endl;
    for (const auto& row : result_dense) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    test_sparse_matrix();
    return 0;
}