/* Basic adaptive Runge-Kutta ODE algorithm implementation
 * Program solves differential equations of the form dx/dt = F(x(t),t)
 */

/* Given an initial step size h0, desired accuracy d, and an initial x0,t0, 
 * (all doubles), as well as the funcion F(x(t), t) of the form shown above,
 * we will calculate k1, k2, k3, k4, and then finally x1, the next value of x */

#include<functional>

double exx1(double h, double x, double t, std::function<double(double, double)> F){
	double kay1 = h*F(x,t);
	double kay2 = h*F(x + .5*kay1, t + .5*h);
	double kay3 = h*F(x + .5*kay2, t + .5*h);
	double kay4 = h*F(x + kay3, t + h);	
	return  x + kay1/6 + kay2/3 + kay3/3 + kay4/6;
}
