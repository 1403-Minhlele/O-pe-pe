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
    int day, month, year;

    bool check_date(int d, int m, int y)
    {
        if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0) return true;
        int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) date_of_month[2] = 29;
        if(d > date_of_month[m]) return true;
        return false;
    }
    
    void in()
    {
        do{
            cout<<"Nhập ngày tháng năm theo định dạng dd mm yyyy: ";
            cin>>day>>month>>year;
        }while(check_date(day, month, year));
    }
};

void next_day(int &d, int &m, int &y)
{
    int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) date_of_month[2] = 29;
    d++;
    if(d > date_of_month[m]) {
        d = d%date_of_month[m];
        m++;
        if(m > 12){
            m = 1;
            y++;
        }
    }
}

void tranform_date(int d, int m, int y)
{
    string day, month, year;
    if(d < 10) day = "0" + to_string(d);
    else day = to_string(d);
    if(m < 10) month = "0" + to_string(m);
    else month = to_string(m);
    year = to_string(y);
    cout<<"Ngày kế tiếp là: "<<day<<"/"<<month<<"/"<<year;
}

int main()
{
    Date x;
    x.in();
    next_day(x.day, x.month, x.year);
    tranform_date(x.day, x.month, x.year);
    return 0;
}