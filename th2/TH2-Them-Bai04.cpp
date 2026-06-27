#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define ll long long 

class Tamgiac{
    private:
        double a, b, c;
    public:
        Tamgiac(double a = 1, double b = 1 , double c = 1) : a(a), b(b), c(c) {};
        void inp()
        {
            cout<<"Nhập thông số 3 cạnh của tam giác: ";
            cin>>a>>b>>c;
            a *= 1.0;
            b *= 1.0;
            c *= 1.0;
        }

        int check()
        {
            if(a + b <= c || b + c <= a || a + c <= b) return 0;
            else
            {
                if(abs(a - b) < 1e-9 && abs(b - c) < 1e-9 && abs(a - c) < 1e-9) return 1;
                else if(abs(a - b) < 1e-9 || abs(b - c) < 1e-9 || abs(a - c) < 1e-9)
                {
                    if(abs(a*a + b*b - c*c) < 1e-9 || abs(a*a + c*c - b*b) < 1e-9 || abs(b*b + c*c - a*a) < 1e-9)
                        return 2;
                    else return 3;
                }
                else
                {
                    if(abs(a*a + b*b - c*c) < 1e-9 || abs(a*a + c*c - b*b) < 1e-9 || abs(b*b + c*c - a*a) < 1e-9)
                        return 4;
                    else return 5;
                }
            }
        }

        void classify()
        {
            int key = check();
            switch (key)
            {
                case 0: cout<<"Khong la tam giac"; break;
                case 1: cout<<"La tam giac deu"; break;
                case 2: cout<<"La tam giac vuong can"; break;
                case 3: cout<<"La tam giac can"; break;
                case 4: cout<<"La tam giac vuong"; break;
                case 5: cout<<"La tam giac thuong"; break;
            }
            cout<<"\n";
        }

        void area()
        {
            double p = (a + b + c)/2;
            double s = sqrt(p*(p - a)*(p - b)*(p - c));
            cout<<"Diện tích tam giác là: "<<fixed<<setprecision(2)<<s<<"\n";
        }

        void perimeter()
        {
            cout<<"Chu vi tam giác là: "<<fixed<<setprecision(2)<<a + b + c<<"\n";
        }
        
        void out()
        {
            cout<<"Độ dài 3 cạnh là: "<<a<<" "<<b<<" "<<c<<"\n";
            int key = check();
            switch (key){
                case 0: cout<<"-> Độ dài 3 cạnh không thể tạo thành tam giác"; break;
                case 1: case 2: case 3: case 4:
                {
                    area();
                    perimeter();
                    break;
                }
            }
        }
        void menu()
        {
            cout<<"=========================================\n";
            cout<<"1. Thiết lập độ dài 3 cạnh bằng 1\n"; 
            cout<<"2. Nhập tam giác\n";
            cout<<"3. Xuất thông tin tam giác\n";
            cout<<"4. Tính diện tích\n";
            cout<<"5. Tính chu vi\n";
            cout<<"6. Phân loại tam giác\n";
            cout<<"7. Thoát\n";
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
    Tamgiac t;
    while(1)
    {
        t.menu();
        int choice;
        cout<<"Nhập lựa chọn: ";
        do
        {
            /* code */
            cin>>choice;
            if(choice < 1 || choice > 7) cout<<"Cảnh báo! Lựa chọn không hợp lệ, nhập lại: ";
        } while (choice < 1 || choice > 7);
        switch(choice)
        {
            case 1: t = Tamgiac(); break;
            case 2: t.inp(); break;
            case 3: t.out(); break;
            case 4: t.area(); break;
            case 5: t.perimeter(); break;
            case 6: t.classify(); break;
            case 7: exit(0);
        }
        t.confirm_prompt();
        
    }
    return 0;
}