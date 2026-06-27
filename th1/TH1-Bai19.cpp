#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

vector<ll> Data[3];

ll cal(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

void display_menu()
{
    cout<<"================= MENU chương trình ================\n";
    cout<<"0. Thoát chương trình\n";
    cout<<"1. Nhập vào dữ liệu \n";
    cout<<"2. Hiển thị ước chung lớn nhất và bội chung nhỏ nhất của hai số\n";
    cout<<"====================================================\n";
}

void display_Data()
{
    cout<<"\t\t Dữ liệu hiện tại là: \n";
    for(int i = 1 ; i<=2 ; i++)
    {
        if(Data[i].size() == 0) {cout<<"Empty\n";}
        else
        {
            cout<<"Các số thứ "<<char('a' + i - 1)<<": ";
            for(int j = 0 ; j<Data[i].size() ; j++)
            {
                cout<<Data[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    cout<<"\n";
    
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

void Input_Data()
{
    display_Data();
    for(int i = 1 ; i<=2 ; i++)
    {
        ll x;
        if(Data[i].size() == 0)
        {
            cout<<"Dữ liêu bị trống, vui lòng nhập vào số thứ "<<char('a' + i - 1)<<": ";
            cin>>x;
            Data[i].push_back(x);
        }
        else
        {
            cout<<"Bạn có muốn cập nhật dữ liệu cho số thứ "<<char('a' + i - 1)<<" không (Yes, No)?: ";
            string confirm;
            do
            {
                cin>>confirm;
                if(confirm != "Yes" && confirm != "No") cout<<"Cảnh báo! Nhập sai, nhập lại: ";
            } while (confirm != "Yes" && confirm != "No");
            if(confirm == "Yes")
            {
                cout<<"Nhập vào số thứ "<<char('a' + i - 1)<<": ";
                cin>>x;
                Data[i].push_back(x);
            }
        }
    }
    confirm_prompt();
}

void Output_process()
{
    display_Data();
    if(Data[1].size() == 0 || Data[2].size() == 0)
    {
        system("clear");
        cout<<"Cảnh báo! Dữ liệu bị trống, vui lòng nhập lại dữ liệu!\n";
        return;
    }
    ll a = Data[1][Data[1].size() - 1];
    ll b = Data[2][Data[2].size() - 1];
    ll gcd = cal(a, b);
    ll lcm = (a / gcd) * b;
    cout<<"Ước chung lớn nhất của "<<a<<" và "<<b<<" là: "<<gcd<<"\n";
    cout<<"Bội chung nhỏ nhất của "<<a<<" và "<<b<<" là: "<<lcm<<"\n";
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
            if(key < 0 || key > 2) cout<<"Cảnh báo! Lựa chọn không hợp lệ với dữ liệu và chương trình, nhập lại: ";
        } while (key < 0 || key > 2);
        switch(key)
        {
            case 0: cout<<"Thoát chương trình thành công!\n"; exit(0);
            case 1: Input_Data(); break;
            case 2: Output_process(); break;
        }
    }
}