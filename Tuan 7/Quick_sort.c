#include <stdio.h>
void PrintArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int Partition(int a[], int left, int right, int pivot_val, int n) {
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= right && a[i] < pivot_val) i = i + 1;
        while (j >= left + 1 && a[j] > pivot_val) j = j - 1;
        if (i < j) {
            Swap(&a[i], &a[j]);
            PrintArray(a, n);
            i = i + 1;
            j = j - 1;
        } else {
            break;
        }
    }
    if (left != j) {
        Swap(&a[left], &a[j]);
        PrintArray(a, n);
    }
    return j;
}
void QuickSort(int a[], int left, int right, int n) {
    if(right - left <= 0) {
        return;
    }
    else{
        int pivot = a[left];
        int partition = Partition(a, left, right, pivot, n);
        QuickSort(a, left, partition - 1, n);
        QuickSort(a, partition + 1, right, n);
    }
}
int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    QuickSort(a, 0, n - 1, n);
    return 0;
}