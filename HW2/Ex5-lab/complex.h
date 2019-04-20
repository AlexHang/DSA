#include <iostream>
using namespace std;
class complex {
private:
	double re;
	double im;
public:
	complex();
	complex(double param_re, double param_im);
    double getRe();
    double getIm();
    void setRe(double r);
    void setIm(double i);
	void adunare (complex c1);
	void inmultire(complex c1);
	void afisare();
};
complex::complex()
{ }

complex::complex (double param_re, double param_im)
{
    this->re=param_re;//re=param_re;
    this->im=param_im;//im=param_im;
}

double complex::getRe(){
    return this->re;
}
double complex::getIm(){
    return this->im;
}
void complex::setRe(double r){
    this->re=r;
}
void complex::setIm(double i){
    this->im=i;
}
void complex::afisare(){
    cout<<this->re<<"+"<<this->im<<"i"<<endl;
}


void complex::adunare (complex c1)
{
	// code for adding complex numbers
	complex aux;
	aux.setRe(this->getRe()+c1.getRe());
	aux.setIm(this->getIm()+c1.getIm());
	aux.afisare();

}
void complex::inmultire (complex c1)
{
	// code for multiplying complex numbers
	complex aux;
	aux.setRe((this->getRe()*c1.getRe())-(this->getIm()*c1.getIm()));
	aux.setIm((this->getRe()*c1.getIm())+(this->getIm()*c1.getRe()));
	aux.afisare();

}

