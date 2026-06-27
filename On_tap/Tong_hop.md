<center>
    <h1>
        Tổng hợp kiến thức OOP
    </h1>
</center>
Author: Lê Vũ Khánh Minh - ATTT2025.2

> Tài liệu này tóm tắt 16 ý quan trọng trong OOP theo kiểu dễ học, dễ ôn và phù hợp để chép lại trước kỳ thi.
> Các ví dụ code dùng **C++** và có tô màu cú pháp khi mở bằng Markdown viewer hỗ trợ.

---

## Mục lục

1. [Các đặc điểm quan trọng của OOP](#1-các-đặc-điểm-quan-trọng-của-oop)
2. [Đối tượng hằng và phương thức hằng](#2-đối-tượng-hằng-và-phương-thức-hằng)
3. [Thuộc tính static và phương thức static](#3-thuộc-tính-static-và-phương-thức-static)
4. [Hàm thiết lập và hàm hủy](#4-hàm-thiết-lập-và-hàm-hủy)
5. [Hàm truy vấn và hàm cập nhật](#5-hàm-truy-vấn-và-hàm-cập-nhật)
6. [Phương thức thiết lập sao chép](#6-phương-thức-thiết-lập-sao-chép)
7. [Hàm toán tử gán](#7-hàm-toán-tử-gán)
8. [Nạp chồng toán tử](#8-nạp-chồng-toán-tử)
9. [Con trỏ this](#9-con-trỏ-this)
10. [Hàm bạn](#10-hàm-bạn)
11. [Lớp bao](#11-lớp-bao)
12. [Quan hệ Has-A, Is-A](#12-quan-hệ-has-a-is-a)
13. [Các loại thừa kế](#13-các-loại-thừa-kế)
14. [Phạm vi truy xuất](#14-phạm-vi-truy-xuất)
15. [Phương thức ảo(Virtual function) và Đa hình](#15)
16. [Lớp trừu tượng, hàm thuần ảo](#16-Lớp-trừu-tượng-hàm-thuần-ảo)

---

## 1) Các đặc điểm quan trọng của OOP

- **Đóng gói (Encapsulation)**: che giấu dữ liệu, thông tin nội bộ thông qua thuộc tính **_private_**, chỉ cho truy cập thông qua hàm thành viên, hoặc phương thức công khai **_public_**.

```cpp
class Sinhvien
{
    private:
        string name, MSSV;
        int Diem;
        // ---> Đây là biểu diễn cho tính đóng gói
        // Tính đóng góp không chỉ thể hiện qua các biến mà các hàm thành viên cũng có thể set private
    public: // ---> Đây là phương thức để truy cập các biến private của lớp.
        string Get_MSSS()
        {
            return MSSS;
        }

        void Set_Diem(int New_diem)
        {
            Diem = New_diem;
        }
};

int main()
{
    Sinhvien A;
    cout<< A.MSSS; // BUG
}
```

- **Trừu tượng (Abstraction)**: Là một kỹ thuật lập trình và thiết kế dựa trên sự tách biệt giữa **Giao diện** và **Thực thi**. Chỉ thể hiện những gì cần thiết, ẩn phần cài đặt.
- **Kế thừa (Inheritance)**: lớp con dùng lại thuộc tính và phương thức của lớp cha. Giúp tái sử dụng mã nguồn một cách linh hoạt.
- **Đa hình (Polymorphism)**: Cùng một phương thức nhưng có thể thực hiện những hành vi khác nhau tùy thuộc vào đối tượng đang gọi nó (thường thông qua hàm ảo virtual).

```cpp
class Animal{
    private:
        string name;
    public:
        virtual void AmThanh() = 0; // Tính đa hình, ở đây hàm thuần ảo này quy định rằng động vật chỉ biết kêu, tuy nhiên chưa biết kêu như nào
};
class Cho: public Animal{ // Tính kế thừa, lớp con (class Chó) kế thừa thuộc tính và phương thức của lớp cha (class Animal)
    private:
        string thuc_an;
        int old;
    public:
        void Amthanh() override {
            cout<<"Gau Gau";
        }
};
```

---

## 2) Đối tượng hằng và phương thức hằng

> ❗Dùng `const` để bảo đảm hàm không làm thay đổi trạng thái đối tượng.

- **Đối tượng hằng**: Là các đối tượng mà các giá trị thuộc tính của nó sau khi khởi tạo không được phép thay đổi.
- **Phương thức hằng**: Là phương thức cam kết không làm thay đổi các giá trị, thuộc tính nào lớp. Đối tượng hằng chỉ có thể gọi bằng phương thức hằng.

```cpp
class ToaDo {
private:
    int x, y;
public:
    ToaDo(int x, int y) : x(x), y(y) {} // Đây là thể hiện tính đóng gói và constructor giúp truy cập và set nhanh giá trị từ lúc khởi tạo
    void inToaDo() const { cout << x << " " << y; } // Phương thức hằng
    void setX(int val) { x = val; } // Không phải phương thức hằng
};

int main() {
    const ToaDo diemA(1, 2); // Đối tượng hằng
    diemA.inToaDo(); // Hợp lệ
    // diemA.setX(5); // Lỗi biên dịch vì diemA là hằng
}
```

---

## 3) Thuộc tính static và phương thức static

> ❗ `static` thuộc về **lớp**, không thuộc riêng từng đối tượng.

- **Thuộc tính static**: Là biến dùng chung cho mọi đối tượng của lớp. Tồn tại duy nhất 1 bản sao trong bộ nhớ. Khi sử dụng phương thức này, tưởng tượng nó là kiểu biến cục bộ, và dùng chung cho mọi đối tượng và thuộc tính. Khi thay đổi giá trị của biến này thì các đối tượng khác dùng chung biến này cũng sẽ thay đổi theo.
- **Phương thức static**: Có thể được gọi trực tiếp thông qua tên lớp mà không cần tạo đối tượng. Phương thức static chỉ có thể truy cập các thuộc tính/phương thức static khác.

```cpp
class SinhVien {
private:
    static int soLuong; // Thuộc tính static
public:
    SinhVien() { soLuong++; }
    static int getSoLuong() { return soLuong; } // Phương thức static
};
int SinhVien::soLuong = 0; // Khởi tạo

int main() {
    SinhVien sv1, sv2;
    cout << SinhVien::getSoLuong(); // Kết quả: 2 (gọi không cần đối tượng)
}
```

---

## 4) Hàm thiết lập và hàm hủy

- **Constructor**: Tự động gọi khi đối tượng được tạo ra. Dùng để khởi tạo giá trị ban đầu hoặc cấp phát vùng nhớ. **_Cùng tên với lớp, không có kiểu trả về_**.
- **Destructor**: Tự động gọi khi đối tượng bị hủy (kết thúc hàm/khối lệnh hoặc bị delete). Dùng để dọn dẹp bộ nhớ. Có dấu `~` trước tên lớp.

❗**LƯU Ý: Với phương thức hủy mà đối tượng có sử dụng mảng con trỏ thì phải viết hàm delete con trỏ và truyền vào hàm hủy. Khi lớp của bạn có sử dụng kế thừa và đa hình (có hàm virtual), hàm hủy của lớp cha bắt buộc phải là hàm hủy ảo (virtual ~TenLop()). Nếu không, khi bạn delete một con trỏ lớp cha đang trỏ đến đối tượng lớp con, trình biên dịch sẽ chỉ gọi hàm hủy của lớp cha mà bỏ qua hàm hủy của lớp con, dẫn đến rò rỉ bộ nhớ (Memory Leak).**.

```cpp
class A {
    private:
        string name;
        int *Favor;
    public:
        A(string a = "") : name(a){
            Favor = new int[1000];
        }

        ~A() {
            cout << "Huy\n";
            delete[] Favor; // với các kiểu dữ liệu con trỏ, mảng động thì cần phải viết riêng hàm hủy
        }
};
```

---

## 5) Hàm truy vấn và hàm cập nhật

- **Hàm truy vấn(Get)**: Dùng để đọc dữ liệu được đóng gói của đối tượng. Không làm thay đổi dữ liệu của đối tượng.
- **Hàm cập nhật(Set)**: Dùng để thay đổi dữ liệu của đối tượng đó, mục đích thay đổi giá trị của dữ liệu bị đóng góp của

```cpp
class Person {
    string name;
public:
    string getName() const { // dùng phương thức hằng để đảm bảo không làm thay đổi dữ liệu
        return name;
    }

    void setName(string n) {
        name = n;
    }
};
```

---

## 6) Phương thức thiết lập sao chép

- **Phương thức thiết lập sao chép**: Là hàm dùng để khởi tạo một đối tượng mới bằng cách sao chép dữ liệu từ dữ liệu của một đối tượng đã tồn tại cùng kiểu. Nếu lớp con trỏ, phải tự định nghĩa để copy sâu tránh lỗi cùng bộ nhớ.

```cpp
class Point {
    int x, y;
    int *list_data;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {
        list_data = new int[1000];
    } // ---> thiết lập dữ liệu

    Point(const Point& p) {
        x = p.x;
        y = p.y;
        // Ở đây mảng con trỏ list_data không thể trực tiếp sao chép nên ta phải tự code hàm sao chép
        list_data = new int[1000];
        for(int i = 0 ; i < 1000 ; i++)
            list_data[i] = p.list_data[i];
    }
};
```

- ### Tham số đầu vào phải là tham chiếu

```cpp
class A{
    private:
        int old;
    public:
        A(int old = 0): old(old){}
        A(const A& temp)
        {
            old = temp.old;
        }
};
```

- Nếu tham số đầu vào không phải là tham chiếu thì trình biên dịch sẽ hiểu theo kiểu `const temp = a;`. Mà chẳng hạn ta truyền b vào hàm sao chép đó thì tức là: a sao chép b, temp sao chép a, như vậy sẽ dẫn đến việc 1 **_vòng lặp vô hạn_** lời gọi hàm sao chép.

---

## 7) Hàm toán tử gán

- Nguyên lí khá giống với hàm thiết lập sao chép. Tuy nhiên, ta sẽ cài đặt và giúp đối tượng hiểu và dùng được phép gán = . Hàm đa năng hóa toán tử gán chỉ có thể được định nghĩa dưới dạng phương thức của lớp
- Nếu lớp có sử dụng cấp phát bộ nhớ động (con trỏ new), hàm toán tử gán ngoài việc kiểm tra tự gán if (this != &p), còn bắt buộc phải giải phóng (delete) vùng nhớ hiện tại của đối tượng trước khi cấp phát và sao chép vùng nhớ mới từ p sang.

### Lưu ý: tham số đầu vào phải là tham chiếu.

```cpp
class Point {
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}

    Point& operator=(const Point& p) {
        if (this != &p) {
            x = p.x;
            y = p.y;
        }
        return *this;
    }
};
```

---

## 8) Nạp chồng toán tử

- **Nạp chồng toán tử (Overload operator)** là cách định nghĩa lại toán tử đã có trên kiểu dữ liệu người dùng tự định nghĩa để dễ dàng thực hiện câu lệnh của chương trình.
- **Cú pháp: _operator@_** với @ là các toán tử. Có 2 loại hàm là hàm cục bộ(dùng chính phương thức của lớp) và hàm toàn cục(dùng hàm friend)
- Thường gặp với `+`, `-`, `*`, `/`, `<<`, `>>`, `=`.
- ### Lưu ý: Với kiểu trả về, cần phân biệt lúc nào cần sử dụng tham chiếu, lúc nào không cần sử dụng tham chiếu, lúc nào cần.
- #### KHÔNG dùng & (Trả về giá trị - Pass by Value): Dùng cho các toán tử sinh ra một đối tượng hoàn toàn mới bên trong hàm (Ví dụ: +, -, \*, /). Nếu trả về & sẽ bị lỗi vì đang trỏ đến một biến cục bộ sắp bị hủy.

- #### CÓ dùng & (Trả về tham chiếu - Pass by Reference): Dùng cho các toán tử cập nhật, thay đổi giá trị của chính đối tượng đã tồn tại sẵn (Ví dụ: =, +=, -=, ++a, cin >>, cout <<). Phải trả về & để tránh copy dư thừa và cho phép gán liên hoàn (VD: A = B = C;).

```cpp
class PhanSo {
    int tu, mau;
public:
    PhanSo(int t = 0, int m = 1) : tu(t), mau(m) {}

    PhanSo operator+(const PhanSo& p) const {
        return PhanSo(tu * p.mau + p.tu * mau, mau * p.mau);
    } // hàm này không cần sử dụng tham chiếu bởi vì sau khi thực hiện phép cộng sẽ tạo ra một biến ảo MỚI
};
```

- **Chuyển kiểu:** có 2 loại chuyển kiểu: chuyển kiểu theo contructor và chuyển kiểu theo toán tử chuyển kiểu

### Chuyển kiểu theo contructor

- Tương tự hàm thiết lập mặc định, phương thức chuyển kiểu bằng contructor sử dụng tên là tên của lớp với tham số đầu vào là kiểu dữ liệu cần chuyển kiểu
- VD: cần chuyển kiểu từ `int` về `Phanso` để thực hiện toán tử cộng mà không cần khai báo thêm nhiều hàm định nghĩa.

```cpp
class Phanso{
    private:
        int tu, mau;
    public:
        Phanso(int tu = 0, int mau = 1): tu(tu), mau(mau){}
        Phanso(int val){
            tu = val;
            mau = 1;
        }
        friend Phanso operator+(const Phanso& ps1, const Phanso& ps2){
            Phanso ans;
            ans.tu = ps1.tu*ps2.mau + ps1.mau*ps2.tu;
            ans.mau = ps1.mau*ps2.mau;
            return ans;
        }
};
```

- Lúc này ta chỉ cần `a = b + 1 hoặc a = 1 + b hoặc a = b + c` mà không cần khai bao từng phương thức toán tử cho từng tham số đầu vào. Cách này còn dùng được cho các toán tử khác.

### Chuyển kiểu bằng toán tử chuyển kiểu ( Ít ứng dụng hơn)
```cpp
/* cú pháp operator Kieu_DL_can_chuyen(){
    Doing something here to change type of variable
}*/

class Phanso{
    private:
        int tu, mau;
    public:
        // Phuong thuc thiep lap
        operator float()
        {
            return (float)this -> tu / this -> mau;
        }
};

```
---

## 9) Con trỏ this

- **Con trỏ this** là một **_con trỏ hằng_** được chương trình tự định nghĩa bên trong một phương thức, nó sẽ giữ địa chỉ của đối tượng đang gọi thực hiện phương thức đó. Để đơn giản thì khi sử dụng 1 biến/phương thức, để phân biệt với các biến của hàm và đối tượng thì ta sẽ sử dụng con trỏ this. Tuy nhiên, trình biên dịch hiện tại có khả năng tự nhận diện mà không cần dùng tới con trỏ this.

```cpp
class A {
    int x;
public:
    void setX(int x) {
        this->x = x;
    }
};
```

---

## 10) Hàm bạn

- Là hàm không phải thành viên lớp nhưng vẫn truy cập được `private` và `protected`. Là mối quan hệ 1 chiều, tức là lớp bạn có thể truy cập vào thành phần lớp này nhưng không có nghĩa lớp này có thể truy cập vào thành phần của lớp bạn.
- Thường dùng cho `operator<<` và `operator>>`.

```cpp
class A {
    int x;
public:
    A(int a = 0) : x(a) {}
    friend void show(const A& a);
};

void show(const A& a) {
    cout << a.x << endl;
}
```

---

## 11) Lớp bao

- Lớp bao là lớp sử dụng một hoặc nhiều đối tượng của lớp khác làm thuộc tính để xây dựng một đối tượng mới.

```cpp
// Lớp bao là kỹ thuật sử dụng đối tượng của một hoặc nhiều lớp khác
// làm thuộc tính (data member) bên trong một lớp mới.
class DongCo {
    // ... chi tiết động cơ
};

class XeOto {
private:
    DongCo dc; // XeOto là lớp bao, nó "bao bọc" đối tượng DongCo bên trong
public:
    void KhoiDong() { /* ... */ }
};

```

---

## 12) Quan hệ Has-A, Is-A

- **Has-A**: quan hệ sở hữu, chứa đối tượng khác làm thành phần.
- **Is-A**: quan hệ kế thừa, lớp con là một dạng của lớp cha.

```cpp
class Engine {};

class Car {
    Engine engine;   // Has-A
};

class Animal {};

class Dog : public Animal {   // Is-A
};
```

---

## 13) Các loại thừa kế

> [!NOTE]
> Các kiểu thừa kế thường gặp: đơn, đa cấp, phân cấp, đa thừa kế, lai.

```cpp
class A {};
class B : public A {};
class C : public B {};
class D : public A {};
class E : public A, public B {};
```

- **Đơn thừa kế**: 1 lớp cha, 1 lớp con.
- **Đa cấp**: A -> B -> C.
- **Phân cấp**: 1 lớp cha, nhiều lớp con.
- **Đa thừa kế**: 1 lớp con có nhiều lớp cha.
- **Lai**: kết hợp nhiều kiểu trên.

---

## 14) Phạm vi truy xuất

- **Theo chiều dọc**: truy xuất trong quan hệ kế thừa giữa lớp cha và lớp con.
- **Theo chiều ngang**: truy xuất giữa các đối tượng hoặc lớp cùng mức.

```cpp
class Base {
protected:
    int x;
public:
    int y;
};

class Derive : public Base {
public:
    void f() {
        x = 1;
        y = 2;
    }
};
```

---

## 15) Phương thức ảo(Virtual function) và Đa hình

- **Lớp dẫn xuất được kế thừa** các phương thức đã có ở lớp cơ sở, tuy nhiên phương thức của chúng **_có thể tinh chỉnh_** để phù hợp với lớp dẫn xuất. Như vậy, ta cần định nghĩa lại một phiên bản khác cho các phương thức đó bằng **_phương thức ảo(Virtual function) xây dựng trên lớp cơ cở_** và **_overide(ghi đè) ngay tại lớp dẫn xuất_**

❗ ĐIỀU KIỆN KÍCH HOẠT: Tính đa hình (Polymorphism) chỉ xảy ra khi ta gọi phương thức ảo thông qua Con trỏ (Pointer) hoặc Tham chiếu (Reference) của lớp cơ sở đang trỏ/tham chiếu đến đối tượng của lớp dẫn xuất. Nếu gán bằng giá trị thông thường (Pass by value), tính đa hình sẽ bị mất (hiện tượng Object Slicing).

```cpp
void print(int x);
void print(double x);

class A {
public:
    virtual void show() {
        cout << "A\n";
    }
};

class B : public A {
public:
    void show() override {
        cout << "B\n";
    }
};
```

## 16) Lớp trừu tượng, hàm thuần ảo

- **Lớp trừu tượng** là một loại lớp đặt biệt vì ta không thể khởi tạo các đối tượng của lớp này. Mục địch của lớp này là tạo ra 1 khuôn mẫu để lớp dẫn xuất kế thừa, cung cấp 1 khuôn mẫu và giao diện chung cho các lớp con đó.
- Để nó trở thành 1 lớp trừu tượng thì cần ít nhất 1 phương thức thuần ảo. **Phương thức thuần ảo** là phương thức ảo **không nhất thiết phải được định nghĩa**.
- Cú pháp ` virtual type_function name_function() = 0;`

```cpp
#include<bits/stdc++.h>
using namespace std;

class HinhHoc
{
    public:
        virtual ~HinhHoc() {}
        virtual double TinhDienTich() const = 0;
};

class HinhVuong : public HinhHoc
{
    private:
        double canh;

    public:
        HinhVuong(double c = 0) : canh(c) {}

        double TinhDienTich() const override
        {
            return canh * canh;
        }
};

class HinhTron : public HinhHoc
{
    private:
        double banKinh;

    public:
        HinhTron(double r = 0) : banKinh(r) {}

        double TinhDienTich() const override
        {
            return 3.14159 * banKinh * banKinh;
        }
};

int main()
{
    // HinhHoc h; // LOI COMPILER: Khong the khoi tao doi tuong tu lop truu tuong

    HinhHoc* h1 = new HinhVuong(5.0);
    HinhHoc* h2 = new HinhTron(3.0);

    cout << "Dien tich hinh vuong: " << h1->TinhDienTich() << "\n";
    cout << "Dien tich hinh tron: " << h2->TinhDienTich() << "\n";

    delete h1;
    delete h2;

    return 0;
}
```

---
