#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Функция вставки узла в бинарное дерево поиска
long long insert_node(unordered_map<long long, vector<long long>> &tree, long long root, long long val) {

    long long depth=1;
    long long node = root;
    while (true) {
        ++depth;
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
    return depth;
}

int main() {
    long long root;
    if (!(cin >> root)) return 1; // Проверяем, что ввод не пустой

    vector<long long> ans={1};
    unordered_map<long long, vector<long long>> tree;
    tree[root] = {-1, -1}; // Корень дерева

    long long val;
    while (cin >> val) {
        if(val==0) break;
        if (tree.find(val) != tree.end()) continue; // Узел уже существует, не добавляем его
        ans.push_back(insert_node(tree, root, val));
    }

    for(long long el:ans)
      cout << el << " ";
    return 0;
}


