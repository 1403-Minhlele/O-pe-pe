#include<bits/stdc++.h>
using namespace std;

class Date{
    private:
        int d, m, y;
        bool check_date(int d, int m, int y) const 
        {
            if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0) return true;
            int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) date_of_month[2] = 29;
            if(d > date_of_month[m]) return true;
            return false;
        }
    public:
        Date(int d = 1, m = 1, y = 2000): d(d), m(m), y(y) {}
        void inp()
        {
            do
            {
                cout<<"Canh bao!!! Nhap sai dinh dang";
                cin>>d>>m>>y;
            } while (!check_date(d, m, y));
        }
        void out() const
        {
            string day, month, year;
            if(d < 10) day = "0" + to_string(d);
            else day = to_string(d);
            if(m < 10) month = "0" + to_string(m);
            else month = to_string(m);
            year = to_string(y);
            cout<<day<<"/"<<month<<"/"<<year;
            cout<<"\n";
        }
        friend istream &operator>>(istream &in, cDate & a)
        {
            a.inp();
            return in;
        }
        friend ostream &operator<<(ostream &ou, const cDate&a)
        {
            a.out();
            return ou;
        }
};

class BatDongSan{
    private:
        string MaGiaoDich;
        Date NgayGiaoDich;
    public:
        BatDongSan()
};