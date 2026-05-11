#include "studentbst.h"
#include <iostream>

using namespace std;

StudentBST::StudentBST()
{
    root = nullptr;
}

StudentNode* StudentBST::insertRec(StudentNode* node, int id, string name, string dept)
{
    if (!node)
    {
        StudentNode* n = new StudentNode;
        n->id = id;
        n->name = name;
        n->dept = dept;
        n->left = n->right = nullptr;
        return n;
    }

    if (id < node->id)
        node->left = insertRec(node->left, id, name, dept);
    else
        node->right = insertRec(node->right, id, name, dept);

    return node;
}

bool StudentBST::exists(int id)
{
    return searchRec(root, id) != nullptr;
}

void StudentBST::insert(int id, string name, string dept)
{
    if (exists(id))
    {
        cout << "Error: ID already exists\n";
        return;
    }

    root = insertRec(root, id, name, dept);
}

StudentNode* StudentBST::searchRec(StudentNode* node, int id)
{
    if (!node || node->id == id)
        return node;

    if (id < node->id)
        return searchRec(node->left, id);

    return searchRec(node->right, id);
}

void StudentBST::search(int id)
{
    StudentNode* s = searchRec(root, id);

    if (!s)
    {
        cout << "Not found\n";
        return;
    }

    cout << "ID: " <<s->id  <<" NAME: "<< s->name  << " DEPARTMENT: "<< s->dept << endl;

}

void StudentBST::display()
{
    displayRec(root);
}

void StudentBST::displayRec(StudentNode* node)
{
    if (!node) return;

    displayRec(node->left);
    cout<<"------------------------------------------------------"<<endl;
    cout <<"ID: "<< node->id << "| NAME: "
         << node->name << "| DEPARTMENT: "
         << node->dept << endl;
    cout<<"------------------------------------------------------"<<endl;
    displayRec(node->right);
}
