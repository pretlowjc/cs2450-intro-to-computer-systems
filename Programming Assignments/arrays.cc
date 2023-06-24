#include <stdio.h>

double getPositiveAverage(double myArray[], int numItems)
{
    if (numItems == 0)
        return 0;
    else
    {
        double sum = 0;
        int posItems = 0;
        for (int i = 0; i < numItems; i++)
        {
            if (myArray[i] >= 0)
            {
                sum += myArray[i];
                ;
                posItems++;
            }
        }
        if (posItems > 0)
        {
            return sum / posItems;
        }
        else
        {
            return 0;
        }
    }
}

int countRangeValues(double myArray[], int numItems, double numtoCount)
{
    int count = 0;
    double lowerBound = numtoCount - 0.5;
    double upperBound = numtoCount + 0.5;

    for (int i = 0; i < numItems; i++)
    {
        if (myArray[i] >= lowerBound && myArray[i] < upperBound)
        {
            count++;
        }
    }
    return count;
}

double getMaxAbsolute(double myArray[], int numItems)
{
    double max = 0;
    int maxAbs = 0;

    for (int i = 0; i < numItems; i++)
    {
        double absolute;
        if (myArray[i] < 0)
        {
            absolute = myArray[i] * -1;
        }
        else
        {
            absolute = myArray[i];
        }

        if (absolute == max)
        {
            if (myArray[i] > 0)
            {
                maxAbs = i;
            }
            else
            {
                maxAbs = maxAbs;
            }
        }
        if (absolute > max)
        {
            max = absolute;
            maxAbs = i;
        }
    }
    return myArray[maxAbs];
}

int countInverses(int myArray[], int numItems)
{
    int count = 0;
    for (int i = 0; i < numItems; i++)
    {
        for (int j = i + 1; j < numItems; j++)
        {
            if ((myArray[i] != 0) && (myArray[j] != 0))
            {
                if ((myArray[i] / myArray[j]) == -1)
                {
                    count++;
                    myArray[j] = 0;
                    myArray[i] = 0;
                }
            }
        }
    }
    return count;
}

int getMaxCount(double myArray[], int numItems)
{
    double maxAbs = getMaxAbsolute(myArray, numItems);
    return countRangeValues(myArray, numItems, maxAbs);
}
