#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using std::vector;
using std::string;

/*
 * 1.采用邻接链表来建立，让数据结构尽可能简单，更加容易快速构建;
 * 2.实现基本的算法;
 * 3.常见的无向图算法;
 */
class UnorderGraph
{
public:
    UnorderGraph(int n);
    int GetVerticeCount();
    int GetEdgeCount();
    void AddEdge(int v, int w);
    vector<int> GetAdjVec(int v);
    string ToString();
private:
    vector<vector<int>> oAdjVec;
};

UnorderGraph::UnorderGraph(int n): oAdjVec(n)
{
}

int UnorderGraph::GetVerticeCount()
{
    return oAdjVec.size();
}

int UnorderGraph::GetEdgeCount()
{
    int iCount = 0;
    for (const auto & vec: oAdjVec)
    {
        iCount += vec.size();
    }
    return iCount / 2;
}

void UnorderGraph::AddEdge(int v, int w)
{
    oAdjVec[v].push_back(w);
    oAdjVec[w].push_back(v);
}

vector<int> UnorderGraph::GetAdjVec(int v)
{
    return oAdjVec[v];
}

string UnorderGraph::ToString()
{
    string sGraphString;
    for (int i = 0; i < oAdjVec.size(); i++)
    {
        sGraphString.append(std::to_string(i)).append(": ");
        for (int x: oAdjVec[i])
        {
            sGraphString.append(std::to_string(x)).append(" ");
        }
        sGraphString.append("\n");
    }
    return sGraphString;
}

/*
 * 1.dfs算法;
 * 2.从源点s到所有的点的路径;
 */
class DfsSearcher
{
public:
    DfsSearcher(UnorderGraph & graph, int s);
    void Dfs(UnorderGraph & graph, int v);
    bool HasPathTo(int v);
    vector<int> GetPath(int v);
private:
    vector<bool> oMarked;
    vector<int> oEdgeVec;
    UnorderGraph oGraph;
    int iStart;
};

DfsSearcher::DfsSearcher(UnorderGraph & graph, int s):
    oGraph(graph), iStart(s), oMarked(graph.GetVerticeCount(), false), oEdgeVec(graph.GetVerticeCount(), 0)
{
    Dfs(oGraph, iStart);
}

void DfsSearcher::Dfs(UnorderGraph & graph, int v)
{
    oMarked[v] = true;
    vector<int> oAdjVec = graph.GetAdjVec(v);
    for (int w: oAdjVec)
    {
        if (!oMarked[w])
        {
            oEdgeVec[w] = v;
            Dfs(graph, w);
        }
    }
}

bool DfsSearcher::HasPathTo(int v)
{
    return oMarked[v];
}

vector<int> DfsSearcher::GetPath(int v)
{
    vector<int> oPath;
    if (!HasPathTo(v))
    {
        return oPath;
    }
    for (int x = v; x != iStart; x = oEdgeVec[x])
    {
        oPath.push_back(x);
    }
    std::reverse(oPath.begin(), oPath.end());
    return oPath;
}

int main(int argc, char ** argv)
{
    UnorderGraph oGraph(10);
    oGraph.AddEdge(0, 1);
    oGraph.AddEdge(2, 3);
    oGraph.AddEdge(4, 9);
    oGraph.AddEdge(4, 8);
    oGraph.AddEdge(8, 7);
    oGraph.AddEdge(1, 4);

    printf("oGraph:\n%s\n", oGraph.ToString().c_str());

    DfsSearcher oSearch(oGraph, 1);
    for (int i = 0; i < 10; i++)
    {
        printf("%d hasPathTo %d: %d\n", 1, i, oSearch.HasPathTo(i));
    }
    return 0;
}
