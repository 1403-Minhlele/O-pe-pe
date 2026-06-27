#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

string type_comp[] = {"keo", "bua", "bao"};

struct Users{
    string type;

    void inp()
    {
        cout<<"Nhập kéo, búa, bao : ";
        do{
            cin>>type;
            if(type != "keo" && type != "bua" && type != "bao") cout<<"Cảnh bảo người chơi nhập sai, nhập lại: "; 
        }while(type != "keo" && type != "bua" && type != "bao");
    }
};

struct Computer{
    int n;

    void inp()
    {
        n = rand()%3;
        cout<<"Lựa chọn của máy: "<<type_comp[n]<<"\n";
    }
};

void cmp(Users a, Computer b)
{
    string user_type = a.type;
    string comp_type = type_comp[b.n];

    if(user_type == comp_type) cout<<"Hòa \n";
    else
    {
        if(user_type == "keo" && comp_type == "bua" || user_type == "bua" && comp_type == "bao" || user_type == "bao" && comp_type == "keo")
            cout<<"Máy thắng \n";
        else
            cout<<"Người chơi thắng \n";    
    }
}

int main()
{
    srand(time(0));
    while(1)
    {
        int key;
        cout<<"Lựa chọn của bạn (1: chơi, 0: thoát): ";
        do{
            cin>>key;
            if(key != 0 && key != 1) cout<<"Cảnh báo người chơi nhập sai trạng thái, nhập lại: ";
        }while(key != 0 && key != 1);
        if(key == 0)
        {
            cout<<"Kết thúc trò chơi\n";
            return 0;
        }
        Users a;
        a.inp();
        Computer b;
        b.inp();
        cmp(a, b);
    }

    return 0;

}