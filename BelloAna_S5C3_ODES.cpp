#include<iostreams>
#include<fstream>
#include<fstream>

using namespace std;

void euler(double a, double b,double delta, int npuntos, string filename);
void rungek4(double a, double b, double delta, int npuntos, string filename);

int main()
{

	return 0;
}

double dvdt(double k, double x, double m){
	return (-k*x)/m
}

double dxdt(double)