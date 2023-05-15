//
//  main.cpp
//  MP5
//
//  Created by Fei Gao on 2022/4/23.
//

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;
};

struct node *newNode(string data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}



void printvector(const vector<string>& vector, string space = " ")
{
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << space;
    }
    cout << endl;
}


void PreOrder(struct node *temp, vector<string> &list)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        list.push_back(temp->data);
        PreOrder(temp->left, list);
        PreOrder(temp->right, list);
    }
}


void InOrder(struct node *temp, vector<string> &list)
{
    if (temp != NULL)
    {
        InOrder(temp->left, list);
        cout << temp->data << " ";
        list.push_back(temp->data);
        InOrder(temp->right, list);
    }
}


void PostOrder(struct node *temp, vector<string> &list)
{
    if (temp != NULL)
    {
        PostOrder(temp->left, list);
        PostOrder(temp->right, list);
        cout << temp->data << " ";
        list.push_back(temp->data);
    }
}

string onlyLetters(string str)
{
    string retStr = "";

    for(int i = 0; i < str.length(); i++)
    {
        if(!ispunct(str[i]))
            retStr += str[i];
    }
    
    return retStr;
}

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = str.begin();

    while (i != str.end())
    {
    i = find_if(i, str.end(), not_space);
    iter j = find_if(i, str.end(), space);
    if (i != str.end())
        ret.push_back(onlyLetters(string(i, j)));
    i = j;
    }
    sort(ret.begin(), ret.end());
    return ret;
}

struct node* build(string arr[], int first, int last)
{
    if (first > last)
        return NULL;
    
    int mid = (first + last) / 2;
    struct node *root = newNode(arr[mid]);
    
    root->left = build(arr, first, mid-1);
    root->right = build(arr, mid+1, last);
    return root;
}

int height(struct node* root)
{
    if (root == NULL)
        return -1;
    return 1+max(height(root->left), height(root->right));
}

int leafs(struct node* root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right==NULL)
        return 1;

    return leafs(root->left)+leafs(root->right);
}

int main()
{
    string sentence, word;
    vector<string> words, words2, words3, temp;
    //1. Inputs a line of text
    cout << "1. Input your sentence: ";
    getline(cin, sentence);
    
    //2. Tokenizes the line into separate words
    words = split(sentence);
    string arr[words.size()];
    copy(words.begin(), words.end(), arr);
    cout << "2. Tokenization completed." << endl;
    
    //3. Inserts the words into a binary search tree (BST), T1
    int size = int(sizeof(arr) / sizeof(arr[0]));
    struct node* T1 = build(arr, 0, size-1);
    cout << "3. BST built." << endl;
    
    //4. Do a postorder traversal of the tree T1 and print it, then insert them into T2
    cout << "4. Postorder traversal and Insertion." << endl;
    PostOrder(T1, words2);
    sort(words2.begin(), words2.end());
    string arr2[words2.size()];
    copy(words2.begin(), words2.end(), arr2);
    
    int size2 = int(sizeof(arr2) / sizeof(arr2[0]));
    struct node* T2 = build(arr2, 0, size2-1);


    cout << endl;
    
    //5. Do a preorder traversal of the tree T2 and print it, then insert them into T3
    cout << "5. Preorder traversal and Insertion." << endl;
    PreOrder(T2, words3);
    sort(words3.begin(), words3.end());
    string arr3[words3.size()];
    copy(words3.begin(), words3.end(), arr3);
    int size3 = int(sizeof(arr3) / sizeof(arr3[0]));
    struct node* T3 = build(arr3, 0, size3-1);
    cout << endl;
    
    //6. Do an inorder traversal of the tree T3 and print it.
    cout << "6. Inorder traversal." << endl;
    InOrder(T3, temp);
    cout << endl;
    
    //7.
    cout << "7. Height of T1, T2, and T3 are: " << height(T1) << " " << height(T2) << " ";
    cout << height(T3) << endl;
    cout << "Number of leafs in T1, T2, and T3 are: " << leafs(T1) << " " << leafs(T2) << " ";
    cout << leafs(T3) << endl;
    return 0;
}
