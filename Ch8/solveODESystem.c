#include <stdio.h>
#include <math.h>

/**
 * This program solves the ODE system
 * u' = v,
 * v'= -kv + u**3 + B*cos(t),
 * with u(0)=v(0)=1. Note that k and B are constants.
 * Two different sets of values are used for both k and B.
 * The Euler method is used to solve this system and the
 * results for both cases are plotted via gnuplot.
*/

double f1(double u, double v, double t){
    return v;
}

double f2(double u, double v, double k, double B, double t){
    return -k*v - pow(u,3) + B*cos(t);
}

int main(){
    double k1 = 0.1, B1 = 11.0;  //first case 
    double k2 = 0.4, B2 = 20.0; //second case 
    double u = 1.0, v = 1.0;
    double t = 0.0, h = 0.01;
    
    //first case
    FILE *fp1;
    fp1 = fopen("ODESystemCase1.dat","w");
    fprintf(fp1,"%-15s\n","#First case with k = 0.1 and B = 11.0");
    fprintf(fp1,"%-15s %-15s\n","#u","v");
    for(int i=0;i<=10000;++i){
        fprintf(fp1,"%-15lf %-15lf\n",u,v);
        u = u + h*f1(u,v,t);
        v = v + h*f2(u,v,k1,B1,t);
        t = t + h; 
    }
    fclose(fp1);
    
    //second case
    u = 1.0, v = 1.0, t = 0.0; 
    FILE *fp2;
    fp2 = fopen("ODESystemCase2.dat","w");
    fprintf(fp2,"%-15s\n","#Second case with k = 0.4 and B = 20.0");
    fprintf(fp2,"%-15s %-15s\n","#u","v");
    for(int i=0;i<=10000;++i){
        fprintf(fp2,"%-15lf %-15lf\n",u,v);
        u = u + h*f1(u,v,t);
        v = v + h*f2(u,v,k2,B2,t);
        t = t + h;
    }
    fclose(fp2);
    return 0;
}