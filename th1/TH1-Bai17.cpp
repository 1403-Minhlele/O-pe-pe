#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

vector<double> Data[4];
bool check(int key)
{
    if(key < 0 || key > 5) return true;
    if((Data[1].size() == 0 || Data[2].size() == 0) && (key == 2 || key == 3 || key == 4 || key == 5)) return true;
    return false;
}

void display_menu()
{
    cout<<"================= MENU chương trình ================\n";
    cout<<"0. Thoát chương trình\n";
    cout<<"1. Nhập vào(Sửa đổi) dữ liệu\n";
    cout<<"2. Thực hiện phép +\n";
    cout<<"3. Thực hiện phép -\n";
    cout<<"4. Thực hiện phép x\n";
    cout<<"5. Thực hiện phép :\n";
    cout<<"====================================================\n";
}

void display_data()
{
    int cnt_empty = 0;
    cout<<"\t\t Dữ liệu hiện tại là: \n";
    for(int i = 1 ; i<=2 ; i++)
    {
        if(Data[i].size() == 0) {cout<<"Empty\n"; cnt_empty++;}
        else
        {
            cout<<"Số thứ "<<i<<": ";
            for(int j = 0 ; j<Data[i].size() ; j++)
            {
                cout<<Data[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    cout<<"\n";
    if(cnt_empty == 2) cout<<"Warning! Dữ liệu hiện tại đang trống, vui lòng nhập dữ liệu để chương trình không báo lỗi\n";
}

void display_edit_menu()
{
    system("clear");
    cout<<"================= MENU nhập dữ liệu ================\n";
    display_data();
    cout<<"==> \t1. Nhập vào(Sửa đổi) dữ liệu cho số thứ nhất\n";
    cout<<"==> \t2. Nhập vào(Sửa đổi) dữ liệu cho số thứ hai\n";
    cout<<"==> \t3. Nhập vào(Sửa đổi) dữ liệu cho cả 2 số\n";
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

void Input_data()
{
    int sub_key;
    cout<<"Nhập lựa chọn của bạn (1, 2, 3): ";
    do
    {
        /* code */
        cin>>sub_key;
        if(sub_key < 0 || sub_key > 3) cout<<"Cảnh báo! Nhập sai, nhập lại: ";
    } while (sub_key < 0 || sub_key > 3);
    
    if(Data[sub_key].size() != 0) Data[sub_key].clear();
    if(sub_key == 1)
    {
        double val;
        cout<<"Nhập vào số thứ nhất: ";
        cin>>val;
        Data[1].push_back(val);
    }
    else if(sub_key == 2)
    {
        double val;
        cout<<"Nhập vào số thứ hai: ";
        cin>>val;
        Data[2].push_back(val);
    }
    else if(sub_key == 3)
    {

        double a, b;
        cout<<"Nhập vào số thứ nhất: ";
        cin>>a;
        cout<<"Nhập vào số thứ hai: ";
        cin>>b;
        Data[1].clear();
        Data[2].clear();
        Data[1].push_back(a);
        Data[2].push_back(b);
    }
    system("clear");
}

void Addition()
{
    cout<<"Kết quả của phép cộng là: "<<Data[1][0] + Data[2][0]<<"\n";
    confirm_prompt();
}

void Subtraction()
{
    cout<<"Kết quả của phép trừ là: "<<Data[1][0] - Data[2][0]<<"\n";
    confirm_prompt();
}

void Multiplication()
{
    cout<<"Kết quả của phép nhân là: "<<Data[1][0] * Data[2][0]<<"\n";
    confirm_prompt();
}

void Division()
{
    if(abs(Data[2][0]) < 1e-9)
    {
        cout<<"Cảnh báo! Phép chia không hợp lệ do mẫu số bằng 0, vui lòng nhập lại dữ liệu!\n";
        confirm_prompt();
        return;
    }
    cout<<"Kết quả của phép chia là: "<<fixed<<setprecision(3)<<Data[1][0] / Data[2][0]<<"\n";
    confirm_prompt();
}


int main()
{
    while(1)
    {
        display_menu();
        display_data();
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
            case 1: Input_data(); break;
            case 2: Addition(); break;
            case 3: Subtraction(); break;
            case 4: Multiplication(); break;
            case 5: Division(); break;
            default: break;
        }
        
    }
    return 0;
}

