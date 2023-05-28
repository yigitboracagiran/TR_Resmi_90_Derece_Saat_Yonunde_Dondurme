#include <iostream>
#include <vector>

class Solution {
public:
    void yazdir( std::vector<std::vector<int>>& matrix ) {
        int n = matrix.size();
        std::cout<<"\n";
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                std::cout<<matrix[i][j]<<" ";
            }
            std::cout<<"\n";
        }
    }

    void rotate( std::vector<std::vector<int>>& matrix ) {
        yazdir(matrix);

        int n = matrix.size();
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        yazdir(matrix);

        int a = 0, b = n - 1, c = 0;
        while ( c < n ) {
            while ( a < b ) {
                int temp = matrix[c][a];
                matrix[c][a] = matrix[c][b];
                matrix[c][b] = temp;
                a++;
                b--;
            }
            a = 0; 
            b = n - 1;
            c++;
        }
        yazdir(matrix);
    }
};

int main ( void ) {

    Solution solution;
    std::vector<std::vector<int>> matrix = { { 10, 11, 12, 13, 14 }, { 15, 16, 17, 18, 19 }, { 20, 21, 22, 23, 24 }, { 25, 26, 27, 28, 29 }, { 30, 31, 32, 33, 34} };
    solution.rotate(matrix);
    return 0;

}