//
//  main.cpp
//  cp_1_13
//
//  Created by Nikolay Tikhonov on 21.02.16.
//  Copyright © 2016 Nikolay Tikhonov. All rights reserved.
//

#include <iostream>
#include <math.h>

double my_sin(double x, double precision);
double my_arctan(double x, double precision);
double my_pow(double x, double pow);
double my_abs(double x);
double my_sqrt(double x, double precision);
double my_factorial(int x);
int signum(double x);
double my_function(double x);
double standart_function(double x);

const double PI = 3.1415926535897932384626433832795;

int signum(double x){
    if(x>0) {return 1;}
    if(x==0){return 0;}
    if(x<0) {return -1;}else{return -20;}
}

double my_sin(double x, double precision){
    double res,a;
    int k=0;
    do{
        a=my_pow(-1,k)*(my_pow(x,2*k+1)/my_factorial(2*k+1));
        res=res+a;
        k++;
    }while(my_abs(a)>=precision);
    return res;
}

double my_arctan(double x, double precision){
    double res=0;
    double a;
    if(my_abs(x)<1){
        int k=0;
        do{
            a=my_pow(-1, k)*(my_pow(x,(2*k+1))/(2*k+1));
            res=res+a;
            k++;
        }while(a>=precision);
    }else{
        int k=0;
        do{
            a=my_pow(-1,k)*(my_pow(x,-(2*k+1))/(2*k+1));
            res=res+a;
            k++;
        }while(a>=precision);
        res=PI/2*signum(x)-res;
    }
    return res;
}

double my_pow(double x, double pow){
    double res=1;
    for(int i=1;i<=pow;i++)
        res=res*x;
    return res;
}

double my_abs(double x){
    if(x<0){
        return x*(-1);
    }else return x;
}

double my_sqrt(double x, double precision){
    double res=1;
    double pre_res;
    do{
        pre_res=res;
        res=0.5*(res+x/res);
        
    }while(my_abs(pre_res-res)>precision);
    
    return res;
}

double my_factorial(int x){
    int res=1;
    for(int i=1;i<=x;i++){
        res=res*i;
    }
    return res;
}

double my_function(double x){
    double precision = 0.0000001;
    return my_arctan(my_sqrt((0.9*x+1), precision)/(1-my_pow(x, 2)),precision)+my_sin((3*x+0.6), precision);
}

double standart_function(double x){
    return atan(sqrt(0.9*x+1)/(1-pow(x, 2)))+sin((3*x+0.6));
}

int main(int argc, const char * argv[]) {
    double xfrom, xto, xstep;
    int exite;
    std::cout<<"Value starts counting x: "; std::cin>>xfrom;
    std::cout<<"Value ends counting x: "; std::cin>>xto;
    std::cout<<"Step sise: "; std::cin>>xstep;
    
    for(double x=xfrom;x<=xto;x=x+xstep){
        std::cout<<x<<"\t"<<my_function(x)<<"\t"<<standart_function(x)<<"\t"<<my_function(x)-standart_function(x)<<std::endl;
    }
    std::cin>>exite;
    return 0;
}