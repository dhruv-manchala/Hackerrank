//
//  bus_station.c
//  Hackerrank C
//
//  Created by Dhruv Manchala on 11/8/14.
//  Copyright (c) 2014 Dhruv Manchala. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int bus_station()
{
    int n;
    
    scanf("%d", &n);
    
    int A[n];
    int min = INT_MAX;
    int max = 0;
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        sum += A[i];
        
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }
    
    for (int i = max; i <= sum; i += min)
    {
        if (sum % i == 0)
        {
            int curr = 0;
            
            for (int j = 0; j < n; j++)
            {
                if (curr > i) break;
                if (curr == i) curr = 0;
                if (curr < i) curr += A[j];
            }
            
            if (curr == i) printf("%d ", i);
        }
    }
    
    return 0;
}
