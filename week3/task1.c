#include <stdio.h>
#define INT_MAX 2147483647
#define FLOAT_MAX 3.402823E+38
#define DBL_MAX 1.7E+308
int main() {
	 int a = INT_MAX;
	 float b = FLOAT_MAX;
	 double c = DBL_MAX;
	 printf("%lu, %d\n", sizeof(a),a); 
	 printf("%lu, %f\n", sizeof(b),b); 
	 printf("%lu, %f\n", sizeof(c),c); 
	return 0;
}
