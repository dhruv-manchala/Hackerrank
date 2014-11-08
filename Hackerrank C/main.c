//
//  main.c
//  Hackerrank
//
//  Created by Dhruv Manchala on 11/7/14.
//  Copyright (c) 2014 Dhruv Manchala. All rights reserved.
//

#include <stdio.h>

int main(void)
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