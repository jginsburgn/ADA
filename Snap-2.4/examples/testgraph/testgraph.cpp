#include "stdafx.h"
#include "LocalHelper.h"

/*
//Node traversal
//for (TNEANet::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
//    TIntV attributes;
//    NI.GetIntAttrVal(attributes);
//    std::string firstMessage = "Node with info: ";
//    firstMessage.append(IntToString(attributes[0]));
//    Print(firstMessage, true);
//    printf("\tNode's Id: %i, Node's out degree: %d, Nobde's in degree: %d\n", NI.GetId(), NI.GetOutDeg(), NI.GetInDeg());
//}
 */

//Printing operations:
void PrintEdges(const PNEANet & graph){
    Print("Edge's list: ", true);
    for (TNEANet::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++){
        printf("\t%s\n", GetEdgeDescription(EI).c_str());
    }
}
void PrintNodes(const PNEANet & graph){
    Print("Node's list: ");
    int counter = 1;
    for (TNEANet::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
        std::string info = IntToString(GetInfo(NI));
        if (counter++ < graph->GetNodes()) info.append(", ");
        else info.append(".");
        Print(info);
    }
    PrintEmptyLine();
}
void PrintGraphDetails(const PNEANet & graph) {
    printf("Details: \n\tNumber of nodes %d, number of edges %d...",
           graph->GetNodes(), graph->GetEdges());
    PrintEmptyLine();
    if (!graph->Empty()) {
        PrintNodes(graph);
        PrintEdges(graph);
    }
}

//Saving and loading:
void SaveGraph(const PNEANet & graph){
    TSnap::SaveEdgeListNet(graph, ReadWord("Enter name of graph to save (single word): ").c_str(), "");
}
void LoadGraph(PNEANet & graph){
    graph = TSnap::LoadEdgeListNet(ReadWord("Enter name of graph to load (single word): ").c_str(), '\t');
}

//Depth First Traversing:
void DFSExploreNode(TIntV & visitedNodes, TIntV & edgesStack, const TNEANet::TNodeI & node, const PNEANet & graph){
    if (!IsIntInVector(node.GetId(), visitedNodes)) visitedNodes.Add(node.GetId());
    for (int e = 0; e < node.GetOutDeg(); e++){
        int edgesId = node.GetOutEId(e);
        TNEANet::TEdgeI edge = graph->GetEI(edgesId);
        int destinationNodesIdOfEdge = edge.GetDstNId();
        if (!IsIntInVector(destinationNodesIdOfEdge, visitedNodes)) {
            InsertInStack(edgesStack, edgesId);
            visitedNodes.Add(destinationNodesIdOfEdge);
        }
    }
}
void DepthFirstTraversing(const PNEANet & graph, int sourceNodeId){
    if (!graph->IsNode(sourceNodeId)) {
        Print("Node is not in the graph...", true);
        return;
    }
    TIntV visitedNodes;
    TIntV edgesStack;
    TNEANet::TNodeI currentNode = graph->GetNI(sourceNodeId);
    DFSExploreNode(visitedNodes, edgesStack, currentNode, graph);
    printf("\tConducting DFS from node with id: %i\n", currentNode.GetId());
    while (!edgesStack.Empty()) {
        TNEANet::TEdgeI edgeToExplore = graph->GetEI(PopFromStack(edgesStack));
        currentNode = graph->GetNI(edgeToExplore.GetDstNId());
        printf("\t\tArriving to: %i, from edge: %s.\n", currentNode.GetId(), GetEdgeDescription(edgeToExplore).c_str());
        DFSExploreNode(visitedNodes, edgesStack, currentNode, graph);
    }
}

//Breadth First Traversing:
void BFSExploreNode(TIntV & visitedNodes, TSnapQueue<int> & edgesQueue, const TNEANet::TNodeI & node, const PNEANet & graph){
    if (!IsIntInVector(node.GetId(), visitedNodes)) visitedNodes.Add(node.GetId());
    for (int e = 0; e < node.GetOutDeg(); e++){
        int edgesId = node.GetOutEId(e);
        TNEANet::TEdgeI edge = graph->GetEI(edgesId);
        int destinationNodesIdOfEdge = edge.GetDstNId();
        if (!IsIntInVector(destinationNodesIdOfEdge, visitedNodes)) {
            edgesQueue.Push(edgesId);
            visitedNodes.Add(destinationNodesIdOfEdge);
        }
    }
}
void BreadthFirstTraversing(const PNEANet & graph, int sourceNodeId){
    if (!graph->IsNode(sourceNodeId)) {
        Print("Node is not in the graph...", true);
        return;
    }
    TIntV visitedNodes;
    TSnapQueue<int> edgesQueue;
    TNEANet::TNodeI currentNode = graph->GetNI(sourceNodeId);
    BFSExploreNode(visitedNodes, edgesQueue, currentNode, graph);
    printf("\tConducting BFS from node with id: %i\n", currentNode.GetId());
    while (!edgesQueue.Empty()) {
        TNEANet::TEdgeI edgeToExplore = graph->GetEI(edgesQueue.Top());
        edgesQueue.Pop();
        currentNode = graph->GetNI(edgeToExplore.GetDstNId());
        printf("\t\tArriving to: %i, from edge: %s.\n", currentNode.GetId(), GetEdgeDescription(edgeToExplore).c_str());
        BFSExploreNode(visitedNodes, edgesQueue, currentNode, graph);
    }
}

//Prim's Minimum Expansion:
void PrimsExploreNode(TIntV & visitedNodes, TIntV & edgesQueue, const TNEANet::TNodeI & node, const PNEANet & graph){
    if (!IsIntInVector(node.GetId(), visitedNodes)) visitedNodes.Add(node.GetId());
    for (int e = 0; e < node.GetOutDeg(); e++){
        int edgesId = node.GetOutEId(e);
        TNEANet::TEdgeI edge = graph->GetEI(edgesId);
        int destinationNodesIdOfEdge = edge.GetDstNId();
        if (!IsIntInVector(destinationNodesIdOfEdge, visitedNodes)) {
            PrimEnqueue(edgesQueue, edgesId, graph);
        }
    }
}
PNEANet PrimsMinimumExpansionTree(const PNEANet & graph, const int sourceNodeId){
    PNEANet minimumExpansionTree = TNEANet::New();
    if (!graph->IsNode(sourceNodeId)) {
        Print("Node is not in the graph...", true);
        return minimumExpansionTree;
    }
    InsertNode(minimumExpansionTree, sourceNodeId);
    TIntV visitedNodes;
    TIntV edgesQueue;
    TNEANet::TNodeI currentNode = graph->GetNI(sourceNodeId);
    PrimsExploreNode(visitedNodes, edgesQueue, currentNode, graph);
    while (visitedNodes.Len() < graph->GetNodes()) {
        TNEANet::TEdgeI edgeToExplore = graph->GetEI(PrimDequeue(edgesQueue));
        ForceEdgeInsertion(minimumExpansionTree, edgeToExplore.GetSrcNId(), edgeToExplore.GetDstNId(), GetInfo(edgeToExplore));
        currentNode = graph->GetNI(edgeToExplore.GetDstNId());
        PrimsExploreNode(visitedNodes, edgesQueue, currentNode, graph);
    }
    return minimumExpansionTree;
}

//Kruskal's Minimum Expansion:
void BuildSingletonClusters(TVec<TIntV> & clusters, const PNEANet & graph){
    for (TNEANet::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
        TIntV newCluster;
        newCluster.Add(NI.GetId());
        clusters.Add(newCluster);
    }
}
void EnqueueAllEdges(TIntV & queue, const PNEANet & graph){
    for (TNEANet::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++){
        PrimEnqueue(queue, EI.GetId(), graph);
    }
}
void MergeClusters(TVec<TIntV> & clusters, const int indexOfClusterOne, const int indexOfClusterTwo){
    TIntV clusterOne = clusters[indexOfClusterOne];
    TIntV clusterTwo = clusters[indexOfClusterTwo];
    for (int i = 0; i < clusterTwo.Len(); ++i) {
        clusters[indexOfClusterOne].Add(clusterTwo[i]);
    }
    clusters.Del(indexOfClusterTwo);
}
int GetClustersIndexWhichContains(TVec<TIntV> & clusters, const int nodeId){
    for (int i = 0; i < clusters.Len(); ++i) {
        if (IsIntInVector(nodeId, clusters[i])) {
            return i;
        }
    }
    return -1;
}
PNEANet KruskalMinimumExpansionTree(const PNEANet & graph, const int sourceNodeId){
    PNEANet minimumExpansionTree = TNEANet::New();
    if (!graph->IsNode(sourceNodeId)) {
        Print("Node is not in the graph...", true);
        return minimumExpansionTree;
    }
    TVec<TIntV> clusters;
    BuildSingletonClusters(clusters, graph);
    TIntV edgesQueue;
    EnqueueAllEdges(edgesQueue, graph);
    while (clusters.Len() != 1) {
        TNEANet::TEdgeI currentEdge = graph->GetEI(PrimDequeue(edgesQueue));
        int indexOfClusterWithOrigin = GetClustersIndexWhichContains(clusters, currentEdge.GetSrcNId());
        int indexOfClusterWithDestination = GetClustersIndexWhichContains(clusters, currentEdge.GetDstNId());
        if (indexOfClusterWithOrigin != indexOfClusterWithDestination) {
            MergeClusters(clusters, indexOfClusterWithOrigin, indexOfClusterWithDestination);
            ForceEdgeInsertion(minimumExpansionTree, currentEdge.GetSrcNId(), currentEdge.GetDstNId(), GetInfo(currentEdge));
        }
    }
    return minimumExpansionTree;
}

//Dijkstra's Shortest Paths:
void EnqueueAllNodes(TIntV & queue, const PNEANet & graph){
    for (TNEANet::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
        queue.Add(NI.GetId());
    }
}
int DequeueDijkstras(TIntV & queue, THash<TInt, TInt> & distance){
    int minimumsIndex = 0;
    for (int i = 0; i < queue.Len(); ++i) {
        if (distance.IsKey(queue[i])) {
            minimumsIndex = i;
            break;
        }
    }
    for (int i = 0; i < queue.Len(); ++i) {
        if (distance.IsKey(queue[i])) {
            if (distance.GetDat(queue[i]) < distance.GetDat(queue[minimumsIndex])) {
                minimumsIndex = i;
            }
        }
    }
    int retVal = queue[minimumsIndex];
    queue.Del(minimumsIndex);
    return retVal;
}
void GetPathTo(std::string & path, const THash<TInt, TInt> & predecessor, const int destinationNodesId){
    if (predecessor.IsKey(destinationNodesId)) {
        GetPathTo(path, predecessor, predecessor.GetDat(destinationNodesId));
        path.append(" -> ");
    }
    path.append(IntToString(destinationNodesId));
}
void DijkstrasShortestPaths(THash<TInt, TInt> & distance, THash<TInt, TInt> & predecessor, const PNEANet & graph, const int sourceNodeId){
    if (!graph->IsNode(sourceNodeId)) {
        Print("Node is not in the graph...", true);
        return;
    }
    TIntV nodesQueue;
    EnqueueAllNodes(nodesQueue, graph);
    distance.AddDat(sourceNodeId) = 0;
    while (!nodesQueue.Empty()) {
        int currentNodesId = DequeueDijkstras(nodesQueue, distance);
        TNEANet::TNodeI currentNode = graph->GetNI(currentNodesId);
        for (int e = 0; e < currentNode.GetOutDeg(); e++){
            int edgesId = currentNode.GetOutEId(e);
            TNEANet::TEdgeI edge = graph->GetEI(edgesId);
            if (!IsIntInVector(edge.GetDstNId(), nodesQueue)) {
                continue;
            }
            if (distance.IsKey(edge.GetDstNId())) {
                int alternativeDistance = distance.GetDat(currentNodesId) + GetInfo(edge);
                if (alternativeDistance < distance.GetDat(edge.GetDstNId())) {
                    distance.GetDat(edge.GetDstNId()) = alternativeDistance;
                    predecessor.GetDat(edge.GetDstNId()) = currentNode.GetId();
                }
            }
            else {
                distance.AddDat(edge.GetDstNId()) = distance.GetDat(currentNodesId) + GetInfo(edge);
                predecessor.AddDat(edge.GetDstNId()) = currentNode.GetId();
            }
        }
    }
}

//Miscellaneous:
void ShowOperationTime(int wait){
    std::string timeMessage = "Operation completed in: ";
    std::string time = ChronometerLap();
    timeMessage.append(time);
    timeMessage.append(" seconds");
    Print(timeMessage);
    for (int i = 0; i < wait; ++i) {
        usleep(500000);
        Print(".");
    }
    PrintEmptyLine();
}

//User Interaction:
void PrintMenu(){
    PrintEmptyLine();
    Print("1) For Vertex Insertion", true);
    Print("2) For Edge Insertion", true);
    Print("3) For Vertex Deletion", true);
    Print("4) For Edge Deletion", true);
    Print("5) For Depth First Traversing", true);
    Print("6) For Breadth First Traversing", true);
    Print("7) For getting Minimum Expansion Tree of Graph by Prim's Algorithm", true);
    Print("8) For getting Minimum Expansion Tree of Graph by Kruskal's Algorithm", true);
    Print("9) For getting Shortest Paths from a given Vertex to all others by Dijkstra's Algorithm", true);
    Print("10) For getting Shortest Paths from a given Vertex to all others by Floyd-Warshall's Algorithm", true);
    Print("11) For printing Graph statistics", true);
    Print("12) For Saving Current Graph", true);
    Print("13) For Loading a Saved Graph", true);
    Print("0) For finishing program", true);
}
int Prompt(){
    PNEANet graph = TNEANet::New();
    while (true) {
        PrintMenu();
        int choice = ReadInt("Enter your choice: ");
        PrintEmptyLine();
        StartChronometer();
        if (choice == 0) {
            Print("Process terminated...", true);
            break;
        }
        else if (choice == 1){
            int data = ReadInt("Enter info (integer) of vertex to add: ");
            InsertNode(graph, data);
        }
        else if (choice == 2){
            PrintNodes(graph);
            int origin = ReadInt("Enter origin node: ");
            int destination = ReadInt("Enter destination node: ");
            int weight = ReadInt("Enter the weight of the edge to add: ");
            InsertEdge(graph, origin, destination, weight);
        }
        else if (choice == 3){
            if (graph->GetNodes() == 0) {
                Print("Graph has no nodes...", true);
            }
            else {
                PrintNodes(graph);
                int nodeToDelete = ReadInt("Enter node to delete: ");
                DeleteNode(graph, nodeToDelete);
            }
        }
        else if (choice == 4){
            if (graph->GetEdges() == 0) {
                Print("Graph has no edges...", true);
            }
            else {
                PrintEdges(graph);
                int edgeToDelete = ReadInt("Enter id of edge to delete: ");
                DeleteEdge(graph, edgeToDelete);
            }
        }
        else if (choice == 5){
            PrintNodes(graph);
            DepthFirstTraversing(graph, ReadInt("Enter the source node's id for traversing: "));
        }
        else if (choice == 6){
            PrintNodes(graph);
            BreadthFirstTraversing(graph, ReadInt("Enter the source node's id for traversing: "));
        }
        else if (choice == 7){
            PrintNodes(graph);
            PNEANet minimumExpansionTree = PrimsMinimumExpansionTree(graph, ReadInt("Enter the source node's id for building minimum expansion tree with Prim's Algorithm: "));
            PrintGraphDetails(minimumExpansionTree);
        }
        else if (choice == 8){
            PrintNodes(graph);
            PNEANet minimumExpansionTree = KruskalMinimumExpansionTree(graph, ReadInt("Enter the source node's id for building minimum expansion tree with Kruskal's Algorithm: "));
            PrintGraphDetails(minimumExpansionTree);
        }
        else if (choice == 9){
            PrintNodes(graph);
            THash<TInt, TInt> distance;
            THash<TInt, TInt> predecessor;
            int sourceNodesId = ReadInt("Enter the source node's id for finding shortest paths from, using Dijkstra's Algorithm: ");
            DijkstrasShortestPaths(distance, predecessor, graph, sourceNodesId);
            int input = 0;
            while (input != -1) {
                input = ReadInt("Enter the destination node's id for showing shortest path and cost, or -1 to finish: ");
                if (!graph->IsNode(input)) {
                    continue;
                }
                std::string path;
                GetPathTo(path, predecessor, input);
                std::string message = "To get from ";
                message.append(IntToString(sourceNodesId));
                message.append(" to ");
                message.append(IntToString(input));
                message.append(" it costs: ");
                message.append(IntToString(distance.GetDat(input)));
                message.append(", and you need to follow this path:\n\t");
                message.append(path);
                Print(message, true);
            }
        }
        else if (choice == 10){
            
        }
        else if (choice == 11){
            PrintGraphDetails(graph);
        }
        else if (choice == 12){
            SaveGraph(graph);
        }
        else if (choice == 13){
            LoadGraph(graph);
        }
        ShowOperationTime(0);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    std::string welcomeMessage = "Welcome to the Graph Algorithm Application with Stanford's SNAP (snap.stanford.edu). Jonathan Ginsburg (C) Ocober 21, 2015.";
    Print(welcomeMessage, true);
    return Prompt();
}
