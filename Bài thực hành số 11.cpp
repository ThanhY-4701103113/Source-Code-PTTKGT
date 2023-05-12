#include <iostream>
#include <climits>

using namespace std;

const int MAX = 100;

void dijkstra(int graph[MAX][MAX], int n, int s) {
    int dist[MAX]; // Lưu trữ khoảng cách ngắn nhất từ s đến các đỉnh trong đồ thị
    bool visited[MAX] = { false }; // Đánh dấu các đỉnh đã được duyệt
    int previous[MAX]; // Lưu trữ đỉnh trước đỉnh hiện tại trên đường đi ngắn nhất

    // Khởi tạo các giá trị ban đầu cho dist và previous
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        previous[i] = -1;
    }
    dist[s] = 0;

    // Thực hiện thuật toán Dijkstra
    for (int count = 0; count < n - 1; count++) {
        // Tìm đỉnh chưa được duyệt có đường đi ngắn nhất từ s đến nó là nhỏ nhất
        int u = -1;
        int minDist = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                u = v;
                minDist = dist[v];
            }
        }

        // Đánh dấu đỉnh đã được duyệt
        visited[u] = true;

        // Cập nhật đường đi ngắn nhất từ s đến các đỉnh kề của đỉnh u
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }

    // In ra đường đi ngắn nhất từ s đến các đỉnh trong đồ thị và trọng số của chúng
    cout << "Đường đi ngắn nhất đến từ " << s << ":\n";
    for (int i = 0; i < n; i++) {
        if (i != s) {
            cout << "Vertex " << i << ": ";
            if (dist[i] != INT_MAX) {
                cout << dist[i] << " (";
                int j = i;
                while (j != s) {
                    cout << j << " <- ";
                    j = previous[j];
                }
                cout << s << ")\n";
            }
            else {
                cout << "Không có đường đi.\n";
            }
        }
    }
}

int main() {
    int n; // Số đỉnh trong đồ thị
    int graph[MAX][MAX]; // Ma trận kề của đồ thị
    int s; // Đỉnh nguồn

    // Nhập thông tin về đồ thị
    cout << "Nhập số đỉnh: ";
    cin >> n;
    cout << "Nhập ma trận kề\n";
    // Nhập ma trận kề của đồ thị
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Nhập đỉnh nguồn
    cout << "Nhập đỉnh dừng: ";
    cin >> s;

    // Tìm đường đi ngắn nhất từ đỉnh nguồn
    dijkstra(graph, n, s);

    return 0;
}