
int distanceFromRoot(struct Node* root, int x)
{
    if (root->key == x)
        return 0;
    else if (root->key > x)
        return 1 + distanceFromRoot(root->left, x);
    return 1 + distanceFromRoot(root->right, x);
}

int distanceBetween2(struct Node* root, int a, int b)
{
    if (!root)
        return 0;

    // Both keys lie in left
    if (root->key > a && root->key > b)
        return distanceBetween2(root->left, a, b);

    // Both keys lie in right
    if (root->key < a && root->key < b) // same path
        return distanceBetween2(root->right, a, b);

    // Lie in opposite directions (Root is
    // LCA of two nodes)
    if (root->key >= a && root->key <= b)
        return distanceFromRoot(root, a) +
               distanceFromRoot(root, b);
}

// This function make sure that a is smaller
// than b before making a call to findDistWrapper()
int findDistWrapper(Node *root, int a, int b)
{
   if (a > b)
     swap(a, b);
   return distanceBetween2(root, a, b);
}
