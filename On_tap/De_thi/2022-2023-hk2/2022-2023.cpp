#include<bits/stdc++.h>
using namespace std;


class Convat{
    protected:
        int giaidoan[6];
        string name;
    public:
        virtual ~Convat(){}
        virtual void Nhap() = 0;
        virtual bool check_diff() = 0;

        string get_name() const
        {
            return name;
        }

        int get_giaidoan(int i) const
        {
            return giaidoan[i];
        }
};

class Muoi: public Convat
{
    public:
        void Nhap() override{
            name = "Muoi";
            for(int i = 1 ; i<=4 ; i++)
            {
                cout<<"Nhap thoi gian phat trien giai doan "<<i<<"(Tinh theo ngay): ";
                cin>>giaidoan[i];
            }
        }

        bool check_diff() override
        {
            return (1 <= giaidoan[1] && giaidoan[1] <= 3 && 4 <= giaidoan[2] && giaidoan[2] <= 10 && 2 <= giaidoan[3] && giaidoan[3] <= 3 && 5 <= giaidoan[4] && giaidoan[4] <= 8);
        }
};

class Ech: public Convat{
    public:
        void Nhap() override{
            name = "Ech";
            for(int i = 1 ; i<=4 ; i++)
            {
                cout<<"Nhap thoi gian phat trien giai doan "<<i<<"(Tinh theo tuan): ";
                cin>>giaidoan[i];
            }
            cout<<"Nhap thoi gian phat trien giai doan 5(Tinh theo nam): ";cin>>giaidoan[5];
        }

        bool check_diff() override
        {
            return (1 <= giaidoan[1] && giaidoan[1] <= 3 && 4 == giaidoan[2]  && 6 <= giaidoan[3] && giaidoan[3] <= 9 && 1 <= giaidoan[4] && giaidoan[4] <= 4 && 2 <= giaidoan[5] && giaidoan[5] <= 4);
        }
};

class Buom: public Convat{
    public:
        void Nhap() override{
            name = "Buom";
            for(int i = 1 ; i<=4 ; i++)
            {
                cout<<"Nhap thoi gian phat trien giai doan "<<i<<"(Tinh theo ngay): ";
                cin>>giaidoan[i];
            }
        }

        bool check_diff() override
        {
            return (3 <= giaidoan[1] && giaidoan[1] <= 8 && 15 <= giaidoan[2] && giaidoan[2] <= 16 && 10 == giaidoan[3] && 2 <= giaidoan[4] && giaidoan[4] <= 3);
        }
};

class Hesinhthai{
    private:
        int n;
        vector<Convat* > ds;
    public:
        void Nhap()
        {
            cout<<"Nhap so luong con vat: ";
            cin>>n;
            for(int i = 1 ; i<=n ; i++)
            {
                int type;
                do
                {
                    /* code */
                    cout<<"Chon thong tin con vat(1. Muoi, 2. Ech, 3. Buom): ";
                    cin>>type;
                } while (type <1 || type > 3);
                switch(type)
                {
                    case 1:
                    {
                        Convat *temp = new Muoi();
                        temp->Nhap();
                        ds.push_back(temp);
                        break;
                    }
                    case 2:
                    {
                        Convat *temp = new Ech();
                        temp->Nhap();
                        ds.push_back(temp);
                        break;
                    }
                    case 3:
                    {
                        Convat *temp = new Buom();
                        temp->Nhap();
                        ds.push_back(temp);
                        break;
                    }
                }
            }
        }

        void Xuat()
        {
            cout<<"Danh sach con vat co thoi gian phat trien khong tuan theo qui luat\n";
            int cnt = 0;
            for(auto it: ds)
            {
                cnt++;
                if(it->check_diff() == false)
                    cout<<cnt<<". "<<it->get_name()<<"\n";
            }
        }

        bool check()
        {
            int cnt1, cnt2, cnt3;
            cnt1 = cnt2 = cnt3 = 0;
            for(auto it: ds)
            {
                if(it->get_name() == "Muoi") cnt1++;
                else if(it->get_name() == "Ech") cnt2++;
                else if(it->get_name() == "Buom") cnt3++;
            }
            return (cnt1 != 0 && cnt2 != 0 && cnt3 != 0);
        }
        ~Hesinhthai() {
            for(auto it : ds) {
                delete it;
            }
            ds.clear();
        }
};

int main()
{
    Hesinhthai b;
    b.Nhap();
    b.Xuat();
    if(b.check() == true) cout<<"Co tinh da dang";
    else cout<<"Khong co tinh da dang";
    return 0;
}