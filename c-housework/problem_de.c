#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void egcd(int x, int y, int *u, int *v, int *g)
{
	int uold = 1; int u_cur = 0;
	int vold = 0; int v_cur = 1;
	int b = y, a = x,q,r,utmp,vtmp,d;
	while ( b!=0 )
	{
		q = a/b;
		r = a%b;
		a = b;
		b = r;
		utmp = u_cur; u_cur = uold - q*u_cur; uold = utmp; 
		vtmp = v_cur; v_cur = vold - q*v_cur; vold = vtmp;
	}
	d = a; 
	if (d<0)
    	{
    		d = -d;
    		u_cur = -uold; v_cur = -vold;
    	}
    	else {u_cur = uold; v_cur = vold;}
	assert( d == u_cur*x+ v_cur*y );
	*u = u_cur;
	*v = v_cur;
	*g = d;

}
void diof(int a, int b, int c)
{
	int u, v, g;
	egcd(a,b,&u,&v,&g);
	if (c%g != 0) printf("NONE");
	else {
		int k = c / g;
		printf("%d %d", u*k, v*k);
	}	
}

int main()
{
	int a,b,c;
	int res = scanf("%d%d%d",&a,&b,&c);
	if (res != 3) abort();
	diof(a,b,c);
}

