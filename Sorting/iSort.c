#include<stdio.h>
#include<stdlib.h>

int arr[10];


int iSort(int n){
    int temp,i,j;
    for(i=1;i<n;i++){
        temp = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = temp;
    }
}


int main(){
    int n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements into the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    iSort(n);
    printf("The iSorted array is\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}