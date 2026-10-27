#include <bits/stdc++.h>
using namespace std;
void countingsort(int a[], int n) {
    int k = a[0];
    for (int i = 1; i < n; i++) {
        k = max(a[i], k);
    }
    int count[k + 1] = {
        0
    };
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }
int result[n];
for(int i = 0; i < n; i++){
    cout << result[i] << " ";
}
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    countingsort(a, n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}