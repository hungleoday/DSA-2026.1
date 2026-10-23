#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        int sum=a[i];
        if(sum==0) printf("%d\n", a[i]);
        for(int j=i+1;j<n;j++){
            sum+=a[j];
            if(sum==0){
                for(int k=i;k<=j;k++){
                    printf("%d ",a[k]);
                }
                printf("\n");
            }
        }
    }
}