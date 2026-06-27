#include<bits/stdc++.h>
using namespace std;

class DIEM2D
{
private:
    double x, y;
    static int dem;

public:
    DIEM2D(double x = 0, double y = 0) : x(x), y(y){}

    void inp()
    {
        cin >> x >> y;
    }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getX() const { return x; }
    double getY() const { return y; }

    void out() const
    {
        cout << "(" << x << ", " << y << ")\n";
    }

    bool checking(DIEM2D p) const
    {
        return (abs(x - p.x) < 1e-9 && abs(y - p.y) < 1e-9);
    }

    void move_point(double dis_x, double dis_y)
    {
        x += dis_x;
        y += dis_y;
    }

    friend double distance(const DIEM2D& st, const DIEM2D& en)
    {
        double tmp = (st.x - en.x) * (st.x - en.x) + (st.y - en.y) * (st.y - en.y);
        tmp = sqrt(tmp);
        return tmp;
    }

    DIEM2D point_of_symmetry() const
    {
        return DIEM2D((x == 0) ? 0 : -x, (y == 0) ? 0 : -y);
    }

    static int get_Dem(){return dem; }

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

    friend bool operator==(const DIEM2D& a, const DIEM2D& b)
    {
        return (a.x == b.x) && (a.y == b.y);
    }
};

int DIEM2D::dem = 0;

class dthang
{
    private:
        DIEM2D A, B;
        static int cnt;
    public:
        dthang();
        dthang(DIEM2D a, DIEM2D b);
        ~dthang();

        void setA(const DIEM2D& a) { A = a; }
        void setB(const DIEM2D& b) { B = b; }
        DIEM2D getA() const { return A; }
        DIEM2D getB() const { return B; }

        static int get_cnt()
        {
            return cnt;
        }

        void inp()
        {
            cout<<"Nhap diem dau cua doan thang: "; cin>>A;
            cout<<"Nhap diem cuoi cua doan thang: "; cin>>B;
            while(A == B)
            {
                cout<<"Diem dau va diem cuoi khong duoc trung nhau, nhap lai \n";
                cout<<"Nhap diem dau cua doan thang: "; cin>>A;
                cout<<"Nhap diem cuoi cua doan thang: "; cin>>B;
            }
        }

        friend istream &operator>>(istream &in, dthang &a)
        {
            a.inp();
            return in;
        }

        void out() const
        {
            cout<<"Toa do diem dau: "<<A<<"\n";
            cout<<"Toa do diem cuoi: "<<B<<"\n";
        }

        friend ostream &operator<<(ostream &ou, const dthang& a)
        {
            a.out();
            return ou;
        }

        void di_chuyen(double dx, double dy)
        {
            A.move_point(dx, dy);
            B.move_point(dx, dy);
        }

        double chieu_dai() const
        {
            return distance(A, B);
        }
};

int dthang::cnt = 0;

dthang::dthang()
{
    A = DIEM2D(0,0);
    B = DIEM2D(0,1);
    cnt++;
}

dthang::dthang(DIEM2D a, DIEM2D b) : A(a), B(b)
{
    cnt++;
}

dthang::~dthang()
{
    cnt--;
}

int main()
{
    dthang A, B(DIEM2D(2, 3), DIEM2D(3, 4));
    cout<<"So doan thang da tao la: "<<dthang::get_cnt()<<"\n";
    
    cout<<"--- Nhap doan thang A ---\n";
    cin>>A;

    cout<<"Doan thang A vua nhap:\n"<<A;
    cout<<"Do dai doan thang A la: "<<A.chieu_dai()<<"\n";

    cout<<"--- Di chuyen doan thang A (dx=2, dy=3) ---\n";
    A.di_chuyen(2, 3);
    cout<<A;

    return 0;
}