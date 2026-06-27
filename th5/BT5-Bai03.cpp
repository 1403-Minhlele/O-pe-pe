#include<bits/stdc++.h>
using namespace std;

class MTVUONG
{
    private:
        int n;
        int **p;
        
        void clear()
        {
            if(p != NULL)
            {
                for(int i = 0 ; i<n ; i++)
                    delete[] p[i];
                delete[] p;
                p = NULL;
                n = 0;
            }
        }
        
    public:
        MTVUONG(int n = 0, int val = 0): n(n)
        {
            if(n <= 0)
                p = NULL;
            else
            {
                p = new int*[n];
                for(int i = 0 ; i<n ; i++)
                {
                    p[i] = new int[n];
                    for(int j = 0 ; j<n ; j++)
                        p[i][j] = val;
                }
            }
        }
        
        ~MTVUONG()
        {
            clear();
        }

        MTVUONG (const MTVUONG& orther)
        {
            this -> n = orther.n;
            if(this -> n > 0){
                p = new int*[n];
                for(int i = 0 ; i < n ; i++)
                {
                    p[i] = new int[n];
                    for(int j = 0 ; j<n ; j++)
                    {
                        p[i][j] = orther.p[i][j];
                    }
                }
            }
            else
                p = NULL;
        }

        MTVUONG& operator=(const MTVUONG&orther)
        {
            if(this != &orther)
            {
                clear();
                this -> n = orther.n;
                if(this -> n > 0){
                    p = new int*[n];
                    for(int i = 0 ; i < n ; i++)
                    {
                        p[i] = new int[n];
                        for(int j = 0 ; j<n ; j++)
                        {
                            p[i][j] = orther.p[i][j];
                        }
                    }
                }
            }
            return *this;
        }

        int Get_n() const
        {
            return n;
        }
        
        int** Get_matrix() const 
        {
            return p;
        }

        void Set_n(int val)
        {
            if(val <= 0)
            {
                clear();
                return ;
            }
            if(val == n) return ;

            int **temp = new int*[val];
            for(int i = 0 ; i<val ; i++)
            {
                temp[i] = new int[val];
                for(int j = 0 ; j<val ; j++)
                    temp[i][j] = 0;
            }

            for(int i = 0 ; i < min(n, val) ; i++)
            {
                for(int j = 0 ; j < min(n, val) ; j++)
                    temp[i][j] = p[i][j];
            }

            clear();
            this -> n = val;
            this -> p = temp;
        }

        void Set_matrix(const MTVUONG&orther)
        {
            *this = orther;
        }

        void inp()
        {
            clear();
            cout<<"Nhap kich thuoc ma tran vuong: ";
            do
            {
                cin>>n;
                if(n < 0) cout<<"Nhap sai nhap lai: ";
            } while (n < 0);
            if(n == 0)
            {
                p = NULL;
                return ;
            }
            p = new int*[n];
            for(int i = 0; i <n ; i++)
            {
                p[i] = new int[n];
                for(int j = 0 ; j <n ; j++)
                    cin>>p[i][j];
            }
        }

        void out() const
        {
            if(p == NULL)
                cout<<"Empty matrix\n";
            else
            {
                cout<<"n: "<<n<<"\n";
                for(int i = 0 ; i<n ; i++){
                    for(int j = 0 ; j<n ; j++)
                        cout<<p[i][j]<<" ";
                    cout<<"\n";
                }
            }
        }

        friend istream &operator>>(istream &in, MTVUONG &a)
        {
            a.inp();
            return in;
        }

        friend ostream&operator<<(ostream &ou, const MTVUONG &a)
        {
            a.out();
            return ou;
        }

        void Phatsinh()
        {
            clear();
            cout<<"Nhap kich thuoc ma tran vuong phat sinh: ";
            do
            {
                cin>>n;
                if(n < 0) cout<<"Nhap sai nhap lai: ";
            } while (n < 0);

            if(n == 0)
            {
                p = NULL;
                return;
            }

            srand(time(NULL));
            cout<<"Nhap khoang [a, b] muon phat sinh: ";
            int a, b;
            do
            {
                cin>>a>>b;
                if(a > b) cout<<"Sai dinh dang nhap lai khoang [a, b]: ";
            } while (a > b);
            
            p = new int*[n];
            for(int i = 0; i< n ; i++)
            {
                p[i] = new int[n];
                for(int j =0 ; j<n ; j++)
                {
                    int val = rand()%(b-a+1);
                    val += a;
                    p[i][j] = val;
                }
            }
        }

        void ListOdd() const
        {
            if(p == NULL)
            {
                cout<<"Empty list";
                return;
            }
            for(int i = 0; i<n ; i++)
            {
                if(p[i][i] % 2 != 0)
                    cout<<p[i][i]<<" ";
            }
        }

        void ListLast3() const
        {
            if(p == NULL)
            {
                cout<<"Empty list";
                return;
            }
            for(int i = 0 ; i<n ; i++)
            {
                if(abs(p[i][n-i-1]) % 10 == 3)
                    cout<<p[i][n-i-1]<<" ";
            }
        }

        bool HaveNegative() const
        {
            if(p == NULL)
            {
                return false;
            }
            for(int i = 0 ; i<n ; i++)
            {
                for(int j = i ; j<n ; j++)
                {
                    if(p[i][j] < 0)
                        return true;
                }
            }
            return false;
        }

        void FindFirstEven() const
        {
            if(p != NULL)
            {
                for(int i = 0 ; i<n ; i++)
                {
                    for(int j = n - i - 1 ; j < n ; j++)
                    {
                        if( p[i][j] % 2 == 0)
                        {
                            cout<<"Gia tri chan dau tien nua duoi duong cheo phu la: ("<<i<<" , "<<j<<") co gia tri la: "<<p[i][j];
                            return;
                        }
                    }
                }
            }
            cout<<"Khong tim thay phan tu chan dau tien theo o nua duoi duong cheo phu";
        }

        void Sort()
        {
            if(p == NULL)
            {
                cout<<"Empty list\n";
                return;
            }
            int *temp = new int[n];
            for(int i = 0 ; i<n ; i++)
            {
                temp[i] = p[i][n-i-1];
            }
            sort(temp, temp+n, greater<int>());
            for(int i = 0 ; i<n ; i++)
            {
                p[i][n-i-1] = temp[i];
            }
            delete[] temp;
        }
};

void display_menu()
{
    cout << "------CHUONG TRINH XU LY MA TRAN VUONG------\n";
    cout << "1. Nhap ma tran\n";
    cout << "2. Phat sinh ma tran\n";
    cout << "3. Xuat ma tran\n";
    cout << "4. Xem kich thuoc ma tran hien tai\n";
    cout << "5. Thay doi kich thuoc ma tran\n";
    cout << "6. Liet ke cac phan tu le tren duong cheo chinh\n";
    cout << "7. Liet ke cac phan tu tan cung la 3 tren duong cheo phu\n";
    cout << "8. Kiem tra ma tran co chua so am hay khong\n";
    cout << "9. Tim phan tu chan dau tien o nua duoi duong cheo phu\n";
    cout << "10. Sap xep cac phan tu tren duong cheo phu giam dan\n";
    cout << "0. Thoat CT\n";
    cout << "--------------------------------------------\n";
}

void continue_prompt()
{
    cout << "Ban co muon tiep tuc khong (Yes, No)?: ";
    string confirm;
    do
    {
        cin >> confirm;
        if (confirm != "Yes" && confirm != "No")
            cout << "Canh bao! Nhap sai, nhap lai: ";
    } while (confirm != "Yes" && confirm != "No");
    if (confirm == "No")
    {
        cout << "Thoat chuong trinh thanh cong!\n";
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
    MTVUONG mt;
    while(1)
    {
        display_menu();
        int chon;
        cout<<"Lua chon cua ban la: ";
        do
        {
            cin>>chon;
            if(chon < 0 || chon > 10) cout<<"Lua chon khong hop le, nhap lai: ";
        } while (chon < 0 || chon > 10);
        
        switch(chon)
        {
            case 1:
            {
                mt.inp();
                break;
            }
            case 2:
            {
                mt.Phatsinh();
                break;
            }
            case 3:
            {
                mt.out();
                break;
            }
            case 4:
            {
                cout<<"Kich thuoc ma tran vuong hien tai la: "<<mt.Get_n()<<"\n";
                break;
            }
            case 5:
            {
                int val;
                cout<<"Nhap kich thuoc moi cho ma tran: ";
                cin>>val;
                mt.Set_n(val);
                cout<<"Da thay doi kich thuoc thanh cong!\n";
                break;
            }
            case 6:
            {
                cout<<"Cac phan tu le tren duong cheo chinh: ";
                mt.ListOdd();
                cout<<"\n";
                break;
            }
            case 7:
            {
                cout<<"Cac phan tu tan cung la 3 tren duong cheo phu: ";
                mt.ListLast3();
                cout<<"\n";
                break;
            }
            case 8:
            {
                if(mt.HaveNegative())
                    cout<<"Ma tran co chua so am.\n";
                else
                    cout<<"Ma tran KHONG chua so am.\n";
                break;
            }
            case 9:
            {
                mt.FindFirstEven();
                cout<<"\n";
                break;
            }
            case 10:
            {
                mt.Sort();
                cout<<"Da sap xep cac phan tu tren duong cheo phu giam dan!\n";
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