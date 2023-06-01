// Binary Search Tree : Is valid Binary Search Tree?
// Program Author : Abhisek Kumar Gupta
/*
    Input :  7 3 9 2 4 8 10 -1

    Output :  YES
                  7
                /   \
               3     9
              / \   / \ 
             2  4  8  10
    
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x){
            data = x;
            left = NULL;
            right = NULL;
        }
};
void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* element = q.front();
        if(element == NULL){
            cout << "\n";
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << element->data << "->";
            q.pop();
            if(element->left != NULL){
                q.push(element->left);
            }
            if(element->right != NULL){
                q.push(element->right);
            }
        }
    }
    return;
}
Node* insert_into_binary_search_tree(Node* root, int data){
    if(root == NULL)
        return new Node(data);
    if(data <= root->data){
        root->left = insert_into_binary_search_tree(root->left, data);
    }    
    else{
        root->right = insert_into_binary_search_tree(root->right, data);
    }
    return root;
}
Node* build_binary_search_tree(){
    int data;
    cin >> data;
    Node* root = NULL;
    while(data != -1){
        root = insert_into_binary_search_tree(root, data);
        cin >> data;
    }
    return root;
}
bool is_binary_search_tree(Node* root, int minimum = INT_MIN, int maximum = INT_MAX){
    if(root == NULL)
        return true;
    if(root->data >= minimum && root->data <= maximum && is_binary_search_tree(root->left, minimum, root->data) && is_binary_search_tree(root->right, root->data, maximum))
        return true;
    return false;        

}
int main(){
    Node* root = build_binary_search_tree();
    cout << endl;
    bfs(root);
    cout << endl;
    if(is_binary_search_tree(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}