#include <bits/stdc++.h>
using namespace std;

// The isprime() and nextprime() functions remain the same.
bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int nextprime(int n) {
    n++;
    while (!isprime(n)) {
        n++;
    }
    return n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr(101);
        for (int i = 1; i < 101; i++) {
            arr[i] = i;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int from, to;
            cin >> from >> to;
            arr[from] = to;
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int from, to;
            cin >> from >> to;
            arr[from] = to;
        }
        int six, one, prime;
        cin >> six >> one >> prime;
        int thor, hulk;
        cin >> thor >> hulk;
        int rollnum;
        cin >> rollnum;

        // Corrected loop for Thor
        for (int i = 0; i < rollnum; i++) {
            int roll;
            cin >> roll;

            // Case 1: Penalty Roll (A roll of 6 with the rule ON)
            if (roll == 6 && six) {
                thor = max(thor - 6, 1);
                thor = arr[thor];
            } 
            // Case 2: Bonus Roll (A roll of 1 with the rule ON)
            else if (roll == 1 && one) {
                // First, make the initial 1-square move
                if (thor + 1 <= 100) {
                    thor += 1;
                    thor = arr[thor];
                    // Then, apply the 6-square bonus boost
                    if (thor + 6 <= 100) {
                        thor += 6;
                        thor = arr[thor];
                    }
                }
            } 
            // Case 3: Normal Roll (All other cases)
            else {
                if (thor + roll <= 100) {
                    thor += roll;
                    thor = arr[thor];
                }
            }

            // The Prime Jump rule is applied at the end of any move
            if (isprime(thor) && prime) {
                int np = nextprime(thor);
                if (np <= 100) {
                    thor = np;
                    thor = arr[thor];
                }
            }
        }

        // Corrected loop for Hulk
        for (int i = 0; i < rollnum; i++) {
            int roll;
            cin >> roll;

            // Case 1: Penalty Roll (A roll of 6 with the rule ON)
            if (roll == 6 && six) {
                hulk = max(hulk - 6, 1);
                hulk = arr[hulk];
            } 
            // Case 2: Bonus Roll (A roll of 1 with the rule ON)
            else if (roll == 1 && one) {
                // First, make the initial 1-square move
                if (hulk + 1 <= 100) {
                    hulk += 1;
                    hulk = arr[hulk];
                    // Then, apply the 6-square bonus boost
                    if (hulk + 6 <= 100) {
                        hulk += 6;
                        hulk = arr[hulk];
                    }
                }
            } 
            // Case 3: Normal Roll (All other cases)
            else {
                if (hulk + roll <= 100) {
                    hulk += roll;
                    hulk = arr[hulk];
                }
            }

            // The Prime Jump rule is applied at the end of any move
            if (isprime(hulk) && prime) {
                int np = nextprime(hulk);
                if (np <= 100) {
                    hulk = np;
                    hulk = arr[hulk];
                }
            }
        }

        // The final result logic remains the same.
        if (thor == 100 && hulk == 100) {
            cout << "Both player win" << endl;
        } else if (thor == hulk) {
            cout << "Draw" << endl;
        } else if (thor > hulk) {
            cout << "Thor wins by " << (thor - hulk) << " points" << endl;
        } else {
            cout << "Hulk wins by " << (hulk - hulk) << " points" << endl;
        }
    }
    return 0;
}