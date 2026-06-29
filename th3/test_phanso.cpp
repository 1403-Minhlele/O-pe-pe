#include<bits/stdc++.h>
using namespace std;

class PhanSo{
    private: 
        int tu, mau;
    public:
        PhanSo();
        PhanSo(int);
        PhanSo(int, int);

        void Nhap()
        {
            cin>>tu>>mau;
        }

        void Xuat() const
        {
            cout<<tu<<"/"<<mau;
        }

        PhanSo& operator=(PhanSo d);
        friend istream& operator>> (istream& , PhanSo&);
        friend ostream& operator<< (ostream&, const PhanSo&);
};

PhanSo& PhanSo::operator= (PhanSo d)
{
    tu = d.tu;
    mau = d.mau;
    return *this;
}

istream& operator>> (istream& in, PhanSo& a)
{
    a.Nhap();
    return in;
}

ostream& operator<< (ostream& ou, const PhanSo& a)
{
    a.Xuat();
    return ou;
}

PhanSo::PhanSo()
{
    tu = 0;
    mau = 1;
}

PhanSo::PhanSo(int t)
{
    tu = t;
    mau = 1;
}   

PhanSo::PhanSo(int t, int m)
{
    tu = t;
    mau = m;
}   

int main()
{
    PhanSo A, B(3), C(2, 3), D;

    cin>>D;
    cout<<D<<" "<<A<<" "<<B<<" "<<C<<" ";

    D = C;

    cout<<"\n"<<D;
    return 0;
}