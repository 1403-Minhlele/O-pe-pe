#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

void display_menu()
{
    cout<<"================= MENU chương trình ================\n";
    cout<<"0. Thoát chương trình\n";
    cout<<"1. Nhập vào dữ liệu mới\n";
    cout<<"2. Kiểm tra năm nhuận\n";
    cout<<"3. Tính ngày tiếp theo\n";
    cout<<"4. Tính ngày trước đó\n";
    cout<<"5. Kiểm tra thứ\n";
    cout<<"====================================================\n";
}

void confirm_prompt()
{
    cout<<"Bạn có muốn tiếp tục không (Yes, No)?: ";
    string confirm;
    do
    {
        cin>>confirm;
        if(confirm != "Yes" && confirm != "No") cout<<"Cảnh báo! Nhập sai, nhập lại: ";
    } while (confirm != "Yes" && confirm != "No");
    if(confirm == "No")
    {
        cout<<"Thoát chương trình thành công!\n";
        exit(0);
    }
    system("clear");
}

class Date
{
    private:
        int d, m, y;
        string day, month, year;
    public:
        void inp();
        void set()
        {
            if(d < 10) day = "0" + to_string(d);
            else day = to_string(d);
            if(m < 10) month = "0" + to_string(m);
            else month = to_string(m);
            year = to_string(y);
        }
        void out();
        void is_nhuan(Date p);
        void change_date(int key, Date &val);
        void Days();
        pair<int, pair<int,int>> get();
};

bool check_date(int d, int m, int y)
{
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0) return true;
    int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) date_of_month[2] = 29;
    if(d > date_of_month[m]) return true;
    return false;
}

void Date::inp()
{
    do{
        cout<<"Nhập ngày tháng năm theo định dạng dd mm yyyy: ";
        cin>>d>>m>>y;
    }while(check_date(d, m, y));
}

void Date::out()
{
    cout<<day<<"/"<<month<<"/"<<year;
    cout<<"\n";
}

pair<int, pair<int,int>> Date::get()
{
    pair<int, pair<int,int>> tmp;
    tmp.fi = d;
    tmp.se.fi = m;
    tmp.se.se = y;
    return tmp;
}

void Date::is_nhuan(Date p)
{
    p.set();
    p.out();
    if(p.y % 400 == 0 || (p.y % 4 == 0 && p.y % 100 != 0))
    {
        cout<<" là một năm nhuận";
    }
    else
        cout<<" không là năm nhuận";
    cout<<"\n";
}

pair<int, pair<int,int>> op1(Date val)
{
    pair<int, pair<int,int>> tmp = val.get();
    int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(tmp.se.se % 400 == 0 || (tmp.se.se % 4 == 0 && tmp.se.se % 100 != 0)) date_of_month[2] = 29;
    tmp.fi++;
    if(tmp.fi > date_of_month[tmp.se.fi]) {
        tmp.fi = tmp.fi%date_of_month[tmp.se.fi];
        tmp.se.fi++;
        if(tmp.se.fi > 12){
            tmp.se.fi = 1;
            tmp.se.se++;
        }
    }
    return tmp;
}

pair<int, pair<int,int>> op2(Date val)
{
    pair<int, pair<int,int>> tmp = val.get();
    int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(tmp.se.se % 400 == 0 || (tmp.se.se % 4 == 0 && tmp.se.se % 100 != 0)) date_of_month[2] = 29;
    if(tmp.fi == 1)
    {
        if(tmp.se.fi == 1)
        {
            tmp.fi = 31;
            tmp.se.fi = 12;
            tmp.se.se--;
        }
        else
        {
            tmp.se.fi--;
            tmp.fi = date_of_month[tmp.se.fi];
        }
    }
    else 
        tmp.fi--;
    return tmp;
}

void Date::change_date(int key, Date &val)
{
    switch (key)
    {
        case 1:
        {
            pair<int, pair<int,int>> tmp = op1(val);
            val.d = tmp.fi;
            val.m = tmp.se.fi;
            val.y = tmp.se.se;
            break;
        }
        case 2:
        {
            pair<int, pair<int,int>> tmp = op2(val);
            val.d = tmp.fi;
            val.m = tmp.se.fi;
            val.y = tmp.se.se;
            break;
        }
    }
}

void Date::Days()
{
    int cur_y = y;
    int date_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(cur_y % 400 == 0 || (cur_y % 4 == 0 && cur_y % 100 != 0)) date_of_month[2] = 29;

    cur_y -= 1;
    int tmp = cur_y/4 + cur_y/400 - cur_y/100;
    int num_day = cur_y*365 + tmp;
    
    for(int i = 1 ; i < m ; i++) num_day += date_of_month[i];
    num_day += d;
    num_day %= 7;
    string days[] = {"Chủ nhật", "Thứ 2", "Thứ 3", "Thứ 4", "Thứ 5", "Thứ 6", "Thứ 7"};

    set();
    out();
    cout<<"-> Là "<<days[num_day];
    cout<<"\n";
} 

int main()
{
    Date x, y;
    while(1)
    {
        display_menu();
        int key;
        cout<<"Nhập sự lựa chọn của bạn: ";
        do
        {
            cin>>key;

            if(key < 0 || key > 5) cout<<"Cảnh báo! Lựa chọn không hợp lệ với dữ liệu và chương trình, nhập lại: ";
        } while (key < 0 || key > 5);
        switch (key)
        {
            case 0: exit(0);
            case 1:
            {
                x.inp(); x.set();
                break;
            }
            case 2: x.is_nhuan(x); break;
            case 3:
            {
                x.change_date(1, x);
                x.set(); x.out();
                break;
            }
            case 4:
            {
                x.change_date(2, x);
                x.set(); x.out();
                break;
            }
            case 5:
            {
                x.Days();
                break;
            }
        }
        confirm_prompt();
    }
    return 0;
}