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
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int sum_id=n*(n-1)/2;
    printf("The duplicate number is %d",sum-sum_id);
}