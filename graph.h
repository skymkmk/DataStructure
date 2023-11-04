// 使用邻接表法

// 边节点
typedef struct ENode {
    int adjvex; // 该边在顶点表中的位置
    struct ENode *next; // 下一个边
} ENode;

// 顶点节点
typedef struct VNode {
    int data; // 顶点数据
    ENode *first; // 第一个相连的边
} VNode;

typedef struct graph {
    VNode* vertices;
    int length;
} graph;

// 生成顶点表
VNode * newVertices(const int length, const int data[]); // length 为顶点数量，data 数组为其内容

// 设置边
void setEdge(VNode *const vertices, const int vertice, const int adjvex); // vertices 为顶点表，vertice 为顶点，adjvex 为邻接顶点

// 从文件输入图
graph generateGraphFromFile(const char filename[]);

// 打印图
void printGraph (const graph theGrpah);