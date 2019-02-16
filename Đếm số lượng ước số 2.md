#  Đếm số lượng ước số 

## Java Code

```java
public void start(){
    Scanner sc = new Scanner(System.in);
    int  n = sc.nextInt();
    int array[] = new int[n+1];
    //gán các giá trị của mảng  = 2 vì số nguyên luôn chia cho nó và số 1
    for (int i = 1; i <=l ; i++) {
        array[i] =2;
    }
    System.out.printf("1 : 1\n");
    int diemDung = n/2;
    //Chạy từ i -> n/2 vì  các số nguyên < n/2 thì mới có bội số
    for (int i = 2; i <=diemDung ; i++) {
        //Tăng giá trị tại vị trí của bội số lên 1 đơn vị
        for (int j = i+i; j <= n ;j+=i ) {
            array[j]++;
        }
        System.out.printf("%d : %d\n",i,array[i]);
    }
    for(int i=diemDung+1;i<=n;i++){
        System.out.printf("%d : %d\n",i,array[i]);
    }
}

public static void main(String[] args) {
    Main ktsnt = new Main();
    ktsnt.start();
}
```

## C Code
```c
#include <stdio.h>
#include <stdlib.h>    
void start(){
    int  n ,i,j;
    scanf("%d",&n);
    int *array = (int*) malloc (4*(n+1));
    
    for (int i = 1; i <=n ; i++) {
        array[i] =2;
    }
    printf("1 : 1\n");
    int diemDung = n/2;
    for ( i = 2; i <=diemDung ; i++) {
        for ( j = i+i; j <= n ;j+=i ) {
            array[j]++;
        }
        printf("%d : %d\n",i,array[i]);
    }
    for( i=diemDung+1;i<=n;i++){
        printf("%d : %d\n",i,array[i]);
    }

}
int main(){
    start();
    return 0;

}
```