#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

class DIEM2D
{
private:
    double x, y;
    static int dem;

public:
    DIEM2D(double x = 0, double y = 0) : x(x), y(y)
    {
        dem++;
        cout << "Khoi tao doi tuong DIEM2D thu " << dem << "\n";
    }

    void inp()
    {
        cin >> x >> y;
    }

    int Get_X()
    {
        return x;
    }

    int Get_Y()
    {
        return y;
    }

    void out()
    {
        cout << "(" << x << ", " << y << ")\n";
    }

    bool checking(DIEM2D p)
    {
        return (abs(x - p.x) < 1e-9 && abs(y - p.y) < 1e-9);
    }

    void move_point(double dis_x, double dis_y)
    {
        x += dis_x;
        y += dis_y;
    }

    double distance(DIEM2D p)
    {
        double tmp = (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
        tmp = sqrt(tmp);
        return tmp;
    }

    DIEM2D point_of_symmetry()
    {
        return DIEM2D((x == 0) ? 0 : -x, (y == 0) ? 0 : -y);
    }

    static int get_Dem()
    {
        return dem;
    }

    friend istream &operator>>(istream &in, DIEM2D &a)
    {
        in >> a.x >> a.y;
        return in;
    }

    friend ostream &operator<<(ostream &out, const DIEM2D &a)
    {
        out << "(" << a.x << ", " << a.y << ")";
        return out;
    }
};

class TamGiac
{
private:
    DIEM2D a, b, c;
    static int cnt;

public:
    TamGiac(DIEM2D pA = DIEM2D(0, 0), DIEM2D pB = DIEM2D(0, 1), DIEM2D pC = DIEM2D(1, 0)) : a(pA), b(pB), c(pC)
    {
        cnt++;
        cout << "Khoi tao doi tuong TamGiac thu " << cnt << "\n";
    }

    static int get_Cnt()
    {
        return cnt;
    }

    friend istream &operator>>(istream &in, TamGiac &t)
    {
        cout << "Nhap toa do diem A: ";
        in >> t.a;
        cout << "Nhap toa do diem B: ";
        in >> t.b;
        cout << "Nhap toa do diem C: ";
        in >> t.c;
        return in;
    }

    friend ostream &operator<<(ostream &out, const TamGiac &t)
    {
        out << "Toa do diem A la: " << t.a << "\n";
        out << "Toa do diem B la: " << t.b << "\n";
        out << "Toa do diem C la: " << t.c << "\n";
        return out;
    }

    int check_tri()
    {
        double A, B, C;
        A = a.distance(b);
        B = b.distance(c);
        C = a.distance(c);
        if (A + B <= C || B + C <= A || A + C <= B)
            return 0;
        else
        {
            if (abs(A - B) < 1e-9 && abs(B - C) < 1e-9 && abs(A - C) < 1e-9)
                return 1;
            else if (abs(A - B) < 1e-9 || abs(B - C) < 1e-9 || abs(A - C) < 1e-9)
            {
                if (abs(A * A + B * B - C * C) < 1e-9 || abs(A * A + C * C - B * B) < 1e-9 || abs(B * B + C * C - A * A) < 1e-9)
                    return 2;
                else
                    return 3;
            }
            else
            {
                if (abs(A * A + B * B - C * C) < 1e-9 || abs(A * A + C * C - B * B) < 1e-9 || abs(B * B + C * C - A * A) < 1e-9)
                    return 4;
                else
                    return 5;
            }
        }
    }

    double Perimeter();
    double Area();
    void move_triangle(double dis_x, double dis_y)
    {
        a.move_point(dis_x, dis_y);
        b.move_point(dis_x, dis_y);
        c.move_point(dis_x, dis_y);
    }
    void classify();
    friend void info_ds(vector<TamGiac> ds);
};

int DIEM2D::dem = 0;
int TamGiac::cnt = 0;

double TamGiac::Perimeter()
{
    double A, B, C;
    A = a.distance(b);
    B = b.distance(c);
    C = a.distance(c);
    return A + B + C;
}

double TamGiac::Area()
{
    double p = Perimeter();
    p /= 2.0;
    double A, B, C;
    A = a.distance(b);
    B = b.distance(c);
    C = a.distance(c);
    double area = p * (p - A) * (p - B) * (p - C);
    area = sqrt(area);
    return area;
}

void TamGiac::classify()
{
    int key = check_tri();
    switch (key)
    {
    case 0:
        cout << "Khong la tam giac";
        break;
    case 1:
        cout << "La tam giac deu";
        break;
    case 2:
        cout << "La tam giac vuong can";
        break;
    case 3:
        cout << "La tam giac can";
        break;
    case 4:
        cout << "La tam giac vuong";
        break;
    case 5:
        cout << "La tam giac thuong";
        break;
    }
    cout << "\n";
}

void display_menu()
{
    cout << "------------------MENU------------------\n";
    cout << "1. Nhap toa do 3 diem A, B, C trong tam giac\n";
    cout << "2. Xuat toa do 3 diem A, B, C trong tam giac\n";
    cout << "3. Di chuyen tam giac\n";
    cout << "4. Phan loai tam giac\n";
    cout << "5. Tinh chu vi va dien tich tam giac\n";
    cout << "6. So luong tam giac da nhap\n";
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

void info_ds(vector<TamGiac> ds)
{
    if (ds.empty())
        cout << "Danh sach tam giac rong!\n";
    else
    {
        for (int i = 0; i < ds.size(); i++)
        {
            cout << "Thong tin tam giac thu " << i + 1 << ":\n";
            cout << ds[i];
        }
    }
}

int main()
{
    vector<TamGiac> ds;
    while (1)
    {
        display_menu();
        int key;
        cout << "Nhap lua chon: ";
        do
        {
            cin >> key;
            if (key < 0 || key > 6)
                cout << "Lua chon khong hop le, vui long nhap lai: ";
        } while (key < 0 || key > 6);
        switch (key)
        {
            case 0:
                exit(0);
            case 1:
            {
                TamGiac t;
                cin >> t;
                ds.push_back(t);
                break;
            }
            case 2:
            {
                info_ds(ds);
                break;
            }
            case 3:
            {
                if (ds.empty())
                {
                    cout << "Danh sach tam giac rong!, Yeu cau nhap tam giac!\n";
                    break;
                }
                else
                {
                    for (int i = 0; i < ds.size(); i++)
                    {
                        cout << "Thong tin tam giac thu " << i + 1 << ":\n";
                        cout << ds[i];
                    }
                }
                cout << "Chon tam giac can di chuyen: ";
                int idx;
                do
                {
                    cin >> idx;
                    if (idx < 1 || idx > ds.size())
                        cout << "Lua chon khong hop le, vui long nhap lai: ";
                } while (idx < 1 || idx > ds.size());
                cout << "Nhap khoang cach di chuyen theo x va y: ";
                double dis_x, dis_y;
                cin >> dis_x >> dis_y;
                ds[idx - 1].move_triangle(dis_x, dis_y);
                break;
            }
            case 4:
            {
                info_ds(ds);
                cout << "Chon tam giac can phan loai: ";
                int idx;
                do
                {
                    cin >> idx;
                    if (idx < 1 || idx > ds.size())
                        cout << "Lua chon khong hop le, vui long nhap lai: ";
                } while (idx < 1 || idx > ds.size());
                ds[idx - 1].classify();
                break;
            }
            case 5:
            {
                info_ds(ds);
                cout << "Chon tam giac can tinh: ";
                int idx;
                do
                {
                    cin >> idx;
                    if (idx < 1 || idx > ds.size())
                        cout << "Lua chon khong hop le, vui long nhap lai: ";
                } while (idx < 1 || idx > ds.size());
                int test = ds[idx - 1].check_tri();
                if (test == 0)
                    cout << "Khong la tam giac, khong the tinh chu vi va dien tich!\n";
                else
                {
                    cout << "Chu vi tam giac la: " << fixed << setprecision(2) << ds[idx - 1].Perimeter() << "\n";
                    cout << "Dien tich tam giac la: " << fixed << setprecision(2) << ds[idx - 1].Area() << "\n";
                }
                break;
            }
            case 6:
            {
                cout << "So luong tam giac da nhap la: " << ds.size() << "\n";
                break;
            }
        }
        continue_prompt();
    }
    return 0;
}