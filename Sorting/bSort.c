#include<stdio.h>
int arr[10],n=0,i=0,j=0;
void bsort(){
    int temp;
    for(i=n-2;i>=0;i--)
        for(j=0;j<=i;j++)
            if(arr[j]>arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
}

void main(){

    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    if(n>10)
        printf("Enter the elements the maximum is 10");
    else
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        bsort();

    printf("The sorted elements are");
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
}