
#include <iostream>
#include <vector>
#include <iomanip>
#include <list>



using namespace std;
/*
Task 1 - в мейне.

Написать функцию, добавляющую в конец списка вещественных чисел элемент,
значение которого равно среднему арифметическому всех его элементов.
*/

/*
Task 2:

Создать класс, представляющий матрицу.
Реализовать в нем метод, вычисляющий определитель матрицы.
*/


class Matrix
{
    vector<vector<int>>data;
    unsigned int size;

public:
    Matrix(unsigned int size) : size(size)
    {
        data.reserve(size);
        for (int j = 0; j < size; j++)
        {
            vector<int> a;
            data.push_back(a);
            data[j].reserve(size);
            for (int d = 0; d < size; d++)
            {
                data[j].push_back(rand() % 66);
            }
        }
    };
    ~Matrix() = default;

    void getMatrixWithoutRowAndCol(vector<vector<int>>* matrix, int sizet, int row, int col, vector<vector<int>>* newMatrix) {
        int offsetRow = 0;
        int offsetCol = 0;
        for (int i = 0; i < sizet - 1; i++) {

            if (i == row) {
                offsetRow = 1;
            }

            offsetCol = 0;
            for (int j = 0; j < sizet - 1; j++) {

                if (j == col) {
                    offsetCol = 1;
                }
                (*newMatrix)[i].push_back((*matrix)[i + offsetRow][j + offsetCol]);
            }
        }
    }

    int matrixDet(vector<vector<int>> matrix, int sizet) {
        int det = 0;
        int degree = 1;

        if (sizet == 1) {
            return matrix[0][0];
        }

        else if (sizet == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        else {

            vector<vector<int>> newMatrix;
            for (int i = 0; i < sizet - 1; i++) {
                vector<int> a;
                newMatrix.push_back(a);
            }

            for (int j = 0; j < sizet; j++) {

                getMatrixWithoutRowAndCol(&matrix, sizet, 0, j, &newMatrix);

                det = det + (degree * matrix[0][j] * matrixDet(newMatrix, sizet - 1));

                degree = -degree;
            }
        }

        return det;
    }

    void Print()
    {
        cout <<"Матрица:";
        for (int i = 0; i < size; ++i)
        {
            
            for (int j = 0; j < size; ++j)
                cout <<setw(4) << data[i][j];
        }      
        cout << "\n"<< "Детерменант: " << matrixDet(data, size) << " " << endl;
    }

};
/*
 Task 3 
 Реализовать собственный класс итератора, с помощью которого
 можно будет проитерироваться по диапазону целых чисел в цикле for-range-based.
*/
template <typename T>
class DemoArrey
{
    T* arr;
    int one;
 
public:
    
    class Iterator;
    
    DemoArrey(int x = 1) : one(x)
    {
        arr = new T[x];
    }
 

    T& operator[] (const int& x)
    {
        if (x > 0 && x < one)
            return arr[x];
            return arr[0];
    }
    Iterator begin()
    {
        return arr;
    }
    Iterator end()
        {
           return arr + one;
        }
    friend ostream& operator << (ostream & y, const DemoArrey<T>& x);
    class Iterator
    {
        T* objeckt;
       
    public:
       Iterator(T* test) : objeckt(test) {}
       
        T& operator + (int x)
        {
            return *(objeckt + x);
        }

        T& operator - (int x)
        {
            return *(objeckt - x);
        }

        T& operator ++ (int)
        {
            return *objeckt++;
        }

        T& operator -- (int)
        {
            return *objeckt--;
        }

        T& operator ++ ()
        {
            return *++objeckt;
        }

        T& operator -- ()
        {
            return *--objeckt;
        }

        bool operator != (const Iterator& it)
        {
            return objeckt != it.objeckt;
        }

        bool operator == (const Iterator& it)
        {
            return objeckt == it.objeckt;
        }

        T& operator* ()
        {
            return *objeckt;
        }

    };

};

template<typename T>
ostream& operator << (ostream& y, const DemoArrey<T>& x)
{
    y << DemoArray<T>::arr[x];
    return y;
}


int main()
{
    // Task 1:
    setlocale(LC_ALL, "rus");
    {
        vector<double> add{ 17.4, 24.3, 32.6, 43.1, 51.5, 66.6 };

        double middle = 0.0;
        for (int i = 0; i < add.size(); i++) middle += add[i];
        middle = middle / add.size();
        cout << "Задание 1\n" << "Среднее арифметическое всех элементов = " << middle << endl;
        add.push_back(middle);
        cout << "Добавляем последний элемент в конец списка вещественных чисел: ";
        for (vector<double>::const_iterator i = add.begin(); i != add.end(); ++i)
            cout << *i << ' ';
        cout << endl;
    }

    // Task 2:

    {
        cout << "\nЗадание 2" << endl;

        int size = 3;
        Matrix mat(size);
        mat.Print();
    }

    // Task 3

    {
        cout << "\nЗадание 3\n";

        DemoArrey <int> arr(16);

        arr[0] = 1, arr[1] = 55, arr[2] = 112, arr[3] = 388, arr[4] = 9999,

        arr[5] = 66, arr[6] = 777, arr[7] = 14221, arr[8] = 21, arr[9] = 17,

        arr[10] = 95, arr[11] = 123, arr[12] = 73, arr[13] = 144, arr[14] = 150; arr[15] = 546;
      
        auto it = DemoArrey <int>::Iterator(arr.begin());

        cout << "Итератор проитерироваться в цикле for-range-based и остановился на элементе: ";
        cout << it + (5 - 2 + 4 - 1) << endl; // в данном случае 777 
        cout << "Диапазон целых чисел: ";
        for (auto i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }
  
    return 0;
};