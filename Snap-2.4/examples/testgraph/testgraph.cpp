#include "stdafx.h"
#include "LocalHelper.h"

//Node traversal
//for (TNEANet::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
//    TIntV attributes;
//    NI.GetIntAttrVal(attributes);
//    std::string firstMessage = "Node with info: ";
//    firstMessage.append(IntToString(attributes[0]));
//    Print(firstMessage, true);
//    printf("\tNode's Id: %i, Node's out degree: %d, Node's in degree: %d\n", NI.GetId(), NI.GetOutDeg(), NI.GetInDeg());
//}

void PrintGStats(PNEANet Graph) {
    printf("Stats: nodes %d, edges %d, empty %s\n",
           Graph->GetNodes(), Graph->GetEdges(),
           Graph->Empty() ? "yes" : "no");
}

int Prompt(){
    PNEANet graph = TNEANet::New();
    while (true) {
        Print("", true);
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
        Print("0) For finishing program", true);
        int choice = ReadInt("Enter your choice: ");
        Print("", true);
        StartChronometer();
        if (choice == 0) {
            Print("Process terminated...", true);
            break;
        }
        else if (choice == 1){
            int data = ReadInt("Enter info (integer) of vertex to add: ");
            if (graph->IsNode(data)) Print("That vertex already exists.", true);
            else {
                graph->AddNode(data);
                graph->AddIntAttrDatN(data, data, "");
            }
        }
        else if (choice == 2){
            Print("Node's list: ");
            int counter = 1;
            for (TNEANet::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
                TIntV attributes;
                NI.GetIntAttrVal(attributes);
                std::string info = IntToString(attributes[0]);
                if (counter++ < graph->GetNodes()) info.append(", ");
                else info.append(".");
                Print(info);
            }
            Print("", true);
            int origin = ReadInt("Enter origin node: ");
            int destination = ReadInt("Enter destination node: ");
            int edgesId = 0;
            if (!graph->IsNode(origin) || !graph->IsNode(destination)) Print("Origin or destination does not exist", true);
            else {
                edgesId = graph->AddEdge(origin, destination);
                graph->AddIntAttrDatE(edgesId, ReadInt("Enter the weight of the edge to add: "), "");
            }
        }
        else if (choice == 3){
            
        }
        else if (choice == 4){
            
        }
        else if (choice == 5){
            
        }
        else if (choice == 6){
            
        }
        else if (choice == 7){
            
        }
        else if (choice == 8){
            
        }
        else if (choice == 9){
            
        }
        else if (choice == 10){
            
        }
        else if (choice == 11){
            PrintGStats(graph);
        }
        std::string timeMessage = "Operation completed in: ";
        std::string time = ChronometerLap();
        timeMessage.append(time);
        timeMessage.append(" seconds.");
        Print(timeMessage, true);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    std::string welcomeMessage = "Welcome to the Graph Algorithm Application with Stanford's SNAP (snap.stanford.edu). Jonathan Ginsburg (C) Ocober 21, 2015.";
    Print(welcomeMessage, true);
    return Prompt();
}
