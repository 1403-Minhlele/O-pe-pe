#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Pi 3.14159265358979323846
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

vector<double> Data[Nmax];

bool check(int key)
{
    if(key < 0 || key > 4) return true;
    if(Data[key-1].size() == 0 && (key == 2 || key == 3 || key == 4)) return true;
    return false;
}

bool check_second_chose(double a, double b)
{
    if(a < 1e-9 || b <1e-9)
    {
        cout<<"Cảnh báo! Chiều dài và chiều rộng không được âm, nhập lại: ";
        return true;
    }
    return false;
}

bool check_third_chose(double a, double b, double c)
{
    if(a < 1e-9 || b <1e-9 || c < 1e-9 || a + b <= c || a + c <= b || b + c <= a)
    {
        cout<<"Cảnh báo! Độ dài các cạnh không hợp lệ, nhập lại: ";
        return true;
    }
    return false;
}

void display_menu()
{
    cout<<"================= MENU chương trình ================\n";
    cout<<"0. Thoát chương trình\n";
    cout<<"1. Nhập vào dữ liệu mới\n";
    cout<<"2. Tính diện tích hình tròn\n";
    cout<<"3. Tính diện tích hình chữ nhật\n";
    cout<<"4. Tính diện tích hình tam giác\n";
    cout<<"====================================================\n";
}

void display_data()
{
    cout<<"\t\t Dữ liệu hiện tại là: \n";
    for(int i = 1 ; i<=3 ; i++)
    {
        if(Data[i].size() == 0) cout<<"Empty\n";
        else
        {
            for(auto it: Data[i]) cout<<it<<" ";
            cout<<"\n";
        }
    }
    cout<<"\n";
    cout<<"------- Các lựa chọn nhập vào dữ liệu cho chương trình -------\n";
    cout<<"\t 1. Nhập dữ liệu cho hình tròn\n";
    cout<<"\t 2. Nhập dữ liệu cho hình chữ nhật\n";
    cout<<"\t 3. Nhập dữ liệu cho hình tam giác\n";
    cout<<"--------------------------------------------------------------\n";
}

void Input_data()   
{
    display_data();
    cin.ignore();
    string sub_key;
    int idx;
    cout<<"Nhập lựa chọn của bạn (1, 2, 3, bạn có thể chọn nhiều lựa chọn): ";
    do
    {
        getline(cin, sub_key);
        if(sub_key.size() == 0) cout<<"Cảnh báo! Nhập sai, nhập lại: ";
    } while (sub_key.size() == 0);
    for(int i = 0 ; i < sub_key.size() ; i++)
    {
        idx = sub_key[i] - '0';
        if(Data[idx].size() != 0) Data[idx].clear();
        if(sub_key[i] == '1')
        {
            double r;
            cout<<"Nhập bán kính hình tròn: ";
            do
            {
                cin>>r;
                if(r < 0) cout<<"Cảnh báo! Bán kính không được âm, nhập lại: ";
            } while (r < 0 );
            Data[idx].push_back(r);
        }
        else if(sub_key[i] == '2')
        {
            double a, b;
            cout<<"Nhập chiều dài và chiều rộng hình chữ nhật: ";
            do
            {
                cin>>a>>b;
                if(check_second_chose(a, b)) cout<<"Cảnh báo! Chiều dài và chiều rộng không được âm, nhập lại: ";
            } while (check_second_chose(a, b));
            Data[idx].push_back(a);
            Data[idx].push_back(b);
        }
        else if(sub_key[i] == '3')
        {
            double a, b, c;
            cout<<"Nhập độ dài ba cạnh hình tam giác: ";
            do
            {
                cin>>a>>b>>c;
                if(check_third_chose(a, b, c))
                    cout<<"Cảnh báo! Độ dài các cạnh không hợp lệ, nhập lại: ";
            } while (check_third_chose(a, b, c));
            Data[idx].push_back(a);
            Data[idx].push_back(b);
            Data[idx].push_back(c);
        }
    }
}

void continue_prompt()
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

void Circle_area()
{
    cout<<"Diện tích hình tròn là: "<<fixed<<setprecision(2)<<Pi*Data[1][0]*Data[1][0]<<"\n";
    continue_prompt();
}

void Retangle_area()
{
    cout<<"Diện tích hình chữ nhật là: "<<fixed<<setprecision(2)<<Data[2][0]*Data[2][1]<<"\n";  
    continue_prompt();
}

void Triangle_area()
{
    double p = (Data[3][0] + Data[3][1] + Data[3][2])*1.0/2.0;
    double a = Data[3][0], b = Data[3][1], c = Data[3][2];
    double area = p*(p - a)*(p - b)*(p - c);
    cout<<"Diện tích hình tam giác là: "<<fixed<<setprecision(2)<<sqrt(area)<<"\n";
    continue_prompt();
}

int main()
{
    while(1)
    {
        int key;
        display_menu();
        cout<<"Nhập lựa chọn của bạn: ";
        do
        {
            cin>>key;
            cout<<"Bạn có chắc với lựa chọn của mình không(Yes, No)?: ";
            string confirm;
            do
            {
                cin>>confirm;
                if(confirm != "Yes" && confirm != "No") cout<<"Cảnh báo! Nhập sai, nhập lại: ";
            } while (confirm != "Yes" && confirm != "No");
            if(confirm == "No")
            {
                cout<<"Nhập lại lựa chọn của bạn: ";
                cin>>key;
            }
            
            if(check(key)) cout<<"Cảnh báo! Nhập sai hoặc lựa chọn không phù hợp với dữ liệu, nhập lại: ";
        }while(check(key));

        switch(key)
        {
            case 0 : cout<<"Thoát chương trình thành công!\n"; return 0;
            case 1 : {Input_data(); break;}
            case 2 : Circle_area(); break;
            case 3 : Retangle_area(); break;
            case 4 : Triangle_area(); break;
            default : break;
        }
    }
    return 0;
}