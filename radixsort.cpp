#include <bits/stdc++.h>
using namespace std;
void countingsort(int a[], int n, int place) {
    int count[10] = {0};

    for(int i = 0; i < n; i++){
        count[(a[i] / place) % 10]++;
    }
    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    int result[n];
    for(int i = n - 1; i >= 0; i--){
        result[--count[(a[i] / place) % 10]] = a[i];
    }
    for(int i = 0; i < n; i++){
        a[i] = result[i];
    }
}
void radixsort(int a[], int n){
    int k = a[0];
    for(int i = 1; i < n; i++){
        k = max(k, a[i]);
    }
    for(int place = 1; k / place > 0; place *= 10){
        countingsort(a, n, place);
    }
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    radixsort(a, n);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}