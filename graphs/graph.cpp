#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

enum COLOR { White, Grey, Black };

struct vertices {
    int vertices = 0;
    COLOR color = White;
};

struct edge {
    int edge[2];
    COLOR color = White;
};

typedef struct graph {
    vector<struct vertices> V;
    vector<struct edge> E;
} graph_t;


int main(int argc, char **argv)
{
    graph_t G;

    return 0;
}
