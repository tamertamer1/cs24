#include "Node.h"

bool recurCont(Node* top,const std::string& value){
    if (!top) return false;
    if (value == top->data) return true;
    if (value < top->data) return recurCont(top->left, value);
    return recurCont(top->right, value);
};

void del(Node *n){
    if (!n) {return;}
    del(n->left);
    del(n->right);
    delete n;
};

Node* Insertrec(Node*root, const std::string& value){
    if (!root) {
        return new Node(value);
    }
    if (value > root->data) {
        root->right = Insertrec(root->right, value);
    }
    else if (value < root->data){
        root->left = Insertrec(root->left, value);
    }
    return root;
};
size_t recurCount(Node *root,size_t n){
    if(!root)
		return 0;
	if(root->left!=NULL)
	{
		n=n+1;
		n=recurCount(root->left,n);
	}
	if(root->right!=NULL)
	{
		n=n+1;
		n=recurCount(root->right,n);
	}
	return n;
}
