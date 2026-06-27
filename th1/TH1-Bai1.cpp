#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

struct Phanso{
    int tu, mau;
    void in(){
        cout<<"Nhập tử số: ";
        cin>>tu;
        do{
            cout<<"Nhập mẫu số: ";
            cin>>mau;
        }while(mau == 0);
    }

    void rut_gon()
    {
        int chung = __gcd(tu, mau);
        tu = tu/chung;
        mau = mau/chung;
    }

    void tranform()
    {
        if(mau < 0){
            tu = -tu;
            mau = -mau;
        }
    }
};

int main()
{
    Phanso x;   
    x.in();
    x.rut_gon();
    x.tranform();
    cout<<x.tu<<"/"<<x.mau;
    return 0;
}