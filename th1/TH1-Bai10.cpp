#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

struct Users{
    int in, out;

    bool check(int a, int b)
    {
        return(a < 6 || b > 18 || a >= b);
    }

    void inp()
    {
        do{
            cout<<"Nhập giờ vào và giờ ra (theo định dạng 24h): ";
            cin>>in>>out;
        }while(check(in, out));
    }
};

int cal_val(Users x)
{
    int a = x.in;
    int b = x.out;
    if(b < 12) return (b - a )*6000;
    else
    {
        if(a >= 12) return (b-a)*7500;
        else return (12 - a)*6000 + (b - 12)*7500;
    }
}
int main()
{
    Users x;
    x.inp();
    cout<<"Tiền công là: "<<cal_val(x);
    return 0;
}

