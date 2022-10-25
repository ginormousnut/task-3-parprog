#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double sh(double x)
{
	double s = x, a=x;//a is the current summand of the series
	int i;

		for (i = 1; i < 100000; i++)
		{
			if (a == a * x * x / (2 * i * (2 * i + 1))) //check for machine zero
			{
				break;
			}
			else
				{
					a = a * x * x / (2 * i * (2 * i + 1));
					s = s + a;
				}
				
		}
		// printf("%d\n", i); output check of the final iteration
		return s;
}


int main()
{
	double a = -5, b = 5; //a,b bounds of the interval at which we count
	int n = 20; //the number of segments into which we divide the segment, the number of points = n+1
	/*scanf("Enter the value of the left point %lf", &a);
	scanf("Enter the value of the right point %lf", &b);
	scanf("Enter the number of partition segments %d", &n); 
	if you'd like to enter your own values*/

	int k = 0; //point counter
	double f; // the current value of sh
	for (double x = a; x <= b; x= x + (b - a) / n)
	{
		if (k >= 0 && k <= 2 || k >= n - 2 && k <= n)
		{
			f = sh(x);
			printf("The value of the Taylor series in the point %.2lf = %.10e\n", x, f);
			printf("The real value in the point %.2lf = %.10e\n", x, sinh(x));
			printf("Difference in values = %e\n\n", abs(sinh(x)- f));
		}
		k++;
	}
}