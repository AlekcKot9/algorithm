#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Функция поиска максимальной глубины дерева
long long search_deep(unordered_map<long long, vector<long long>> &tree, long long node, long long depth) {
    if (node == -1 || tree.find(node) == tree.end()) return depth - 1; // Проверяем, существует ли узел

    long long left_depth = search_deep(tree, tree[node][0], depth + 1);
    long long right_depth = search_deep(tree, tree[node][1], depth + 1);

    return max(left_depth, right_depth);
}

// Функция вставки узла в бинарное дерево поиска
void insert_node(unordered_map<long long, vector<long long>> &tree, long long root, long long val) {
    if (tree.find(val) != tree.end()) return; // Узел уже существует, не добавляем его

    long long node = root;
    while (true) {
        if (val < node) {
            if (tree[node][0] == -1) {
                tree[node][0] = val;
                tree[val] = {-1, -1}; // Создаём новый узел
                break;
            }
            node = tree[node][0];
        } else {
            if (tree[node][1] == -1) {
                tree[node][1] = val;
                tree[val] = {-1, -1}; // Создаём новый узел
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
    tree[root] = {-1, -1}; // Корень дерева

    long long val;
    while (cin >> val) {
    	if(val==0) break;
        insert_node(tree, root, val);
    }

    cout << search_deep(tree, root, 1) << endl;
    return 0;
}

