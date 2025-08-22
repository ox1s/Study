/*
Problem EE -- расширенный алгоритм E

Даны два целых числа x и y
Необходимо найти их наибольший общий делитель d и целые, возможно отрицательные числа a и b, такие, что:
ax + by = d
Используйте тип long long для всех чисел
Посылка должна состоять из программы, считывающей со стандартного ввода два числа x и y и выводящей на стандартный вывод три числа: a, b, d
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

long long egcd(long long x, long long y)
{

	long long uold = 1; long long u = 0;
	long long vold = 0; long long v = 1;
	long long b = y, a = x,q,r,utmp,vtmp,d;
	while ( b!=0 )
	{
		q = a/b;
		r = a%b;
		a = b;
		b = r;
		utmp = u; u = uold - q*u; uold = utmp;
		vtmp = v; v = vold - q*v; vold = vtmp;
	}
	d = a;
	if (d<0)
    {
    	d = -d;
    	u = -uold; v = -vold;
    }
    else {u = uold; v = vold;}
	assert( d == u*x+ v*y );
	printf("%lld %lld %lld\n", u,v,d);
	return d;
}
int main()
{
	long long x,y;
	int res = scanf("%lld%lld",&x,&y);
	if (res != 2)
		abort();
	egcd(x,y);


}


