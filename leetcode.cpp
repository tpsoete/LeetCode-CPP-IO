#include "leetcode.h"

#include <charconv>
#include <queue>

using namespace std;

static void read_vint(vector<int>& v, const string& s)
{
    v.clear();
    if (s.size() == 2) return;
    size_t i = 1;
    while (i < s.size()) {
        size_t j = s.find(',', i);
        if (j == s.npos) j = s.size() - 1;
        v.emplace_back(stoi(s.substr(i, j - i)));
        i = j + 1;
    }
}

istream& operator>>(istream& is, vector<int>& v)
{
    string s;
    is >> s;
    read_vint(v, s);
    return is;
}

ostream& operator<<(ostream& os, vector<int> const& v)
{
    if (v.empty()) return os << "[]";
    os << "[" << v.front();
    for (size_t i = 1; i < v.size(); i++) cout << "," << v[i];
    return os << "]";
}

istream& operator>>(istream& is, vector<vector<int>>& vv)
{
    string s;
    is >> s;
    size_t i = 1, j;
    vv.clear();
    for (;;) {
        for (j = i; j < s.size(); j++) if (s[j] == ']') break;
        ++j;
        read_vint(vv.emplace_back(), s.substr(i, j - i));
        if (s[j] == ']') break;
        i = ++j;
    }
    return is;
}

ostream& operator<<(ostream& os, vector<vector<int>> const& vv)
{
    os << "[\n";
    for (auto& v : vv)  os << v << ",\n";
    return os << "]\n";
}

void DeleteList(ListNode* list)
{
    ListNode* p;
    while (list != nullptr) {
        p = list;
        list = list->next;
        delete p;
    }
}

istream& operator>>(istream& is, ListNode*& list)
{
    vector<int> v;
    is >> v;
    list = nullptr;
    ListNode* tail = nullptr;
    for (auto i : v) {
        if (list == nullptr) list = tail = new ListNode(i);
        else tail = tail->next = new ListNode(i);
    }
    return is;
}

ostream& operator<<(ostream& os, ListNode* list)
{
    ListNode* p = list;
    os << "[";
    bool first = true;
    while (p != nullptr) {
        if (first) first = false;
        else os << ",";
        os << p->val;
        p = p->next;
    }
    return os << "]";
}

void DeleteTree(TreeNode* tree)
{
    if (tree->left) DeleteTree(tree->left);
    if (tree->right) DeleteTree(tree->right);
    delete tree;
}

static string serialize(TreeNode* root)
{
    string s = "[";
    bool first = true;
    queue<TreeNode*> q;
    q.push(root);
    int nodes = 1;
    while (nodes && !q.empty()) {
        if (first) first = false;
        else s += ',';
        auto p = q.front();
        q.pop();
        if (p == nullptr) s += "null";
        else {
            --nodes;
            q.push(p->left);
            q.push(p->right);
            if (p->left) ++nodes;
            if (p->right) ++nodes;
            s += to_string(p->val);
        }
    }
    return s += "]";
}

static TreeNode* deserialize(string const& data)
{
    char s[16];
    auto* p = data.c_str() + 1;
    if (*p == ']') return nullptr;
    TreeNode* ans = nullptr;
    queue<TreeNode**> q;
    q.push(&ans);
    while (*p != '\0') {
        int ofs;
        sscanf(p, "%[^],]%n", s, &ofs);
        p += ofs + 1;
        TreeNode*& rp = *q.front();
        q.pop();
        if (strcmp(s, "null") != 0) {
            rp = new TreeNode(atoi(s));
            q.push(&rp->left);
            q.push(&rp->right);
        }
    }
    return ans;
}

std::istream& operator>>(std::istream& is, TreeNode*& tree)
{
    string s;
    is >> s;
    tree = deserialize(s);
    return is;
}

std::ostream& operator<<(std::ostream& os, TreeNode* tree)
{
    return os << serialize(tree);
}