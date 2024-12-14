#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct Edge
{
    int to, weight;
};

void dijkstra(int start, vector<vector<Edge>> &graph, vector<int> &distance)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > distance[currentNode])
            continue;

        for (const Edge &edge : graph[currentNode])
        {
            int nextNode = edge.to;
            int newDist = currentDist + edge.weight;

            if (newDist < distance[nextNode])
            {
                distance[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }
}

int main()
{
    int jumlahKota, jumlahJalur;

    cout << "Masukkan jumlah kota: ";
    cin >> jumlahKota;
    cout << "Masukkan jumlah jalur: ";
    cin >> jumlahJalur;

    vector<vector<Edge>> graph(jumlahKota + 1);

    cout << "Masukkan jalur antar kota dan jaraknya (Input kotanya dengan angka (contoh : 1(nama kota) 2(kota tujuan) 10(panjang jarak ke kota tujuan)):\n";
    for (int i = 0; i < jumlahJalur; i++)
    {
        int kota1, kota2, jarak;
        cin >> kota1 >> kota2 >> jarak;
        graph[kota1].push_back({kota2, jarak});
        graph[kota2].push_back({kota1, jarak});
    }

    int start, end;
    cout << "Masukkan kota awal: ";
    cin >> start;
    cout << "Masukkan kota tujuan: ";
    cin >> end;

    vector<int> distance(jumlahKota + 1, INT_MAX);

    dijkstra(start, graph, distance);

    if (distance[end] == INT_MAX)
    {
        cout << "Tidak ada jalur dari kota " << start << " ke kota " << end << ".\n";
    }
    else
    {
        cout << "Jarak terpendek dari kota " << start << " ke kota " << end << ": " << distance[end] << "\n";
    }

    return 0;
}
