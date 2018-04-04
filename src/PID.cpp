#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
	p_error =0.0;
	i_error =0.0;
	d_error =0.0;
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;
	cout<<" KP "<<Kp<<" Ki "<<Ki<<" Kd "<<Kd<< std::endl;
}

void PID::UpdateError(double cte) {
	static double cte_previous =0.0;
	p_error = cte;
	i_error +=cte;
	d_error = cte-cte_previous;
	cte_previous = cte;

	//cout<<" p_error "<<p_error<<" i_error "<<i_error<<" d_error "<<d_error<< std::endl;
}

double PID::TotalError() {
	return (-p_error*Kp-i_error*Ki-d_error*Kd);
}

