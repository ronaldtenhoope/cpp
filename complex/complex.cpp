#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class complex { // very simpliﬁed complex
private:
	double re, im; 
public: 
	complex(double r, double i) :re{r}, im{i} { } 
	complex operator+(complex o); 
	complex operator*(complex o); 
	void print(void);
};

complex complex::operator+(complex o) {
	complex tmp {re, im};
	tmp.re=re+o.re;
	tmp.im=im+o.im;
	return tmp;
};

complex complex::operator*(complex o) {
	complex tmp {re, im};
	tmp.re*=o.re;
	tmp.im*=o.im;
	return tmp;
};

void complex::print(void) {
	printf("%f, %f\n", re, im);
}
	
int main() {

	complex a = complex{1,3.1}; 
	complex b {1.2, 2}; 
	complex c {b};
	printf("Initialisatie\n");
	a.print();
	b.print();
	c.print();
	
	printf("Eerste a=b+c\n");
	a = b+c; 
	a.print();

	printf("Tweede b=b+c*a\n");
	b = b+c*a; 
	b.print();

	printf("Derde c=a*b+(1, 2)\n");
	c = a*b+complex(1,2);
	c.print();

}


