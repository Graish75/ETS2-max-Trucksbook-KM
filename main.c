#include <stdio.h>
#include <stdbool.h>

void kmCalc(){
    double km_strt, km_max, adding;
    do{
        printf("\nInserisci i km iniziali: ");
        scanf("%lf",&km_strt);
        adding = (km_strt * 24.90) / 100;
        km_max = km_strt + adding;
        printf("\nI km massimi percorribili sono: %.0lf",km_max);
    }while(km_strt <= 0);
}

int main() {
    do{
        kmCalc();
    }while(true);
    return 0;
}
