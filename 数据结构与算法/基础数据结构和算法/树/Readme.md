1. 基本的数据结构（节点由什么组成的）

   - [ ] 链表

     ```c++
     // 二叉树
     struct  TreeNode{
       int val;
       int left;
       int right;
       
     };
     
     class Solution {
     public:
         TreeNode* first,*second,*prev;
         void traverse(TreeNode* root)
         {
             if(root==NULL)
                 return;
             traverse(root->left);
             
             if(first==NULL&&prev->val>root->val)
                 first=prev;
             if(first!=NULL&&prev->val>root->val)
                 second=root;
             prev=root;
             
             traverse(root->right);
             
         }
         void recoverTree(TreeNode* root) {
             first=NULL;
             second=NULL;
             prev=new TreeNode(INT_MIN);
             traverse(root);
             swap(first->val,second->val);
         }
     };
     ```

   - [ ] 数组

2. 基础框架



 Line 22: Char 21: fatal error: use of undeclared identifier 'null'        if (root == null) return  ;                    ^ 1 error generated. 