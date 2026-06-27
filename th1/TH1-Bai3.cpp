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
        int chung = gcd(tu, mau);
        tu = tu/chung;
        mau = mau/chung;
    }
};

void sum_diff(Phanso &A, Phanso &B, Phanso a, Phanso b)
{
    A.mau = a.mau*b.mau;
    A.tu = a.tu*b.mau + a.mau*b.tu;
    A.rut_gon();

    B.mau = a.mau*b.mau;
    B.tu = a.tu*b.mau - a.mau*b.tu;
}


void cal(Phanso &A, Phanso &B, Phanso a, Phanso b)
{
    A.tu = a.tu*b.tu;
    A.mau = a.mau*b.mau;
    B.tu = a.tu*b.mau;
    B.mau = a.mau*b.tu;
    A.rut_gon();
    B.rut_gon();
}


int main()
{
    Phanso x, y;
    cout<<"Nhập phân số thứ 1: \n"; x.in();
    cout<<"Nhập phân số thứ 2: \n"; y.in();

    x.rut_gon();
    y.rut_gon();
    
    Phanso ans, ans1, ans2, ans3;

    sum_diff(ans, ans1, x, y);
    cal(ans2, ans3, x, y);

    ans.tranform();
    ans1.tranform();
    ans2.tranform();
    ans3.tranform();

    cout<<"Tổng: "<<ans.tu<<"/"<<ans.mau<<"\n";
    cout<<"Hiệu: "<<ans1.tu<<"/"<<ans1.mau<<"\n";
    cout<<"Tích: "<<ans2.tu<<"/"<<ans2.mau<<"\n";
    cout<<"Thương: "<<ans3.tu<<"/"<<ans3.mau<<"\n";
    return 0;
}