#include <bits/stdc++.h>
using namespace std;

class Date
{
    private:
        int d, m, y;

    public:
        Date(int d = 1, int m = 1, int y = 2000) : d(d), m(m), y(y) {}
        bool check_date(int d, int m, int y)
        {
            if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0)
                return true;
            int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
                date_of_month[2] = 29;
            if (d > date_of_month[m])
                return true;
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

        friend istream &operator>>(istream &in, Date &a)
        {
            a.inp();
            return in;
        }

        friend ostream &operator<<(ostream &ou, const Date&a)
        {
            a.out();
            return ou;
        }
};

class cCandidate
{
    private:
        string name, ma;
        double toan, van, anh;
        Date date;

    public:
        cCandidate(string name = "", string ma = "", double toan = 0, double van = 0, double anh = 0):
            name(name), ma(ma), toan(toan), van(van), anh(anh){}

        void inp()
        {
            cout<<"Nhap ma thi sinh: "; cin>>ma;
            cout<<"Nhap ten thi sinh: "; cin.ignore(); getline(cin, name);
            cin>>date;
            cout<<"Nhap diem toan, van , anh (diem so >= 0): ";
            do
            {
                cin>>toan>>van>>anh;
                if(toan < 0 || anh < 0 || van < 0)
                    cout<<"Du lieu khong hop le, vui long kiem tra va nhap lai: ";
            } while (toan < 0 || anh < 0 || van < 0);
        }
        double tong() const
        {
            return toan + van + anh;
        }

        void out() const
        {
            cout << left << setw(10) << ma 
                 << " | " << left << setw(25) << name 
                 << " | ";
            cout<<date;
            cout << " | " << right << setw(6) << toan 
                 << " | " << right << setw(6) << van 
                 << " | " << right << setw(6) << anh 
                 << " | " << right << setw(8) << tong() << "\n";
        }

        friend istream &operator>>(istream& in, cCandidate& a)
        {
            a.inp();
            return in;
        }
        friend ostream &operator<<(ostream &ou, const cCandidate& a)
        {
            a.out();
            return ou;
        }
};

class cListCandidate
{
    private:
        int n;
        cCandidate *list;
    public:
        cListCandidate(): n(0)
        {
            list = NULL;
        }

        void inp()
        {
            cout<<"Nhap so luong thi sinh: ";
            do
            {
                /* code */
                cin>>n;
                if(n <= 0) cout<<"Du lieu khong hop le, nhap lai: ";
            } while (n <= 0);
            delete[] list;
            list = new cCandidate[n+1];
            for(int i = 1 ; i<=n; i ++)
                cin>>list[i];
        }

        void Headerout() const
        {
            cout << left << setw(10) << "Ma TS" 
             << " | " << left << setw(25) << "Ho va Ten" 
             << " | " << left << setw(10) << "Ngay Sinh" 
             << " | " << right << setw(6) << "Toan" 
             << " | " << right << setw(6) << "Van" 
             << " | " << right << setw(6) << "Anh" 
             << " | " << right << setw(8) << "Tong" << "\n";
            cout << string(89, '-') << "\n";
        }

        void out() const
        {
            Headerout();
            for(int i = 1 ; i<=n ; i++)
                if(list[i].tong() >= 15)
                    cout<<list[i];
        }

        void out1()
        {
            Headerout();
            for(int i = 1 ; i<=n ; i++)
                cout<<list[i];
        }

        friend istream &operator>>(istream &in, cListCandidate& a)
        {
            a.inp();
            return in;
        }

        friend ostream &operator<<(ostream &ou, const cListCandidate& a)
        {
            a.out();
            return ou;
        } 

        void sort()
        {
            for(int i = 1 ; i <=n ; i++)
            {
                for(int j = i+1 ; j<=n; j++)
                {
                    if(list[i].tong() < list[j].tong())
                        swap(list[i], list[j]);
                }
            }
        }

        void highest()
        {
            sort();
            double best = list[1].tong();
            Headerout();
            for(int i = 1 ; i<=n ; i++)
            {
                if(list[i].tong() == best)
                    cout<<list[i]<<"\n";
            }
        }
};

void display_menu()
{
    cout << "------------------MENU------------------\n";
    cout << "1. Nhap vao danh sach thi sinh\n";
    cout << "2. In ra danh sach thi sinh co tong diem >= 15\n";
    cout << "3. In ra danh sach thi sinh co tong diem cao nhat\n";
    cout << "4. In ra danh sach thi sinh sau khi sap xep\n";
    cout << "0. Thoat\n";
    cout << "----------------------------------------\n";
}

void continue_prompt()
{
    cout << "Bạn có muốn tiếp tục không (Yes, No)?: ";
    string confirm;
    do
    {
        cin >> confirm;
        if (confirm != "Yes" && confirm != "No")
            cout << "Cảnh báo! Nhập sai, nhập lại: ";
    } while (confirm != "Yes" && confirm != "No");
    if (confirm == "No")
    {
        cout << "Thoát chương trình thành công!\n";
        exit(0);
    }
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main()
{
    cListCandidate ds;
    while(1)
    {
        display_menu();
        int key;
        cout<<"Nhap su lua chon cua ban: ";
        do
        {
            /* code */
            cin>>key;
            if(key < 0 || key > 4) cout<<"Lua chon sai, vui long nhap lai: ";
        } while (key <0 || key > 4);
        switch(key)
        {
            case 0: exit(0);
            case 1: cin>>ds; break;
            case 2: cout<<ds; break;
            case 3: ds.highest(); break;
            case 4:
            {
                ds.sort();
                ds.out1();
                break;
            }
        }
        continue_prompt();
    }
}