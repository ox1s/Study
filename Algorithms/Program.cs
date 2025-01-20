// АЛГОРИТМЫ



// 1. Сортировка выбором - O(n^2)
static int[] selectionSort(int[] arr)
{
    int[] newArr = new int[arr.Length]; // Создаем новый массив с количеством элементов заданного
    bool[] selected = new bool[arr.Length]; // Отслеживаем использованные элементы

    for (int i = 0; i < newArr.Length; i++)
    {
        int smallestIndex = -1;
        for (int j = 0; j < arr.Length; j++)
        {
            if (!selected[j] && (smallestIndex == -1 || arr[j] < arr[smallestIndex]))
            {
                smallestIndex = j; // Находим минимальный элемент
            }
        }
        newArr[i] = arr[smallestIndex]; // Помещаем минимальный элемент в новый массив
        selected[smallestIndex] = true; // Отмечаем этот элемент как использованный
    }
    return newArr;
}
// 2. Бинарный поиск - O(log n)
static int binarySearch(int[] numbers, int num)
{
    int left = 0;
    int right = numbers.Length - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int guess = numbers[mid];
        if (guess == num)
            return mid;
        else if (guess > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
// ---------------
// Разделяй и властвуй!

// 1. Сумма чисел массива
static int Sum(int[] arr)
{
    if (arr.Length == 0) // Если массив пуст возвращаем ноль
        return 0;
    else // В противном случае результат равен сумме первого числа в массиве и сумме остального массива
        return arr[0] + Sum(arr.Skip(1).ToArray());
}
// 2. Рекурсивная функция для подсчета элементов в массиве
static int CountElements(int[] arr)
{
    if (arr.Length == 0)
        return 0;
    else
        return 1 + CountElements(arr.Skip(1).ToArray());
}
// 3.а) Рекурсивная функция для нахождения максимального числа в массиве
static int Max(int[] arr)
{
    if (arr.Length == 2)
        return arr[0] > arr[1] ? arr[0] : arr[1];
    int subMax = Max(arr.Skip(1).ToArray());
    return arr[0] > subMax ? arr[0] : subMax;
}
// 3.б) Рекурсивная функция для нахождения минимального числа в массиве
static int Min(int[] arr)
{
    if (arr.Length == 2)
        return arr[0] < arr[1] ? arr[0] : arr[1];
    int subMin = Min(arr.Skip(1).ToArray());
    return arr[0] < subMin ? arr[0] : subMin;
}
// ИЛИ
// 3.а)* Рекурсивная функция для нахождения максимального числа в массиве без создания нового массива
static int MaxWithoutSkip(int[] arr, int index = 0)
{
    if (index == arr.Length - 1)
        return arr[index];

    int subMax = MaxWithoutSkip(arr, index + 1);
    return arr[index] > subMax ? arr[index] : subMax;
}
// 3.б)* Рекурсивная функция для нахождения минимального числа в массиве без создания нового массиваs
static int MinWithoutSkip(int[] arr, int index = 0)
{
    if (index == arr.Length - 1)
        return arr[index];

    int subMin = MinWithoutSkip(arr, index + 1);
    return arr[index] < subMin ? arr[index] : subMin;
}

// 4. Быстрая сортировка - О(n*log n)
static int[] QuickSort(int[] arr)



int[] nums = { 1, 3, 7, 5 };

Console.WriteLine("Введите число из массива {" + string.Join(", ", nums) + "} = индекс которого хотите получить");
string? input = Console.ReadLine();
if (int.TryParse(input, out int n))
{
    // Преобразование прошло успешно, n содержит значение
    Console.WriteLine($"Вы ввели число: {n}");
}
else
{
    // Преобразование не удалось
    Console.WriteLine("Ошибка: введено не число.");
}
Console.Write("Загрузка: [");
int total = 30; // Длина прогресс-бара
for (int i = 0; i <= total; i++)
{
    Console.Write("#");
    Thread.Sleep(100); // Задержка в 100 миллисекунд
}
Console.WriteLine("] Загрузка завершена!");


Console.WriteLine("1. Сортировка выбором в массиве - {" + string.Join(", ", nums) + "} = " + "{" + string.Join(", ", selectionSort(nums)) + "}");
Console.WriteLine("2. Бинарный поиск индекса числа " + n + " в массиве - {" + string.Join(", ", selectionSort(nums)) + "} = " + binarySearch(selectionSort(nums), n));
Console.WriteLine("--------------- \nРазделяй и властвуй!");
Console.WriteLine("1. Сумма чисел массива - {" + string.Join(", ", nums) + "} = " + Sum(nums));
Console.WriteLine("2. Рекурсивная функция для подсчета элементов в массиве - {" + string.Join(", ", nums) + "} = " + CountElements(nums));
Console.WriteLine("3.а) Рекурсивная функция для нахождения максимального числа в массиве - {" + string.Join(", ", nums) + "} = " + Max(nums));
Console.WriteLine("3.а)* Рекурсивная функция для нахождения максимального числа в массиве без создания нового массива - {" + string.Join(", ", nums) + "} = " + MaxWithoutSkip(nums));
Console.WriteLine("3.б) Рекурсивная функция для нахождения минимального числа в массиве - {" + string.Join(", ", nums) + "} = " + Min(nums));
Console.WriteLine("3.б)* Рекурсивная функция для нахождения минимального числа в массиве без создания нового массива - {" + string.Join(", ", nums) + "} = " + MinWithoutSkip(nums));
