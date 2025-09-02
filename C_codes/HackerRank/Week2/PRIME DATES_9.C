PRIME DATES

#include <stdio.h>

static const int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int isLeap(int y){
    return (y%400==0) || ((y%4==0) && (y%100!=0));
}

void nextDate(int *d,int *m,int *y){
    int dim = (*m==2 && isLeap(*y)) ? 29 : mdays[*m-1];
    if (++(*d) > dim){ *d = 1; if (++(*m) > 12){ *m = 1; ++(*y); } }
}

long long makeNum(int d,int m,int y){
    return (long long)d*100*10000 + (long long)m*10000 + y;
}

int findLucky(int d1,int m1,int y1,int d2,int m2,int y2){
    int cnt = 0;
    for(;;){
        long long z = makeNum(d1,m1,y1);
        if (z % 4 == 0 || z % 7 == 0) ++cnt;
        if (d1==d2 && m1==m2 && y1==y2) break;
        nextDate(&d1,&m1,&y1);
    }
    return cnt;
}

int main(void){
    int d1,m1,y1,d2,m2,y2;
    if (scanf("%d-%d-%d %d-%d-%d", &d1,&m1,&y1, &d2,&m2,&y2) != 6) return 0;
    printf("%d\n", findLucky(d1,m1,y1,d2,m2,y2));
    return 0;
}
