/* # include <stdio.h>
//大きい方の数を返してあげる。
# define MAX(a,b) (a > b ? a : b)

//マイナスな値は正の値で返ってくる
# define MOD(a) ((a < 0) ? -a : a)

int main(void)
{
    float a = -100000;
    float b = -2;
    float c = -100;
    int hoge;
/*     int hoge
    
    hoge = MAX(a, b);
    printf("%d\n", hoge); */

    //hoge = MOD(a);
    //printf("%d\n", hoge);
//} */

#include <stdio.h>

int MAX(int a, int b)
{
	if (a > b)
	return (a);
	else
	return (b);
}

int change_plus(int num){
   if (num > 0)
      return num;
   else
      return -num;
}

int main(void)
{
    int a = -1000;
    int b = 100;
    int max;

    max = change_plus(a);
    printf("%d\n", max);
}
