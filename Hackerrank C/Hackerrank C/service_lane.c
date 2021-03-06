//
//  service_lane.c
//  Hackerrank
//
//  Created by Dhruv Manchala on 11/7/14.
//  Copyright (c) 2014 Dhruv Manchala. All rights reserved.
//


#include <stdio.h>

// Ad Hoc Solution

int service_lane(void)
{
    int n;
    int t;
    
    scanf("%d %d", &n, &t);
    
    int A[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    int start;
    int end;
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &start, &end);
        
        int max_width = 3;
        
        for (int j = start; j <= end; j++)
        {
            max_width = A[j] < max_width ? A[j] : max_width;
            
            if (A[j] == 1) break;
        }
        
        printf("%d\n", max_width);
    }
    
    return 0;
}

// Dynamic Programming Solution

/*
int service_lane(void)
{
    int n;
    int t;
    
    scanf("%d %d", &n, &t);
    
    int A[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    int cases[t][2];
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &cases[i][0], &cases[i][1]);
    }
    
    int partial[n + 1][n];
    
    for (int i = 0; i < n; i++) partial[1][i] = A[i];
    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int prev = partial[k - 1][i];
            partial[k][i] = prev < A[i + k - 1] ? prev : A[i + k - 1];
        }
    }
    
    for (int i = 0; i < t; i++)
    {
        int start = cases[i][0];
        int end = cases[i][1];
        
        printf("%d\n", partial[end - start + 1][start]);
    }
    
    return 0;
}
*/


