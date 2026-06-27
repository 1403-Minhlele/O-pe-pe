#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

struct Student{
    string name;
    double toan, van;
    double tbm = 0.0;
    void in()
    {
        cout<<"Nhập tên sinh viên: ";
        getline(cin, name);
        do{
            cout<<"Nhập điểm toán: ";
            cin>>toan;
        }while(toan < 1e-9);

        do{
            cout<<"Nhập điểm văn: ";
            cin>>van;
        }while(van < 1e-9);
    }

    void cal()
    {
        tbm = (toan + van)*1.0/2.0;
    }
};

int main()
{
    Student x;
    cout<<"Nhập thông tin học sinh: \n";
    x.in();
    cout<<"Điểm trung bình của "<<x.name<<" là: "; x.cal();
    cout<<fixed<<setprecision(2)<<x.tbm;
    return 0;
}