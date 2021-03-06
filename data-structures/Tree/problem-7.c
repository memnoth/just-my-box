/*
 * Karumanchi N. - Data Structures and Algorithms Made Easy
 * 
 * Section : Tree
 * Problem : No. 7
 * 
 * Give an algorithm for finding the size of binary tree without recursion.
 * 
 * O(N) for time-complexity, O(N) for space-complexity.
 */

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "mytree.h"

size_t
get_tree_size (XZTreeNode *root)
{
    GQueue queue = G_QUEUE_INIT;
    XZTreeNode *cur;
    size_t total = 0;

    if (root == NULL)
        return total;

    cur = root;
    g_queue_push_tail (&queue, cur);

    while (!g_queue_is_empty (&queue)) {
        total++;

        cur = g_queue_pop_head (&queue);
        if (cur->left)
            g_queue_push_tail (&queue, cur->left);
        if (cur->right)
            g_queue_push_tail (&queue, cur->right);
    }

    return total;
}

int
main (void)
{
    XZTree *tree;

    tree = xz_tree_new (COMPARE_FUNC (my_tree_cmp));

    /*
     *     3
     *    / \
     *   2   5
     *  /   / \
     * 1   4   6
     *          \
     *           7
     */
    xz_tree_insert (tree, my_tree_node_new (3));
    xz_tree_insert (tree, my_tree_node_new (2));
    xz_tree_insert (tree, my_tree_node_new (1));
    xz_tree_insert (tree, my_tree_node_new (5));
    xz_tree_insert (tree, my_tree_node_new (4));
    xz_tree_insert (tree, my_tree_node_new (6));
    xz_tree_insert (tree, my_tree_node_new (7));

    g_assert (get_tree_size (tree->root) == 7);

    xz_tree_destroy (&tree);

    return 0;
}