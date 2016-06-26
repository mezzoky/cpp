#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
#define DEBUG
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
int a[1005], v[1005], d[1005];

int main() {
    //freopen("x.in", "r", stdin);
    // freopen("C-small-attempt0.in", "r+", stdin);
    freopen("C-small-attempt0.out", "a", stdout);

    int foo = 10;
    printf("\n\nstatic val: %i, addr: %p\n", foo, (void*)&foo);

    int *bar = &foo;
    printf(
        "heap pointer point_to: %p, val: %i, addr: %p\n",
        bar,
        *bar,
        (void*)&bar
    );

    int x = 20;
    bar = &x;
    printf(
        "heap pointer point_to: %p, val: %i, addr: %p\n",
        bar,
        *bar,
        (void*)&bar
    );

    printf(
        "sizeof bar(%lu), *bar(%lu), &bar(%lu)\n",
        sizeof(bar),
        sizeof(*bar),
        sizeof(&bar)
    );

    *bar = 0;
    bar = NULL;
    delete bar;

    int save = 55;
    bar = &save;

    int *s = &x;
    *s = 1000;
    printf(
        "%i %i %i \n",
        *s,
        x,
        *bar
    );


    /* array pointer */
    int numbers[5];
    int *p = numbers;

    *p = 10;
    printf(
        "normal: %d %p %p \n",
        numbers[0],
        p,
        numbers
    );
    *(++p) = 20;
    printf(
        "normal: %d %p %p \n",
        numbers[1],
        p,
        numbers
    );
    p = &numbers[2];
    *p = 30;
    printf(
        "normal: %d %p %p \n",
        numbers[2],
        p,
        numbers
    );
    p = numbers + 3;
    *p = 40;
    printf(
        "normal: %d %p %p \n",
        numbers[3],
        p,
        numbers
    );
    p = numbers;
    *(p+4) = 50;
    printf(
        "normal: %d %p %p \n",
        numbers[4],
        p + 4,
        numbers
    );
    p += 4;
    int j = 5;
    while (j--) {
        printf(
            "reverse: %d %p %p \n",
            numbers[j],
            p--,
            numbers
        );
    }
    printf("end \n");
    printf("\n");
    p = NULL;
    delete p;

    int *q = new int(11);

    cout << q << " | " << *q << " | " << &q << endl;

    delete q;
    q = NULL;

    string ss = "123";
    cout << SZ(ss) << endl;
    
    cout << endl;

    int zzz;
    F0(zzz, 5) {
        cout << zzz << endl;
    }
    cout << endl;
    cout << endl;
    
    F1(zzz, 5) {
        cout << zzz << endl;
    }

    return 0;
}
