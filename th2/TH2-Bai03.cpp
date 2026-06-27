#include<bits/stdc++.h>
using namespace std;

class soPhuc{
    private:
        double thuc, ao;
    public:
        bool check()
        {
            return (thuc == 0 && ao == 0);
        }
        void inp(int idx)
        {
            cout<<"Nhập lần lượt thành phần thực và thành phần ảo của số thứ "<<idx<<": ";
            double x, y;
            cin>>x>>y;
            this -> thuc = x;
            this -> ao = y;
        }
        void out()
        {
            if(thuc == 0 && ao == 0) cout<<0<<"\n";
            else 
            {
                if(thuc != 0 && ao == 0) cout<<thuc<<"\n";
                else if(thuc == 0 && ao != 0) cout<<ao<<"i\n";
                else
                {
                    cout<<thuc<<" ";
                    if(ao < 0) cout<<"- "<<abs(ao)<<"i\n";
                    else cout<<"+ "<<ao<<"i\n";
                }
            }
        }
        void menu()
        {
            cout<<"1. Nhập số phức\n";
            cout<<"2. Xuất số phức\n";
            cout<<"3. Tính tổng hai số phức\n";
            cout<<"4. Tính hiệu hai số phức\n";
            cout<<"5. Tính tích hai số phức\n";
            cout<<"6. Tính thương hai số phức\n";
            cout<<"7. Thoát\n";
        }
        soPhuc sum(soPhuc p);
        soPhuc diff(soPhuc p);
        soPhuc multi(soPhuc p);
        soPhuc div(soPhuc p);

        void process()
        {
            int choice;
            do
            {
                menu();
                cout<<"Nhập lựa chọn: ";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        inp(1);
                        break;
                    case 2:
                    {   
                        cout<<"==============================\n";
                        cout<<"Số phức vừa nhập: ";
                        out();
                        cout<<"==============================\n";
                        break;
                    }
                    case 3:
                        {
                            soPhuc p;
                            p.inp(2);
                            soPhuc ans = sum(p);
                            cout<<"Tổng: "; ans.out();
                            break;
                        }
                    case 4:
                        {
                            soPhuc p;
                            p.inp(2);
                            soPhuc ans = diff(p);
                            cout<<"Hiệu: "; ans.out();
                            break;
                        }
                    case 5:
                        {
                            soPhuc p;
                            p.inp(2);
                            soPhuc ans = multi(p);
                            cout<<"Tích: "; ans.out();
                            break;
                        }
                    case 6:
                        {
                            soPhuc p;
                            p.inp(2);
                            soPhuc ans = div(p);
                            cout<<"Thương: "; ans.out();
                            break;
                        }
                    case 7:
                        exit(0);
                    default:
                        cout<<"Lựa chọn không hợp lệ\n";
                }
            } while(choice >= 1 && choice <= 6);
        }
};

soPhuc soPhuc::sum(soPhuc p)
{
    soPhuc tmp;
    tmp.thuc = thuc + p.thuc;
    tmp.ao = ao + p.ao;
    return tmp;
}

soPhuc soPhuc::diff(soPhuc p)
{
    soPhuc tmp;
    tmp.thuc = thuc - p.thuc;
    tmp.ao = ao - p.ao;
    return tmp;
}

soPhuc soPhuc::multi(soPhuc p)
{
    soPhuc tmp;
    tmp.thuc = thuc*p.thuc - ao*p.ao;
    tmp.ao = thuc*p.ao + ao*p.thuc;
    return tmp;
}

soPhuc soPhuc::div(soPhuc p)
{
    soPhuc tmp;
    bool checking = p.check();
    if(checking == true)
    {
        cout<<"Không thể thực hiện phép chia";
        exit(0);
    }
    tmp.thuc = thuc*p.thuc + ao*p.ao;
    tmp.ao = p.thuc*ao - thuc*p.ao;

    double mau = p.thuc*p.thuc + p.ao*p.ao;
    tmp.thuc /= mau;
    tmp.ao /= mau;
    
    return tmp;
}


int main()
{
    while(1)
    {
        soPhuc p;
        p.process();
    }
    return 0;   
}
