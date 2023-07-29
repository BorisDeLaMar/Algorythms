#include <iostream>
#include <map>

using namespace std;

struct Branch{
    Branch() {
        this->name = "";
        this->children = {};
    }

    Branch(string name) {
        this->name = name;
        this->children = {};
    }

    string name;
    map<string, Branch*> children;
};

void print_tree(Branch *cur_brnch, int depth) {
    for (int i = 0; i < depth - 1; i++) {
        cout << " ";
    }
    if (!cur_brnch->name.empty()) {
        cout << cur_brnch->name << "\n";
    }
    depth++;
    for (auto &child_brnch : cur_brnch->children) {
        print_tree(child_brnch.second, depth);
    }
}

int main() {
    int n;
    cin >> n;

    Branch *brnch = new Branch();

    for (int i = 0; i < n; i++) {
        string path;
        cin >> path;
        string dir;

        Branch *cur_brnch = brnch;

        for (int j = 0; j <= path.size(); j++) {
            if (path[j] == '\\' || path[j] == '\0') {
                auto dir_tr = cur_brnch->children.find(dir);

                if (dir_tr == cur_brnch->children.end()) {
                    Branch *new_brnch = new Branch(dir);
                    cur_brnch->children[dir] = new_brnch;
                    cur_brnch = cur_brnch->children.find(dir)->second;
                } else {
                    cur_brnch = dir_tr->second;
                }

                dir = "";
            } else {
                dir += path[j];
            }
        }

    }

    print_tree(brnch, 0);

    return 0;
}