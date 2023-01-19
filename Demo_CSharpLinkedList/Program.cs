using System;
using System.Collections;
using System.Collections.Generic;

// C++ std::list => Linked List
// C# List<T> => Dynamic Array

// C# LinkedList<T> => Linked List

class Program
{
    static void Main()
    {
        LinkedList<int> numbers = new LinkedList<int>();

        // O(1)
        var node = numbers.AddLast(5);

        // O(1)
        numbers.Remove(node);

        // O(N)
        numbers.Remove(5);
    }
}