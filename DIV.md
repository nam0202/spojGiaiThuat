# DIV - Divisors


```java
    int MAX = 1000000;
    int dc[];
    int primer[];
    int prime_count = 0;

    public Main(){
        dc = new int[MAX+1];
        primer = new int[MAX+1];
    }

    public boolean is_prime(int x){
        int i;
        for(i=0;i<prime_count && primer[i]<=x;i++){
            if(primer[i]==x){
                return true;
            }
        }
        return false;
    }

    public boolean check(int x){
        int i,j;
        int lim = (int)Math.sqrt(x);
        for(i=0;primer[i]<=lim;i++){
            if(x%primer[i]==0){
                j = x/primer[i];
                if(is_prime(j) && (j!=primer[i])){
                    return true;
                }
                return false;
            }
        }
        return false;
    }
    void build_prime_list(){
        int i;
        for(i=2;i<=MAX;i++){
            if(dc[i]==2){
                primer[prime_count] = i;
                prime_count++;
            }
        }
    }
    void count_divisor(){
        dc[1]= 1;
        int i,j;
        for(i=2;i<MAX;i++){
            dc[i] =2;
        }
        int lim = (int)Math.sqrt(MAX);
        for(i=2;i<=lim;i++){
            j = i*i;
            dc[j]++;
            while(j+i<=MAX){
                j+=i;
                dc[j]+=2;
            }

        }
    }


    public void start(){
        count_divisor();
        build_prime_list();
        int i,count = 0;
        for(i=12;i<=MAX;i++){
            if(check(dc[i])){
                count++;
                if(count%9==0)
                    System.out.println(i);
            }
        }
    }

    public static void main(String[] args) {
        Main ktsnt = new Main();
        ktsnt.start();
    }
```

## C code
```C
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000000
int *dc;
int *primer;
int prime_count=0;

int is_prime(int x){
  int i;
  for(i=0;i<prime_count && primer[i]<=x;i++){
    if(primer[i]==x){
      return 1;
    }
  }
  return 0;
}

int check(int x){
  int i,j;
  int lim = sqrt(x);
  for(i=0;primer[i]<=lim;i++){
    if(x%primer[i]==0){
        j = x/primer[i];
        if(is_prime(j) && (j!=primer[i])){
          return 1;
        }
        return 0;
    }
  }
  return 0;
}
void build_prime_list(){
    primer = (int*)malloc(MAX*sizeof(int));
    int i;
    for(i=2;i<=MAX;i++){
      if(dc[i]==2){
        primer[prime_count] = i;
        prime_count++;
      }
    }
}
void count_divisor(){
    dc[1]= 1;
    int i,j;
    for(i=2;i<MAX;i++){
      dc[i] =2;
    }
    int lim = (int)sqrt(MAX);
    for(i=2;i<=lim;i++){
      j = i*i;
      dc[j]++;
      while(j+i<=MAX){
        j+=i;
        dc[j]+=2;
      }
      
    }
}


int main(){
  dc = (int*) malloc((MAX+1)*sizeof(int));
  count_divisor();
  build_prime_list();
  int i,count = 0;
  for(i=12;i<=MAX;i++){
    if(check(dc[i])){
       count++;
       if(count%9==0)
          printf("%d\n",i); 
    }
  }


  return 0;
}
```