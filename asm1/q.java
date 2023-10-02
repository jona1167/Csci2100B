 static void Main(string[] args)
    {
        // Input
        var elements = new List<string> { "letitbe", "mihon", "mihon", "omi", "omi", "letitbe" };

        // Find distinct elements
        var distinctElements = elements.Distinct().ToList();

        // Create a dictionary that tells us how many copies of each element we have in the current subseries, initialize all values to 0
        var copiesOfElementInCurrentSubseries = distinctElements.ToDictionary(key => key, value => 0);

        // The sum of lengths of strings in the current subseries
        // Our goal is to minimize this
        var lengthOfCurrentSubseries = 0;

        // How many distinct elements are covered by the current subseries
        // The condition under which we minimize lengthOfCurrentSubseries is that numberOfElementsCoveredByCurrentSubseries equals distinctElements
        var numberOfElementsCoveredByCurrentSubseries = 0;

        // We remember the solution in these
        var bestStartIndex = 0;
        var bestLength = elements.Sum(e => e.Length);
        var bestNum = elements.Count;

        // Start with startIndex and endIndex at 0, increase endIndex until we cover all distinct elements
        // The subseries from startIndex to endIndex (inclusive) is our current subseries
        for (int startIndex = 0, endIndex = 0; endIndex < elements.Count; endIndex++)
        {
            // We add the element at endIndex to our current subseries:

            // If we found an element that previously wasn't covered, increase the count of covered elements
            // Note that we never decrease this, because once we find a solution that covers all elements, we never make a change which "loses" some element
            if (copiesOfElementInCurrentSubseries[elements[endIndex]] == 0)
            {
                numberOfElementsCoveredByCurrentSubseries++;
            }
            // Increase the number of copies of the element we added
            copiesOfElementInCurrentSubseries[elements[endIndex]]++;
            // Increase the total length of subseries by this element's length
            lengthOfCurrentSubseries += elements[endIndex].Length;

            // Initially, we will just loop increasing endIndex until all elements are covered
            // Once we are covering all elements, try to improve the solution
            if (numberOfElementsCoveredByCurrentSubseries == distinctElements.Count)
            {
                // Move startIndex to the right as far as possible while still covering all elements
                while (copiesOfElementInCurrentSubseries[elements[startIndex]] > 1)
                {
                    lengthOfCurrentSubseries -= elements[startIndex].Length;
                    copiesOfElementInCurrentSubseries[elements[startIndex]]--;
                    startIndex++;
                }

                // If the new solution is better, remember it
                if (lengthOfCurrentSubseries < bestLength)
                {
                    bestLength = lengthOfCurrentSubseries;
                    bestStartIndex = startIndex;
                    bestNum = endIndex - startIndex + 1;
                }
            }

            // Now we add another element by moving endIndex one place to the right, then try improving the solution by moving startIndex to the right, and we repeat this process...
        }

        Console.WriteLine(string.Join(" ", elements.Skip(bestStartIndex).Take(bestNum)));
    }