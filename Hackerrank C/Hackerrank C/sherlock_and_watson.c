//
//  sherlock_and_watson.c
//  Hackerrank C
//
//  Created by Dhruv Manchala on 11/8/14.
//  Copyright (c) 2014 Dhruv Manchala. All rights reserved.
//

#include <stdio.h>

void reverse(int* A, int start, int end)
{
    for (int i = 0; i < (end - start + 1) / 2; i++)
    {
        int temp = A[start + i];
        A[start + i] = A[end - i];
        A[end - i] = temp;
    }
}

void rotate(int* A, int len, int n)
{
    n = n % len;
    
    reverse(A, 0, len - 1 - n);
    reverse(A, len - n, len - 1);
    reverse(A, 0, len - 1);
}

int sherlock_and_watson(void)
{
    int n;
    int k;
    int q;
    
    scanf("%d %d %d", &n, &k, &q);
    
    int A[n];
    
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    
    rotate(A, n, k);
    
    for (int i = 0; i < q; i++)
    {
        int ind;
        
        scanf("%d", &ind);
        printf("%d\n", A[ind]);
    }
    
    return 0;
}