#include<bits/stdc++.h>
using namespace std;

double exp(double a, int b)
{
    if(b == 0) return 1.0;
    double tmp = exp(a, b/2);
    if(b%2 == 0) return tmp*tmp;
    else return tmp*tmp*a;
}

class cDathuc{
    private:
        int n;
        double *heso;
    public:
        cDathuc();
        cDathuc(int);
        cDathuc(const cDathuc& orther);
        static int cnt;
        ~cDathuc();
        void inp()
        {
            cout<<"Nhap bac cua da thuc: ";
            do
            {
                /* code */
                cin>>n;
                if(n < 0) cout<<"Bac da thuc khong am, vui long nhap lai: ";
            } while (n < 0);
            delete[] heso;
            heso = new double[n+1];
            for(int i = n; i>=0; i--)
            {
                cout<<"Nhap he so cua x^"<<i<<": ";
                cin>>heso[i];
            }
        }

        void out() const
        {
            bool free = true;
            for(int i = n ; i >= 0 ; i--)
            {
                if(heso[i] != 0)
                {
                    if(free)
                    {
                        if(heso[i] < 0)  cout<<" -";
                        free = false;
                    }
                    else
                    {
                        if(heso[i] < 0) cout<<" - ";
                        else cout<<" + ";
                    }
                    cout<<abs(heso[i]);
                    if(i > 1) cout<<"x^"<<i;
                    else if(i == 1) cout<<"x";

                }
            }
            if(free) cout<<"0";
            cout<<"\n";
        }

        friend istream &operator>>(istream& in, cDathuc& a)
        {
            cnt++;
            a.inp();
            return in;
        }

        friend ostream &operator<<(ostream& ou, const cDathuc& a)
        {
            a.out();
            return ou;
        }

        friend cDathuc operator+(const cDathuc& a, const cDathuc& b)
        {
            cDathuc tmp(max(a.n, b.n));
            for(int i = max(a.n, b.n ) ; i > min(a.n, b.n) ; i--)
            {
                if(a.n > b.n) tmp.heso[i] = a.heso[i];
                else tmp.heso[i] = b.heso[i];
            }
            for(int i = min(a.n, b.n) ; i>=0 ; i--)
                tmp.heso[i] = a.heso[i] + b.heso[i];

            return tmp;
        }

        friend cDathuc operator-(const cDathuc& a, const cDathuc& b)
        {
            cDathuc tmp(max(a.n, b.n));
            for(int i = max(a.n, b.n ) ; i > min(a.n, b.n) ; i--)
            {
                if(a.n > b.n) tmp.heso[i] = a.heso[i];
                else tmp.heso[i] = -1*b.heso[i];
            }
            for(int i = min(a.n, b.n) ; i>=0 ; i--)
                tmp.heso[i] = a.heso[i] - b.heso[i];

            return tmp;
        }

        cDathuc& operator=(const cDathuc& orther);

        void cal_x(double x)
        {
            double sum = 0;
            for(int i = n ; i>= 0 ; i--)
            {
                sum += 1.0*heso[i]*exp(x, i);
            }
            cout<<sum;
        }

};

int cDathuc::cnt = 0;

cDathuc::cDathuc(): n(0)
{
    heso = new double[1];
    heso[0] = 0;
}

cDathuc::cDathuc(int n): n(n)
{
    heso = new double[n+1];
    for(int i = 0; i <= n ; i++) heso[i] = 0;
}

cDathuc::cDathuc(const cDathuc& orther): n(orther.n)
{
    heso = new double[n+1];
    for(int i = n ; i>=0 ; i--) heso[i] = orther.heso[i];
}

cDathuc::~cDathuc()
{
    delete[] heso;
}

cDathuc& cDathuc::operator=(const cDathuc& orther)
{
    if(this != &orther)
    {
        delete[] heso;
        n = orther.n;
        heso = new double[n+1];
        for(int i = n ; i >= 0 ; i--) heso[i] = orther.heso[i];
    }
    return *this;
}

void display_menu()
{
    cout << "------------------MENU------------------\n";
    cout << "1. Nhap vao gia tri cua 2 da thuc\n";
    cout << "2. Xuat ra bieu thuc cua 2 da thuc\n";
    cout << "3. Cong 2 da thuc\n";
    cout << "4. Tru 2 da thuc\n";
    cout << "5. Tinh gia tri da thuc khi biet 1 so x\n";
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
}

int main()
{
    cDathuc a, b;
    while(1)
    {
        display_menu();
        int key;
        cout<<"Nhap su lua chon cua ban: ";
        do
        {
            /* code */
            cin>>key;
            if(key < 0 || key > 5) cout<<"Lua chon khong hop le, vui long chon lai: ";
        } while (key < 0 || key  > 5);
        switch(key)
        {
            case 0: exit(0);
            case 1:
            {
                cout<<"Nhap da thuc thu 1\n";
                cin>>a;
                cout<<"Nhap da thuc thu 2\n";
                cin>>b;
                break;
            }
            case 2:
            {
                cout<<"Da thuc thu 1: "<<a<<"\n"<<"Da thuc thu 2: "<<b<<"\n";
                break;
            }
            case 3:
            {
                cDathuc ans = a + b;
                cout<<"Da thuc ket qua la: \n";
                cout<<ans;
                break;
            }
            case 4:
            {
                cDathuc ans = a - b;
                cout<<"Da thuc ket qua la: \n";
                cout<<ans;
                break;
            }
            case 5:
            {
                int value;
                cout<<"Nhap gia tri ban muon tinh: "; cin>>value;
                cout<<"-------------  thong tin -------------\n";
                cout<<"Da thuc thu 1: "<<a<<"\n"<<"Da thuc thu 2: "<<b<<"\n";
                cout<<"Chon da thuc ban muon tinh gia tri(a, b)";
                char key;
                do{
                    cin>>key;
                    if(key != 'a' && key != 'b') cout<<"Nhap sai, vui long nhap lai: ";
                }while(key != 'a' && key != 'b');
                (key == 'a')? a.cal_x(value): b.cal_x(value);
                break;
            }
        }
        continue_prompt();
    }
}