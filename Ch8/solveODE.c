#include <stdio.h>
#include <math.h>

double f(double x, double y){
    return -pow(x,2)*y;
}

int main(){
    double y_Eul = 1.0, y_RK4 = 1.0, y_exact = 1.0;
    double x_Eul = 0.0, x_RK4 = 0.0, x_exact = 0.0; 
    
    //Euler Block
    double h = 0.1;
    FILE* fp1;
    fp1 = fopen("Euler.dat","w");
    fprintf(fp1,"#%-15s %-15s\n","x","y");
    for(int i=0;i<=10;++i){
        fprintf(fp1,"%-15lf %-15lf\n",x_Eul,y_Eul);
        y_Eul = y_Eul + h*f(x_Eul,y_Eul);
        x_Eul = x_Eul + h;
    }
    fclose(fp1);
    
    //RK4 Block
    FILE* fp2;
    fp2 = fopen("RK4.dat","w");
    fprintf(fp2,"#%-15s %-15s\n","x","y");
    for(int i=0;i<=10;++i){
        fprintf(fp2,"%-15lf %-15lf\n",x_RK4,y_RK4);
        double k1 = f(x_RK4,y_RK4);
        double k2 = f(x_RK4 + 0.5*h, y_RK4 + (0.5*h*k1));
        double k3 = f(x_RK4 + 0.5*h, y_RK4 + (0.5*h*k2));
        double k4 = f(x_RK4 + h, y_RK4 + h*k3); 
        y_RK4 = y_RK4 + h*(k1+2*k2+2*k3+k4)/6.0;
        x_RK4 = x_RK4 + h;
    }
    fclose(fp2);
    
    //exact solution block
    FILE* fp3;
    fp3 = fopen("exact.dat","w");
    fprintf(fp3,"#%-15s %-15s\n","x","y");
    for(int i=0;i<=10;++i){
        fprintf(fp3,"%-15lf %-15lf\n",x_exact,y_exact);
        x_exact = x_exact + h;
        y_exact = exp(pow(x_exact,3)/-3.0);
    }
    fclose(fp3);

    return 0;
}