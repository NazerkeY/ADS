/*/ Среди элементов массива выделяют минимальный и максимальный элементы, вычисляется их среднее 
арифметическое m. Массив разделяется на две части: в первую заносятся те элементы, 
которые меньше, чем среднее арифметическое, во вторую – элементы, которые больше 
среднего арифметического. Процедура повторяется рекурсивно для каждой части массива. 
Когда в очередных частях остаётся по два элемента, производится их сравнение и перемещение 
согласно условию упорядочивания*/

/* Есть массив, длину которого задает пользователь, в нем нужно отсортировать 
лишь числа, которые находятся на непарных местах. 
Бинарная сортировка.*/
#include <iostream>
using namespace std;

void generete(int array2[],int len)
{
       int random;
       for (int i = 0; i < len; i++)
       {
             random = rand() % 51;
             array2[i] = random;
       }
}
void printarray(int array3[],int len)
{
       cout << endl;
       for (int i = 0; i < len; i++)
       {
             cout << array3[i] << " ";
       }
       cout << endl;
}

void binary_sorting(int *Array, int b, int N)
{
       int left = b; int right = N;
       int oporniy = *(Array + (left + right) / 2);
       while (left <= right)
       {
             while (*(Array + left) > oporniy)
                    left++;
             while (*(Array + right) < oporniy)
                    right—;
             if (left <= right)
             {
                    int temp = *(Array + left);
                    *(Array + left) = *(Array + right);
                    *(Array + right) = temp;
                    left++;
                    right—;
             }
       }
       if (b < right)
             binary_sorting(Array, b, right);
       if (N > left)
             binary_sorting(Array, left, N);
}
int main()
{
       int len;
       cout << "Long: ";
       cin >> len;
       int *array1 = new int[len];
       generete(array1,len);
       int *array12 = new int[(len/2)];
       for (int i = 0; i < (len/2); i++)
       {
             array12[i] = array1[2 * i];
       }
       cout << "Array1: ";
       printarray(array1,len);
       cout<<endl;
       cout << "Array2: " << endl;
       printarray(array12,(len / 2));
       cout << endl;
       if (len > 1)
       {
             binary_sorting(array12, 0,(len / 2-1));
       }
       else
       {
             cout << "The array is too short for sorting"<< endl;
       }
       cout << endl << "Array2sorted: "<< endl;
       printarray(array12, (len / 2));
    cout << endl;
       for (int i = 0; i < len; i++)
       {
             if ((i % 2) == 0)
             {
                    array1[i] = array12[(i/2)];
             }
       }
       cout << endl << "Array1sorted: " << endl;
       printarray(array1, len);
       cout << endl;
       system("pause");
       delete[]array1;
       delete[]array12;

       return 0;
}

