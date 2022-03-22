#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 10
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int binary_search(int a[], int len, int num){
    int low = 0, heigh = len;
    while(low < heigh){
        int mid = low + (heigh - low) / 2;
        if(a[mid] == num) return mid;
        else if(a[mid] > num)
            heigh = mid;
        else
            low = mid + 1;
    }
    return -1;
}

void quicksort(int num[], int a, int b){
    if(a >= b) return;
    int i = a, j = b, t = a;
    int pivot = num[(a + b)/2];
    while(t <= j){
        if(a[t] < pivot){
            swap(a[t], a[i]);
            i++;
            t++;
        }
        else if(a[t] > pivot){
            swap(a[t], a[j]);
            j--;
        }
        else
            t++;
    }

    quicksort(num, a, i - 1);
    quicksort(num, j + 1, b);
}

int turn_num(int num){
    int ret = 0;
    while(num){
        if(abs(ret) > INT_MAX / 10) return 0;
        ret = 10 * ret + num % 10;
        num /= 10;
    }
    return ret;
}

char* str_reverse(char* ptr){
    if(NULL == ptr) return NULL;
    char* head = ptr;
    char* tail = ptr + strlen(ptr) - 1;
    char tmp;

    while(head != tail){
        tmp = *head;
        *head = *tail;
        *tail = tmp;
        head++;
        tail--;
    }
    return ptr;
}

int stoi(char *p){
    int ret = 0;
    for(; *p; p++){
        if(ret > INT_MAX / 10) return 0;
        ret = ret * 10 + (*p - '0');
    }
    return ret;
}

int NumOne(int i){
    int ret = 0;
    while(i){
        if(i & 1)
            ret++;
        i = i >> 1;
    }
    return ret;
}

//判断一个数是否为2的幂。一个数是2的幂，则最高位为1其余位为0. 可以用它跟 它 - 1 与一下。
bool judge(int i){
    if(i <= 0) return false;
    if(!(i & (i - 1))) return true;
    return false; 
}

char* my_strcat(char* dest, const char *src){
    char* p = dest;
    if(dest == NULL || src == NULL) 
        return NULL;
    while(*dest)
        dest++;
    
    while(*dest++ == *src++)
    return p;
}

void* my_memcpy(void * dest, const void* src, size_t count){
    if(NULL == dest || NULL == src) return NULL;
    char * pdest = dest;
    const char *psrc = src;

    while(count--){
        *pdest++ = *psrc++;
    }
    return dest;
}

int main(void){
    union{
        short i;
        char a[2];
    } u;

    u.a[0] = 0x11;
    u.a[1] = 0x22;
    printf("0x%x\n", u.i);
    return 0;
}

typedef unsigned int uint_32;
typedef unsigned short uint_16;

#define BSWAP_16(x) \
        (unit_16)((((unit_16)(x) & 0x00ff) << 8) | (((unit_16)(x) & 0xff00) >> 8))

#define BSWAP_32(x) \
        (unit_32)((((unit_32)(x) & 0xff000000) >> 24) | \
                  (((unit_32)(x) & 0x00ff0000) >> 8 ) | \
                  (((unit_32)(x) & 0x0000ff00) << 8 ) | \
                  (((unit_32)(x) & 0x000000ff) << 24) | \
                )
                  

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

#define BUFFSIZE 1024;
char workarea[1024];

void func1(void* arg){
    sem_wait(&sem);
    int* running = arg;
    printf("thread running1\n");
    printf("%d\n", *running);
}

void func2(void* arg){
    pringf("thread running2\n");
    sem_post(&sem);
}

int main(){
    sem_init(&sem, 0, 0); //创建一个信号量，第一个0是局部信号量， 第二个0是初始值0；
    pthread_t thread[2];
    int a = 5;
    pthread_create(&(thread[0]), NULL, (void*)func1, (void*)&a);
    printf("main thread running1\n");
    sleep(10);
    pthread_create(&(thread[1]), NULL, (void*)func2, (void*)&a);
    printf("main thread running2\n");
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    sem_destroy(&sem);

    return 0;
}

#define OUT 0
#define IN 1

int stat = OUT; 
int nw, nc, nl, c;
nw = nc = nl = 0;
while（(c = getchar()) != EOF){
    nc++;
    if(c = '\n')
        ++ln;
    if(c == ' ' || c == '\t' || c == '\n')
       stat = OUT;
    else if(stat = OUT){
        stat = IN;
        nw++;
    }
}
printf("%d %d %d\n", nw, nc, nl);
printf("%d\n", ln);