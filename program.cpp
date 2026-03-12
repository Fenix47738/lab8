#include <iostream>
#include <fstream>

using namespace std;

const int M = 20; // обмеження для створення масивів або матриці
const int N = 20;

void Array96(); // Завдання 1

void Diag_Array96(int (& arr)[N], int& col); // видаляє повторювані елементи в масиві
void Show_Array96(int arr[N], int col); // виводить результат завдання 1

void Matrix_22(); // Завдання 2

void Get_Matrix22(int (& matrix)[M][N], int& row, int& col); // користувач вводить данні
int Diag_Matrix22(int (& matrix)[M][N], int row, int col); // обчислює суму елементів на головній діагоналі
void Show_Matrix22(int (& matrix)[M][N], int row, int col, int sum); // виводить результат завдання 2

void sort_13(); // Завдання 3

void DiagSort13(string arr[N], int col); // сортує масив рядків за алфавітом методом вибору
void Show_Array13(string arr[N], int col); // виводить результат завдання 3

void Get_Array(int (& arr)[N], int& col); // користувач вводить данні для завдання 1, 2
void Get_Array(string (& arr)[N], int& col);

void EnterInFileData(string fileName, auto data); // записує результат у файл

int main()
{
    int menu = 1; // змінна для вибора завдання

    while (menu != 0) // це цикл який дозволяє обирати завдання багато разів, 0 це вихід
    {
        cout << "1. Array96" << endl; // виводимо просте меню
        cout << "2. Matrix_22" << endl;
        cout << "3. sort_13" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter menu: ";

        cin >> menu; // дозволяємо користувачу вводити номер завдання

        switch (menu) // що обрав користувач?
        {
            case 1:
                Array96();
                break;
            case 2:
                Matrix_22();
                break;
            case 3:
                sort_13();
                break;
            case 0:
                break;
            default:
                cout << "Invalid menu!" << endl; // помилка
                break;
        }
    }

    system("pause"); //завершення програми
    return 0;
}

void Array96()
{
    int col; // кількість елементів в масиві
    int arr[N]; // масив для зберігання елементів

    Get_Array(arr, col); // отримуємо данні від користувача
    Diag_Array96(arr, col); // видаляємо повторювані елементи
    Show_Array96(arr, col); // записує результат у файл та вмводить на консоль
}

void Diag_Array96(int (& arr)[N], int& col)
{
    for (int i = 1; i < col; ++i) // лічильник для перебору елементів
        for (int j = i + 1; j < col; ++j) // лічильник для порівняння з наступними елементами
            if (arr[i] == arr[j]) // якщо знайдено повторюваний елемент
            {
                for (int k = j; k < col - 1; k++) // здвиг елементів вліво, починаючи з позиції j
                    arr[k] = arr[k + 1]; // замінюємо поточний елемент наступним

                arr[col - 1] = 0; // очищуємо останній елемент, який тепер є зайвим

                col--; // зменшуємо кількість елементів в масиві
                j--; // повертаємося на попередню позицію, щоб перевірити новий елемент на цій позиції
            }
}

void Show_Array96(int arr[N], int col)
{
    string result; // змінна для зберігання результату, який буде записаний у файл

    for (int i = 0; i < col; ++i) // лічильник для виводу елементів масиву
    {
        result += to_string(arr[i]) + " "; // додаємо елемент до результату

        cout << arr[i] << " "; // виводимо елемент на консоль
    }

    cout << endl; // наступна строчка

    EnterInFileData("array_in_96.txt.txt", result); // результат до файлу
}

void Matrix_22()
{
    int row, col; // строчка та стовпець

    int matrix[M][N]; // матриця

    Get_Matrix22(matrix, row, col); // отримуємо данні від користувача
    int sum = Diag_Matrix22(matrix, row, col); // обчислюємо суму елементів на головній діагоналі
    Show_Matrix22(matrix, row, col, sum); // записує результат у файл та виводить на консоль
}

void Get_Matrix22(int (& matrix)[M][N], int& row, int& col)
{
    cout << "Enter a limit for row and col" << endl; // просимо користувача ввести кількість рядків та ствопців
    cin >> row >> col;

    while ((row < 1 || row > M) || (col < 1 || col > N)) // поки данні не будуть виходити за межі та не будуть менше нуля
    {
        cerr << "Invalid number of limit. Please enter again (1 < M < 20) AND (1 < N < 20)" << endl; // помилка та просимо ввести данні повторно
        cin >> row >> col;
    }

    cout << "\nEnter element in matrix" << endl; // просимо ввести елементи

    for (int i = 0; i < row; ++i) // лічильник для рядків
        for (int j = 0; j < col; ++j) // лічильник для стовпців
        {
            cout << "Element i = " << i + 1 << ", j = " << j + 1 << ": "; // користувач вводить
            cin >> matrix[i][j];
        }
    
    for (int i = 0; i < row; ++i) // лічильник для виводу матриці
    {
        for (int j = 0; j < col; ++j)
            cout << matrix[i][j] << " ";
        
        cout << endl;
    }

    cout << endl;
}

int Diag_Matrix22(int (& matrix)[M][N], int row, int col)
{
    int sum = 0; // змінна в якій зберігається сума

    for (int i = 0; i < row; i++) // лічильник рядків
        for (int j = 2; j < col; j+=2) // лічильник стовпців, кожне парне
            sum += matrix[i][j]; // сумуємо

    return sum; // повертаємо
}

void Show_Matrix22(int (& matrix)[M][N], int row, int col, int sum)
{
    
    string result; // змінна для зберігання результату, який буде записаний у файл

    cout << "result" << endl; // виводимо результат

    for (int i = 0; i < row; ++i) // лічильник для виводу матриці та формування результату для файлу
    {
        for (int j = 0; j < col; ++j)
        {
            result += to_string(matrix[i][j]) + " ";
            cout << matrix[i][j] << " ";
        }

        result += "\n";
        cout << endl;
    }

    result += "Sum: " + to_string(sum) + "\n"; // виводимо у консоль та файл суму
    cout << "Sum: " << sum << endl;

    EnterInFileData("matrix_in_22.txt", result); // записуємо до файлу
}

void sort_13()
{
    int col; // ствопець

    string arr[N]; // масив

    Get_Array(arr, col); // користувач вводить
    DiagSort13(arr, col); // сортування
    Show_Array13(arr, col); // виводимо та записуємо у файл
}

void DiagSort13(string arr[N], int col)
{
    for (int i = 0; i < col - 1; ++i) // лічильник для масива
    {
        int minE_index = i; // індекс елемента який повинен бути йти з початку алфовиту

        for (int j = i + 1; j < col; ++j) // лічильник для пошуку літери яка повинна бути перше у алфовитному порядку
            if (arr[j] < arr[minE_index]) // якщо елемент повинен йти раніше
                minE_index = j; // записуємо індекс елемента цієї літери
        
        if (minE_index != i) // якщо індекси не дорівнюють
            swap(arr[i], arr[minE_index]); // змінюємо місцями елементи
    }
}

void Show_Array13(string arr[N], int col)
{
    string result; // результат

    for (int i = 0; i < col; ++i) // лічильник для масиву
    {
        result += arr[i] + " "; // виводимо у консоль та додаємо до результату
        cout << arr[i] << " ";
    }

    cout << endl; // нова строчка

    EnterInFileData("sort_in_13.txt", result); // записуємо до файлу
}

void Get_Array(int (& arr)[N], int& col)
{
    cout << "Enter a limit for array: "; // просимо користувача ввести скільки у нього елементів
    cin >> col;

    while (col < 1 || col > N) // якщо його елменти превишаєть допустимість та якщо вказав що у нього менше нуля або нуль елементів
    {
        cerr << "Invalid number of limit. Please enter again (1 < N < 20)" << endl; // помилка, просимо користувача знову ввести кількість
        cin >> col;
    }

    cout << "\nEnter element in array" << endl; // просимо користувача ввести елементи

    for (int i = 0; i < col; ++i) // лічільник для того щоб користувач ввів елементи
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < col; ++i) // лічильник для виведення елементів
        cout << arr[i] << " ";

    cout << endl;
}

void Get_Array(string (& arr)[N], int& col)
{
    cout << "Enter a limit for array: "; // просимо користувача ввести скільки у нього елементів
    cin >> col;

    while (col < 1 || col > N) // якщо його елменти превишаєть допустимість та якщо вказав що у нього менше нуля або нуль елементів
    {
        cerr << "Invalid number of limit. Please enter again (1 < N < 20)" << endl;
        cin >> col;
    }

    cout << "\nEnter element in array" << endl; // просимо користувача ввести елементи

    for (int i = 0; i < col; ++i) // лічільник для того щоб користувач ввів елементи
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    for (int i = 0; i < col; ++i) // лічильник для виведення елементів
        cout << arr[i] << " ";

    cout << endl;
}

void EnterInFileData(string fileName, auto data)
{
    try 
    {
        ofstream file(fileName); // файл в який будуть записани данні

        if (!file.is_open()) // якщо не вдалося відкрити ми повидомимо це користувачу
            throw runtime_error("can`t open file: " + fileName);

        file << data; // введемо данні у файл

        file.close(); // зачиняємо файл
    }
    catch (const runtime_error& e) // ловимо ісключеніє
    {
        cerr << "Error: " << e.what() << endl; // виводимо помилку
    }
}