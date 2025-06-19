class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

    int height(Node* node) {
        // code here
        if(node==nullptr) return -1;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        return 1+max(leftHeight,rightHeight);
    }
