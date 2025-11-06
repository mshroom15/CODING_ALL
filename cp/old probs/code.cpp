# GCD Problems

## Problem 1: Common Divisor Count
**Description**: Given two integers `a` and `b`, find how many integers `d` exist such that `d` divides both `a` and `b`.

**Input**:
```
10 15
```
**Output**:
```
2
```

**Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int g = __gcd(a, b);
    int count = 0;
    for (int i = 1; i <= g; i++) {
        if (g % i == 0) count++;
    }
    cout << count << endl;
    return 0;
}
```

---

## Problem 2: All Pair GCD Sum
**Description**: Given an array of integers, find the sum of GCDs of all distinct pairs.

**Input**:
```
3
4 6 8
```
**Output**:
```
6
```

**Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += __gcd(a[i], a[j]);
        }
    }
    cout << sum << endl;
    return 0;
}
```

---

## Problem 3: GCD in Range [1...N] with X
**Description**: Given two integers `n` and `x`, count how many integers from `1` to `n` have GCD with `x` equal to 1.

**Input**:
```
10 4
```
**Output**:
```
5
```

**Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (__gcd(i, x) == 1) count++;
    }
    cout << count << endl;
    return 0;
}
```

# LCM Problems

## Problem 1: LCM of Array
**Description**: Given an array of `n` integers, find the LCM of all elements.

**Input**:
```
3
2 7 3
```
**Output**:
```
42
```

**Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}
int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long res = a[0];
    for (int i = 1; i < n; i++) {
        res = lcm(res, a[i]);
    }
    cout << res << endl;
    return 0;
}
```

---

## Problem 2: Smallest Common Multiple of Two Numbers
**Description**: Given two integers `a` and `b`, print their LCM.

**Input**:
```
6 8
```
**Output**:
```
24
```

**Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << a / __gcd(a, b) * b << endl;
    return 0;
}
```

---

## Problem 3: LCM in Range
**Description**: Given integers `l` and `r`, compute the LCM of all numbers in the range `[l, r]`.

**Input**:
```
1 4
```
**Output**:
```
12
```

**Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b) {
    return a / __gcd(a, b) * b;
}
int main() {
    int l, r;
    cin >> l >> r;
    long long res = l;
    for (int i = l + 1; i <= r; i++) {
        res = lcm(res, i);
    }
    cout << res << endl;
    return 0;
}
```



