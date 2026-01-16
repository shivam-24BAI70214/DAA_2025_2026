#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long operation_count = 0;
int max_depth = 0;
void complexRec(int n, int current_depth) {
    max_depth = max(max_depth, current_depth);
    operation_count++;

    if (n <= 2) {
        operation_count++;
        return;
    }

    int p = n;
    operation_count++;
    while (p > 0) {
        operation_count++;

        vector<int> temp(n);
        operation_count += n;

        for (int i = 0; i < n; i++) {
            operation_count++;
            temp[i] = i ^ p;
            operation_count++;
        }
        p >>= 1;
        operation_count++;
    }
    vector<int> small(n);
    operation_count += n;
    for (int i = 0; i < n; i++) {
        operation_count++;
        small[i] = i * i;
        operation_count++;
    }
    reverse(small.begin(), small.end());
    operation_count += n;

    complexRec(n / 2, current_depth + 1);
    operation_count++;
    complexRec(n / 2, current_depth + 1);
    operation_count++;
    complexRec(n / 2, current_depth + 1);
    operation_count++;
}

int main() {
    int n = 300;
    complexRec(n, 1);
    cout << "Input Size: " << n << endl;
    cout << "Maximum Recursion Depth: " << max_depth << endl;
    cout << "Approximate Operation Count: " << operation_count << endl;
    return 0;
}
