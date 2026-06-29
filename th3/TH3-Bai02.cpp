#include <bits/stdc++.h>
using namespace std;

class DIEM2D
{
    private:
        double x, y;
        static int dem;

    public:
        DIEM2D(double x = 0, double y = 0) : x(x), y(y) { dem++; }
        void inp()
        {
            cout << "Nhap toa do diem: ";
            cin >> x >> y;
        }
        void out() const
        {
            cout << "Toa do diem la: ";
            cout << "(" << x << ", " << y << ")\n";
        }
        friend istream &operator>>(istream &in, DIEM2D &a)
        {
            a.inp();
            return in;
        }
        friend ostream &operator<<(ostream &ou, const DIEM2D &a)
        {
            a.out();
            return ou;
        }

        DIEM2D &operator+=(const DIEM2D tmp)
        {
            this->x += tmp.x;
            this->y += tmp.y;
            return *this;
        }

        friend int functionOfLine(DIEM2D apex1, DIEM2D apex2, DIEM2D testpoint) {
            double cross_product = (apex2.x - apex1.x) * (testpoint.y - apex1.y) - (apex2.y - apex1.y) * (testpoint.x - apex1.x);
            if (cross_product > 0) return 1;
            if (cross_product < 0) return -1;
            return 0;
        }

        friend double distane(DIEM2D d, DIEM2D d1)
        {
            return sqrt((d.x - d1.x)*(d.x - d1.x) + (d.y - d1.y)*(d.y - d1.y));
        }
};

class cDaGiac
{
private:
    DIEM2D* dagiac;
    int n;
    static int cnt;

public:
    cDaGiac();
    cDaGiac(int);
    ~cDaGiac();

    static int Get_cnt()
    {
        return cnt;
    }

    void inp()
    {
        cout << "Nhap so luong dinh cua da giac: ";
        do
        {
            cin >> n;
            if (n <= 2)
                cout << "So luong dinh khong hop le, vui long nhap lai: ";
        } while (n <= 2);
        
        delete[] dagiac;
        dagiac = new DIEM2D[n];
        
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap toa do dinh thu " << i + 1 << ": ";
            dagiac[i].inp();
        }
    }
    void out() const
    {
        cout << "Toa do cac dinh cua da giac la: \n";
        for (int i = 0; i < n; i++)
        {
            cout << "Dinh thu " << i + 1 << ": ";
            dagiac[i].out();
        }
    }

    friend istream &operator>>(istream &in, cDaGiac &a)
    {
        a.inp();
        return in;
    }

    friend ostream &operator<<(ostream &ou, const cDaGiac &a)
    {
        a.out();
        return ou;
    }

    void move_dagiac(double dis_x, double dis_y)
    {
        for (int i = 0; i < n; i++)
        {
            dagiac[i] += DIEM2D(dis_x, dis_y);
        }
    }
    bool check_dagiac()
    {
        int result = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1 && j != 0)
            {
                result = result + functionOfLine(dagiac[n - 1], dagiac[0], dagiac[j]);
            }
        }
        if (abs(result) != n - 2)
            return false;
        else
            result = 0;
            
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != i && j != i + 1)
                {
                    result = result + functionOfLine(dagiac[i], dagiac[i + 1], dagiac[j]);
                }
            }
            if (abs(result) != n - 2)
                return false;
            else
                result = 0;
        }
        return true;
    }
    void phanloai()
    {
        if(check_dagiac())
            cout << "Da giac loi\n";
        else
            cout << "Da giac lom\n";
    }

    void chuvi()
    {
        double ans = 0.0;
        for(int i = 0 ; i<n-1 ; i++)
        {
            ans += distane(dagiac[i+1], dagiac[i]);
        }
        ans += distane(dagiac[0], dagiac[n-1]);
        cout<<ans;
    }
};

int cDaGiac::cnt = 0;
int DIEM2D::dem = 0;

cDaGiac::cDaGiac(): n(3)
{
    cout<<"Khoi tao da giac mac dinh co 3 dinh\n";
    cnt++;
    dagiac = new DIEM2D[3];
    dagiac[0] = DIEM2D(0,0);
    dagiac[1] = DIEM2D(0,1);
    dagiac[2] = DIEM2D(1,0);
}

cDaGiac::~cDaGiac()
{
    cout<<"Goi ham huy da giac\n";
    delete[] dagiac;
}

int main()
{
    cDaGiac a;
    cout<<a;

    cin>>a;
    cout<<"Da giac moi sau khi nhap la";
    cout<<a;

    cout<<"Chu vi da giac la: ";
    a.chuvi();
    cout<<"\nDa giac tren la: ";
    a.phanloai();
    return 0;
}