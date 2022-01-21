#include<iostream>
using namespace std;

int main()
{
    int n, a=1, ans = 0;
    int left, loc, right;

    scanf("%d", &n);
    while(n/a!=0)
    {
        left = n/(a*10);
        loc = (n/a)%10;
        right = n%a;

        if(loc == 0) ans += left*a;
        else if(loc==1) ans += left *a + right + 1;
        else ans += (left + 1)*a;
//        cout << "left " << left << " loc " << loc << " right " << right<< " a " << a << " ans " << ans << endl;
        a *= 10;
    }

    printf("%d", ans);

    return 0;
}

