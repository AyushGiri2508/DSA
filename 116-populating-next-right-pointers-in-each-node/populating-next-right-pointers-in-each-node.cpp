class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;

        Node* levelStart = root;

        while (levelStart->left != NULL) {
            Node* curr = levelStart;

            while (curr != NULL) {
                // Connect left child to right child
                curr->left->next = curr->right;

                // Connect right child to next subtree's left child
                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            levelStart = levelStart->left;
        }

        return root;
    }
};