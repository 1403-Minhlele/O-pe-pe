#include<bits/stdc++.h>
using namespace std;

class MANG1D
{
    private:
        int n;
        int *a;
        void clear()
        {
            if (a != NULL)
            {
                delete[] a;
                a = NULL;
                n = 0;
            }
        }

    public:
        MANG1D(int n = 0, int m = 0);
        MANG1D(const MANG1D& A);
        ~MANG1D();

        MANG1D& operator=(const MANG1D& A)
        {
            if(this != &A) 
            {
                clear();
                this->n = A.n;
                if(n > 0)
                {
                    a = new int[n];
                    for(int i = 0; i < n; i++) a[i] = A.a[i];
                }
            }
            return *this;
        } 

        int getN() const { return n; }
        int* getA() const { return a; }

        void setN(int new_n)
        {
            if(new_n <= 0)
            {
                clear();
            }
            else
            {
                MANG1D M(new_n);
                int limit = min(new_n, this->n);
                for(int i = 0; i < limit; i++) M.a[i] = a[i];
                for(int i = limit; i < new_n; i++) M.a[i] = 0;
                
                *this = M;
            }
        }

        void setA(const MANG1D &b)
        {
            *this = b;
        }

        void inp()
        {
            clear(); 
            cout << "Nhap so luong phan tu: ";
            do
            {
                cin >> n;
                if(n <= 0) cout << "Phan tu mang phai > 0, nhap lai: ";
            } while (n <= 0);

            cout << "Nhap cac phan tu trong mang: ";
            a = new int[n];
            for(int i = 0; i < n; i++)
                cin >> a[i];
        }

        void out() const
        {
            if(a == NULL || n == 0)
                cout << "Mang rong\n";
            else
            {
                cout << "Cac phan tu trong mang hien tai la: ";
                for(int i = 0; i < n; i++) cout << a[i] << " ";
                cout << "\n";
            }
        }

        friend istream &operator>>(istream &in, MANG1D &A)
        {
            A.inp();
            return in;
        }

        friend ostream &operator<<(ostream &ou, const MANG1D& A)
        {
            A.out();
            return ou;
        }

        void PhatSinh()
        {
            clear();
            cout << "Nhap so luong phan tu mang muon phat sinh: ";
            do
            {
                cin >> n;
                if(n <= 0) cout << "So luong phan tu > 0, nhap lai: ";
            } while (n <= 0);
            
            a = new int[n];
            cout << "Nhap mien gia tri ban muon phat sinh (min max): ";
            int mi, ma;
            cin >> mi >> ma;
            srand(time(NULL));
            for(int i = 0; i < n; i++)
                a[i] = rand() % (ma - mi + 1) + mi;
        }

        void ListNT() const
        {
            if(a == NULL) {
                cout << "Canh bao mang rong!!!\n";
                return;
            }
            int cnt = 0;
            cout << "Cac so nguyen to trong mang la: ";
            for(int i = 0; i < n; i++)
            {
                int val = a[i];
                bool flag = true;
                if(val < 2) flag = false;
                for(int j = 2; j * j <= val; j++)
                {
                    if(val % j == 0) { flag = false; break; }
                }
                if(flag)
                {
                    cnt++;
                    cout << a[i] << "\t";
                }
            }
            cout << "\nTong cong mang co " << cnt << " so nguyen to\n";
        }

        void DemCP() const
        {
            if(a == NULL) {
                cout << "Canh bao mang rong!!!\n";
                return;
            }
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if (a[i] >= 0) {
                    int tmp = sqrt(a[i]);
                    if(tmp * tmp == a[i]) cnt++;
                }
            }
            cout << "So luong so chinh phuong trong mang la: " << cnt << "\n";
        }

        void SumHT() const
        {
            if(a == NULL) {
                cout << "Canh bao mang rong!!!\n";
                return;
            }
            int sumht = 0;
            cout << "Cac phan tu la so hoan thien la: ";
            for(int i = 0; i < n; i++)
            {
                if (a[i] <= 1) continue;
                int sum = 0, val = a[i];
                for(int j = 1; j * j <= val; j++)
                {
                    if(val % j == 0)
                    {
                        if (j != val) sum += j;
                        if (val / j != val && val / j != j) sum += val / j;
                    }
                }
                if(sum == a[i])
                {
                    cout << a[i] << " ";
                    sumht += a[i];
                }
            }
            cout << "\nTong cac so hoan thien la: " << sumht << "\n";
        }

        void SumDX() const
        {
            if(a == NULL) {
                cout << "Canh bao mang rong!!!\n";
                return;
            }
            double sum = 0;
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                int val = a[i];
                if (val < 0) continue;
                
                int tmp = 0, original = val;
                while(val > 0)
                {
                    tmp = tmp * 10 + (val % 10);
                    val /= 10;
                }
                if(tmp == original)
                {
                    cnt++;
                    sum += original;
                }
            }
            
            if (cnt > 0) {
                cout << "Trung binh cong cac so doi xung trong mang la: ";
                cout << fixed << setprecision(4) << sum / cnt << "\n";
            } else {
                cout << "Khong co so doi xung trong mang.\n";
            }
        }

        bool is_le() const
        {
            if(a == NULL) return false;
            for(int i = 0; i < n; i++)
            {
                if(a[i] % 2 == 0) return false;
            }
            return true;
        }

        void min_chan() const
        {
            if(a == NULL) cout << "Canh bao mang rong!!!\n";
            else
            {
                int mi = INT_MAX;
                bool found = false;
                for(int i = 0; i < n; i++)
                {
                    if(a[i] % 2 == 0) {
                        mi = min(mi, a[i]);
                        found = true;
                    }
                }
                if(found) cout << "Phan tu chan nho nhat la: " << mi << "\n";
                else cout << "Khong co phan tu chan\n";
            }
        }

        void sort_tang() { if(a != NULL) sort(a, a+n); }
        void sort_giam() { if(a != NULL) sort(a, a+n, greater<int>()); }

        void XoaViTri(int vt)
        {
            if(vt >= 0 && vt < n)
            {
                int *tmp = new int[n - 1];
                for(int i = 0; i < vt; i++) 
                    tmp[i] = a[i];
                for(int i = vt + 1; i < n; i++) 
                    tmp[i - 1] = a[i];
                
                delete[] a;
                a = tmp;
                n--;
                
                if(n == 0)
                {
                    delete[] a;
                    a = NULL;
                }
            }
        }

        void ThemViTri(int vt, int gt)
        {
            if(vt >= 0 && vt <= n)
            {
                int *tmp = new int[n + 1];
                for(int i = 0; i < vt; i++) 
                    tmp[i] = a[i];
                
                tmp[vt] = gt;
                
                for(int i = vt; i < n; i++) 
                    tmp[i + 1] = a[i];
                
                delete[] a;
                a = tmp;
                n++;
            }
        }

        void CapNhat(int vt, int gt)
        {
            if(vt >= 0 && vt < n)
            {
                a[vt] = gt;
            }
        }

        int TimKiemTuyenTinh(int gt)
        {
            for(int i = 0; i < n; i++)
            {
                if(a[i] == gt) 
                    return i;
            }
            return -1;
        }

        int TimKiemNhiPhan(int gt)
        {
            sort_tang();
            int l = 0;
            int r = n - 1;
            while(l <= r)
            {
                int m = l + (r - l) / 2;
                if(a[m] == gt) 
                    return m;
                if(a[m] < gt) 
                    l = m + 1;
                else 
                    r = m - 1;
            }
            return -1;
        }
};

MANG1D::MANG1D(int n, int m)
{
    if(n <= 0)
    {
        a = NULL;
        this->n = 0;
    }
    else
    {
        a = new int[n];
        this->n = n;
        for(int i = 0; i < n; i++) a[i] = m;
    }
}

MANG1D::MANG1D(const MANG1D& A)
{
    if(A.n <= 0)
    {
        this->n = 0;
        a = NULL;
    }
    else
    {
        this->n = A.n;
        a = new int[n];
        for(int i = 0; i < n; i++) a[i] = A.a[i];
    }
}

MANG1D::~MANG1D()
{
    clear();
}

void display_menu()
{
    cout << "------CHUONG TRINH XU LY MANG 1 CHIEU------\n";
    cout << "1. Nhap mang\n";
    cout << "2. Phat sinh mang\n";
    cout << "3. Xuat mang\n";
    cout << "4. Cap nhat so phan tu mang goi ham SetN(n)\n";
    cout << "5. Liet ke cac phan tu la SNT\n";
    cout << "6. Dem so luong cac phan tu la SCP\n";
    cout << "7. Tinh tong gia tri cac phan tu la SHT\n";
    cout << "8. Tinh TB cong gia tri cac phan tu la SDX\n";
    cout << "9. Kiem tra mang toan phan tu le\n";
    cout << "10. Tim phan tu chan be nhat\n";
    cout << "11. Sap xep mang tang dan\n";
    cout << "12. Xoa phan tu tai vi tri\n";
    cout << "13. Them phan tu tai vi tri\n";
    cout << "14. Xoa mang\n";
    cout << "15. Cap nhat gia tri phan tu tai vi tri\n";
    cout << "16. Tim kiem tuyen tinh\n";
    cout << "17. Tim kiem nhi phan\n";
    cout << "0. Thoat CT\n";
    cout << "-------------------------------------------\n";
}

void continue_prompt()
{
    cout << "Bạn có muốn tiếp tục không (Yes, No)?: ";
    string confirm;
    do
    {
        cin >> confirm;
        if (confirm != "Yes" && confirm != "No")
            cout << "Cảnh báo! Nhập sai, nhập lại: ";
    } while (confirm != "Yes" && confirm != "No");
    if (confirm == "No")
    {
        cout << "Thoát chương trình thành công!\n";
        exit(0);
    }
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif 
}

int main()
{
    MANG1D m1c; // Đã sửa tên biến từ 'a' thành 'm1c'
    while(1)
    {
        display_menu();
        int chon;
        cout<<"Lua chon cua ban la: ";
        do
        {
            /* code */
            cin>>chon;
            if(chon < 0 || chon > 17) cout<<"Lua chon khong hop le, nhap lai: ";
        } while (chon < 0 || chon > 17);
        switch(chon)
        {
            case 1:
            {
                m1c.inp();
                break;
            }
            case 2:
            {
                m1c.PhatSinh();
                break;
            }
            case 3:
            {
                m1c.out();
                break;
            }
            case 4:
            {
                int n_moi;
                cout << "Nhap so phan tu moi: ";
                cin >> n_moi;
                m1c.setN(n_moi);
                break;
            }
            case 5:
            {
                m1c.ListNT();
                break;
            }
            case 6:
            {
                m1c.DemCP();
                break;
            }
            case 7:
            {
                m1c.SumHT();
                break;
            }
            case 8:
            {
                m1c.SumDX();
                break;
            }
            case 9:
            {
                if (m1c.is_le())
                    cout << "Mang toan phan tu le\n";
                else
                    cout << "Mang KHONG toan phan tu le\n";
                break;
            }
            case 10:
            {
                m1c.min_chan();
                break;
            }
            case 11:
            {
                m1c.sort_tang();
                cout << "Da sap xep mang tang dan!\n";
                break;
            }
            case 12:
            {
                int vt;
                cout << "Nhap vi tri can xoa: ";
                cin >> vt;
                m1c.XoaViTri(vt);
                cout << "Da xoa phan tu (neu vi tri hop le).\n";
                break;
            }
            case 13:
            {
                int vt, gt;
                cout << "Nhap vi tri can them: ";
                cin >> vt;
                cout << "Nhap gia tri can them: ";
                cin >> gt;
                m1c.ThemViTri(vt, gt);
                cout << "Da them phan tu (neu vi tri hop le).\n";
                break;
            }
            case 14:
            {
                m1c.setN(0);
                cout << "Da xoa toan bo mang!\n";
                break;
            }
            case 15:
            {
                int vt, gt;
                cout << "Nhap vi tri can cap nhat: ";
                cin >> vt;
                cout << "Nhap gia tri moi: ";
                cin >> gt;
                m1c.CapNhat(vt, gt);
                cout << "Da cap nhat (neu vi tri hop le).\n";
                break;
            }
            case 16:
            {
                int gt;
                cout << "Nhap gia tri can tim tuyen tinh: ";
                cin >> gt;
                int kq = m1c.TimKiemTuyenTinh(gt);
                if (kq != -1)
                    cout << "Tim thay gia tri " << gt << " tai vi tri " << kq << "\n";
                else
                    cout << "Khong tim thay gia tri " << gt << " trong mang\n";
                break;
            }
            case 17:
            {
                int gt;
                cout << "Nhap gia tri can tim nhi phan (mang se duoc sap xep truoc): ";
                cin >> gt;
                int kq = m1c.TimKiemNhiPhan(gt);
                if (kq != -1)
                    cout << "Tim thay gia tri " << gt << " tai vi tri " << kq << "\n";
                else
                    cout << "Khong tim thay gia tri " << gt << " trong mang\n";
                break;
            }
            case 0:
            {
                cout << "Thoat CT\n";
                exit(0);
            }
        }
        continue_prompt();
    }
    return 0;
}