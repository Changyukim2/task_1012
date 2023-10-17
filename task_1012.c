#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct graphytype {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}graphtype;

void init(graphtype* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;

}

void insert_vertex(graphtype* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과 ");
		return;
	}
	g->n++;
}

void insert_edge(graphtype* g, int start, int end) {
	if (start >= g->n || end > g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류 ");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void print_adj(graphtype* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}
 void count_edges(graphtype* g) {
	int count = 0;
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			if (g->adj_mat[i][j] == 1) {
				count++;
			}
		}
	}
	printf("총 엣지 수: %d\n", count/2);
}

 void find_degree(graphtype* g, int n) {
	 int degree = 0;
	 for (int i = 0; i < g->n; i++) {
		 if (g->adj_mat[n][i] == 1) {
			 degree++;
		 }
	 }
	 printf("정점 %d의 차수: %d\n", n+1, degree);
 }

void edge_exist(graphtype* g, int m, int n) {
	if (g->adj_mat[m][n] == 1 || g->adj_mat[n][m] == 1) {
		 printf("정점 %d과 정점 %d 사이에 엣지가 존재합니다.\n", m+1, n+1);
	 }
	else {
		 printf("정점 %d과 정점 %d 사이에 엣지가 존재하지 않습니다.\n", m+1, n+1);
	 }
 }

void list_conn_vertex(graphtype* g, int n) {
	 printf("정점 %d과 연결된 정점들: ", n+1);
	 for (int i = 0; i < g->n; i++) {
		 if (g->adj_mat[n][i] == 1) {
			 printf("%d ", i+1);
		 }
	 }
	 printf("\n");
 }

int main(void) {
	graphtype* g;
	g = (graphtype*)malloc(sizeof(graphtype));
	init(g);
	for (int i = 0; i<5; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 4);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 4);
	print_adj(g);
	count_edges(g);
	find_degree(g, 0);
	edge_exist(g, 1, 3);
	list_conn_vertex(g, 0);
	free(g);
}