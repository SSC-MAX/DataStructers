package Graph;

/*
* 图 Graph
* 概念：
*   顶点
*   边
*   路径
* 分类
*   1.无向图
*   2.有向图
*   3.权图（网）
* 表示
*   1.邻接矩阵（所有边都需要关心）
*   2.邻接表（只关心存在的边）
* */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

public class Graph {
    private ArrayList<String> vertextList; //存储顶点
    private int[][] edges;   //存储图对应的邻接矩阵
    private int numOfEdges;  //边的数量
    private boolean[] isVistsd; //记录是否被访问过

    public static void main(String[] args) {
        int n = 5; //结点个数
        String verTexts[] = {"A","B","C","D","E"};
       Graph graph = new Graph(n);
        for (int i = 0; i < verTexts.length ; i++) {
            graph.insertVertex(verTexts[i]);
        }
        //添加边
        //A-B A-C B-C B-D B-E
        graph.insertEdge(0,1,1);
        graph.insertEdge(0,2,1);
        graph.insertEdge(1,2,1);
        graph.insertEdge(1,3,1);
        graph.insertEdge(1,4,1);
        //显示图
        graph.showGraph();
        System.out.println("------深度优先算法------");
//        graph.dfs(graph.isVistsd, 0);
        System.out.println();
        System.out.println("------广度优先------");
        graph.bfs();
    }

    public Graph(int n){
        edges = new int[n][n];
        vertextList = new ArrayList<>(n);
        numOfEdges = 0;
        isVistsd = new boolean[n];
    }

    //插入结点
    public void insertVertex(String vertex){
        vertextList.add(vertex);
    }
    //添加边
    public void insertEdge(int v1, int v2, int weight){
        //v1与v2表示点的下标，weight表示权重，1代表有连接，0代表无连接
        //由于是无向图，所以还要反过来再写一遍
        edges[v1][v2] = weight;
        edges[v2][v1] = weight;
        numOfEdges++;
    }

    //返回结点的个数
    public int getNumOfVertex(){
        return vertextList.size();
    }
    //返回边的个数
    public int getNumOfEdges(){
        return numOfEdges;
    }
    //返回i对应的结点的数值
    public String getValueByIndex(int i){
        return vertextList.get(i);
    }
    //返回v1和v2的权值
    public int getWeight(int v1, int v2){
        return edges[v1][v2];
    }
    //显示矩阵
    public void showGraph(){
       for (int[] link:edges){
           System.out.println(Arrays.toString(link));
       }
    }

    /*
     * 深度优先搜索(dfs)
     * 从初始访问结点出发，它可能有多个邻接结点，先访问它的第一个邻接结点，再以该邻接结点为初始结点继续向下遍历
     * 这是一个递归的过程
     * 步骤：
     *  1.访问初始结点V，并将其标记已经访问
     *  2.查找V的第一个临界结点W
     *  3.若W存在，继续执行4，否则回到1，将W后一个的结点作为初始结点
     *  4.若W未被访问，将初始结点标记为W，对其进行深度优先搜索
     *  5.查找W的第一个邻接结点，继续3
     * 树的前中后序遍历都是深度优先
     */
    //得到第一个邻接结点的下标 w
    public int getFirstNeighbor(int index){
        for (int i = 0; i <vertextList.size() ; i++) {
            //这样一旦遍历到第一个为1（即表示有连接）就会返回index
            if (edges[index][i] > 0){
                return i;
            }
        }
        //循环结束还没有遍历到则认为没有邻接结点
        return -1;
    }
    //根据前一个邻接结点的下标来获取下一个邻接结点
    public int getNextNeighbor(int v1, int v2){
        for (int i = v2+1; i <vertextList.size() ; i++) {
            if (edges[v1][i] > 0){
                return i;
            }
        }
        return -1;
    }
    //深度优先遍历
    public void dfs(boolean[] isVistsd, int i){
        //首先访问该节点
        System.out.print(getValueByIndex(i)+"->");
        //访问后将结点置为已访问
        isVistsd[i] = true;
        //获取第一个邻接结点
        int w = getFirstNeighbor(i);
        while (w!=-1){
            if (!isVistsd[w]){
                dfs(isVistsd,w);
            }
            w = getNextNeighbor(i,w);
        }
    }
    //对dfs重载，即为了保证每一个节点都会被遍历到
    //如A-B,A-C,B-D，E-F如果没有以下重载，按照原数组进行，则只会遍历A的部分，不会遍历E,F
    public void dfs(){
        for (int i = 0; i <getNumOfVertex(); i++) {
            if (!isVistsd[i]){
                dfs(isVistsd,i);
            }
        }
    }

    /**
     * 广度优先遍历 bfs
     * 先遍历当前节点的所有邻接结点，再遍历下一个结点的
     */
    //广度优先遍历
    public void bfs(boolean[] isVisited, int i){
        int u; //队列头结点对应的下标
        int w; //邻接结点的下标
        //需要一个队列记录结点访问的顺序
        LinkedList queue = new LinkedList();
        //访问结点
        System.out.print(getValueByIndex(i)+"->");
        //访问结束后标记为已访问
        isVisited[i] = true;
        //将结点加入队列
        queue.addLast(i);
        while (!queue.isEmpty()){
            //取出队列的头结点下标
            u = (Integer)queue.removeFirst();
            //得到第一个邻接点的下标w
            w = getFirstNeighbor(u);
            while (w!=-1){
                //是否访问过
                if (!isVistsd[w]){
                    System.out.println(getValueByIndex(w)+"=>");
                    isVisited[w] = true;
                    //入队列
                    queue.addLast(w);
                }
                //若w已经被访问过，则找w后一个邻接结点进行访问
                w=getNextNeighbor(u,w); //这里就体现出了广度优先的思想
            }
            //一层while结束代表一层广度结束
        }
    }
    //遍历所有结点，都进行广度优先（道理同深度优先重载）
    public void bfs(){
        for (int i = 0; i <getNumOfVertex() ; i++) {
            if (!isVistsd[i]){
                bfs(isVistsd,i);
            }
        }
    }
}
