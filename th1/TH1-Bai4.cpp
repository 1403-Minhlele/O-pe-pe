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
    void in(int idx){
        cout<<"Nhập tử số ps thứ "<<idx<<": ";
        cin>>tu;
        do{
            cout<<"Nhập mẫu số ps thứ "<<idx<<": ";
            cin>>mau;
        }while(mau == 0);
    }

    void out()
    {
        cout<<tu<<"/"<<mau<<"\n";
    }

    void rut_gon()
    {
        int chung = gcd(tu, mau);
        tu = tu/chung;
        mau = mau/chung;
    }
};

bool cmp(Phanso A, Phanso B)
{
    return A.tu*B.mau < B.tu*A.mau;
}

bool cmp1(Phanso A, Phanso B)
{
    return A.tu*B.mau > B.tu*A.mau;
}

Phanso a[100010];
ll n;

int main()
{
    cout<<"Nhập số lượng phân số bạn mong muốn: ";  cin>>n;
    for(int i = 1 ; i<=n; i++){
        a[i].in(i);
        a[i].rut_gon();
        a[i].tranform();
    }
    sort(a+1,a+n+1, cmp);
    cout<<"Số lớn nhất trong tất cả là: "<<a[n].tu<<"/"<<a[n].mau<<"\n";

    cout<<"Mảng sắp xếp tăng dần là: \n";
    for(int i = 1 ; i<=n; i++) a[i].out();

    sort(a+1,a+n+1, cmp1);
    cout<<"Mảng sắp xếp giảm dần là: \n";
    for(int i = 1 ; i<=n; i++) a[i].out();

    return 0;
}