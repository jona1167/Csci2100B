#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//Dijkstra’s Algorithm
struct AdjListNode{
    int dest;
    int weight;
    struct AdjListNode *next;
};
 
struct AdjList{
    struct AdjListNode *head;
};
 
struct Graph{
    int V;
    struct AdjList *array;
};
 
struct AdjListNode *newAdjListNode(int dest, int weight){
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph *createGraph(int V){
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
 
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
}
 
void addEdge(struct Graph *graph, int src, int dest, int weight){
    struct AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    //undirected
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
struct MinHeapNode{
    int v;
    int dist;
};
 
struct MinHeap{
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};
 
struct MinHeapNode *newMinHeapNode(int v, int dist){
    struct MinHeapNode *minHeapNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}
 
struct MinHeap *createMinHeap(int capacity){
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}
 
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b){
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}
 
void minHeapify(struct MinHeap *minHeap, int idx){
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * (idx + 1);
 
    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;
 
    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;
 
    if (smallest != idx)
    {
        struct MinHeapNode *smallestNode = minHeap->array[smallest];
        struct MinHeapNode *idxNode = minHeap->array[idx];
 
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
 
        minHeapify(minHeap, smallest);
    }
}
 
struct MinHeapNode *extractMin(struct MinHeap *minHeap){
    if (minHeap->size == 0)
        return NULL;
    struct MinHeapNode *root = minHeap->array[0];
 
    struct MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
 
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return root;
}
 
void decreaseKey(struct MinHeap *minHeap, int v, int dist){
    int i = minHeap->pos[v];
 
    minHeap->array[i]->dist = dist;
 
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void dijkstra(struct Graph *graph, int src)
{
 
    int V = graph->V;
    int dist[V];
    memset(dist,-1,sizeof(dist));
    int next[V+1];
    memset(next,-1,sizeof(next));
    
    struct MinHeap *minHeap = createMinHeap(V);
 
    for (int v = 0; v < V; ++v){
            dist[v] = 2147483647;
            minHeap->array[v] = newMinHeapNode(v, dist[v]);
            minHeap->pos[v] = v;
        
    }
    //set the first
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
 
    minHeap->size = V;
 
    while (minHeap->size != 0){
        struct MinHeapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        struct AdjListNode *pCrawl = graph->array[u].head;
        while (pCrawl != NULL){
            int v = pCrawl->dest;
            if (minHeap->pos[v] < minHeap->size && dist[u] != 2147483647
             && pCrawl->weight + dist[u] < dist[v]){
                dist[v] = dist[u] + pCrawl->weight;
                next[v] = u;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    //display
    int ans[V], num=0;
    int i = V-1;
 
    while(i != -1){
        ans[num] = i;
        //printf("%d",next[i]);
        i = next[i];

        num++;
    }
 
    if(num==1){//if cannot find
        printf("-1");
    }
    else{
        //printf("ans");
        for(int i = num-1; i > -1; i--){
            
            printf("%d ", ans[i]+1);
        }
    }
    
    
}
 
int main(){
    int n, m,num1,num2,num3;
    scanf("%d %d", &n, &m);//grt

    struct Graph *a = createGraph(n);
    for (int i = 0; i < m; i++){

        scanf("%d %d %d", &num1, &num2, &num3);
        addEdge(a, num1-1, num2-1, num3);//start at 0
    }

    dijkstra(a, 0);//0mean start from 0;
    
    return 0;
}