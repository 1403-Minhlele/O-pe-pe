#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

struct pt_bac_nhat{
    double a, b;
    void in()
    {
        cout<<"Nhập hệ số a và b của phương trình ax + b = 0: ";
        cin>>a>>b;
    }

    void giai_pt()
    {
        if(abs(a) < 1e-9 && abs(b) < 1e-9) cout<<"Phương trình có vô số nghiệm\n";
        else if(abs(a) < 1e-9 && abs(b) >= 1e-9) cout<<"Phương trình vô nghiệm\n";
        else cout<<"Phương trình có nghiệm x = "<<-b/a<<"\n";
    }
};

int main()
{
    pt_bac_nhat x;
    x.in();
    x.giai_pt();

    return 0;
}