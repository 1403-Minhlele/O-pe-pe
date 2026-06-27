#include<bits/stdc++.h>
using namespace std;

class cMatrix;

class cVector
{
    private:
        int n;
        double *a;
    public:
        cVector(int n = 0);
        cVector(const cVector& orther);
        ~cVector();
        
        cVector& operator=(const cVector& p);
        
        void inp();
        void out() const;
        
        friend istream &operator>>(istream &in, cVector &v);
        friend ostream &operator<<(ostream &ou, const cVector &v);
        
        friend cVector operator*(const cMatrix& m, const cVector& v);
};

class cMatrix
{
    private:
        int r, c;
        double **mat;
    public:
        cMatrix(int r = 0, int c = 0);
        cMatrix(const cMatrix& orther);
        ~cMatrix();
        
        cMatrix& operator=(const cMatrix& orther);
        
        void inp();
        void out() const;
        
        friend istream &operator>>(istream &in, cMatrix &m);
        friend ostream &operator<<(ostream &ou, const cMatrix &m);
        
        friend cMatrix operator*(const cMatrix& m1, const cMatrix& m2);
        friend cVector operator*(const cMatrix& m, const cVector& v);
};

cVector::cVector(int n) : n(n)
{
    if (n <= 0)
    {
        this->n = 0;
        a = NULL;
    }
    else
    {
        a = new double[n];
        for(int i = 0; i < n; i++)
            a[i] = 0;
    }
}

cVector::cVector(const cVector& orther) : n(orther.n)
{
    if (n == 0) a = NULL;
    else
    {
        a = new double[n];
        for(int i = 0; i < n; i++) a[i] = orther.a[i];
    }
}

cVector::~cVector()
{
    if (a != NULL) delete[] a;
}

cVector& cVector::operator=(const cVector& p)
{
    if(this != &p)
    {
        delete[] a;
        this->n = p.n;
        if(n == 0) a = NULL;
        else
        {
            a = new double[n];
            for(int i = 0; i < n; i++) a[i] = p.a[i];
        }
    }
    return *this;
}

void cVector::inp()
{
    if (a != NULL) delete[] a;
    cout << "Nhap so chieu cua vector: ";
    do
    {
        cin >> n;
        if(n <= 0) cout << "So chieu phai > 0, nhap lai: ";
    } while (n <= 0);
    
    a = new double[n];
    cout << "Nhap toa do " << n << " thanh phan cua vector: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void cVector::out() const
{
    if (n == 0) cout << "()";
    else
    {
        cout << "(";
        for(int i = 0; i < n; i++)
        {
            cout << a[i];
            if (i < n - 1) cout << ", ";
        }
        cout << ")";
    }
}

istream &operator>>(istream &in, cVector &v)
{
    v.inp();
    return in;
}

ostream &operator<<(ostream &ou, const cVector &v)
{
    v.out();
    return ou;
}

cMatrix::cMatrix(int r, int c) : r(r), c(c)
{
    if (r <= 0 || c <= 0)
    {
        this->r = 0;
        this->c = 0;
        mat = NULL;
    }
    else
    {
        mat = new double*[r];
        for(int i = 0; i < r; i++)
        {
            mat[i] = new double[c];
            for(int j = 0; j < c; j++) mat[i][j] = 0;
        }
    }
}

cMatrix::cMatrix(const cMatrix& orther) : r(orther.r), c(orther.c)
{
    if (r == 0 || c == 0) mat = NULL;
    else
    {
        mat = new double*[r];
        for(int i = 0; i < r; i++)
        {
            mat[i] = new double[c];
            for(int j = 0; j < c; j++) mat[i][j] = orther.mat[i][j];
        }
    }
}

cMatrix::~cMatrix()
{
    if (mat != NULL)
    {
        for(int i = 0; i < r; i++) delete[] mat[i];
        delete[] mat;
    }
}

cMatrix& cMatrix::operator=(const cMatrix& orther)
{
    if(this != &orther)
    {
        if (mat != NULL)
        {
            for(int i = 0; i < r; i++) delete[] mat[i];
            delete[] mat;
        }
        this->r = orther.r;
        this->c = orther.c;
        if(r == 0 || c == 0) mat = NULL;
        else
        {
            mat = new double*[r];
            for(int i = 0; i < r; i++)
            {
                mat[i] = new double[c];
                for(int j = 0; j < c; j++) mat[i][j] = orther.mat[i][j];
            }
        }1
    }
    return *this;
}

void cMatrix::inp()
{
    if (mat != NULL)
    {
        for(int i = 0; i < r; i++) delete[] mat[i];
        delete[] mat;
    }
    
    cout << "Nhap so dong cua ma tran: "; cin >> r;
    cout << "Nhap so cot cua ma tran: "; cin >> c;
    
    if(r <= 0 || c <= 0)
    {
        r = c = 0;
        mat = NULL;
        return;
    }
    
    mat = new double*[r];
    for(int i = 0; i < r; i++)
    {
        mat[i] = new double[c];
        cout << "Nhap cac phan tu dong " << i + 1 << ": ";
        for(int j = 0; j < c; j++)
            cin >> mat[i][j];
    }
}

void cMatrix::out() const
{
    if (mat == NULL)
    {
        cout << "Ma tran rong\n";
        return;
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
}

istream &operator>>(istream &in, cMatrix &m)
{
    m.inp();
    return in;
}

ostream &operator<<(ostream &ou, const cMatrix &m)
{
    m.out();
    return ou;
}

cMatrix operator*(const cMatrix& m1, const cMatrix& m2)
{
    if(m1.c != m2.r)
    {
        cout << "\n[Loi] Kich thuoc khong the nhan (Cot M1 khac Dong M2)!\n";
        return cMatrix(); 
    }
    
    cMatrix res(m1.r, m2.c);
    for(int i = 0; i < m1.r; i++)
    {
        for(int j = 0; j < m2.c; j++)
        {
            res.mat[i][j] = 0;
            for(int k = 0; k < m1.c; k++)
            {
                res.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
            }
        }
    }
    return res;
}

cVector operator*(const cMatrix& m, const cVector& v)
{
    if(m.c != v.n)
    {
        cout << "\n[Loi] Kich thuoc khong the nhan (Cot Ma Tran khac So chieu Vector)!\n";
        return cVector();
    }
    
    cVector res(m.r);
    for(int i = 0; i < m.r; i++)
    {
        res.a[i] = 0;
        for(int j = 0; j < m.c; j++)
        {
            res.a[i] += m.mat[i][j] * v.a[j];
        }
    }
    return res;
}

void display_menu()
{
    cout << "------------------MENU------------------\n";
    cout << "1. Nhap thong tin Vector\n";
    cout << "2. Nhap thong tin Ma tran 1\n";
    cout << "3. Nhap thong tin Ma tran 2\n";
    cout << "4. Xuat thong tin cac doi tuong hien tai\n";
    cout << "5. Tinh tich 2 Ma tran (Ma tran 1 * Ma tran 2)\n";
    cout << "6. Tinh tich Ma tran va Vector (Ma tran 1 * Vector)\n";
    cout << "0. Thoat\n";
    cout << "----------------------------------------\n";
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
    cVector vec;
    cMatrix mat1, mat2;
    
    while(1)
    {
        display_menu();
        int key;
        cout << "Nhap su lua chon cua ban: ";
        do
        {
            cin >> key;
            if(key < 0 || key > 6) cout << "Lua chon khong hop le, vui long chon lai: ";
        } while (key < 0 || key > 6);
        
        switch(key)
        {
            case 0: 
                exit(0);
            case 1:
            {
                cout << "--- NHAP VECTOR ---\n";
                cin >> vec;
                break;
            }
            case 2:
            {
                cout << "--- NHAP MA TRAN 1 ---\n";
                cin >> mat1;
                break;
            }
            case 3:
            {
                cout << "--- NHAP MA TRAN 2 ---\n";
                cin >> mat2;
                break;
            }
            case 4:
            {
                cout << "--- THONG TIN HIEN TAI ---\n";
                cout << "Vector:\n" << vec << "\n\n";
                cout << "Ma tran 1:\n" << mat1 << "\n";
                cout << "Ma tran 2:\n" << mat2 << "\n";
                break;
            }
            case 5:
            {
                cout << "--- TICH HAI MA TRAN ---\n";
                cMatrix ans_mat = mat1 * mat2;
                cout << "Ket qua (Ma tran 1 * Ma tran 2):\n";
                cout << ans_mat << "\n";
                break;
            }
            case 6:
            {
                cout << "--- TICH MA TRAN VA VECTOR ---\n";
                cVector ans_vec = mat1 * vec;
                cout << "Ket qua (Ma tran 1 * Vector):\n";
                cout << ans_vec << "\n\n";
                break;
            }
        }
        continue_prompt();
    }
    return 0;
}