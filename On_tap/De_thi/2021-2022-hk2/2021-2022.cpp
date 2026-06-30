#include<bits/stdc++.h>
using namespace std;

class Sach{
    protected:
        string masach, name, nxb;
        int soluong, dongia;
    public:
        virtual void Nhap(){
            cout<<"Nhap ma quyen sach: ";
            getline(cin>>ws, masach);
            cout<<"Nhap ten quyen sach: ";
            getline(cin>>ws, name);
            cout<<"Nhap ten nha xuat ban: ";
            getline(cin>>ws, nxb);
            cout<<"Nhap so luong quyen sach: ";
            cin>>soluong;
            cout<<"Nhap don gia cua quyen sach: ";
            do
            {
                /* code */
                cin>>dongia;
            } while (dongia < 0);
            
        }

        virtual void Xuat() const{
            cout<<"["<<masach<<"]--> "<<name<<"| "<<nxb<<"| "<<soluong<<"| "<<dongia<<"\n";
        }

        virtual int Thanhtien() = 0;

        string get_nxb()
        {
            return nxb;
        }

        virtual ~Sach(){}

};

class GK: public Sach{
    protected:
        int type;
    public:
        void Nhap() override {
            Sach::Nhap();
            cout<<"Nhap tinh trang cua quyen sach(0. cu, 1. moi): ";
            do
            {
                /* code */
                cin>>type;
            } while (type < 0 || type > 1);
        }

        void Xuat() const override{
            cout<<"Sach giao khoa: ";
            Sach::Xuat();
            cout<<"==> Tinh trang: ";
            if(type == 0) cout<<"Cu";
            else cout<<"Moi";
        }

        int Thanhtien() override{
            if(type == 0)
                return soluong*dongia/2;
            else return soluong*dongia;
        }
};

class TK: public Sach{
    protected:
        int thue;
    public:
        void Nhap() override{
            Sach::Nhap();
            cout<<"Nhap thue: ";
            do
            {
                /* code */
                cin>>thue;
            } while (thue < 0);
        }

        void Xuat() const override{
            cout<<"Sach tham khao: ";
            Sach::Xuat();
            cout<<"==> Gia thue: "<<thue;
        }

        int Thanhtien() override{
            return soluong*dongia + thue;
        }
};

class Thuvien{
    private:
        vector<Sach*> ds_sach;
        vector<Sach*> min_sach;
        int n;
    public:
        void Nhap()
        {
            cout<<"Nhap so luong sach cua thu vien: ";
            do
            {
                /* code */
                cin>>n;
            } while (n < 0);
            for(int i = 1 ; i<= n ; i++)
            {
                int type;
                cout<<"Nhap loai cua quyen sach thu "<<i<<"(1.Sach giao khoa, 2. Sach tham khao): ";
                do
                {
                    /* code */
                    cin>>type;
                } while (type != 1 && type != 2);
                Sach* temp;
                if(type == 1) temp = new GK();
                else temp = new TK();
                temp->Nhap();
                ds_sach.push_back(temp);
            }
        }

        void Xuat()
        {
            for(auto it: ds_sach)
            {
                it->Xuat();
                cout<<"\n";
            }
        }

        void Cost_tv()
        {
            int sum = 0;
            int min = INT_MAX;
            for(auto it: ds_sach)
            {
                sum += it->Thanhtien();
                if(it->Thanhtien() < min)
                {
                    min = it->Thanhtien();
                    if(!min_sach.empty()) min_sach.clear();
                    min_sach.push_back(it);
                }
                else if(it->Thanhtien() == min)
                    min_sach.push_back(it);
            }
            cout<<"Gia thu vien phai tra: "<<sum<<"\n";
            cout<<"Danh sach sach co thanh tien nho nhat: \n";
            for(auto it: min_sach)
            {
                it->Xuat();
                cout<<"\n";
            }
        }

        void Find_nxb(){
            string f;
            cout<<"Nhap ten nha xuat ban ban muon tim: ";
            getline(cin>>ws, f);
            for(auto it: ds_sach)
            {
                if(it->get_nxb() == f)
                {
                    it->Xuat();
                    cout<<"\n";
                }
            }
        }

        ~Thuvien()
        {
            for(auto it: ds_sach) delete it;
        }

};

int main()
{
    Thuvien UIT;
    UIT.Nhap();

    UIT.Xuat();

    UIT.Cost_tv();

    UIT.Find_nxb();
}