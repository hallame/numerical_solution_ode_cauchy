#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fun(double x, double y)                                     // variant 19 function
{
   return 3*pow(x, 3)*y;
}

double fun_analit(double  x)                                       //function for calculating the analytical value
{
   double xx = 3*pow(x, 4)/4;
   return exp(xx);
}

double* X(double a, double b, int n)                               //function for calculating x
{
   double h = (b-a)/n;                                             //counting the step
   auto* x= new double [n];
   x[0] = a;
   for(int i = 1; i <= n; i++)                                     //we go through the cycle and count x
   {
       x[i] = a + i*h;
   }
   return x;
}

double* R_K(double a, double b, int n, double* x)                  //function for calculating y by the Runge-Kutta method
{
   double h = (b-a)/n;
   auto* y = new double [n];
   auto* temp = new double [n];
   y[0] = 1;
   for(int i = 1; i <= n; i++)                                      //we go through the cycle and count y
   {
       temp[i] = y[i-1] +  h * fun(x[i-1], y[i-1]);
       y[i] = y[i-1] + h * ((fun(x[i-1], y[i-1]) + fun(x[i], temp[i]))/2);
   }
   return y;
}

void print_(double* x, double* y, int n)                             //function for beautiful printing
{
   for(int i = 0; i < n; i++){
       cout << setprecision(5) << fixed << x[i] << setw(10) << y[i] << setw(10);
       cout << fun_analit(x[i]) << setw(10) << abs(fun_analit(x[i]) - y[i])<< endl;
   }
}


int main()
{
   int n = 8;
   cout << endl;
   double a = 0, b = pow(4/3, 1/4);
   double* x = X(a, b, n);
   double* y = R_K(a, b, n, x);
   print_(x, y, n);
   return 0;
}
