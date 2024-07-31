class Solution {
public:
    void help(int n, vector<vector<int>>& matrix, int threshold) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] =
                        min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] > threshold) {
                    matrix[i][j] = 1e8;
                }
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    int findTheCity(int n, vector<vector<int>>& nums, int threshold) {
        vector<vector<int>> edges(n, vector<int>(n, 1e8));

        for (auto it : nums) {
            edges[it[0]][it[1]] = it[2];
            edges[it[1]][it[0]] = it[2];
        }

        help(n, edges, threshold);
        int cnt = 1e8;
        int city = n;

        for (int i = n - 1; i >= 0; i--) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                // cout<<edges[i][j]<<" "<<i<<" "<<j<<" ";
                if (edges[i][j] != 1e8) {
                    temp++;
                }
            }
            // cout<<endl;
            if (cnt > temp) {
                city = i;
                cnt = temp;
            }
        }

        return city;
    }
};