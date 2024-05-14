#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
        else if(speed > 100 && speed < 181){
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

void timeCalcBefore(double strt_km, double speed){
    double irl_km, irl_raw, irl_raw_m, irl_raw_s, irl_h, irl_m, irl_s;
    irl_km = strt_km/15.56;
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
    irl_km = g_km/15.56;
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

int kmCalc(){
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
    int select, ret_code;
    do{
        printf("\n=== MENU DI SELEZIONE ===\n\n1. Fai un'altro calcolo\n2. Esci dal programma\n3. Altre funzionalità in arrivo...\n");
        scanf("%d",&select);
        switch(select){
            case 1:
                ret_code = 1;
                break;
            case 2:
                ret_code = 2;
                break;
            case 3:
                ret_code = 3;
                break;
            default:
                ret_code = 0;
                exit(0);
        }
    }while(select < 0);
    return ret_code;
}

int kmCalcStart(){
    int ret_code = kmCalc();
    return ret_code;
}

void main() {
    do{
        int ret_code = kmCalcStart();
        if(ret_code == 0 || ret_code == 2){
            ret_code = 0;
            printf("\nGrazie per aver usato il nostro programma!\n");
            exit(0);
        }
        else if(ret_code == 1){
            ret_code = 0;
            ret_code = kmCalcStart();
        }
        else if(ret_code == 3){
            printf("\nQuesta funzionalità sarà disponibile nella prossima versione del programma!\n");
            ret_code = 0;
            exit(0);
        }
    }while(true);
}
