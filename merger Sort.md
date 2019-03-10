# Đệ quy. Quá trình MergeSort. Trái sang phải

[Link bai Tap](https://www.spoj.com/KMASAM/problems/TAALG209/)

## C Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *a;
int n;
int *b;
int count = 0;
void outArray(int left,int mid,int right){
	int i;
	for(i=left;i<mid+1;i++){
		printf("%d ",a[i]);
	}
	printf(":: ");
	for(;i<right+1;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	
}
void merge(int left, int mid, int right){
    //printf("%d %d\n",left,right);
    int i,j;
    i = left;
    j = mid+1;
    count  = left;
    for(; i<=mid && j <=right;){
        if(a[i]<a[j]){
            b[count] = a[i++];
        }else {
            b[count] = a[j++];
        }
        count++;
    }
    while(i<=mid){
        b[count++] = a[i++];
    }
    while(j<=right){
        b[count++] = a[j++];
    }
    memcpy(a+left,b+left,(right-left+1)*sizeof(int));
    
}
void mergeSort(int left,int right){
    if(right <= left) return ;
    int mid  = (left+right)/2;
    printf("Divide: %d --> %d and %d --> %d\n",left,mid,mid+1,right);
    outArray(left,mid,right);
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid,right);
    printf("Merge: %d --> %d and %d --> %d\n",left,mid,mid+1,right);
    int i;
    for(i=left;i<right+1;i++){
    	printf("%d ",a[i]);
    }
    printf("\n\n");

}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("E:\\input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    scanf("%d",&n);
    int i;
    a = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        printf(" %d",a[i]);
    }
    printf("\n");
    b = (int*)malloc(sizeof(int)*n);
    mergeSort(0,n-1);
    return 0;
}

```