#include <stdio.h>

void start(){
        int  n,i,j ;
        scanf("%d",&n);
        int array[n+1];
        for (i = 0; i <=n ; i++) {
            array[i] =1;
        }
        int can = (int)sqrt(n);
        for (i = 2; i <=can ; i++) {
            if(array[i]){
                for ( j = i*i; j <= n ;j+=i ) {
                    array[j] = 0;
                }
                printf("%d\n",i);
            }
        }
        for (i = can+1; i <= n; i+=2) {
            if(array[i]){
                printf("%d\n",i);
            }
        }
    }

int main() {
    start();
    return 0;
}