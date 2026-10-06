#include<stdio.h>
void Insertion(int n, int a[n]){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i;
        while(j>0 && a[j-1]>temp){
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
        for(int k=0;k<n;k++){
            printf("%d ",a[k]);
        }
        printf("\n");
    }
}
int main(void){
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Insertion(n,a);
    return 0;
}