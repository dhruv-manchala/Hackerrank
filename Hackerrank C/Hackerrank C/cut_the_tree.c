//
//  cut_the_tree.c
//  Hackerrank C
//
//  Created by Dhruv Manchala on 11/10/14.
//  Copyright (c) 2014 Dhruv Manchala. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tree
{
    int num_nodes;
    int* vals;
    int** edges;
    int* degree;
} Tree;

Tree* new_Tree(int num_nodes)
{
    Tree* tree = malloc(sizeof(Tree));
    
    tree->num_nodes = num_nodes;
    tree->vals = malloc((num_nodes + 1) * sizeof(int));
    tree->edges = malloc((num_nodes + 1) * sizeof(int*));
    tree->degree = malloc((num_nodes + 1) * sizeof(int));
    
    for (int i = 1; i <= num_nodes; i++)
    {
        tree->vals[i] = -1;
        tree->edges[i] = malloc(3 * sizeof(int));
        
        for (int j = 0; j < 3; j++) tree->edges[i][j] = -1;
        
        tree->degree[i] = 0;
    }
    
    return tree;
}

int tree_diff;

int solve(int root, Tree* tree, int tree_sum, bool* visited)
{
    visited[root] = true;
    int sum = tree->vals[root];
    
    for (int i = 0; i < tree->degree[root]; i++)
    {
        int next = tree->edges[root][i];
        
        if (!visited[next]) sum += solve(next, tree, tree_sum, visited);
    }
    
    int curr_diff = abs(tree_sum - 2 * sum);
    
    if (curr_diff < tree_diff) tree_diff = curr_diff;
    
    return sum;
}

int cut_the_tree(void)
{
    int tree_sum = 0;
    int n;
    
    scanf("%d", &n);
    
    bool* visited = malloc((n + 1) * sizeof(bool));
    
    for (int i = 1; i <= n; i++) visited[i] = false;
    
    Tree* tree = new_Tree(n);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tree->vals[i]);
        tree_sum += tree->vals[i];
    }
    
    tree_diff = tree_sum;
    
    for (int i = 0; i < n - 1; i++)
    {
        int start;
        int end;
        
        scanf("%d %d", &start, &end);
        
        int d1 = tree->degree[start];
        int d2 = tree->degree[end];
        
        tree->edges[start][d1] = end;
        tree->edges[end][d2] = start;
        tree->degree[start]++;
        tree->degree[end]++;
    }
    
    int root;
    
    for (int i = 1; i <= n; i++)
    {
        if (tree->degree[i] == 1 || tree->degree[i] == 2)
        {
            root = i;
            break;
        }
    }
    
    solve(root, tree, tree_sum, visited);
    printf("%d\n", tree_diff);
    
    return 0;
}