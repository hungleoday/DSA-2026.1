#include<stdio.h>
int main(){
   int n;
   scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
   }            
   int target;
   scanf("%d",&target);
   int max = 0;
    int end = -1;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == target) {
                if (j - i + 1 > max) {
                    max = j - i + 1;
                    end = j;
                }
            }
        }
    }
    if (end != -1) {
        printf("The longest subarray with sum %d is: ", target);
        for (int i = end - max + 1; i <= end; i++) {
            printf("%d ", a[i]);
        }
    }
}