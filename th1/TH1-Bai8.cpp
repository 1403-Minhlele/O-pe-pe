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

void cal_years(Date a)
{
    int cur_y = a.year;
    int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(cur_y % 400 == 0 || (cur_y % 4 == 0 && cur_y % 100 != 0)) date_of_month[2] = 29;

    cur_y -= 1;
    int tmp = cur_y/4 + cur_y/400 - cur_y/100;
    int num_day = cur_y*365 + tmp;
    
    for(int i = 1 ; i < a.month ; i++) num_day += date_of_month[i];
    num_day += a.day;
    num_day %= 7;
    string days[] = {"Chủ nhật", "Thứ 2", "Thứ 3", "Thứ 4", "Thứ 5", "Thứ 6", "Thứ 7"};
    cout<<"Ngày "<<a.day<<"/"<<a.month<<"/"<<a.year<<" là: "<<days[num_day];
}

int main()
{
    Date x;
    x.in();

    cal_years(x);
    return 0;
}