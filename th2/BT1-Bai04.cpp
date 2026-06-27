#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second 
#define ll long long 

class Time{
    private:
        int h, m, s;
    public:
        Time(int h = 0, int m = 0, int s = 0): h(h), m(m), s(s){}

        void inp()
        {
            cout<<"Nhập giờ phút giây(định dạng 24h\n";
            cout<<"Nhập giờ: ";
            do
            {
                /* code */
                cin>>h;
                if(h < 0 || h > 23) cout<<"Nhập sai định dạng giờ, nhập lại: ";
            } while (h < 0 || h > 23);
            cout<<"Nhập phút: ";
            do
            {
                /* code */
                cin>>m;
                if(m < 0 || m > 59) cout<<"Nhập sai định dạng phút, nhập lại: ";
            } while (m < 0 || m > 59);
            cout<<"Nhập giây: ";
            do
            {
                /* code */
                cin>>s;
                if(s < 0 || s > 59) cout<<"Nhập sai định dạng giây, nhập lại: ";
            } while (s < 0 || s > 59);
        }
        void out()
        {
            cout<<"Thời gian: "<<h<<" giờ "<<m<<" phút "<<s<<" giây\n";
        }

        int Get_gio();
        int Get_phut();
        int Get_giay();
        void Set(int h, int m, int s);


        void Update_time(int key);
};

int Time::Get_gio()
{
    return h;
}

int Time::Get_phut()
{
    return m;
}

int Time::Get_giay()
{
    return s;
}

void Time::Set(int h, int m, int s)
{
    this -> h = h;
    this -> m = m;
    this -> s = s;
}

void Time::Update_time(int key)
{
    switch(key)
    {
        case 1:
        {
            cout<<"Nhập khoảng thời gian bạn muốn giảm\n";
            Time tmp; tmp.inp();
            ll n_s = s - tmp.s, n_h, n_m;
            if (n_s < 0) {
                int borrow_m = (abs(n_s) + 59) / 60; 
                tmp.m += borrow_m;
                n_s += borrow_m * 60;
            }

            // Trừ phút
            n_m = m - tmp.m;
            if (n_m < 0) {
                int borrow_h = (abs(n_m) + 59) / 60;
                tmp.h += borrow_h;
                n_m += borrow_h * 60;
            }

            // Trừ giờ
            n_h = h - tmp.h;
            if (n_h < 0) {
                n_h = (n_h % 24 + 24) % 24;
            }
            Set(n_h, n_m, n_s);
            break;
        }
        case 2: 
        {
            cout<<"Nhập khoảng thời gian mà bạn muốn tăng\n";
            Time tmp; tmp.inp();
            int total_s = s + tmp.s;
            int carry_m = total_s / 60;
            int n_s = total_s % 60;

            int total_m = m + tmp.m + carry_m;
            int carry_h = total_m / 60;
            int n_m = total_m % 60;

            // 3. Tính tổng giờ (bao gồm cả phần dư từ phút) và xử lý vòng lặp 24h
            int n_h = (h + tmp.h + carry_h) % 24;

            // Cập nhật lại giá trị cho đối tượng hiện tại
            Set(n_h, n_m, n_s);
            break;
        }   
    }
}

int main()
{
    Time x, y;
    cout<<"Thời gian x khi mới thiết lập là: "; x.out();
    cout<<"Thời gian y khi mới thiết lập là: "; y.out();
    cout<<"\n";
    x.inp();
    cout<<"\nThời gian sau khi thiết lập là: "; x.out();

    cout<<"\nBạn muốn tăng hay giảm thời gian? (1: giảm, 2: tăng): ";
    int key; cin>>key;
    x.Update_time(key);
    cout<<"\nThời gian sau khi cập nhật là: "; x.out();
    cout<<"Giây của thời gian y là: "<<y.Get_giay()<<endl;
    
    return 0;
}