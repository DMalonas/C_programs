#include <stdio.h>


typedef struct
{
    double re;
    double im;
} complex;


complex complex_operation(const complex *c1, const complex *c2, char sign);

int main(void)
{
    char sign;
    complex z1, z2, z;

    printf("No1 real part: ");
    while(scanf("%lf", &z1.re) != 1)
    {
        printf("\n");
        while(getchar() != '\n');
    }
    printf("No1 imag part: ");
    while(scanf("%lf", &z1.im) != 1)
    {
        printf("\n");
        while(getchar() != '\n');
    }
    printf("Enter operation [+, -, *, /]: ");
    while(1)
    {
        scanf("%c", &sign);
        if((sign == '+') || (sign == '-') || (sign == '*') || (sign == '/'))
        {
            break;
        }
        printf("\n");
        continue;
    }
    while(1)
    {
        printf("No2 real part: ");
        while(scanf("%lf", &z2.re) != 1)
        {
            printf("\n");
            while(getchar() != '\n');
        }
        printf("No1 imag part: ");
        while(scanf("%lf", &z2.im) != 1)
        {
            printf("\n");
            while(getchar() != '\n');
        }
        if((sign == '/') && (z2.re == 0) && (z2.im == 0))
        {
            printf("Divisor cannot be 0\n");
            continue;
        }
        break;
    }
    z = complex_operation(&z1, &z2, sign);
    printf("The result of (%.2lf %+.2lfj)  %c  (%.2lf %+.2lfj)  == %.2lf %+.2lfj\n", z1.re, z1.im, sign, z2.re, z2.im, z.re, z.im);
    return 0;
}


complex complex_operation(const complex *c1, const complex *c2, char sign)
{
    complex z;
    char sign_local;

    sign_local = sign;

    switch(sign_local)
    {
        case '+':
            z.re = ((c1->re) + (c2->re));
            z.im = ((c1->im) + (c2->im));
        break;
        case '-':
            z.re = ((c1->re) - (c2->re));
            z.im = ((c1->im) - (c2->im));
        break;
        case '*':
            z.re = ((c1->re) * (c2->re)) + ((c1->im) * (c2->im));
            z.im = ((c1->re) * (c2->im)) + ((c1->im) * (c2->re));
        break;
        case '/':
            z.re = (((c1->re) * (c2->re)) + ((c1->im) * ((c2->im)))) / (((c2->re) * (c2->re)) + ((c2->im) * (c2->im)));
            z.im = (((c1->im) * ((c2->re))) - ((c1->re) * (c2->im))) / (((c2->re) * (c2->re)) + ((c2->im) * (c2->im)));
        break;
    }

    return z;
}
