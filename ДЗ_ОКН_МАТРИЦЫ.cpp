#include <iostream>
#include <ctime>
using namespace std;

void rand_array(int** mas, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            mas[i][k] = rand()%10;
        }
    }
}

void print_array(int** mas, int n, int m) {
    for (int i = 0; i < n;i++) {
        for (int k = 0; k < m; k++) {
             cout<< mas[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void one(int** mas, int n, int m) {
    cout<< "Первая задача:"<< endl;
    int i1=0, k1=0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (mas[i][k] < mas[i1][k1]) {
                i1 = i;
                k1 = k;
            }
        }
    }
    int n1=n-1, m1=m-1;
    int** array = new int* [n1];
    for (int i = 0; i < n1; i++) {
        array[i] = new int[m1];
    }
    for (int i = 0; i < n1; i++) {
        for (int k = 0; k < m1; k++) {
            if ((i < i1) && (k < k1)) {
                array[i][k] = mas[i][k];
            }
            if ((i >= i1) && (k < k1)) {
                array[i][k] = mas[i + 1][k];
            }
            if ((i < i1) && (k >= k1)) {
                array[i][k] = mas[i][k + 1];
            }
            if ((i >= i1) && (k >= k1)) {
                array[i][k] = mas[i + 1][k + 1];
            }
        }
    }
    print_array(array, n1, m1);
    cout <<"Минимальный элемент находится в: " << i1 << " " << k1<< endl;
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
}

void two(int** mas, int n) {
    cout << "Вторая  задача:" << endl;
    cout << "Вторая матрица:" << endl;
    int** array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[n];
    }
    rand_array(array, n, n);
    print_array(array, n, n);
    int** matr = new int* [n];
    for (int i = 0; i < n; i++) {
        matr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            matr[i][j] = 0;
            for (int z = 0; z < n; z++)
                matr[i][j] = matr[i][j] + mas[i][z] * array[z][j];
        }
    cout << "Результат умножения матриц:" << endl;
    print_array(matr, n, n);
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
    for (int i = 0; i < n; i++) {
        delete[] matr[i];
    }
    delete[] matr;
}

void three(int** mas, int n, int m) {
    cout << "Третья задача:" << endl;
    int** array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            array[i][k] = mas[n-i-1][m-k-1];
        }
    }
    cout << "Перевёрнутый массив:" << endl;
    print_array(array, n, m);
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
}

void four(int** mas, int n) {
    cout << "Четвёртая задача:" << endl;
    int i0=0, k0=0;
    cout << "Квадратная матрица:" << endl;
    print_array(mas, n, n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (mas[i][k] < mas[i0][k0]) {
                i0 = i;
                k0 = k;
            }
        }
    }
    cout << "Минимальный элемент находится в: " << i0 << " " << k0 << endl;
    int c;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (i != i0 && k != k0)
            {
                c = mas[i][k0];
                mas[i][k0] = mas[i0][k];
                mas[i0][k] = c;
            }
        }
    }
    cout << "Итог:" << endl;
    print_array(mas, n, n);
}

void five(int** mas, int n, int m) {
    cout << "Пятая задача:" << endl;
    int max = 0, min=0, max1=0;
    for (int i = 1; i < m; i++) {
        if (mas[0][i] > mas[0][max]) {
            max = i;
        }
    }
    for (int k=1; k < n; k++) {
        for (int i = 0; i < m; i++) {
            if (mas[k][i] < mas[k][min]) {
                min = i;
            }
            if (mas[k][i] > mas[k][max1]) {
                max1 = i;
            }
        }
        mas[k][min] = mas[k-1][max];
        max = max1;
    }
    cout << "Итог:" << endl;
    print_array(mas, n, m);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int n, m;
    cin >> n >> m;
    int** mas = new int* [n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[m];
    }
    rand_array(mas, n, m);
    cout << "Изначальный массив"<< endl;
    print_array(mas, n, m);
    one(mas, n, m);
    two(mas, min(n, m));
    three(mas, n, m);
    four(mas, min(n,m));
    five(mas, n, m);
    for (int i = 0; i < n; i++) {
        delete[] mas[i];
    }
    delete[] mas;
}