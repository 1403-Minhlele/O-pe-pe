#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long

class Bangcuuchuong{
    private:
        int m, n;
    public:
        Bangcuuchuong(int m = 2, int n = 9): m(m), n(n){}

        void inp()
        {
            do
            {
                cout<<"Nhap m, n tu 2 den 9\n";
                cin>>m>>n;
            } while (m < 0 || m > 9 || n < 0 || n > 9);
        }

        void get_m()
        {
            
            do
            {
                /* code */
                cout<<"Nhap m tu 2 den 9\n";
                cin>>m;
            } while (m <0 || m > 9);
            for(int i = 1; i <= 10; i++)
            {
                cout<<m<<" x "<<i<<" = "<<m*i<<"\n";
            }
        }

        void get_m_n()
        {
            do
            {
                /* code */
                cout<<"Nhap m, n tu 2 den 9\n";
                cin>>m>>n;
            } while (m < 0 || m > 9 || n < 0 || n > 9);
            if(m < n ){
                for(int i = 1; i <= 10; i++)
                {
                    for(int j = m; j <= n; j++)
                    {
                        cout<<setw(2)<<j<<" x "<<setw(2)<<i<<" = "<<setw(3)<<i*j<<setw(2)<<"  ";
                    }
                    cout<<"\n";
                }
            }   
            else
            {
                for(int j = 1; j <= 10; j++)
                {
                    for(int i = m; i >= n; i--)
                    {
                        cout<<setw(2)<<i<<" x "<<setw(2)<<j<<" = "<<setw(3)<<i*j<<setw(2)<<"  ";
                    }
                    cout<<"\n";
                }
            }
        }
        void out()
        {
            for(int i = 1; i <= 10; i++)
            {
                for(int j = 1 ; j <= 10 ; j++)
                {
                    cout<<setw(3)<<i*j<<setw(2)<<"  ";
                }
                cout<<"\n";
            }
        }
};

int main()
{
    Bangcuuchuong x;
    x.get_m();
    cout<<"\n";
    x.get_m_n();
    cout<<"\n";
    x.out();
    return 0;
}