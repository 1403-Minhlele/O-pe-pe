#include<bits/stdc++.h>
#include<ctime>
using namespace std;
#define fi first
#define se second

class Date
{
    private:
        int d, m, y;

    public:
        Date(int d = 1, int m = 1, int y = 2000): d(d), m(m), y(y){}
        int get_d() const { return d; }
        int get_m() const { return m; }
        int get_y() const { return y; }

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
        }
        friend istream &operator>>(istream &in, Date & a)
        {
            a.inp();
            return in;
        }
        friend ostream &operator<<(ostream &ou, const Date&a)
        {
            a.out();
            return ou;
        }
        void is_nhuan()
        {
            cout<<*this;
            if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            {
                cout<<" là một năm nhuận";
            }
            else
                cout<<" không là năm nhuận";
            cout<<"\n";
        }
};

class NhanVien
{
    private:
        string maNV, name;
        Date ngaySinh, ngayVaoLam;
    public:
        NhanVien(string maNV = "", string name = ""): maNV(maNV), name(name){}
        
        void inp()
        {
            cout<<"Nhap ma nhan vien: "; cin>>maNV;
            cout<<"Nhap ten nhan vien: "; cin.ignore(); getline(cin, name);
            cout<<"Ngay sinh cua nhan vien --> ";cin>>ngaySinh;
            cout<<"Ngay vao lam cua nhan vien -->";cin>>ngayVaoLam;
        }
        friend istream &operator>>(istream &in, NhanVien & a)
        {
            a.inp();
            return in;
        }
        void out() const
        {
            cout << left << setw(10) << maNV 
                 << " | " << left << setw(25) << name 
                 << " | ";
            cout<<ngaySinh;
            cout << " | ";
            cout<<ngayVaoLam;
            cout << "\n";
        }
        friend ostream &operator<<(ostream &ou, const NhanVien &a)
        {
            a.out();
            return ou;
        }

        int tinhTuoi() const
        {
            time_t t = time(0);
            tm* now = localtime(&t);
            
            int current_year = now->tm_year + 1900;
            int current_month = now->tm_mon + 1;
            int current_day = now->tm_mday;

            int age = current_year - ngaySinh.get_y();
            
            if (current_month < ngaySinh.get_m() || (current_month == ngaySinh.get_m() && current_day < ngaySinh.get_d()))
            {
                age--;
            }
            return age;
        }
};

int main()
{
    cout << "=== KIEM TRA LOP DATE ===\n";
    Date d1(29, 2, 2024);
    cout << "Ngay tao bang tham so: " << d1 << "\n";
    d1.is_nhuan();

    cout << "\nNhap mot ngay bat ky:\n";
    Date d2;
    cin >> d2;
    cout << "Ngay vua nhap: " << d2 << "\n";
    d2.is_nhuan();
    cout << "Lay du lieu tu Getter: Ngay " << d2.get_d() << ", Thang " << d2.get_m() << ", Nam " << d2.get_y() << "\n";


    cout << "\n=== KIEM TRA LOP NHAN VIEN ===\n";
    NhanVien A;
    cin >> A;

    cout << "\n========================= THONG TIN NHAN VIEN =========================\n";
    cout << left << setw(10) << "Ma NV" 
         << " | " << left << setw(25) << "Ho va Ten" 
         << " | " << left << setw(10) << "Ngay Sinh" 
         << " | " << left << setw(10) << "Ngay Vao" << "\n";
    cout << string(68, '-') << "\n";
    cout << A;

    cout << "\n-> Tuoi cua nhan vien hien tai la: " << A.tinhTuoi() << " tuoi\n";

    return 0;
}