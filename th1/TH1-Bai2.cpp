#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

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
        int chung = gcd(abs(tu), abs(mau));
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

Phanso cmp(Phanso A, Phanso B)
{
    Phanso ans;
    ans.tu = max(A.tu*B.mau, B.tu*A.mau);
    ans.mau = B.mau*A.mau;
    ans.rut_gon();
    return ans;
}

int main()
{
    Phanso x, y;
    cout<<"Nhập phân số thứ 1: \n"; x.in();
    cout<<"Nhập phân số thứ 2: \n"; y.in();

    x.rut_gon();
    y.rut_gon();

    Phanso ans = cmp(x, y);
    ans.tranform();
    cout<<"Phân số lớn hơn là: "<<ans.tu<<"/"<<ans.mau;

    return 0;
}