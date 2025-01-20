// АЛГОРИТМЫ

// 1. Бинарный поиск - O(log n)
static int findMax(int[] numbers)
{
    int left = 0;
    int right = numbers.Length - 1;
    int max = numbers[0];
    for (int i = left; i < right; i++)
    {
        if (numbers[(left + right) / 2] > max)
            left = right;
        else
            right = (left + right) / 2;

    }
    
}



// ---------------
// Разделяй и властвуй!


// 1. Сумма чисел массива
static int Sum(int[] numbers)
{
    if (numbers.Length == 0) // Если массив пуст возвращаем ноль
        return 0;
    else // В противном случае результат равен сумме первого числа в массиве и сумме остального массива
        return numbers[0] + Sum(numbers.Skip(1).ToArray());

}






int[] nums = { 1, 2, 4, 5 };
Console.WriteLine("1. Сумма чисел массива - {" + string.Join(", ", nums) + "} = " + Sum(nums));

