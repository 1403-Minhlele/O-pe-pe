#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

struct Date{
    int month, year;

    bool check_date(int m, int y)
    {
        return (m < 1 || m > 12 || y < 0);
    }
    
    void in()
    {
        do{
            cout<<"Nhập tháng năm theo định dạng mm yyyy: ";
            cin>>month>>year;
        }while(check_date(month, year));
    }
};

int main()
{
    Date x;
    x.in();
    cout<<"Tháng "<<x.month<<" năm "<<x.year<<" có  ";;
    int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(x.year % 400 == 0 || (x.year % 4 == 0 && x.year % 100 != 0)) date_of_month[2] = 29;
    cout<<date_of_month[x.month]<<" ngày";
    return 0;
}