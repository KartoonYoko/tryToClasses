# MyMatrix Class

Класс матрица. Класс представляет матрицу размера N x M, где N - кол-во строк, M - кол-во столбцов.

**Header**: #include tryToMatrix.h

## Public-Functions

|                 | MyMatrix()                                                   |
| --------------- | :----------------------------------------------------------- |
|                 | MyMatrix(const int& row, const int& col)                     |
|                 | MyMatrix(const int& row, const int& col, const VecType& num) |
| int             | getCol() const                                               |
| int             | getRow() const                                               |
| void            | expand(const int& row, const int& col)                       |
| void            | expand(const int& row, const int& col, const VecType& num)   |
| VecType         | getItem(const int& row, const int& col) const                |
| void            | setItem(const int& row, const int& col, const VecType& num)  |
| VecType&        | operator ()(const int& row, const int& col)                  |
| vector<VecType> | operator [](const int& index)                                |
| void            | fill(const VecType& num)                                     |
| void            | fillRand()                                                   |
| void            | fillRand(const int& fromNum, const int& lastNum)             |
| MyMatrix        | operator =(const MyMatrix &rightMatrix)                      |
| MyMatrix        | operator +(const MyMatrix& rightMatrix)                      |
| MyMatrix        | operator -(const MyMatrix& rightMatrix)                      |
| MyMatrix        | operator *(const VecType& num)                               |
| MyMatrix        | operator *(const MyMatrix& rightMatrix)                      |
| void            | operator *=(const MyMatrix& rightMatrix)                     |
| void            | operator *=(const VecType& num)                              |
| void            | operator -=(const MyMatrix& rightMatrix)                     |
| void            | operator +=(const MyMatrix& rightMatrix)                     |
| void            | transpose()                                                  |
| void            | diag()                                                       |
| double          | determinant()                                                |
| void            | outputConsole()                                              |



## Описание

typedef double VecType; // тип элементов матрицы(вектора)

### Описание методов класса

#### MyMatrix()

​    Создает нулевую матрицу размера 1х1.

#### MyMatrix(const int& row, const int& col)

​    Сздает нулевую матрицу размера row x col.

#### MyMatrix(const int& row, const int& col, const VecType& num)

​    Создает матрицу, заполненную числом num, размера row x col

#### int getCol() const

​    Получить кол-во столбцов

#### int getRow() const

​    Получить кол-во строк

#### void  expand(const int& row, const int& col)

​    Расширяет матрицу до размера row x col и заполняет новые ячейки нулями

#### void  expand(const int& row, const int& col, const VecType& num)

​    Расширяет матрицу до оазмера row x col и заполняет новые ячейки числом num

#### VecType getItem(const int& row, const int& col) const                                                                 

​    Вернет элемент матрицы на позицию row x col

#### void setItem(const int& row, const int& col, const VecType& num)

​    Внесет num в матрицу на позицию row x col

#### VecType& operator ()(const int& row, const int& col)

​    Вернет элемент матрицы row x col по ссылке (для быстрого внесения значения в матрицу)

#### vector<VecType> operator [](const int& index)

​    Доступ к строкам матрицы

#### void fill(const VecType& num)

​    Заполнение матрицы одним значение

#### void fillRand()

​    Заполнение матрицы случайными числами

#### void fillRand(const int& fromNum, const int& lastNum)

​    Заполнение матрицы случайными числами от fromNum до lastNum(целочисленного типа, т.к. рандом работает только с целыми), с десятичным остатком

#### void operator =(const MyMatrix &rightMatrix)

​    В левую матрицу заносятся значения правой матрицы (толко для одноразмерных матриц)

#### MyMatrix operator +(const MyMatrix& rightMatrix)

​    Сложениме матриц

#### MyMatrix operator -(const MyMatrix& rightMatrix)

​    Вычитание матриц

#### MyMatrix operator *(const VecType& num)

​    Умножение на число

#### MyMatrix operator *(const MyMatrix& rightMatrix)

​    Умножение матрицы на матрицу

#### void operator *=(const MyMatrix& rightMatrix)

​    Умножение матрицы на матрицу

#### void operator *=(const VecType& num)

​    Умножение на число

#### void operator -=(const MyMatrix& rightMatrix)

​    Вычитание матриц

#### void operator +=(const MyMatrix& rightMatrix)

​    Сложениме матриц

#### void transpose()

​    Транспонирование текущей матрицы

#### void diag()

​    Создание диагональной матрицы

#### double determinant()

​    Вычесление определителя

#### void outputConsole()

​    Вывод матрицы в консоль