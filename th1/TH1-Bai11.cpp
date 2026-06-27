#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

const ll Nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 10;

struct Student{
    double chuan, mon1, mon2, mon3;
    double bonus = 0;
    string located, obj;

    bool check(int chuan, int m1, int m2, int m3, string loc, string o)
    {
        if(m1 < 1e-9 || m2 < 1e-9 || m3 < 1e-9 || chuan < 1e-9) return true;
        if(loc != "A" && loc != "B" && loc != "C") return true;
        if(o != "1" && o != "2" && o != "3") return true;
        return false;
    }

    void inp()
    {
        do{
            cout<<"Nhập điểm chuẩn và 3 môn thi: ";
            cin>>chuan>>mon1>>mon2>>mon3;
            cout<<"Nhập mã khu vực(A, B, C) và mã đối tượng(1, 2, 3): ";
            cin>>located>>obj;
        }while(check(chuan, mon1, mon2, mon3, located, obj));

    }

    void cal_bonus()
    {
        if(located == "A") bonus += 1.5;
        else if(located == "B") bonus += 1;
        else if(located == "C") bonus += 0.5;

        if(obj == "1") bonus += 1.5;
        else if(obj == "2") bonus += 1;
        else if(obj == "3") bonus += 0.5;
    }
};

int main()
{
    Student x;
    x.inp();
    x.cal_bonus();
    cout<<"Kết quả xét tuyển: ";
    cout<< (x.chuan <= x.mon1 + x.mon2 + x.mon3 + x.bonus ? "Trúng tuyển\n" : "Không trúng tuyển\n");
    return 0;
}