#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, p;
    
    cout << "Enter dimensions for first matrix (rows columns): ";
    cin >> n >> m;
    
    vector<vector<int>> A(n, vector<int>(m));
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
        
    int r, c;
    cout << "Enter dimensions for second matrix (rows columns): ";
    cin >> r >> c;
   
    if (m != r) {
        cout << "Error: Matrices cannot be multiplied." << endl;
        return 1;
    }
    
    vector<vector<int>> B(r, vector<int>(c));
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> B[i][j];
        }
    }
    
    cout << "\nFirst Matrix:" << endl;
    for (const auto& row : A) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    
    cout << "\nSecond Matrix:" << endl;
    for (const auto& row : B) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> C(n, vector<int>(c, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    cout << "\nResultant Matrix after multiplication:" << endl;
    for (const auto& row : C) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    
    return 0;
}
