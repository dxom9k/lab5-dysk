#include <iostream>
#include <vector>
#include <string>
#include<Windows.h>
using namespace std;

// ������� ��� ��������, �� ����� �������� ���� ������
bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& colors, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}

// ������� ��� ������������� ����� � ������, �� ������� 3 � 5 ����� ��������� ����
bool colorGraph(vector<vector<int>>& graph, vector<int>& colors, int vertex, int numColors) {
    if (vertex == graph.size()) {
        return true;
    }

    // ���� ������������ ������� 5, ���� �� �������� ��� ����� ����, �� � ������� 3
    if (vertex == 4) { // ������� 5 �� ������ 4
        colors[vertex] = colors[2]; // ������������ ��� ����� ����, �� � � ������� 3 (������ 2)
        return colorGraph(graph, colors, vertex + 1, numColors);
    }

    for (int color = 1; color <= numColors; color++) {
        if (isSafe(vertex, graph, colors, color)) {
            colors[vertex] = color;
            if (colorGraph(graph, colors, vertex + 1, numColors)) {
                return true;
            }
            colors[vertex] = 0; // �����, ���� ���� �� ��������
        }
    }

    return false;
}

// ������� �������
int main() {
    SetConsoleOutputCP(1251);
    int n;
    cout << "������ ������� ������ �����: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "������ ������� ��������:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> colors(n, 0);
    int numColors = n; // ̳������� ������� ������� ��� ������� ����� � n ���������

    // ����� �������
    vector<string> colorNames = { "��������", "�������", "����", "������", "���������", "Գ��������", "���������", "����������", "������", "�����" };

    if (colorGraph(graph, colors, 0, numColors)) {
        cout << "������������� ����� ������. ������� ������:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "������� " << i + 1 << ": ���� " << colorNames[colors[i] - 1] << endl;
        }
    }
    else {
        cout << "�� ������� ������������ ���� � ������� ������� �������." << endl;
    }

    return 0;
}
