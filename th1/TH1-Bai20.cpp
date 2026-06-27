#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

vector<ll> Data;

void display_menu()
{
    cout<<"================= MENU chương trình ================\n";
    cout<<"0. Thoát chương trình\n";
    cout<<"1. Kiểm tra số nguyên tố\n";
    cout<<"2. Kiểm tra số chính phương\n";
    cout<<"3. Kiểm tra số hoàn thiện\n";
    cout<<"4. Kiểm tra số đối xứng\n";
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

void choose_val(int &val)
{
    cout<<"Vui lòng chọn số bạn muốn kiểm tra\n";
    int sub_key;
    do
    {
        /* code */
        cin>>sub_key;
        if(sub_key < 0 || sub_key > Data.size()) cout<<"Nhập sai, nhập lại: ";
    } while (sub_key < 0 || sub_key > Data.size());
    val = Data[sub_key - 1];
}

bool prime(ll val)
{
    if(val <= 1) return 0;
    if(val == 2 || val == 3) return 1;
    for(int i = 2 ; i*i < val ; i++)
        if(val % i == 0) return 0;
    return 1;
}

bool Perfect_square(ll val)
{
    if(val < 0 ) return 0;
    ll square_val = sqrt(val);
    return (square_val * square_val == val);
}

bool Perfect_number(ll val)
{
    if(val < 0 ) return 0;
    ll  sum = 0;
    if(val == 6) return true;
    sum += 1;
    for(int i = 2 ; i*i <= val ; i++)
    {
        if(val % i == 0)
        {
            sum += i;
            if(i != val /i) sum += val/i;
        }
    }
    return (sum == val);
}

bool Palindrome(ll val)
{
    if (val < 0) return false;
    ll temp = val, reversed = 0;
    while (temp > 0) {
        reversed = reversed * 10 + (temp % 10);
        temp /= 10;
    }
    return (reversed == val);
}

void Process(int key)
{
    int val;
    if(Data.size() == 0)
    {
        cout<<"EMPTY!!!\n";
        cout<<"Cảnh báo, dữ liệu đầu vào còn trống, vui lòng nhập dữ liệu\n";
        cin>>val;
        Data.push_back(val);
    }
    else
    {
        cout<<"-------------------------------------------------\n";
        cout<<"Dữ liệu hiện có là: \n";
        for(int i = 0 ; i < Data.size() ; i++)
            cout<<i+1<<". "<<Data[i]<<"\n";
        cout<<"-------------------------------------------------\n";
        cout<<"===> Bạn có muốn nhập thêm dữ liệu không?(Yes, No)\n";
        string confirm;
        do
        {
            /* code */
            cin>>confirm;
            if(confirm != "Yes" && confirm != "No") 
                cout<<"Nhập sai định dạng, nhập lại: ";
        } while (confirm != "Yes" && confirm != "No");

        if(confirm == "Yes")
        {
            cout<<"Nhập số mới: ";
            cin>>val;
            Data.push_back(val);
        }
        else
            choose_val(val);
    }
    switch(key)
    {
        case 1:
        {
            if(prime(val)) cout<<"Số "<<val<<" là số nguyên tố!!!";
            else cout<<"Số "<<val<<" không là số nguyên tố!!!";
            cout<<"\n";
            break;
        }
        case 2:
        {
            if(Perfect_square(val)) cout<<"Số "<<val<<" là số chính phương!!!";
            else cout<<"Số "<<val<<" không là số chính phương!!!";
            cout<<"\n";
            break;
        }
        case 3:
        {
            if(Perfect_number(val)) cout<<"Số "<<val<<" là số hoàn thiện!!!";
            else cout<<"Số "<<val<<" không là số hoàn thiện!!!";
            cout<<"\n";
            break;
        }
        case 4:
        {
            if(Palindrome(val)) cout<<"Số "<<val<<" là số đối xứng!!!";
            else cout<<"Số "<<val<<" không là số đối xứng!!!";
            cout<<"\n";
            break;
        }
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
            /* code */
            cin>>key;
            if(key <0 || key > 4) cout<<"Nhập sai định dạng của chương trình, nhập lại: ";
        } while (key < 0 || key > 4);
        switch(key)
        {
            case 0: cout<<"Thoát chương trình thành công !!!!" ; exit(0);
            case 1: case 2: case 3: case 4: Process(key); break;
        }
    }
    return 0;
}
