#include <cstring>
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
int queue[100] = {-1};
int top = -1, rear = -1;

void push(int node) {
    queue[++rear] = node;
}

void pop() {
    top++;
}

int peek() {
    return queue[top + 1];
}

bool isempty() {
    return top == rear;
}

void add_edge(int from, int to) {
    Node* temp = adj_list[from];
    Node* temp2 = adj_list[to];
    if (temp == NULL) {
        adj_list[from] = new Node(to);
    } else {
        Node* new_node = new Node(to);
        new_node->next = temp;
        adj_list[from] = new_node;
    }

    if (temp2 == NULL) {
        adj_list[to] = new Node(from);
    } else {
        Node* new_node = new Node(from);
        new_node->next = temp2;
        adj_list[to] = new_node;
    }
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

void bfs(int from, int num_vertices) {
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
void ss_shortest_path(int from, int to, int num_vertices) {
    bool is_visited[num_vertices] = {false};
    int prev[num_vertices];
    memset(prev, -1, num_vertices * sizeof(int));

    push(from);
    is_visited[from] = true;
    while (!isempty()) {
        int index = peek();
        pop();
        Node* temp = adj_list[index];
        while (temp != NULL) {
            int temp_data = temp->data;
            if (!is_visited[temp_data]) {
                push(temp_data);
                is_visited[temp_data] = true;
                prev[temp_data] = index;
            }
            temp = temp->next;
        }
    }

    int tracker = to;
    int path[num_vertices];
    int path_size = 0;
    while (tracker != from) {
        // cout << tracker << ' ';
        path[path_size++] = tracker;
        tracker = prev[tracker];
        if (tracker == -1) {
            cout << "no path exist" << '\n';
            return;
        };
    }

    // cout << from << '\n';
    path[path_size] = from;
    for (int i = path_size; i >= 0; i--) cout << path[i] << ' ';
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
    bfs(0, n);
    cout << '\n';
    // ss_shortest_path(0, 5, n);
}

/*

6
9
0 1
0 2
0 3
1 3
1 4
1 5
2 3
3 5
4 5

*/