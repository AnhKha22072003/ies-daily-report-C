#include <stdio.h>

int sum(int *a,int count){
   int result = 0;
    for(int i=0;i<count;i++){
        result+=*(a+i);
    }
    return result;
}

float avgs(int *a,int count)
{
     int result = 0;
    for(int i=0;i<count;i++){
        result+=*(a+i);
    }
    return (float)result / count;
}

const int *findMax(const int *a, int n)
{
    if (a == NULL || n <= 0) {
        return NULL;
    }

    const int *result = a;

    for (int i = 1; i < n; i++) {
        if (*(a + i) > *result) {
            result = a + i; 
        }
    }

    return result;
}

int *changeValueF(int *a, int n, int x){
    if (a == NULL || n <= 0 ) {
        return NULL;
    }
    const int *result = a;
}
 
int main(void){
    int a[] = {4, 7, 2, 9, 5};
    int count = sizeof(a)/sizeof(a[0]);
    int *pointer = a;
    printf("sum %d \n",sum(pointer,count));
    printf("avgs %.2f \n",avgs(pointer,count));
    const int *max = findMax(a, count);

    printf("value max: %d\n", *max);
   
    printf("index: %td\n", max - a);

    return 0;
}