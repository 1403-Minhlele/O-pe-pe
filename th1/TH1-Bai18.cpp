#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

bool check(int key)
{
    if(key < 0 || key > 4) return true;
    return false;
}

bool check_1(int n)
{
    if(n < 1 || n > 10) return true;
    return false;
}

bool check_2(int m, int n)
{
    if((m >= n) || check_1(m) || check_1(n)) return true;
    return false;
}

void display_menu()
{
    cout<<"================= MENU chương trình ================\n";
    cout<<"0. Thoát chương trình\n";
    cout<<"1. In bảng cửu chương thứ n\n";
    cout<<"2. In bảng cửu chương từ m đến n\n";
    cout<<"3. In bảng cửu chương tổng hợp\n";
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

void Option1()
{
    int n;
    cout<<"Nhập vào số n: ";
    do
    {
        /* code */
        cin>>n;
        if(check_1(n)) cout<<"Cảnh báo! Nhập sai điều kiện 1 <= n <= 10, nhập lại: ";
    } while (check_1(n));
    
    cout<<"Bảng cửu chương thứ "<<n<<": \n";
    for(int i = 1 ; i<=10 ; i++)
    {
        cout<<n<<" x "<<i<<" = "<<n*i<<"\n";
    }
    confirm_prompt();
}

void Option2()
{
    int m, n;
    cout<<"Nhập vào số m và n (m < n): ";
    do
    {
        cin>>m>>n;
        if(check_2(m, n)) cout<<"Cảnh báo! Nhập sai điều kiện m < n, nhập lại: ";
    } while (check_2(m, n));
    
    cout<<"Bảng cửu chương từ "<<m<<" đến "<<n<<": \n";
    for(int i = m ; i<=n ; i++)
    {
        cout<<"Bảng cửu chương thứ "<<i<<": \n";
        for(int j = 1 ; j<=10 ; j++)
        {
            cout<<i<<" x "<<j<<" = "<<i*j<<"\n";
        }
        cout<<"\n";
    }
    confirm_prompt();
}

void Option3()
{
    cout<<"Bảng cửu chương tổng hợp từ 1 đến 10: \n";
    for(int i = 1 ; i<=10 ; i++)
    {
        for(int j = 1 ; j<=10 ; j++)
        {
            cout<<i<<" x "<<j<<" = "<<i*j<<"\n";
        }
        cout<<"\n";
    }
    confirm_prompt();
}

int main()
{
    while(1)
    {
        display_menu();
        int key;
        cout<<"Nhập sự lựa chọn của bạn: ";
        do
        {
            cin>>key;

            if(check(key)) cout<<"Cảnh báo! Lựa chọn không hợp lệ với dữ liệu và chương trình, nhập lại: ";
        } while (check(key));
        switch(key)
        {
            case 0: cout<<"Thoát chương trình thành công!\n"; exit(0);
            case 1: Option1(); break;
            case 2: Option2(); break;
            case 3: Option3(); break;
            default: break;
        }
        
    }
    return 0;
}

