#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

class cDate
{
    private:
        int d, m, y;
        int get_sum_days()const
        {
            int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            long int n = y * 365 + d;
            for (int i = 1; i < m; i++) n += monthDays[i];
            int leaps = y;
            if (m <= 2) leaps--;
            n += leaps / 4 - leaps / 100 + leaps / 400;
            return n;
        }
    public:
        cDate(int d = 1, int m = 1, int y = 2000): d(d), m(m), y(y){}

        bool check_date(int d, int m, int y) const 
        {
            if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0) return true;
            int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) date_of_month[2] = 29;
            if(d > date_of_month[m]) return true;
            return false;
        }
        void inp()
        {
            do{
                cout<<"Nhập ngày tháng năm theo định dạng dd mm yyyy: ";
                cin>>d>>m>>y;
            }while(check_date(d, m, y));
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

        cDate& operator=(const cDate &b)
        {
            if(this != &b)
            {
                this -> d = b.d;
                this -> m = b.m;
                this -> y = b.y;
                return *this;
            }
        } 
        
        friend cDate operator+(cDate a, int days)
        {
            int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            a.d += days;
            while(true) 
            {
                bool leap = (a.y % 400 == 0 || (a.y % 4 == 0 && a.y % 100 != 0));
                monthDays[2] = leap ? 29 : 28;
                if (a.d <= monthDays[a.m]) break;
                a.d -= monthDays[a.m];
                a.m++;
                if (a.m > 12) 
                {
                    a.m = 1;
                    a.y++;
                }
            }
            return a;
        }

        friend cDate operator+(int days, cDate a)
        {
            return a + days;
        }

        friend cDate operator-(cDate a, int days)
        {
            int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            a.d -= days;
            while(a.d <= 0) 
            {
                a.m--;
                if (a.m < 1) 
                {
                    a.m = 12;
                    a.y--;
                }
                bool leap = (a.y % 400 == 0 || (a.y % 4 == 0 && a.y % 100 != 0));
                monthDays[2] = leap ? 29 : 28;
                a.d += monthDays[a.m];
            }
            return a;
        }

        cDate& operator++()
        {
            *this = *this + 1;
            return *this;
        }
        cDate operator++(int)
        {
            cDate tmp = *this;
            *this =  *this + 1;
            return tmp;
        }

        cDate& operator--()
        {
            *this = *this - 1;
            return *this;
        }

        cDate operator--(int)
        {
            cDate tmp = *this;
            *this = *this - 1;
            return tmp;
        }

        friend int operator-(const cDate &a, const cDate &b)
        {
            return abs(a.get_sum_days() - b.get_sum_days());
        }
};

int main()
{
    cout << "--- KIEM TRA NHAP XUAT ---\n";
    cDate d1, d2;
    cout << "Nhap ngay thu nhat:\n";
    cin >> d1;
    cout << "Nhap ngay thu hai:\n";
    cin >> d2;

    cout << "\n--- KIEM TRA TOAN TO TRU 2 NGAY ---\n";
    cout << "Khoang cach giua hai ngay: " << d1 - d2 << " ngay\n";

    cout << "\n--- KIEM TRA TOAN TU CONG/TRU SO NGUYEN ---\n";
    cout << "Ngay thu nhat cong 10 ngay (d1 + 10): " << d1 + 10;
    cout << "Ngay thu nhat cong 10 ngay (10 + d1): " << 10 + d1;
    cout << "Ngay thu hai tru 15 ngay (d2 - 15): " << d2 - 15;

    cout << "\n--- KIEM TRA TOAN TU TANG/GIAM ---\n";
    cout << "Ngay d1 hien tai: " << d1;
    
    cout << "Tien to (++d1): " << ++d1;
    cout << "Sau tien to d1: " << d1;
    
    cout << "Hau to (d1++): " << d1++;
    cout << "Sau hau to d1: " << d1;
    
    cout << "Tien to giam (--d1): " << --d1;
    
    cout << "\n--- KIEM TRA TOAN TU GAN ---\n";
    cDate d3;
    d3 = d1;
    cout << "Ngay d3 sau khi gan bang d1: " << d3;
    return 0;
}