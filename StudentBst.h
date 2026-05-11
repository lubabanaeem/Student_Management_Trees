#ifndef STUDENTBST_H_INCLUDED
#define STUDENTBST_H_INCLUDED

#include <string>
using namespace std;

struct StudentNode
{
    int id;
    string name;
    string dept;

    StudentNode* left;
    StudentNode* right;
};

class StudentBST
{
private:
    StudentNode* root;

    StudentNode* insertRec(StudentNode* node, int id, string name, string dept);
    StudentNode* searchRec(StudentNode* node, int id);
    void displayRec(StudentNode* node);

public:
    StudentBST();

    void insert(int id, string name, string dept);
    void search(int id);
    void display();
    bool exists(int id);
};

#endif
