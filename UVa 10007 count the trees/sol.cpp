#include<stdio.h>
#include<iostream>
#define MAXDIGITS 793
using namespace std;
#define PLUS 1
#define MINUS -1
typedef struct
{
    char digits[MAXDIGITS];
    int signbit;
    int lastdigit;
} bignum;
bignum catalans[301];
bignum factorials[301];
void print_bignum(bignum *);
void subtract_bignum(bignum *, bignum *, bignum *);
void int_to_bignum(int, bignum *);
void initialize_bignum(bignum *);
void digit_shift(bignum *, int);
void zero_justify(bignum *);
int compare_bignum(bignum *, bignum *);
void divide_bignum(bignum *, bignum *, bignum *);
void multiply_bignum(bignum *, bignum *, bignum *);
int compare_bignum(bignum *a, bignum *b)
{
    int i;
    if (b->lastdigit > a->lastdigit) return (PLUS);
    if (a->lastdigit > b->lastdigit) return (MINUS);
    for (i = a->lastdigit; i >= 0; i--)
    {
        if (a->digits[i] > b->digits[i]) return (MINUS);
        if (b->digits[i] > a->digits[i]) return (PLUS);
    }
    return 0;
}
void print_bignum(bignum *n)
{
    int i;
    for (i = n->lastdigit; i >= 0; i--)
        printf("%c", '0' + n->digits[i]);
    printf("\n");
}
void initialize_bignum(bignum *n)
{
    int_to_bignum(0, n);
}
void int_to_bignum(int s, bignum *n)
{
    int i;
    int t;
    n->signbit = PLUS;
    for (i = 0; i < MAXDIGITS; i++)
        n->digits[i] = (char) 0;
    n->lastdigit = -1;
    t = s;
    while (t > 0)
    {
        n->lastdigit ++;
        n->digits[ n->lastdigit ] = (t % 10);
        t = t / 10;
    }
    if (s == 0)
        n->lastdigit = 0;
}
int max(int a, int b)
{
    if (a > b) return (a); else return (b);
}
void zero_justify(bignum *n)
{
    while ((n->lastdigit > 0) && (n->digits[ n->lastdigit ] == 0))
        n->lastdigit --;
}
void digit_shift(bignum *n, int d)
{
    int i;
    if ((n->lastdigit == 0) && (n->digits[0] == 0)) return;
    for (i = n->lastdigit; i >= 0; i--)
        n->digits[i + d] = n->digits[i];
    for (i = 0; i < d; i++)
        n->digits[i] = 0;
    n->lastdigit = n->lastdigit + d;
}
void add_bignum(bignum *a, bignum *b, bignum *c)
{
    int carry;
    int i;
    initialize_bignum(c);
    c->signbit = a->signbit;
    c->lastdigit = max(a->lastdigit, b->lastdigit) + 1;
    carry = 0;
    for (i = 0; i <= (c->lastdigit); i++)
    {
        c->digits[i] = (char) (carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }
    zero_justify(c);
}
void multiply_bignum(bignum *a, bignum *b, bignum *c)
{
    bignum row;
    bignum tmp;
    int i, j;
    initialize_bignum(c);
    row = *a;
    for (i = 0; i <= b->lastdigit; i++)
    {
        for (j = 1; j <= b->digits[i]; j++)
        {
            add_bignum(c, &row, &tmp);
            *c = tmp;
        }
        digit_shift(&row, 1);
    }
    zero_justify(c);
}
void subtract_bignum(bignum *a, bignum *b, bignum *c)
{
    int borrow;
    int v;
    int i;
    initialize_bignum(c);
    c->lastdigit = max(a->lastdigit, b->lastdigit);
    borrow = 0;
    for (i = 0; i <= (c->lastdigit); i++)
    {
        v = (a->digits[i] - borrow - b->digits[i]);
        if (a->digits[i] > 0)
            borrow = 0;
        if (v < 0)
        {
            v = v + 10;
            borrow = 1;
        }
        c->digits[i] = (char) v % 10;
    }
    zero_justify(c);
}
void divide_bignum(bignum *a, bignum *b, bignum *c)
{
    bignum row;
    bignum tmp;
    int i, j;
    initialize_bignum(c);
    initialize_bignum(&row);
    initialize_bignum(&tmp);
    c->lastdigit = a->lastdigit;
    for (i = a->lastdigit; i >= 0; i--)
    {
        digit_shift(&row, 1);
        row.digits[0] = a->digits[i];
        c->digits[i] = 0;
        while (compare_bignum(&row, b) != PLUS)
        {
            c->digits[i] ++;
            subtract_bignum(&row, b, &tmp);
            row = tmp;
        }
    }
    zero_justify(c);
}
void catalan(int n)
{
    int counter;
    bignum aux, aux2;
    counter = 0;
    int_to_bignum(1, &catalans[0]);
    for (int i = 1; i <= n; i++)
    {
        counter++;
        int_to_bignum((4 * i - 2), &catalans[i]);
        multiply_bignum(&catalans[i - 1], &catalans[i], &aux);
        int_to_bignum(i + 1, &aux2);
        divide_bignum(&aux, &aux2, &catalans[i]);
    }
}
void factorial(int n)
{
    bignum aux;
    int_to_bignum(1, &factorials[0]);
    int_to_bignum(1, &factorials[1]);
    for (int i = 2; i <= n; i++)
    {
        int_to_bignum(i, &aux);
        multiply_bignum(&factorials[i - 1], &aux, &factorials[i]);
    }
}
int main()
{
    int n;
    catalan(300);
    factorial(300);
    bignum aux2;
    while (cin >> n && n != 0)
    {
        multiply_bignum(&factorials[n], &catalans[n], &aux2);
        print_bignum(&aux2);
    }
    return 0;
}