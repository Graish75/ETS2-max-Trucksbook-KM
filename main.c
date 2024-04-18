#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int setSpeed(){
    int speed;
    do{
        printf("\nVelocità massima percorso (in km/h): ");
        scanf("%d",&speed);
        if(speed <= 0){
            printf("\nNon puoi specificare una velocità negativa.\n");
        }
        else if(speed > 100 & speed < 181){
            printf("\nAttenzione, questo viaggio potrebbe essere contato nelle statistiche gara.\n");
        }
        else if(speed < 100 && speed > 0){
            printf("\nQuesto viaggio verrà contato nelle statistiche reali.\n");
        }
        else{
            printf("\nNon puoi specificare una velocità superiore a 180 km/h.\n");
        }
    }while(speed <= 0 | speed > 180);
    return speed;
}

int timeCalcBefore(double strt_km, double speed){
    double irl_km, irl_raw, irl_raw_m, irl_raw_s, irl_h, irl_m, irl_s;
    irl_km = strt_km * 0.102;
    irl_raw = irl_km/speed;
    double irl_raw_dec = modf(irl_raw, &irl_h);

/*
    printf("\nDEBUG: Normale h: %.15f\n", irl_raw);
    printf("\nDEBUG: Parte intera h: %.0f\n", irl_h);
    printf("\nDEBUG: Parte decimale h: %.15f\n", irl_raw_dec);
*/

    irl_raw_m = irl_raw_dec * 60;
    double irl_raw_dec_m = modf(irl_raw_m, &irl_m);

/*
    printf("\nDEBUG: Normale m: %.15f\n", irl_raw_m);
    printf("\nDEBUG: Parte intera m: %.0f\n", irl_m);
    printf("\nDEBUG: Parte decimale m: %.15f\n", irl_raw_dec_m);
*/

    irl_raw_s = irl_raw_dec_m * 60;
    double irl_raw_dec_s = modf(irl_raw_s, &irl_s);

/*
    printf("\nDEBUG: Normale s: %.15f\n", irl_raw_s);
    printf("\nDEBUG: Parte intera s: %.0f\n", irl_s);
    printf("\nDEBUG: Parte decimale s: %.15f\n", irl_raw_dec_s);
*/

    printf("\nTempo di percorrenza (in base ai km iniziali) stimato: %.0f h, %.0f m, %.0f s.\n",irl_h,irl_m,irl_s);
}

void timeCalc(double g_km, double speed){
    double irl_km, irl_raw, irl_raw_m, irl_raw_s, irl_h, irl_m, irl_s;
    irl_km = g_km * 0.102;
    irl_raw = irl_km/speed;
    double irl_raw_dec = modf(irl_raw, &irl_h);

/*
    printf("\nDEBUG: Normale h: %.15f\n", irl_raw);
    printf("\nDEBUG: Parte intera h: %.0f\n", irl_h);
    printf("\nDEBUG: Parte decimale h: %.15f\n", irl_raw_dec);
*/

    irl_raw_m = irl_raw_dec * 60;
    double irl_raw_dec_m = modf(irl_raw_m, &irl_m);

/*
    printf("\nDEBUG: Normale m: %.15f\n", irl_raw_m);
    printf("\nDEBUG: Parte intera m: %.0f\n", irl_m);
    printf("\nDEBUG: Parte decimale m: %.15f\n", irl_raw_dec_m);
*/

    irl_raw_s = irl_raw_dec_m * 60;
    double irl_raw_dec_s = modf(irl_raw_s, &irl_s);

/*
    printf("\nDEBUG: Normale s: %.15f\n", irl_raw_s);
    printf("\nDEBUG: Parte intera s: %.0f\n", irl_s);
    printf("\nDEBUG: Parte decimale s: %.15f\n", irl_raw_dec_s);
*/

    printf("\nTempo di percorrenza (in base ai km massimi) stimato: %.0f h, %.0f m, %.0f s.\n",irl_h,irl_m,irl_s);
}

void kmCalc(){
    double km_strt, km_max, adding;
    do{
        printf("\nInserisci i km iniziali: ");
        scanf("%lf",&km_strt);
        int speed = setSpeed();

/*
        printf("\nDEBUG: You have set a maximum speed of %d km/h",speed);
*/

        adding = (km_strt * 24.90) / 100;
        km_max = km_strt + adding;
        if(km_max > km_strt + 1000){
            km_max = km_strt + 1000;
            printf("\nI km massimi percorribili sono: %.0lf",km_max);
        }
        else{
            printf("\nI km massimi percorribili sono: %.0lf",km_max);
        }
        timeCalcBefore(km_strt, speed);
        timeCalc(km_max, speed);
    }while(km_strt <= 0);
}

void main() {
    do{
        kmCalc();
    }while(true);
}
