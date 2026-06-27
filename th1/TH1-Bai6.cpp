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

Student a[100010];

bool cmp(Student A, Student B)
{
    return A.tbm < B.tbm;
}

int main()
{
    ll n;
    cout<<"Nhập số lượng sinh viên: \n";
    cin>>n;
    cin.ignore();  
    for(int i = 1 ; i<=n ;i++) {
        a[i].in(); 
        cin.ignore();
        a[i].cal();
    }

    sort(a+1, a+n+1, cmp);
    cout<<"Học sinh có điểm trung bình thấp nhất: "<<a[1].name<<"\n";
    cout<<"Học sinh có điểm trung bình cao nhất: "<<a[n].name<<"\n";

    return 0;
}