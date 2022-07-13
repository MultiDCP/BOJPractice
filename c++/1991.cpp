#include <bits/stdc++.h>
using namespace std;
map<char, pair<char, char>> tree;
int n;

void preorder(char node){
    cout << node;
    if(tree[node].first != '.')
        preorder(tree[node].first);
    if(tree[node].second != '.')
        preorder(tree[node].second);
}

void inorder(char node){
    if(tree[node].first != '.')
        inorder(tree[node].first);
    cout << node;
    if(tree[node].second != '.')
        inorder(tree[node].second);
}

void postorder(char node){
    if(tree[node].first != '.')
        postorder(tree[node].first);
    if(tree[node].second != '.')
        postorder(tree[node].second);
    cout << node;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        char origin, lchild, rchild;
        cin >> origin >> lchild >> rchild;
        tree[origin] = {lchild, rchild};
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

    return 0;
}

/*
강좌를 보면서 함께 풀음. 복습 및 연습 필요.
*/