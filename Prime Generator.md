# Kiểm Tra Số Nguyên Tố

## Không dùng sàng nguyên tố
### Java Code
```java
public boolean isPrime(int x){
        if(x==2 || x == 3)return  true;

        if(x<=1 || x%2==0) return false;
        int sqrt = (int)Math.sqrt(x);
        for (int i = 3; i <= sqrt  ; i++) {
            if(x%i==0) return false;
        }
        return true;
    }

    public void start(){
        Scanner sc = new Scanner(System.in);
        int  n = sc.nextInt();
        while (n-->0){
            int x = sc.nextInt();
            if(isPrime(x)){
                System.out.println("Yes");
            }else {
                System.out.println("No");
            }
        }

    }

    public static void main(String[] args) {
        KTSNT ktsnt = new KTSNT();
        ktsnt.start();
    }
```

### C Code

```C
int isPrime(int x){
    int i;
    if(x==2 || x == 3)return  1;

        if(x<=1 || x%2==0) return 0;
        int can = sqrt(x);
        for (i = 3; i <= can  ; i++) {
            if(x%i==0) return 0;
        }
        return 1;
}
void start(){
    int n;
    scanf("%d",&n);
    int x;
    while(n--){
        scanf("%d",&x);
        if(isPrime(x)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}

int main(){
    
    start();
    return 0;
}
```

## Có dùng sàng nguyên tố

### Java Code

```Java
    public void start(){
        Scanner sc = new Scanner(System.in);
        int  n = sc.nextInt();
        //Create Array
        boolean array[] = new boolean[n+1];
        int l = array.length;
        //Set all element Of Array  = true
        for (int i = 0; i <l ; i++) {
            array[i] =true;
        }
        
        int sqrt = (int)Math.sqrt(n);
        //Start Filter
        for (int i = 2; i <=sqrt ; i++) {
            if(array[i]){
                for (int j = i; j*i <= n ;j++ ) {
                    array[j*i] = false;
                }
            }
        }
        //Printf All element is Prime
        for (int i = 2; i <= n; i++) {
            if(array[i]){
                System.out.println(i);
            }
        }


    }

    public static void main(String[] args) {
        KTSNT ktsnt = new KTSNT();
        ktsnt.start();
    }
```

### C Code

```C
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
```