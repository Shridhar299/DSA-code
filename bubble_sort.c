#include<stdio.h>


bubble(int a[10000],int n)
{

    int temp;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

        }
        }
    }
    printf("\n\nSorted array is: ");
    print(a,n);



}
print(int a[10000],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
main()
{
    int n,a[1000];

    printf("Enter the size:\n");
    scanf("%d",&n);

    printf("Enter Numbers:");

    for(int i=0;i<n;i++){
        //a[i]=(rand()%200);
        scanf("%d",&a[i]);

    }

    //print(a,n);
    bubble(a,n);



}
