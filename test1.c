

/* int main(void)
{
	int i;
	
	scanf("%d", &i);
	i > 0 ? printf("big\n") : printf("small\n");
	//?マーク便利すぎて最高
} */

#include <stdio.h> /* printf */
#include <math.h> /* M_PI */

int main(void) {
    double degree;
    double radian;

    degree = 30;

    radian = degree * (M_PI / 180);

    printf("degree:%f\n", degree);
    printf("radian:%f\n", radian);
    
    return 0;
}