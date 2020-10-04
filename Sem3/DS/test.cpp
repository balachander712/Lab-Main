
void Tree :: change(Node *&tree_1, Node *&tree_2)
{
    if(tree_1 != NULL)
    {
        if(tree_2 != NULL)
        {
            while(tree_1->val != tree_2->val)
            {
                if(tree_1->val > tree_2->val)
                {
                    if(tree_1->left != NULL && tree_1->left->right != NULL && tree_1->left->right->val == tree_2->val)
                    {
                        tree_1->left = RR(tree_1->left);
                        tree_1 = LL(tree_1);
                        cout << "LR rotation" << endl;
                    }
                    if(tree_1->right != NULL || tree_1->left != NULL)
                    {
                        tree_1 = LL(tree_1);
                        cout << "LL rotation" << endl;
                    }
                }
                if(tree_1->val < tree_2->val)
                {
                    if(tree_1->right != NULL && tree_1->right->left != NULL && tree_1->right->left->val == tree_2->val)
                    {
                        tree_1->right = LL(tree_1->right);
                        tree_1 = RR(tree_1);
                        cout << "RL rotation" << endl;
                    }
                    if(tree_1->right != NULL || tree_1->left != NULL)
                    {
                        tree_1 = RR(tree_1);
                        cout << "RR rotation" << endl;
                    }
                    
                }
            }
            change(tree_1->left, tree_2->left);
            change(tree_1->right, tree_2->right);
        }
    }
} 