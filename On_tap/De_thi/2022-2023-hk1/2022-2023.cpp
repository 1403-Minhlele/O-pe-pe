#include<bits/stdc++.h>
using namespace std;

class Sanpham{
    protected:
        string masp, tieude;
        int giaban;
    public:
        virtual ~Sanpham(){}
        virtual void Nhap(){
            cout<<"Nhap ma san pham: ";
            getline(cin>>ws, masp);
            cout<<"Nhap tieu de san pham: ";
            getline(cin>>ws, tieude);
            cout<<"Nhap gia ban cua san pham: ";
            cin>>giaban;
        }

        int get_giaban()
        {
            return giaban;
        }

        virtual void Xuat() const
        {
            cout<<"San pham: "<<tieude<<"| Ma: "<<masp<<"| Cost: "<<giaban<<"\n";
        }
};

class CD: public Sanpham{
    protected:
        string name_casi, dv_sanxuat;
    public:
        void Nhap() override {
            Sanpham::Nhap();
            cout<<"Nhap ten ca si: ";
            getline(cin>>ws, name_casi);
            cout<<"Nhap don vi san xuat: ";
            getline(cin>>ws, dv_sanxuat);
        }

        void Xuat() const override{
            cout<<"[CD]-> Tac gia "<<name_casi<<"| Don vi san xuat: "<<dv_sanxuat<<"| ";
            Sanpham::Xuat();
        }
};

class Tranh: public Sanpham{
    protected:
        string name;
        int dai, rong;
    public:
        void Nhap() override {
            Sanpham::Nhap();
            cout<<"Nhap kich thuoc buc tranh(dai, rong): ";
            do
            {
                /* code */
                cin>>dai>>rong;
            } while (dai < 0 || rong < 0);
            cout<<"Nhap ten tac gia buc tranh: ";
            getline(cin>>ws, name);
        }

        void Xuat() const override{
            cout<<"[Tranh]-> Tac gia "<<name<<"| Kich thuoc: "<<dai<<"x"<<rong<<"| ";
            Sanpham::Xuat();
        }
};

class Hoadon{
    protected:
        string ma_hoadon, ma_khachhang, date;
        vector<Sanpham*> ds_sp;
        int sl_sp;
    public:
        void Nhap(){
            cout<<"Nhap ma hoa don: ";
            getline(cin>>ws, ma_hoadon);
            cout<<"Nhap ma khach hang: ";
            getline(cin>>ws, ma_khachhang);
            cout<<"Nhap ngay lap hoa don (dinh dang: dd/mm/yyyy): ";
            getline(cin>>ws, date);
            cout<<"Nhap sl_sp: ";
            do
            {
                /* code */
                cin>>sl_sp;
            } while (sl_sp <= 0);
            for(int i = 1 ; i <= sl_sp ; i++)
            {
                int type;
                cout<<"Nhap loai san pham(1.CD, 2.Tranh): ";
                do
                {
                    /* code */
                    cin>>type;
                } while (type < 1 || type > 2);
                switch(type){
                    case 1:
                    {
                        Sanpham* temp = new CD();
                        temp->Nhap();
                        ds_sp.push_back(temp);
                        break;
                    }
                    case 2:
                    {
                        Sanpham* temp = new Tranh();
                        temp->Nhap();
                        ds_sp.push_back(temp);
                        break;
                    }
                }
            }
        }

        string get_makhachhang()
        {
            return ma_khachhang;
        }

        int Tong_gia()
        {
            int sum = 0;
            for(auto it: ds_sp)
            {
                sum += it->get_giaban();
            }
            return sum;
        }

        void Xuat()
        {
            cout<<"["<<ma_hoadon<<"]\n";
            cout<<date<<"| "<<ma_khachhang<<"\n";
            for(auto it: ds_sp)
            {
                it->Xuat();
                cout<<"\n";
            }
        }

        ~Hoadon()
        {
            for(auto it: ds_sp) delete it;
        }
};

class KH{
    protected:
        string ma_khachhang, name, sdt;
    public:
        void Nhap()
        {
            cout<<"Nhap ma khach hang: ";
            getline(cin>>ws, ma_khachhang);
            cout<<"Nhap ten khach hang: ";
            getline(cin>>ws, name);
            cout<<"Nhap so dien thoai: ";
            getline(cin>>ws, sdt);
        }

        string get_makh(){
            return ma_khachhang;
        }

        void set_makh(string ma)
        {
            ma_khachhang = ma;
            cout<<"Nhap ten khach hang: ";
            getline(cin>>ws, name);
            cout<<"Nhap so dien thoai: ";
            getline(cin>>ws, sdt);
        }

        void Xuat()
        {
            cout<<"["<<ma_khachhang<<"] "<<name<<"| "<<sdt<<"\n";
        }
};

class Quanli{
    protected:
        vector<Hoadon*> ds_hoadon;
        vector<KH*> ds_khachhang;
        int sl_hoadon;
    public:

        bool New_KH(string ma)
        {
            if(ds_khachhang.empty()) return true;
            for(auto it: ds_khachhang)
            {
                if(it->get_makh() == ma)
                    return false;
            }
            return true;
        }
        void Nhap(){
            cout<<"Nhap so luong hoa don: ";
            do
            {
                /* code */
                cin>>sl_hoadon;
            } while (sl_hoadon<=0);
            for(int i = 1 ; i<=sl_hoadon ; i++)
            {
                Hoadon* temp = new Hoadon();
                temp->Nhap();
                if(New_KH(temp->get_makhachhang()))
                {
                    KH* khachhang = new KH();
                    khachhang->set_makh(temp->get_makhachhang());
                    ds_khachhang.push_back(khachhang);
                }
                ds_hoadon.push_back(temp);
            }
        }

        int Tong_thunhap()
        {
            int sum = 0;
            for(auto it:ds_hoadon)
                sum += it->Tong_gia();
            
            return sum;
        }

        void Find_KH_max()
        {
            vector<KH*> res;
            int sum = 0;
            for(auto it: ds_khachhang)
            {
                string maso = it->get_makh();
                int mua = 0;
                for(auto it1: ds_hoadon)
                {
                    string cmp_maso = it1->get_makhachhang();
                    if(cmp_maso == maso)
                        mua += it1->Tong_gia();
                }
                if(mua > sum)
                {
                    sum = mua;
                    if(!res.empty())
                        res.clear();
                    res.push_back(it);
                }
                else if(mua == sum)
                    res.push_back(it);
            }
            for(auto it: res)
                it->Xuat();
        }

        void Xuat()
        {
            for(auto it: ds_hoadon)
                it->Xuat();
        }

        ~Quanli()
        {
            for(auto it: ds_hoadon) delete it;
            for(auto it: ds_khachhang) delete it;

        }
};

int main()
{
    Quanli a;
    a.Nhap();

    a.Xuat();

    cout<<"Loi nhuan cua cua hang la : "<<a.Tong_thunhap()<<"\n";
    a.Find_KH_max();

    return 0;
}