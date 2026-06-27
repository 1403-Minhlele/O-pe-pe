#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

class cPhanso{
    private:
        int tu, mau;
    public:
        void inp(int id){
            cout<<"Nhập tử số thứ "<<id<<": ";
            cin>>tu;
            do{
                cout<<"Nhập mẫu số thứ "<<id<<": ";
                cin>>mau;
            }while(mau == 0);
        }
        void tranform();
        void out();
        cPhanso sum(cPhanso p);
        cPhanso diff(cPhanso p);
        cPhanso multi(cPhanso p);
        cPhanso div(cPhanso p);
        string toString() {
            if(mau == 0) return "Không tồn tại phép chia ";
            if (tu == 0) return "0";
            if (mau == 1) return to_string(tu);
            return to_string(tu) + "/" + to_string(mau);
        }
};

void cPhanso::tranform()
{
    if(mau < 0){
        tu = -tu;
        mau = -mau;
    }
    int chung = gcd(abs(tu), abs(mau));
    tu = tu/chung;
    mau = mau/chung;
}

void cPhanso::out()
{
    cout<<tu<<"/"<<mau;
}

cPhanso cPhanso::sum(cPhanso p)
{
    cPhanso tmp;
    tmp.tu = tu*p.mau + p.tu*mau;
    tmp.mau = mau*p.mau;
    tmp.tranform();
    return tmp;
}

cPhanso cPhanso::diff(cPhanso p)
{
    cPhanso tmp;
    tmp.tu = tu*p.mau - p.tu*mau;
    tmp.mau = mau*p.mau;
    tmp.tranform();
    return tmp;
}

cPhanso cPhanso::multi(cPhanso p)
{
    cPhanso tmp;
    tmp.tu = tu*p.tu;
    tmp.mau = mau*p.mau;
    tmp.tranform();
    return tmp;
}

cPhanso cPhanso::div(cPhanso p)
{
    cPhanso tmp;
    tmp.tu = tu*p.mau;
    tmp.mau = mau*p.tu;
    tmp.tranform();
    return tmp;
}

int main()
{
    cPhanso x, y, ans, ans1, ans2, ans3;
    x.inp(1);
    x.tranform();
    y.inp(2);
    y.tranform();
    
    ans = x.sum(y);
    ans1 = x.diff(y);
    ans2 = x.multi(y);
    ans3 = x.div(y);
    
    cout<<"Kết quả các phép tính cộng trừ 2 phân số "<<"\n";
    cout<< setfill('-') << setw(61) << "-" <<endl;
    cout<< setfill(' ');
    cout<<"| "<<setw(12)<< left << "Tổng" << "| " <<setw(12)<< left << "Hiệu" << "| " <<setw(12)<< left << "Tích" << "| " <<setw(12)<< left << "Thương"<< "|" << endl; 
    cout<< setfill('-') << setw(61) << "-" <<endl;
    cout<< setfill(' ');
    cout<<"| "<<setw(10)<< left << ans.toString() << "| " <<setw(10)<< left << ans1.toString() << "| " <<setw(10)<< left << ans2.toString() << "| " <<setw(11)<< left << ans3.toString()<< "|" << endl; 
    cout<< setfill('-') << setw(61) << "-" <<endl;
    return 0;
}