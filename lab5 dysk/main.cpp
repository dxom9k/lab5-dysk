#include <iostream>
#include <vector>
#include <string>
#include<Windows.h>
using namespace std;

// Функція для перевірки, чи можна присвоїти колір вершині
bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& colors, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// Функція для розфарбування графа з умовою, що вершини 3 і 5 мають однаковий колір
bool colorGraph(vector<vector<int>>& graph, vector<int>& colors, int vertex, int numColors) {
    if (vertex == graph.size()) {
        return true;
    }

    // Якщо розглядається вершина 5, вона має отримати той самий колір, що й вершина 3
    if (vertex == 4) { // вершина 5 має індекс 4
        colors[vertex] = colors[2]; // встановлюємо той самий колір, що й у вершини 3 (індекс 2)
        return colorGraph(graph, colors, vertex + 1, numColors);
    }

    for (int color = 1; color <= numColors; color++) {
        if (isSafe(vertex, graph, colors, color)) {
            colors[vertex] = color;
            if (colorGraph(graph, colors, vertex + 1, numColors)) {
                return true;
            }
            colors[vertex] = 0; // відкат, якщо колір не підходить
        }
    }

    return false;
}

// Основна функція
int main() {
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть кількість вершин графа: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Введіть матрицю суміжності:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> colors(n, 0);
    int numColors = n; // Мінімальна кількість кольорів для повного графа з n вершинами

    // Назви кольорів
    vector<string> colorNames = { "Червоний", "Зелений", "Синій", "Жовтий", "Оранжевий", "Фіолетовий", "Блакитний", "Коричневий", "Чорний", "Білий" };

    if (colorGraph(graph, colors, 0, numColors)) {
        cout << "Розфарбування графа успішне. Кольори вершин:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Вершина " << i + 1 << ": Колір " << colorNames[colors[i] - 1] << endl;
        }
    }
    else {
        cout << "Не вдалося розфарбувати граф з заданою кількістю кольорів." << endl;
    }

    return 0;
}
