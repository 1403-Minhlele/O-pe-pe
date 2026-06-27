#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

priority_queue<int, vector<int>, greater<int>> top_secret;

struct User{
    int n;
    void inp()
    {
        cout<<"Nhập số bạn chọn (số nguyên dương < 1234566): ";
        do{
            cin>>n;
            if(n < 0 || n >= 1234566) cout<<"Cảnh báo người chơi nhập sai, nhập lại: ";
        }while(n < 0 || n >= 1234566);
    }

    void inp_game()
    {
        cout<<"Nhập Lựa chọn mới của bạn (số nguyên dương < 1234566): ";
        do{
            cin>>n;
            if(n < 0 || n >= 1234566) cout<<"Cảnh báo người chơi nhập sai, nhập lại: ";
        }while(n < 0 || n >= 1234566);
    }
};

struct Computer{
    int n;
    void inp()
    {
        n = rand()%1234567;
    }
};

bool cmp(User a, Computer b, int &cnt)
{
    cnt++;
    if(a.n == b.n)
    {
        cout<<"Chúc mừng bạn đã thắng! \n";
        cout<<"Số lần bạn đoán là: "<<cnt<<"\n";
        return false;
    }
    else
    {
        if(a.n < b.n) cout<<"Số bạn chọn nhỏ hơn số của máy, thử lại! \n";
        else cout<<"Số bạn chọn lớn hơn số của máy, thử lại! \n";
        return true;
    }
}

int main()
{
    srand(time(0));
    while(1)
    {
        int key;
        cout<<"--------------------------Lựa chọn của bạn (1: chơi, 0: thoát)--------------------------\n";
        do{
            cin>>key;
            if(key != 0 && key != 1) cout<<"Cảnh báo người chơi nhập sai trạng thái, nhập lại: ";
        }while(key != 0 && key != 1);
        if(key == 0)
        {
            cout<<"-------------------------Kết thúc trò chơi-----------------------------\n";
            return 0;
        }
        User a;
        Computer b;
        a.inp();
        b.inp();
        int cnt = 0;
        while(cmp(a, b, cnt))
        {
            a.inp_game();
        }
        if(top_secret.empty())
        {
            cout<<"Kỹ lục mới! \n";
            top_secret.push(cnt);
        }
        else
        {
            if(cnt > top_secret.top())
            {
                cout<<"Còn non lắm con gà, cãi thiện kỹ năng đoán số đê! \n";
            }
            else
            {
                cout<<"Ghê vậy ghê vậy, bạn đã phá kỹ lục! \n";
                top_secret.push(cnt);
            }
        }
    }
}