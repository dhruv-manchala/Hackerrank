//
//  array_utilities.c
//  Hackerrank C
//
//  Created by Dhruv Manchala on 11/8/14.
//  Copyright (c) 2014 Dhruv Manchala. All rights reserved.
//

#include <stdio.h>

void print_array(int* A, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", A[i]);
    }
    
    printf("\n");
}

