#include <stdio.h>
void PrintArray(int a[], int n) {
    for (int k = 0; k < n; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");
}
void MergeArrays(int a[], int m, int n, int p, int total_N) {
    int i = m, j = n + 1;
    while (i < j && j <= p) {
        if (a[i] <= a[j]) {
            i++;
        } else { // Chen a[j] vao vi tri i
            int x = a[j];
            for (int k = j - 1; k >= i; k--) {
                a[k + 1] = a[k];
            }
            a[i] = x;
            PrintArray(a, total_N);
            i++;
            j++;
        }
    }
}
void Split_Merg(int a[], int first, int last, int total_N) {
    if (first >= last) return;
    int m = (first + last) / 2;
    Split_Merg(a, first, m, total_N); 
    Split_Merg(a, m + 1, last, total_N);   
    MergeArrays(a, first, m, last, total_N);
}
void MergeSort(int a[], int n) {
    if (n < 2) return;
    Split_Merg(a, 0, n - 1, n);
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