/*
    Data Structure Algorithm

    -Project for our 2nd Semester
    -Delete Binary Search Trees
    -Writ Code Name Doeurk Panha
    -day 7/8/2023
*/

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<math.h>
using namespace std;

//Data struct to store BST nodes
string line (200,'_');
struct Node{
    int info;
    Node *left,*right;
};

//function to in sert first node (left,right=NULL)
Node* make_node(int item){
    Node* p= new Node;
    p->info=item;
    p->left=NULL;
    p->right=NULL;
    return p;
}

//function to perform preorder traversal (NLR)
void preorder(Node* proot){
    if(proot != NULL)//node root not null
    {
        cout<<proot->info<<"";
        preorder(proot->left);
        preorder(proot->right);
    }
}

//function to perform inorder traversal (LNR)
void inorder(Node* proot){//proot==node root
    if(proot != NULL)//node root not null
    {
        inorder(proot->left);
        cout<<proot->info<<"";
        inorder(proot->right);
    }
}

//function to perform postorder traversal (LRN)
void postorder(Node* proot){
    if(proot != NULL){
        postorder(proot->left);
        postorder(proot->right);
        cout<<proot->info<<"";
    }
}

// function to find minimum value(item)node in the subtree rooted at "curr"
Node* min_item(Node* curr){
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

// function to find maximum value(item) node in the subtree rooted at "curr"
Node* max_item(Node* curr){
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr;
}

// function to sert item or value info BST
Node* insert(Node* proot, int item){
    // if the root is null, create a new node and return it
    if(proot==NULL)
    {
        return make_node(item); // call funtion make_node above
    }
    else 
    {
        //recur for the left subtree
        if(item==proot->info)
        {
            cout<<"Node p have in binary search trees"<<endl;
        }
        else if(item<proot->info)
        {
            proot->left = insert(proot->left,item);
        }
        else 
        {
            proot->right= insert(proot->right,item);
        }
        return proot;
    }
}

// function to delete node that user input
void delete_node(Node* &proot,int item){
    //item is not found
    if(proot==NULL)
    {
        cout<<"\tThis item is not found"<<endl;
        return;
    }
    //item have more than 1
    //if given item is less than node root, recur to left subtree
    if(item<proot->info)
    {
        delete_node(proot->left,item); // call function delete_node abov
    }
    //if given item is more than node root, recur to right subtree
    else if(item>proot->info)
    {
        delete_node(proot->right,item);
    }
    else if(proot->left==NULL && proot->right==NULL)
    {
        //delete == 0
        cout<<endl;
        cout<<std::left<<setw(5)<<"Node has degree = 0"<<endl;
        delete proot;
        proot=NULL;
        
    }
    //delete == 2
    else if (proot->left && proot->right)
    {
        cout<<endl;
        int op;
        cout<<std::left<<setw(5)<<" "<<"The node which delete has degree = 2\n"<<endl;
        cout<<std::left<<setw(5)<<" "<<"[1].Stand for to left Subtree"<<endl;
        cout<<std::left<<setw(5)<<" "<<"[2].Stand for to right subtree\n"<<endl;
        cout<<std::left<<setw(5)<<" "<<"Choose option: ";
        cin>>op;
        switch(op){
            case 1:{
                cout<<line<<endl;
                cout<<std::left<<setw(5)<<""<<"Left Subtree Operted by Maximun Function"<<endl;
                Node* predecessor=max_item(proot->left);//call function max_item (<)
                proot->info=predecessor->info;
                delete_node(proot->left,predecessor->info);//call function delete_node 
                break;
            }
            case 2:{
                cout<<line<<endl;
                cout<<std::left<<setw(5)<<""<<"Right Subtree Operted by Minimum Function"<<endl;
                Node* predecessor=min_item(proot->right);//call function min_item (>)
                proot->info=predecessor->info;
                delete_node(proot->right,predecessor->info);// call function delete_node
                break;
            }
        } 
    }

    else //degree == 1
    {
        cout<<endl;
        cout<<std::left<<setw(5)<<""<<"Node has degree = 1 "<<endl;
        Node* child=(proot->left)?proot->left:proot->right;
        Node* curr=proot;
        proot=child;
        delete curr++;
    }
}

void applytoarr(Node* node,int arr[],int offset)
{
    if(node==NULL){
        return;
    }
    arr[offset]=node->info;
    applytoarr(node->left,arr,offset*2+1);//left son node i*2+1
    applytoarr(node->right,arr,offset*2+2);//right son node i*2+2
}

//find how much node in one level
void printlevel(int arr[],int space,int level){
    if(level>6){
        return;
    }
    for(int i=pow(2,level-1)-1; i<pow(2,level)-1; i++) //2^level-1 //pow(2,n-1)
    {
        if(arr[i]==0)    //arr[0]=50
            cout<<setw(space)<<""<<setw(2)<<setw(space)<<"";
        else 
            cout<<setw(space)<<""<<setw(2)<<arr[i]<<""<<setw(space)<<"";
    }
    cout<<endl<<endl;
    printlevel(arr,space/2,level+1);
}

//print node in BST
void print2D(Node* node){
    int arr[100];
    for(int i=0; i<100; i++){
       arr[i]=0; 
    }
    applytoarr(node,arr,0);
    printlevel(arr,65,1);
}
//45,30,40,35,33,38,43,42,75,65,50,48,55,70,68,85,80,78,83,90,88,95

int main(){
    system("cls");
    system("color f4");
    int n,p;
    char ch;
    int item[]={45,30,40,35,33,38,43,42,75,65,50,48,55,70,68,85,80,78,83,90,88,95};
    Node* proot=NULL;
    
    n=sizeof(item)/sizeof(item[0]);
    for(int i=0; i<n; i++){
        proot=insert(proot,item[i]);
    }
    cout<<endl;
    cout<<std::left<<setw(50)<<""<<"================"<<endl;
    cout<<std::left<<setw(50)<<""<<"All Nodes in BST"<<endl;
    cout<<std::left<<setw(50)<<""<<"================"<<endl;
    cout<<std::left<<setw(5)<<""<<"Node process by inorder Traversal:\n\n"<<endl;
    cout<<std::left<<setw(5)<<""<<"LNR"<<endl;
    inorder(proot);
    cout<<endl;

    cout<<std::left<<setw(5)<<""<<"NLR"<<endl;
    preorder(proot);
    cout<<endl;
   
    cout<<std::left<<setw(5)<<""<<"LRN"<<endl;
    postorder(proot);
    cout<<endl;

    cout<<endl<<line<<endl<<endl;
    do
    {
        cout<<left<<setw(50)<<""<<">>The tree of node which from top to down<<\n"<<endl;
        print2D(proot);
        cout<<std::left<<setw(5)<<""<<"Input Node of Binary Search tree to detele:";
        cin>>p;
        delete_node(proot,p);
        cout<<endl;
        cout<<std::left<<setw(6)<<""<<"Nodes After Delete("<<p<<")\n"<<endl;
        print2D(proot);
        cout<<left<<setw(5)<<"";
        cout<<"LNR"<<endl;
        inorder(proot);//LNR
        cout<<endl;

        cout<<left<<setw(5)<<"";
        cout<<"NLR"<<endl;
        preorder(proot);//NLR
        cout<<endl;

        cout<<left<<setw(5)<<"";
        cout<<"LRN"<<endl;
        postorder(proot);//LRN
        cout<<endl<<line<<endl;
        
        cout<<left<<setw(5)<<""<<"Press ESC for exit other continue:"<<endl;
        ch=getch();
    } while (ch!=27);

    return 0;
}
