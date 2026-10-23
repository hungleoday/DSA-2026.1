#include<stdio.h>
int findmin(int a[], int n){
    int min=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<min) min=a[i];
    }
    return min;
}
int findmax(int a[], int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max) max=a[i];
    }
    return max;
}
int duplicate(int a[], int size, int value) {
    for (int i=0;i<size;i++) {
        if (a[i]==value) return 1;
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int max_len = 1;
    int start=0;
    int end=0;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            int current_size = j - i; 
            if (duplicate(a + i, current_size, a[j])) {
                break;
            }
            int subarray_size = j - i + 1;
            int min_val=findmin(a+i, subarray_size);
            int max_val=findmax(a+i, subarray_size);
            if (max_val - min_val == j - i) {
                if (subarray_size > max_len) {
                    max_len=subarray_size;
                    start=i;
                    end=j;
                }
            }
        }
    }
    printf("The largest subarray is { ");
    for (int i=start;i<=end; i++) {
        printf("%d", a[i]);
        if (i<end) printf(", ");
    }
    printf(" }\n");
    return 0;
}