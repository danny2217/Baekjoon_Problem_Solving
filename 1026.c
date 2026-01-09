#include<stdio.h>

void BUbble(int arr[],int n){

    int i,j;

    int temp;

    for(i = 0;i<n-1;i++){

        for(j = 0;j<(n-i)-1;j++){

 

        if(arr[j]>arr[j+1]){

            temp = arr[j];

            arr[j] = arr[j+1];

            arr[j+1] = temp;

        }

 

        }

    }

}

 

int main(void){

    int a[50];

    int b[50];

    

    int n;

    scanf("%d",&n);

    

    for(int i = 0;i<n;i++){

        scanf("%d",&a[i]);

    }

    

    for(int i = 0;i<n;i++){

        scanf("%d",&b[i]);

    }

 

    BUbble(a,n);

    Bubblesort(b,n);

    int sum = 0;

    int answer[50];

    for(int i = 0;i<n;i++){

        answer[i] = a[i]*b[i];

      sum = sum + answer[i];

 

    }

printf("%d",sum);

}