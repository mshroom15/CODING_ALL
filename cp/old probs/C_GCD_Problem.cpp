#include <iostream>
#include <numeric>
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    std::cin >> n;

    if (n % 2 == 0) {
        std::cout << n - 3 << " " << 2 << " " << 1 << std::endl;
    } else {
        int mid = (n - 1) / 2;
        if (mid % 2 == 0) {
            std::cout << mid - 1 << " " << mid + 1 << " " << 1 << std::endl;
        } else {
            std::cout << mid - 2 << " " << mid + 2 << " " << 1 << std::endl;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}