#include<bits/stdc++.h>
using namespace std;

double RandomDouble() 
{
    return (double)rand() / RAND_MAX;
}

class Virus {
    public:
        virtual ~Virus() {}
        virtual string get_name() const = 0;
        virtual string get_trieuchung(int mucdo) const = 0;
        virtual double get_tuvongrate() const = 0;
};

class Cov: public Virus {
    public:
        string get_name() const override {
            return "SARS-CoV-2";
        }

        string get_trieuchung(int mucdo) const override {
            if(mucdo == 0) return "Khong trieu chung";
            else if(mucdo == 1) return "Sot, ho, mat vi giac";
            else return "Sot cao, ho khan, kho tho";
        }

        double get_tuvongrate() const override {
            return 4.0;
        }
};

class Ebola: public Virus {
    public:
        string get_name() const override {
            return "Ebola";
        }

        string get_trieuchung(int mucdo) const override {
            if(mucdo == 0) return "Khong trieu chung";
            else if(mucdo == 1) return "Sot, dau co, dau hong";
            else return "Non mua, tieu chay, xuat huyet";
        }

        double get_tuvongrate() const override {
            return 50.0;
        }
};

class HIV: public Virus {
    public:
        string get_name() const override {
            return "HIV";
        }

        string get_trieuchung(int mucdo) const override {
            if(mucdo == 0) return "Khong trieu chung";
            else if(mucdo == 1) return "Sot, ho";
            else return "Viem phoi, sung hach, lo loet";
        }

        double get_tuvongrate() const override {
            return 90.0;
        }
};

class Vatchu {
    private:
        string maso;
        bool is_vaccine;
        bool is_dead;
        bool trieu_chung_nang;
        int miendich_rate;
        vector<string> ds_trieuchung;
        
        double vaccine[3] = {80, 60, 40};
        double not_vaccine[3] = {100, 70, 50};
        double rand2[3][3] = {{10, 40, 50}, {20, 50, 30}, {70, 25, 5}};
        double rand1[3][3] = {{5, 15, 80}, {10, 40, 50}, {50, 35, 15}};

    public:
        Vatchu(string maso, int md): maso(maso), miendich_rate(md), is_vaccine(false), is_dead(false), trieu_chung_nang(false) {}

        void tiem_vaccine()
        {
            is_vaccine = true;
        }

        bool get_is_dead() const{
            return is_dead;
        } 
        bool get_trieuchung() const{
            return trieu_chung_nang;
        }
        void Nhiem(Virus *v)
        {
            if (is_dead) return;

            double rate_trieuchung = RandomDouble();
            double rate_tuvong = RandomDouble();
            double heso_tuvong;
            int mucdo = 0;
            if(!is_vaccine)
            {
                heso_tuvong = not_vaccine[miendich_rate];
                double sum = 0.0;
                for(int i = 0 ; i <= 2 ; i++)
                {
                    sum += rand1[miendich_rate][i];
                    if(sum >= rate_trieuchung * 100.0) {
                        mucdo = i;
                        break;
                    }
                }
            }
            else
            {   
                heso_tuvong = vaccine[miendich_rate];
                double sum = 0.0;
                for(int i = 0; i <= 2 ; i++)
                {
                    sum += rand2[miendich_rate][i];
                    if(sum >= rate_trieuchung * 100.0) {
                        mucdo = i;
                        break;
                    }
                }
            }
            if(mucdo == 2)
                trieu_chung_nang = true;
            ds_trieuchung.push_back(v->get_name() + " (" + v->get_trieuchung(mucdo) + ")");

            double thucTeTuVong = (heso_tuvong / 100.0) * (v->get_tuvongrate() / 100.0);
            if(rate_tuvong < thucTeTuVong) {
                is_dead = true;
                ds_trieuchung.push_back("-> DA TU VONG DO " + v->get_name());
            }
        }
        
        void Xuat()
        {
            cout << "Ma vat chu: " << maso << " | Tinh trang: ";
            if (ds_trieuchung.empty()) {
                cout << "Khoe manh";
            } else {
                for(auto it : ds_trieuchung)
                    cout << "[" << it << "] ";
            }
        }
};

int main()
{
    srand(time(0));
    
    int n;
    cout << "Nhap so luong vat chu mo phong: ";
    cin >> n;
    
    vector<Vatchu *> mophong1;
    
    Virus* cov = new Cov();
    Virus* ebola = new Ebola();
    Virus* hiv = new HIV();

    for(int i = 1 ; i <= n; i++)
    {
        cout << "Nhap ma so vat chu thu " << i << ": ";
        string temp;
        cin >> temp;
        
        int md;
        do {
            cout << "Nhap kha nang mien dich (0. THAP, 1. TRUNGBINH, 2. CAO): ";
            cin >> md;
        } while (md < 0 || md > 2);
        
        Vatchu* vc = new Vatchu(temp, md);
        
        vc->Nhiem(cov);
        vc->Nhiem(ebola);
        vc->Nhiem(hiv);
        mophong1.push_back(vc);
    }

    cout << "\n------------------- MO PHONG 1 (KHONG VACCINE) -------------------\n";
    for(auto it: mophong1)
    {
        it->Xuat();
        cout << "\n";
    }

    for(auto it : mophong1) delete it;
    cout<<"\n------------------- MO PHONG 2 (VACCINE) -------------------\n";
    vector<Vatchu*> mophong2;
    for(int i = 1 ; i <= n; i++)
    {
        cout << "Nhap ma so vat chu thu " << i << ": ";
        string temp;
        cin >> temp;
        
        int md;
        do {
            cout << "Nhap kha nang mien dich (0. THAP, 1. TRUNGBINH, 2. CAO): ";
            cin >> md;
        } while (md < 0 || md > 2);
        
        Vatchu* vc = new Vatchu(temp, md);
        vc->tiem_vaccine();
        vc->Nhiem(cov);
        vc->Nhiem(ebola);
        vc->Nhiem(hiv);
        mophong2.push_back(vc);
    }
    int cnt_nang = 0;
    int cnt_dead = 0;
    for(auto it: mophong2)
    {
        if(it->get_trieuchung() == true) cnt_nang++;
        if(it->get_is_dead() == true)
            cnt_dead++;
    }
    cout<<"Qua mo phong co: "<<cnt_nang<<" vc co trieu chung nang va "<<cnt_dead<<" vc da chet";
    for(auto it : mophong2) delete it;
    delete cov;
    delete ebola;
    delete hiv;
    return 0;
}