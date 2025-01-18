using System;
using System.Collections.Generic;
using System.Linq;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string s = "asd asdf asd asd wobtdf wobtdf";
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
            //.ThenBy(x => x.Word)
            .ToList();
            
     List<string> result = new List<string> {};

    int top = 0;
    int second = 0;
    int third = 0;
    
    string topWord = "";
    string secondWord = "";
    string thirdWord = "";
    

    
      foreach(var word in groupedItems)
      {
        if(word.Count >= top)
        {
            top = word.Count;
            topWord = word.Word;
        }
      }
      if(!string.IsNullOrEmpty(topWord) && !topWord.All(c => c == '\''))
      result.Add(topWord);
      groupedItems.RemoveAll(item => item.Word == topWord);
      Console.WriteLine("top: " + topWord);
      foreach(var item in groupedItems)
      Console.Write(item.Word + ":" + item.Count+ " ");
      Console.WriteLine();
      foreach(var word in groupedItems)
      {
        if(word.Count >= second && word.Count <= top)
        {
            //top = word.Count;
            second = word.Count;
            secondWord = word.Word;
        }
      }
      if(!string.IsNullOrEmpty(secondWord) && !secondWord.All(c => c == '\''))
      result.Add(secondWord);
      groupedItems.RemoveAll(item => item.Word == secondWord);
      Console.WriteLine("Second: " + secondWord);
      foreach(var item in groupedItems)
      Console.Write(item.Word + ":" + item.Count+ " ");
      Console.WriteLine();
        foreach (var word in groupedItems)
        {
            if (word.Count >= third && word.Count <= second)
            {
                //top = word.Count;
                third = word.Count;
                thirdWord = word.Word;
            }
        }
        if(!string.IsNullOrEmpty(thirdWord)&& !thirdWord.All(c => c == '\''))
        result.Add(thirdWord);
        Console.WriteLine("Third: " + thirdWord);
      foreach(var item in groupedItems)
      Console.Write(item.Word + ":" + item.Count+ " ");
      Console.WriteLine();
       
      foreach(var item in result)
      Console.Write(item + " ");
      
    }
}


