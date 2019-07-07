#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

void rungek4(double t0, double tfinal ,double x0, double v0, double delta, int npuntos, string filename);

int main()
{
	double t_0=0.0;
	double x_0=0.1;
	double v_0=0.0;
	rungek4(t_0, 5.0 ,x_0,v_0,0.01,1000, "datosresorte.txt" );
	return 0;
}

//Simplicacion de la ecuacion de segundo orden.

double dvdt(double tiempo, double x0 ,double v0){
	double m= 2.0;
	double k= 300.0;
	return (-k*x0)/m;
}

double dxdt(double tiempo, double x0 ,double v0){
	return v0;
}


void rungek4(double t0, double tfinal, double x0, double v0, double delta, int npuntos, string filename){
	ofstream outfile;
	outfile.open(filename);

	double posicion[npuntos];
	double velocidad[npuntos];
	double tiempo[npuntos];
	posicion[0]=x0;
	velocidad[0]=v0;
	tiempo[0]=t0;
	double k1x,k2x,k3x,k4x;
	double k1v,k2v,k3v,k4v;
	double promediokx, promediokv;
	double dx= (tfinal- t0)/(npuntos-1);

	for(int i=1; i<npuntos ; i++)// para crear linspace con npuntos determinado
    {  
      tiempo[i]= tiempo[i-1]+dx;
    }

	for(int i=1; i<npuntos;i++)
	{
		k1x=delta*dxdt(tiempo[i-1],posicion[i-1],velocidad[i-1]);				
		k1v=delta*dvdt(tiempo[i-1],posicion[i-1],velocidad[i-1]);

		k2x=delta*dxdt(tiempo[i-1]+(0.5*delta),posicion[i-1]+(0.5*k1x),velocidad[i-1]+(0.5*k1v));
		k2v=delta*dvdt(tiempo[i-1]+(0.5*delta),posicion[i-1]+(0.5*k1x),velocidad[i-1]+(0.5*k1v));

		k3x=delta*dxdt(tiempo[i-1]+(0.5*delta),posicion[i-1]+(0.5*k2x),velocidad[i-1]+(0.5*k2v));
		k3v=delta*dvdt(tiempo[i-1]+(0.5*delta),posicion[i-1]+(0.5*k2x),velocidad[i-1]+(0.5*k2v));

		k4x=delta*dxdt(tiempo[i-1]+delta,posicion[i-1]+k3x,velocidad[i-1]+k3v);
		k4v=delta*dvdt(tiempo[i-1]+delta,posicion[i-1]+k3x,velocidad[i-1]+k3v);

		promediokx=(1.0/6.0)*(k1x+(2.0*k2x)+(2*k3x)+k4x);
		promediokv=(1.0/6.0)*(k1v+(2.0*k2v)+(2*k3v)+k4v);

		posicion[i]=posicion[i-1]+promediokx;
		velocidad[i]=velocidad[i-1]+promediokv;

		outfile << tiempo[i]<< "  " << posicion[i] << "  " << velocidad[i] << endl;
	}
    outfile.close();
}
