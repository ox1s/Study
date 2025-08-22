#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "u_template.h"

int double_area(struct triangle_t tr)
{
    int res = (tr.pts[0].x * tr.pts[1].y + tr.pts[1].x * tr.pts[2].y +
               tr.pts[2].x * tr.pts[0].y - tr.pts[0].x * tr.pts[2].y -
               tr.pts[1].x * tr.pts[0].y - tr.pts[2].x * tr.pts[1].y);
    return res > 0 ? res : res * (-1);
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    struct point_t p1, p2, p3; 
    struct triangle_t tr;
    int s;

    int res = scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (res != 6) {
        printf("Wrong input!");
        abort();
    }

    p1.x = x1, p1.y = y1;
    p2.x = x2, p2.y = y2;
    p3.x = x3, p3.y = y3;

    tr.pts[0] = p1, tr.pts[1] = p2, tr.pts[2] = p3;

    s = double_area(tr);
    printf("%d", s);

    return 0;
}
