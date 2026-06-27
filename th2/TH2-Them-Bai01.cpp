#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define fi first
#define se second

class Point{
    private:
        double x, y;
    public:
        Point(double x = 0 , double y = 0): x(x) , y(y) {};
        void inp(){
            cin>>x>>y;
        }

        void out(){
            cout<<"("<<x<<", "<<y<<")\n";
        }

        bool checking(Point p) {
            return (abs(x - p.x) < 1e-9 && abs(y - p.y) < 1e-9);
        }

        void move_point(double dis_x, double dis_y){
            x += dis_x;
            y += dis_y;
        }
        
        double ditance(Point p){
            double tmp = (p.x - x)*(p.x - x) + (p.y - y)*(p.y - y);
            tmp = sqrt(tmp);
            return tmp;
        }
        
        int check_tri(Point b, Point c){
            double A, B, C;
            A = ditance(b);
            B = b.ditance(c);
            C = ditance(c);
            if(A + B <= C || B + C <= A || A + C <= B) return 0;
            else
            {
                if(abs(A - B) < 1e-9 && abs(B - C) < 1e-9 && abs(A - C) < 1e-9) return 1;
                else if(abs(A - B) < 1e-9 || abs(B - C) < 1e-9 || abs(A - C) < 1e-9)
                {
                    if(abs(A*A + B*B - C*C) < 1e-9 || abs(A*A + C*C - B*B) < 1e-9 || abs(B*B + C*C - A*A) < 1e-9)
                        return 2;
                    else return 3;
                }
                else
                {
                    if(abs(A*A + B*B - C*C) < 1e-9 || abs(A*A + C*C - B*B) < 1e-9 || abs(B*B + C*C - A*A) < 1e-9)
                        return 4;
                    else return 5;
                }
            }
        }

        Point point_of_symmetry()
        {
            return Point((x == 0)? 0 : -x, (y == 0)? 0 : -y); 
        }

        double Perimeter(Point b, Point c);
        double Area(Point b, Point c);
        void classify(Point b, Point c);
};

double Point::Perimeter(Point b, Point c)
{
    double A, B, C;
    A = ditance(b);
    B = b.ditance(c);
    C = ditance(c);
    return A + B + C;
}

double Point::Area(Point b, Point c)
{
    double p = Perimeter(b, c); p/=2.0;
    double A, B, C;
    A = ditance(b);
    B = b.ditance(c);
    C = ditance(c);
    double area = p*(p - A)*(p - B)*(p - C);
    area = sqrt(area);
    return area; 
}

void Point::classify(Point b, Point c)
{
    int key = check_tri(b, c);
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

int main()
{
    Point a, b, c;
    cout<<"Nhap toa do diem A: "; a.inp();
    cout<<"Nhap toa do diem B: "; b.inp();
    cout<<"Nhap toa do diem C: "; c.inp();
    
    cout<<"Toa do diem A la: "; a.out();
    cout<<"Toa do diem B la: "; b.out();
    cout<<"Toa do diem C la: "; c.out();

    cout<<"Nhap luong dx, dy de di chuyen diem A: "; double dx, dy; cin>>dx>>dy;
    a.move_point(dx, dy);

    cout<<"Toa do diem A sau khi di chuyen la: "; a.out();

    if(a.checking(b)) cout<<"Diem A va B trung nhau\n";
    else cout<<"Diem A va B khong trung nhau\n";

    Point sym_a = a.point_of_symmetry();
    cout<<"Diem doi xung cua A qua goc toa do la: "; sym_a.out();

    cout<<"Khoang cach tu A den B la: "<<a.ditance(b)<<"\n";
    cout<<"Khoang cach tu A den C la: "<<a.ditance(c)<<"\n";
    cout<<"Khoang cach tu B den C la: "<<b.ditance(c)<<"\n";
    a.classify(b, c);
    int key = a.check_tri(b, c);
    if(key != 0){
        cout<<"Chu vi tam giac ABC la: "<<a.Perimeter(b, c)<<"\n";
        cout<<"Dien tich tam giac ABC la: "<<a.Area(b, c)<<"\n";
    }
    else cout<<"Khong co chu vi va dien tich\n";
    // cout<<"Chu vi tam giac ABC la: "<<a.Perimeter(b, c)<<"\n";
    // cout<<"Dien tich tam giac ABC la: "<<a.Area(b, c)<<"\n";

    return 0;
}
