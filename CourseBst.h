#ifndef COURSEBST_H_INCLUDED
#define COURSEBST_H_INCLUDED

#include <string>
using namespace std;

struct CourseNode
{
    int code;
    string title;

    CourseNode* left;
    CourseNode* right;
};

class CourseBST
{
private:
    CourseNode* root;

    CourseNode* insertRec(CourseNode* node, int code, string title);
    CourseNode* searchRec(CourseNode* node, int code);
    void inorderRec(CourseNode* node);

public:
    CourseBST();

    void insert(int code, string title);
    void search(int code);
    void display();
    bool exists(int code);
    string getTitle(int code);
};

#endif
