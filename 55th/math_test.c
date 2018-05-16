#include "vector.h"

int main(void)
{
	double v0[3] = {0.0, 4.0, 0.0};
	double v1[3] = {2.0, 2.0, 1.0};
	double v2[3] = {1.0, 1.0, 1.0};
	
	double w0[3];
	double w1[3];
	double w2[3];

	vector_gso_normalization(v0,v1,v2,w0,w1,w2);
	
	print_vector(w0);
	print_vector(w1);
	print_vector(w2);
}
