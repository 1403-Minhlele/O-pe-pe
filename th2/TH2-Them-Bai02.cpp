#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define ll long long 

class Ptrinh{
    private:
        double a, b, ans;
    public:
        Ptrinh(double a = 0 , double b = 0 ): a(a) , b(b) {};
        void inp()
        {
            cout<<"Nhập hệ số a: "; cin>>a;
            cout<<"Nhập hệ số b: "; cin>>b;
        }
        void cal()
        {
            if(abs(a) < 1e-9 && abs(b) < 1e-9) ans = 1e18;
            else if(abs(a) < 1e-9 && abs(b) >= 1e-9) ans = -1e18;
            else ans = -b/a;
        }
        void out()
        {
            cout<<"Hệ phương trình: ";
            if(a == 0 && b != 0) cout<<b<<" = "<<0;
            else if(a != 0 && b == 0) cout<<a<<"x = 0";
            else
            {
                cout<<a<<"x";
                if(b < 0) cout<<" - "<<abs(b)<<" = 0";
                else cout<<" + "<<b<<" = 0";
            }
            cout<<"\nCó nghiệm là: "<<fixed<<setprecision(2)<<ans;
        }
        void menu()
        {
            cout<<"=========================================\n";
            cout<<"1. Thiết lập hệ số a, b mặc định = 0\n"; 
            cout<<"2. Thiết lập hệ số a = 0, b tùy ý\n";
            cout<<"3. Thiết lập hệ số a tùy ý, b = 0\n";
            cout<<"4. Thiết lập hệ số a, b tùy ý\n";
            cout<<"5. Nhập hệ số a, b\n";
            cout<<"6. Giải hệ phương trình\n";
            cout<<"7. Xuất hệ phương trình và nghiệm\n";
            cout<<"8. Thoát\n";
            cout<<"=========================================\n";
        }
        void confirm_prompt()
        {
            cout<<"\nBạn có muốn tiếp tục không (Yes, No)?: ";
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
            
};

int main()
{
    srand(time(0));
    Ptrinh p;
    while(1)
    {
        p.menu();
        int choice;
        cout<<"Nhập lựa chọn: ";
        do
        {
            /* code */
            cin>>choice;
            if(choice < 1 || choice > 8) cout<<"Cảnh báo! Lựa chọn không hợp lệ, nhập lại: ";
        } while (choice < 1 || choice > 8);
        switch(choice)
        {
            case 1: p = Ptrinh(); break;
            case 2: p = Ptrinh(0, rand()%100); break;
            case 3: p = Ptrinh(rand()%100, 0); break;
            case 4: p = Ptrinh(rand()%100, rand()%100); break;
            case 5: p.inp(); break;
            case 6: p.cal(); break;
            case 7: p.out(); break;
            case 8: exit(0);
        }
        p.confirm_prompt();
    }
    return 0;
}