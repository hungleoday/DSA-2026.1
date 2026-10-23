#include <stdio.h>
void PrintArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void MergeArray(int a[], int m, int n, int p, int N) {
    int i = m, j = n + 1;
    while (i < j && j <= p) {
        if (a[i] <= a[j]) i++;
        else{
            int x = a[j];
            for (int k = j - 1; k >= i; k--) {
                a[k + 1] = a[k];
            }
            a[i] = x;
            PrintArray(a, N);
            i++;
            j++;
        }
    }
}
void Split(int a[], int first, int last, int N) {
    if (first >= last) return;
    int m = (first + last) / 2;
    Split(a, first, m, N); 
    Split(a, m + 1, last, N);   
    MergeArray(a, first, m, last, N);
}
void MergeSort(int a[], int n) {
    if (n < 2) return;
    Split(a, 0, n - 1, n);
}
int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    MergeSort(a, n);
    return 0;
}
