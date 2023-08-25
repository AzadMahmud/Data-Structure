#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* adj_list[100] = {NULL};
int stack[100] = {-1};
int top = -1;

void push(int node) {
    stack[++top] = node;
}

void pop() {
    top--;
}

int peek() {
    return stack[top];
}

bool isempty() {
    return top == -1;
}

void add_edge(int from, int to) {
    Node* temp = adj_list[from];
    if (temp == NULL) {
        adj_list[from] = new Node(to);
        return;
    }

    Node* new_node = new Node(to);
    new_node->next = temp;
    adj_list[from] = new_node;
}

void print_graph(int size) {
    for (int i = 0; i < size; i++) {
        if (adj_list[i] == NULL) continue;
        cout << i << " ->  ";
        Node* temp = adj_list[i];
        while (temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }
}

void dfs(int from, int num_vertices) {
    bool is_visited[num_vertices] = {false};

    push(from);
    is_visited[from] = true;
    while (!isempty()) {
        int index = peek();
        pop();
        cout << index << ' ';

        Node* temp = adj_list[index];
        while (temp != NULL) {
            if (!is_visited[temp->data]) {
                push(temp->data);
                is_visited[temp->data] = true;
            }
            temp = temp->next;
        }
    }

    cout << '\n';
}

int main() {
    int n;
    cout << "number of vertices: ";
    cin >> n;

    int e;
    cout << "number of edges: ";
    cin >> e;

    cout << "edges:" << '\n';
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        add_edge(from, to);
    }

    print_graph(n);
    cout << '\n';
    dfs(0, n);
}