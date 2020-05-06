#ifndef LEETCODE_H_
#define LEETCODE_H_

#include <iostream>
#include <string>
#include <vector>

// ---- vectors ----

std::istream& operator>>(std::istream& is, std::vector<int>& v);
std::ostream& operator<<(std::ostream& os, std::vector<int> const& v);

std::istream& operator>>(std::istream& is, std::vector<std::vector<int>>& vv);
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<int>> const& vv);

std::ostream& operator<<(std::ostream& os, std::vector<std::string> const& vs);

// ---- ListNode ----

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};
void DeleteList(ListNode* list);

std::istream& operator>>(std::istream& is, ListNode*& list);
std::ostream& operator<<(std::ostream& os, ListNode* list);

ListNode* Vector2List(std::vector<int> const& v);

// ---- TreeNode ----

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int val) : left(nullptr), right(nullptr), val(val) {}
};
void DeleteTree(TreeNode* tree);

std::istream& operator>>(std::istream& is, TreeNode*& tree);
std::ostream& operator<<(std::ostream& os, TreeNode* tree);

// ---- go-style print ----

template<class T>
void print(const T& t)
{
    std::cout << t;
}

template<class T, class ...Args>
void print(const T& t, Args ...args)
{
    std::cout << t << " ";
    print(args...);
}

template<class ...Args>
void println(Args ...args)
{
    if (sizeof...(args)) print(args...);
    std::cout << std::endl;
}

#endif