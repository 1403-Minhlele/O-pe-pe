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

        friend int thamnien(const NhanVien a)
        {
            time_t t = time(0);
            tm* now = localtime(&t);
            
            int current_year = now->tm_year + 1900;
            int current_month = now->tm_mon + 1;
            int current_day = now->tm_mday;

            int age = current_year - a.ngayVaoLam.get_y();
            
            if (current_month < a.ngayVaoLam.get_m() || (current_month == a.ngayVaoLam.get_m() && current_day < a.ngayVaoLam.get_d()))
            {
                age--;
            }
            return age;
        }
};

int main()
{
    NhanVien *ds;
    int n;
    cout<<"Nhap so luong nhan vien: ";
    do
    {
        cin>>n;
        if(n <= 0) cout<<"Nhan vien khong the am, vui long nhap lai: ";
    } while (n <= 0);
    
    ds = new NhanVien[n+1];
    for(int i = 1 ; i<=n; i++)
    {
        cout<<"=============== Thong tin  nhan vien thu "<<i<<" ===============\n";
        cin>>ds[i];
    }
    cout << "\n================= THONG TIN NHAN VIEN THAM NIEN > 5 NAM =================\n";
    cout << left << setw(10) << "Ma NV" 
         << " | " << left << setw(25) << "Ho va Ten" 
         << " | " << left << setw(10) << "Ngay Sinh" 
         << " | " << left << setw(10) << "Ngay Vao" << "\n";
    cout << string(68, '-') << "\n";
    for(int i = 1 ; i<=n; i++)
        if(thamnien(ds[i]) > 5)
            cout<<ds[i];
    
    delete[] ds; 
    return 0;
}