#include <stdio.h>
int main()
{
	float b1=0.0, h1=0.0, b2=0.0, h2=0.0, X1=0.0, Y1=0.0, X2=0.0, Y2=0.0, A1=0.0, A2=0.0, X=0.0, Y=0.0;
	// Get dimensions from user.
	printf("Enter b of bigger rectangle: ");
	scanf("%f", &b1);
	printf("Enter h of bigger rectangle: ");
	scanf("%f", &h1);
	printf("Enter b of smaller rectangle: ");
	scanf("%f", &b2);
	printf("Enter h of smaller rectangle: ");
	scanf("%f", &h2);
	// Centroid positions of both rectangles
	X1 = b1 / 2;
	Y1 = h1 / 2;
	X2 = b1 - (b2 / 2);
	Y2 = h1 - (h2 / 2);
	// Areas of both rectangles
	A1 = b1 * h1;
	A2 = b2 * h2;
	// Centroid of required part
	X = ((A1 * X1) - (A2 * X2)) / (A1 - A2);
	Y = ((A1 * Y1) - (A2 * Y2)) / (A1 - A2);
	// Display X and Y
	printf("Centroid of shaded portion is:\n");
	printf("X: %f, Y: %f\n", X, Y);
	return 0;
}