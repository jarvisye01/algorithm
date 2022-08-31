#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <sched.h>
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::deque;

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
    for (size_t i = 0; i < oEdgeVec.size(); i++)
    {
        oEdgeVec[i] = i;
    }
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
    oPath.push_back(iStart);
    std::reverse(oPath.begin(), oPath.end());
    return oPath;
}

/*
 * 1.bfs算法;
 * 2.从原点s到所有点的路径;
 */
class BfsSearcher
{
public:
    BfsSearcher(UnorderGraph & graph, int s);
    void Bfs(UnorderGraph & graph, int v);
    bool HasPathTo(int v);
    vector<int> GetPath(int v);
private:
    vector<bool> oMarked;
    vector<int> oEdgeVec;
    UnorderGraph oGraph;
    int iStart;
};

BfsSearcher::BfsSearcher(UnorderGraph & graph, int s):
    oGraph(graph), iStart(s), oMarked(graph.GetVerticeCount(), false), oEdgeVec(graph.GetVerticeCount(), 0)
{
    for (size_t i = 0; i < oEdgeVec.size(); i++)
    {
        oEdgeVec[i] = i;
    }
    Bfs(oGraph, iStart);
}

void BfsSearcher::Bfs(UnorderGraph & oGraph, int v)
{
    deque<int> oQueue;
    oQueue.push_back(v);
    while (!oQueue.empty())
    {
        int x = oQueue.front();
        oQueue.pop_front();
        vector<int> oAdjVec = oGraph.GetAdjVec(x);
        for (int w: oAdjVec)
        {
            if (!oMarked[w])
            {
                oMarked[w] = true;
                oEdgeVec[w] = x;
                oQueue.push_back(w);
            }
        }
    }
    return;
}

bool BfsSearcher::HasPathTo(int v)
{
    return oMarked[v];
}

// 这里还有一个定理: For any vertex v reachable from s, BFS computes a shortest path from s to v (no path from s to v has fewer edges)
vector<int> BfsSearcher::GetPath(int v)
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
    oPath.push_back(iStart);
    std::reverse(oPath.begin(), oPath.end());
    return oPath;
}

class ConnectedComponents
{
public:
    ConnectedComponents(UnorderGraph & graph);
    void Dfs(UnorderGraph & graph, int v);
    bool Connected(int v, int w);
    int GetId(int v);
    int GetCount();
private:
    vector<bool> oMarked;
    vector<int> oIdVec;
    UnorderGraph & oGraph;
    int iCount;
};

ConnectedComponents::ConnectedComponents(UnorderGraph & graph):
    oGraph(graph), oMarked(graph.GetVerticeCount(), false), oIdVec(graph.GetVerticeCount(), 0), iCount(0)
{
    for (int v = 0; v < graph.GetVerticeCount(); v++)
    {
        if (!oMarked[v])
        {
            Dfs(oGraph, v);
            iCount++;
        }
    }
}

void ConnectedComponents::Dfs(UnorderGraph & graph, int v)
{
    oMarked[v] = true;
    oIdVec[v] = iCount;
    for (int w: graph.GetAdjVec(v))
    {
        if (!oMarked[w])
        {
            Dfs(graph, w);
        }
    }
}

bool ConnectedComponents::Connected(int v, int w)
{
    return oIdVec[v] == oIdVec[w];
}

int ConnectedComponents::GetId(int v)
{
    return oIdVec[v];
}

int ConnectedComponents::GetCount()
{
    return iCount;
}

class Cycle
{
public:
    Cycle(UnorderGraph & graph);
    void Dfs(UnorderGraph & graph, int v, int p);
    bool HasCycle();
private:
    vector<bool> oMarked;
    bool bHasCycle;
    UnorderGraph oGraph;
};

Cycle::Cycle(UnorderGraph & graph): oGraph(graph), oMarked(graph.GetVerticeCount(), false)
{
    for (int v = 0; v < graph.GetVerticeCount(); v++)
    {
        Dfs(oGraph, v, v);
    }
}

void Cycle::Dfs(UnorderGraph & graph, int v, int p)
{
    oMarked[v] = true;
    vector<int> oAdjVec = graph.GetAdjVec(v);
    for (int w: oAdjVec)
    {
        if (!oMarked[w])
        {
            Dfs(graph, w, v);
        }
        else if (w != p)
        {
            bHasCycle = true;
        }
    }
}

bool Cycle::HasCycle()
{
    return bHasCycle;
}

class TwoColor
{
public:
    TwoColor(UnorderGraph & graph);
    void Dfs(UnorderGraph & graph, int v);
    bool CanTwoColor();
private:
    vector<bool> oMarked;
    vector<bool> oColorVec;
    UnorderGraph oGraph;
    bool bCanTwoColor;
};

TwoColor::TwoColor(UnorderGraph & graph):
    oGraph(graph), oMarked(graph.GetVerticeCount(), false), oColorVec(graph.GetVerticeCount(), false), bCanTwoColor(true)
{
    for (int v = 0; v < oGraph.GetVerticeCount(); v++)
    {
        Dfs(oGraph, v);
    }
}

void TwoColor::Dfs(UnorderGraph & graph, int v)
{
    oMarked[v] = true;
    vector<int> oAdjVec = graph.GetAdjVec(v);
    for (int w: oAdjVec)
    {
        if (!oMarked[w])
        {
            oColorVec[w] = !oColorVec[v];
            Dfs(graph, w);
        }
        else if (oColorVec[w] == oColorVec[v])
        {
            bCanTwoColor = false;
        }
    }
}

bool TwoColor::CanTwoColor()
{
    return bCanTwoColor;
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

    printf("DfsSearcher:\n");
    DfsSearcher oDfsSearch(oGraph, 1);
    for (int i = 0; i < 10; i++)
    {
        printf("%d hasPathTo %d: %d\n", 1, i, oDfsSearch.HasPathTo(i));
        if (oDfsSearch.HasPathTo(i))
        {
            printf("\tpath: ");
            vector<int> oPath = oDfsSearch.GetPath(i);
            for (int x: oPath)
            {
                printf("%d ", x);
            }
            printf("\n");
        }
    }

    printf("\n");

    printf("BfsSearcher:\n");
    BfsSearcher oBfsSearch(oGraph, 1);
    for (int i = 0; i < 10; i++)
    {
        printf("%d hasPathTo %d: %d\n", 1, i, oBfsSearch.HasPathTo(i));
        if (oBfsSearch.HasPathTo(i))
        {
            printf("\tpath: ");
            vector<int> oPath = oBfsSearch.GetPath(i);
            for (int x: oPath)
            {
                printf("%d ", x);
            }
            printf("\n");
        }
    }

    printf("\n");
    
    printf("ConnectedComponents:\n");
    ConnectedComponents oCc(oGraph);
    for (int i = 0; i < 10; i++)
    {
        printf("component id: %d\n", oCc.GetId(i));
    }

    printf("\n");
    
    printf("Cycle:\n");
    Cycle oCycle(oGraph);
    printf("HasCycle: %d\n", oCycle.HasCycle() ? 1 : 0);

    printf("\n");

    printf("TwoColor:\n");
    TwoColor oTwoColor(oGraph);
    printf("CanTwoColor: %d\n", oTwoColor.CanTwoColor() ? 1 : 0);
    return 0;
}
