class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> rows[9];
        set<int> cols[9];
        set<int> boxes[9];

        for (int i{}; i < 9; ++i) {
            auto & row = board[i];
            for (int j{} ; j < 9; ++j) {
                if (row[j] == '.') continue;

                const int v = row[j] - '0';
                if (rows[i].contains(v)) return false;
                if (cols[j].contains(v)) return false;

                int k = 3*(i/3) + j/3;
                if (boxes[k].contains(v)) return false;
                
                rows[i].insert(v);
                cols[j].insert(v);
                boxes[k].insert(v);
            }
        }
        return true;
    }
};
