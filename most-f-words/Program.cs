using System;
using System.Collections.Generic;
using System.Linq;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        /* string s = "ldgpx'gq pexxertr qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaadw' qkaad";
        Console.WriteLine("Input: " + s);
        List<string> input = new List<string>(s.ToLower().Split(' '));

        var cleanedItems = input
            .Select(item => new string(item.Where(c => (c >= 'a' && c <= 'z') || c == '\'').ToArray()))
            .Where(item => !string.IsNullOrEmpty(item))
            .ToList();

        var groupedItems = cleanedItems
            .GroupBy(word => word)
            .Select(group => new { Word = group.Key, Count = group.Count() })
            .OrderByDescending(x => x.Count)
            .ToList();

        List<string> result = new List<string> { };

        /* int top = -1;
        int second = -1;
        int third = -1;

        var topWord = groupedItems.OrderByDescending(w => w.Count).FirstOrDefault();
        foreach (var word in groupedItems)
        {
            if (word.Count >= top)

            {
                top = word.Count;
                topWord = word;
            }
        }
        if (topWord != null && !topWord.Word.All(c => c == '\''))
        {
            result.Add(topWord.Word);
            groupedItems.Remove(topWord);
            Console.WriteLine("top: " + topWord.Word);
            foreach (var item in groupedItems)
                Console.Write(item.Word + ":" + item.Count + " ");
            Console.WriteLine();
        }



        var secondWord = groupedItems.OrderByDescending(w => w.Count).FirstOrDefault();
        foreach (var word in groupedItems)
        {
            if (word.Count > second && word.Count <= top)
            {
                second = word.Count;
                secondWord = word;
            }
        }
        if (secondWord != null && !secondWord.Word.All(c => c == '\''))
        {
            result.Add(secondWord.Word);
            groupedItems.Remove(secondWord);
            Console.WriteLine("Second: " + secondWord.Word);
            foreach (var item in groupedItems)
                Console.Write(item.Word + ":" + item.Count + " ");
            Console.WriteLine();
        }

        var thirdWord = groupedItems.OrderByDescending(w => w.Count).FirstOrDefault();
        foreach (var word in groupedItems)
        {
            if (word.Count >= third && word.Count <= second)
            {
                //top = word.Count;
                third = word.Count;
                thirdWord = word;
            }
        }
        if (thirdWord != null && !thirdWord.Word.All(c => c == '\''))
        {
            result.Add(thirdWord.Word);
            Console.WriteLine("Third: " + thirdWord.Word);
            foreach (var item in groupedItems)
                Console.Write(item.Word + ":" + item.Count + " ");
            Console.WriteLine();
        }



        foreach (var item in result)
            Console.Write(item + " "); 
        var topWord = groupedItems
                   .Where(w => !w.Word.All(c => c == '\''))
                   .OrderByDescending(w => w.Count)
                   .FirstOrDefault();

        if (topWord != null)
        {
            result.Add(topWord.Word);
            groupedItems.Remove(topWord);
        }

        var secondWord = groupedItems
            .Where(w => !w.Word.All(c => c == '\''))
            .OrderByDescending(w => w.Count)
            .FirstOrDefault();

        if (secondWord != null)
        {
            result.Add(secondWord.Word);
            groupedItems.Remove(secondWord);
        }

        var thirdWord = groupedItems
            .Where(w => !w.Word.All(c => c == '\''))
            .OrderByDescending(w => w.Count)
            .FirstOrDefault();

        if (thirdWord != null)
        {
            result.Add(thirdWord.Word);
        }
        foreach (var item in result)
            Console.Write(item + " "); */

            
    } 
}


