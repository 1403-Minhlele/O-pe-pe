#include <iostream>
using namespace std;

class MyList
{
private:
    int size;
    int *data;

    bool PerfectNumberTest(int n) const
    {
        if (n <= 1) return false;
        int sum = 1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                sum += i;
                if (i * i != n)
                {
                    sum += n / i;
                }
            }
        }
        return sum == n;
    }

public:
    MyList(int n = 0, int m = 0)
    {
        if (n < 0) n = 0;
        size = n;
        if (size > 0)
        {
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = m;
            }
        }
        else
        {
            data = NULL;
        }
    }

    MyList(const MyList& other)
    {
        size = other.size;
        if (size > 0)
        {
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        else
        {
            data = NULL;
        }
    }

    ~MyList()
    {
        if (data != NULL)
        {
            delete[] data;
            data = NULL;
        }
    }

    MyList& operator=(const MyList& other)
    {
        if (this != &other)
        {
            if (data != NULL)
            {
                delete[] data;
            }
            size = other.size;
            if (size > 0)
            {
                data = new int[size];
                for (int i = 0; i < size; i++)
                {
                    data[i] = other.data[i];
                }
            }
            else
            {
                data = NULL;
            }
        }
        return *this;
    }

    void nhap(istream& in)
    {
        if (data != NULL)
        {
            delete[] data;
            data = NULL;
        }
        cout << "Nhap so luong phan tu: ";
        in >> size;
        if (size < 0) size = 0;
        if (size > 0)
        {
            data = new int[size];
            cout << "Nhap cac phan tu: ";
            for (int i = 0; i < size; i++)
            {
                in >> data[i];
            }
        }
    }

    void xuat(ostream& out) const
    {
        if (size == 0 || data == NULL)
        {
            out << "[]";
        }
        else
        {
            out << "[";
            for (int i = 0; i < size; i++)
            {
                out << data[i];
                if (i < size - 1) out << ", ";
            }
            out << "]";
        }
    }

    friend istream& operator>>(istream& in, MyList& list)
    {
        list.nhap(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const MyList& list)
    {
        list.xuat(out);
        return out;
    }

    bool operator==(const MyList& other) const
    {
        if (size != other.size) return false;
        for (int i = 0; i < size; i++)
        {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    MyList operator+(const MyList& other) const
    {
        MyList result(size + other.size, 0);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = data[i];
        }
        for (int i = 0; i < other.size; i++)
        {
            result.data[size + i] = other.data[i];
        }
        return result;
    }

    MyList operator+(int val) const
    {
        return *this + MyList(val);
    }

    MyList& operator++()
    {
        int* newData = new int[size + 1];
        newData[0] = 0;
        for (int i = 0; i < size; i++)
        {
            newData[i + 1] = data[i];
        }
        if (data != NULL)
        {
            delete[] data;
        }
        data = newData;
        size++;
        return *this;
    }

    MyList operator--(int)
    {
        MyList temp(*this);
        if (size > 0)
        {
            int* newData = NULL;
            if (size - 1 > 0)
            {
                newData = new int[size - 1];
                for (int i = 0; i < size - 1; i++)
                {
                    newData[i] = data[i];
                }
            }
            if (data != NULL)
            {
                delete[] data;
            }
            data = newData;
            size--;
        }
        return temp;
    }

    bool CheckExistencePerfectNumberGreaterThanMinimum() const
    {
        if (size == 0 || data == NULL) return false;
        int minVal = data[0];
        for (int i = 1; i < size; i++)
        {
            if (data[i] < minVal)
            {
                minVal = data[i];
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] > minVal && PerfectNumberTest(data[i]))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    MyList list1, list2(2), list3(3, 6), list4(list3);

    cout << "List 1: " << list1 << "\nList 2: " << list2 << "\nList 3: " << list3 << "\nList 4: " << list4 << "\n";

    if (list3 == list4)
        cout << "List 3 is equal to list 4\n";
    else
        cout << "List 3 isn't equal to list 4\n";

    cout << "Enter new list 1 and list 2:\n";
    cin >> list1 >> list2;

    cout << "New list 1: " << list1 << "\nNew list 2: " << list2 << "\n";

    list3 = ++list1 + list2-- + 7;

    cout << "List 3: " << list3 << "\nList 2: " << list2 << "\nList 1: " << list1 << "\n";

    if (list3.CheckExistencePerfectNumberGreaterThanMinimum())
        cout << "List 3 contains an element whose value is a perfect number greater than the minimum value of all the elements.\n";

    return 0;
}