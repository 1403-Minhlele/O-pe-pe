#include<bits/stdc++.h>
using namespace std;

class soPhuc{
    private:
        double thuc, ao;
        static int cnt;
    public:
        soPhuc(double thuc = 0, double ao = 0): thuc(thuc), ao(ao) {}
        bool check() const
        {
            return (thuc == 0 && ao == 0);
        }
        void inp()
        {
            cout<<"Nhập lần lượt thành phần thực và thành phần ảo của số phuc: ";
            double x, y;
            cin>>x>>y;
            this -> thuc = x;
            this -> ao = y;
        }
        void out() const 
        {
            if(thuc == 0 && ao == 0) cout<<0<<"\n";
            else 
            {
                if(thuc != 0 && ao == 0) cout<<thuc<<"\n";
                else if(thuc == 0 && ao != 0) cout<<ao<<"i\n";
                else
                {
                    cout<<thuc<<" ";
                    if(ao < 0) cout<<"- "<<abs(ao)<<"i\n";
                    else cout<<"+ "<<ao<<"i\n";
                }
            }
        }
        soPhuc sum(const soPhuc p) const ;
        soPhuc diff(const soPhuc p) const ;
        soPhuc multi(const soPhuc p) const ;
        soPhuc div(const soPhuc p) const;

        friend istream &operator>>(istream &in, soPhuc &a)
        {
            a.inp();
            return in;
        }
        friend ostream &operator<<(ostream &ou, const soPhuc &a)
        {
            a.out();
            return ou;
        }
        friend soPhuc operator+(const soPhuc &b, const soPhuc &a)
        {
            return a.sum(b);
        }

        friend soPhuc operator-(const soPhuc &b, const soPhuc &a)
        {
            return b.diff(a);
        }

        friend soPhuc operator*(const soPhuc &b, const soPhuc &a)
        {
            return a.multi(b);
        }

        friend soPhuc operator/(const soPhuc &b, const soPhuc &a)
        {
            return b.div(a);
        }

        friend bool operator==(const soPhuc &a, const soPhuc &b)
        {
            return (a.thuc == b.thuc) && (a.ao == b.ao);
        }

        friend bool operator!=(const soPhuc &a, const soPhuc &b)
        {
            return (a.thuc != b.thuc) || (a.ao != b.ao);
        }

        soPhuc& operator=(const soPhuc &b)
        {
            this -> thuc =  b.thuc;
            this -> ao = b.ao;
            return *this;
        }
};

soPhuc soPhuc::sum(const soPhuc p) const
{
    soPhuc tmp;
    tmp.thuc = thuc + p.thuc;
    tmp.ao = ao + p.ao;
    return tmp;
}

soPhuc soPhuc::diff(const soPhuc p) const 
{
    soPhuc tmp;
    tmp.thuc = thuc - p.thuc;
    tmp.ao = ao - p.ao;
    return tmp;
}

soPhuc soPhuc::multi(const soPhuc p) const 
{
    soPhuc tmp;
    tmp.thuc = thuc*p.thuc - ao*p.ao;
    tmp.ao = thuc*p.ao + ao*p.thuc;
    return tmp;
}

soPhuc soPhuc::div(const soPhuc p) const
{
    soPhuc tmp;
    bool checking = p.check();
    if(checking == true)
    {
        cout<<"Không thể thực hiện phép chia";
        exit(0);
    }
    tmp.thuc = thuc*p.thuc + ao*p.ao;
    tmp.ao = p.thuc*ao - thuc*p.ao;

    double mau = p.thuc*p.thuc + p.ao*p.ao;
    tmp.thuc /= mau;
    tmp.ao /= mau;
    
    return tmp;
}


int main()
{
    soPhuc a, b;
    cout<<"Nhap so phuc a:\n";cin>>a;
    cout<<"Nhap so phuc b:\n";cin>>b;
    soPhuc c = a + b;
    soPhuc d = a - b;
    soPhuc e = a*b;
    soPhuc f = a/b;

    cout<<"Tong 2 so phuc: "<<c<<"=================================\n";
    cout<<"Hieu 2 so phuc: "<<d<<"=================================\n";
    cout<<"Tich 2 so phuc: "<<e<<"=================================\n";
    cout<<"Thuong 2 so phuc: "<<f<<"=================================\n";

    double x;
    cout<<"Nhap 1 so thuc x: "; cin>>x;
    cout<<"Tong so phuc a voi x: "<<a+x;
    cout<<"Hieu so phuc a voi x: "<<a-x;
    cout<<"Tich so phuc b voi x: "<<b*x;
    cout<<"Thuong so phuc b voi x: "<<b/x;

    if(a == b) cout<<"So phuc a bang so phuc b";
    if(a != b) cout<<"So phuc a khac so phuc b";
    return 0;   
}
