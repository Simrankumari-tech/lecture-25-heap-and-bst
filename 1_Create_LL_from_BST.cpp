#include<bits/stdc++.h>
using namespace std;
class node{
public :
int data ;
node*left , *right ;
node(int d){
data = d;
right =left = NULL;
}
};

node*Insertatbst(node*root , int data){
    if(!root){
        root = new node(data);
        return root;
    }

    // recursive case
    if(data <= root ->data){
        root ->left = Insertatbst(root->left , data);
    }
    else{
        root->right = Insertatbst(root->right , data);
    }
    return root;
}


class Linkedlist{
public :
    node*head , *tail ;
};
Linkedlist bstToLL(node*root){
    Linkedlist l;

    if(!root){
        l.head = l.tail = NULL ;
        return l;
    }
    // recursive case
    if(root ->left and root->right  ){
        Linkedlist left = bstToLL(root->left);
        Linkedlist right = bstToLL(root-> right);
        left.tail->right = root;
        root->right = right.head ;
        l.head = left.head ;
        l.tail = right.tail;
        return l;
    }

    else if(root->left and !root->right){
        Linkedlist left = bstToLL(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
        return l; 
    }

    else if(root->right and !root->left){
        Linkedlist right = bstToLL(root->right);
        root ->right= right.head;
        l.head = root;
        l.tail = right.tail;
        return l;
    }
    else{
        l.head= l.tail = root ;
        return l;
    }
}



node*BuildTree (){
    node* root = NULL;
  int data;
   cin >> data ;
   
   while (data != -1 ) {
   
    root  = Insertatbst(root , data);

    cin >> data ;

   }
   return root;
}
void preorder(node*root){
    if(!root) return ;
    cout << root->data << "  "; 
    preorder(root ->left);
    preorder(root ->right ) ;

}
void inorder(node*root){
    if(!root ) return ;
    inorder(root->left);
    cout << root ->data << "  ";
    inorder(root->right);

}
void postorder(node*root){
    if(!root) return ;
    postorder(root->left );
    postorder(root->right);
    cout << root ->data << "  ";
}

// 8 3 10 1 6 14 4 7 13 -1
int main(){
    node*root = BuildTree();
    

Linkedlist ans = bstToLL(root);

node*head = ans.head ;
while (head){
     cout << head->data << "--->" ;
     head = head ->right;
}
cout << "null/n" ;
return 0;
}