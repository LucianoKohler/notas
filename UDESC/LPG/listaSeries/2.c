#include <stdio.h>
#include <math.h>

int main(){
    int k; 
    float num=0;
    scanf("%d", &k);
    for(float i = 1; i <= k; i++){
        num+= (pow(-1, i+1))/i;
    }

    printf("%f\n", num);
    return 0;
}