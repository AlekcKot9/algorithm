#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Функция поиска второго максимального элемента в дереве
long long search_second_max_el(unordered_map<long long, vector<long long>>& tree, long long root) {

    long long val=0;
    long long node=root;
    while (tree[root][1]!=0) {
        if (tree[node][1]==0) {
            if (tree[node][0]!=0) {
                node=tree[node][0];
                while (tree[node][1]!=0) {
                    node=tree[node][1];
                }
                return node;
            }
            return val;
        }
        val=node;
        node=tree[node][1];
    }
}

// Функция вставки узла в бинарное дерево поиска
void insert_node(unordered_map<long long, vector<long long>> &tree, long long root, long long val) {

    long long node = root;
    while (true) {
        if (val < node) {
            if (tree[node][0] == 0) {
                tree[node][0] = val;
                tree[val] = {0, 0}; // Создаём новый узел
                break;
            }
            node = tree[node][0];
        } else {
            if (tree[node][1] == 0) {
                tree[node][1] = val;
                tree[val] = {0, 0}; // Создаём новый узел
                break;
            }
            node = tree[node][1];
        }
    }
}

int main() {
    long long root;
    if (!(cin >> root)) return 1; // Проверяем, что ввод не пустой

    unordered_map<long long, vector<long long>> tree;
    tree[root] = {0, 0}; // Корень дерева

    long long val;
    while (cin >> val) {
        if(val==0) break;
        if (tree.find(val) != tree.end()) continue; // Узел уже существует, не добавляем его
        insert_node(tree, root, val);
    }

    cout<<search_second_max_el(tree, root);
    return 0;
}


