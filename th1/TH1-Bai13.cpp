#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

struct pt_bac_hai{
    double a, b, c;
    void in()
    {
        cout<<"Nhập hệ số a, b và c của phương trình ax^2 + bx + c = 0: ";
        cin>>a>>b>>c;
    }

    void giai_pt    ()
    {
        if(abs(a) < 1e-9 && abs(b) < 1e-9 && abs(c) < 1e-9) cout<<"Phương trình có vô số nghiệm\n";
        else if(abs(a) < 1e-9 && abs(b) < 1e-9 && abs(c) >= 1e-9) cout<<"Phương trình vô nghiệm\n";
        else if(abs(a) < 1e-9 && abs(b) >= 1e-9)
        {
            cout<<"Phương trình có nghiệm x = "<<-c/b<<"\n";
        }
        else
        {
            double delta = b*b - 4*a*c;
            if(delta > 0)
            {
                cout<<"Phương trình có hai nghiệm phân biệt: x1 = "<<(-b + sqrt(delta))/(2*a)<<", x2 = "<<(-b - sqrt(delta))/(2*a)<<"\n";
            }
            else if(abs(delta) < 1e-9)
            {
                cout<<"Phương trình có nghiệm kép x = "<<-b/(2*a)<<"\n";
            }
            else
            {
                cout<<"Phương trình vô nghiệm\n";
            }
        }
    }
};

int main()
{
    pt_bac_hai x;
    x.in();
    x.giai_pt();

    return 0;
}