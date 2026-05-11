#include "coursebst.h"
#include <iostream>

using namespace std;

CourseBST::CourseBST()
{
    root = nullptr;
}

CourseNode* CourseBST::insertRec(CourseNode* node, int code, string title)
{
    if (!node)
    {
        CourseNode* n = new CourseNode;
        n->code = code;
        n->title = title;
        n->left = n->right = nullptr;
        return n;
    }

    if (code < node->code)
        node->left = insertRec(node->left, code, title);
    else
        node->right = insertRec(node->right, code, title);

    return node;
}

void CourseBST::insert(int code, string title)
{
    if(exists(code))
    {
        cout << "Error: Course already exists\n";

        return;
    }
    root = insertRec(root, code, title);
}

CourseNode* CourseBST::searchRec(CourseNode* node, int code)
{
    if (!node || node->code == code)
        return node;

    if (code < node->code)
        return searchRec(node->left, code);

    return searchRec(node->right, code);
}

void CourseBST::search(int code)
{
    CourseNode* c = searchRec(root, code);

    if (!c)
    {
        cout << "Course not found\n";
        return;
    }

    cout << c->code << " | " << c->title << endl;
}

void CourseBST::display()
{
    inorderRec(root);
}

void CourseBST::inorderRec(CourseNode* node)
{
    if (!node) return;

    inorderRec(node->left);
    cout << node->code << " | " << node->title << endl;
    inorderRec(node->right);
}

bool CourseBST::exists(int code)
{
    return searchRec(root, code) != nullptr;
}
