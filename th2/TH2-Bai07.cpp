#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first 
#define se second 
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

class Vehicle{
    private:
        string name, type, val, capa, taxx;
        ll value, capacity, tax;
    public:
        Vehicle(string n = "", string t = "", ll v = 0, ll c = 0, ll ta = 0)
            : name(n), type(t), value(v), capacity(c), tax(ta){}
        void set()
        {
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            transform(type.begin(), type.end(), type.begin(), ::tolower);
        }
        void inp()
        {
            cout<<"Nhập tên chủ xe: "; getline(cin>>ws, name);
            cout<<"Nhập loại xe: "; getline(cin>>ws, type);
            cout<<"Nhập giá trị của chiếc xe: "; 
            do
            {
                cin>>value;
                if(value < 0) cout<<"Nhập lại: ";
            } while (value < 0);
            cout<<"Nhập dung tích của xe: ";
            do
            {
                cin>>capacity;
                if(capacity < 0) cout<<"Nhập lại: ";
            } while (capacity < 0);
        }
        void cal_tax()
        {
            if(capacity < 100)
                tax = value/100;
            else if(100 <= capacity && capacity <= 200)
                tax = value/100*3;
            else tax = value/100*5;
        }

        void out()
        {
            val = to_string(value);
            capa = to_string(capacity);
            taxx = to_string(tax);
            cout<<"| "<<setw(12)<< left << name << "| " 
            <<setw(12)<< left << type << "| " 
            <<setw(12)<< left << val << "| " 
            <<setw(12)<< left << capa << "| " 
            << setw(12)<< left << taxx << "|" <<endl;
        }
};

int main()
{
    Vehicle x("Minh","Xe may",20000000, 50);
    Vehicle y("Khoi","Oto",5000000000, 60000);
    Vehicle z;
    z.inp();
    x.cal_tax(); y.cal_tax(); z.cal_tax();

    cout<< setfill('-') << setw(70) << "-" <<endl;
    cout<< setfill(' ');
    cout<<"| "<<setw(12)<< left << "Tên" << "| " <<setw(12)<< left << "Type" << "| " <<setw(12)<< left << "Value" << "| " <<setw(12)<< left << "Capacity"<< "| " << setw(12)<< left << "Tax"<< "|" <<endl; 
    cout<< setfill('-') << setw(70) << "-" <<endl;
    cout<< setfill(' ');
    x.out();
    cout<< setfill('-') << setw(70) << "-" <<endl;
    cout<< setfill(' ');
    y.out();
    cout<< setfill('-') << setw(70) << "-" <<endl;
    cout<< setfill(' ');
    z.out();
    return 0;
}