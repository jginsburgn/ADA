//
//  LocalHelper.h
//  snap-examples
//
//  Created by Jonathan Ginsburg on 10/21/15.
//  Copyright © 2015 infolab. All rights reserved.
//

#ifndef LocalHelper_h

#include <string>
#include <time.h>

//Local Helper Implementation

//Constants and global variables declaration:
const std::string EMPTY_STRING = "";
time_t begin, end;

//Conversions:
std::string DoubleToString(double value) {
    char buffer[32];
    snprintf(buffer,32,"%f",value);
    std::string retVal = buffer;
    return retVal;
}
std::string IntToString(int value){
    char buffer[32];
    snprintf(buffer,32,"%i",value);
    std::string retVal = buffer;
    return retVal;
}

//Accessors:
int GetInfo(const TNEANet::TNodeI & node){
    TIntV attributes;
    node.GetIntAttrVal(attributes);
    return attributes[0];
}
int GetInfo(const TNEANet::TEdgeI & edge){
    TIntV attributes;
    edge.GetIntAttrVal(attributes);
    return attributes[0];
}

//Printing output:
void Print(const std::string & message, bool addLineBreak = false){
    std::string processedMessage = message;
    if (addLineBreak) processedMessage.append("\n");
    printf(processedMessage.c_str());
    fflush(stdout);
}
void PrintEmptyLine(){
    Print("", true);
}
void PrintIntVector(const TIntV & vector){
    for (int i = 0; i < vector.Len(); ++i) {
        Print(IntToString(vector[i]));
        if (i == vector.Len() - 1) {
            Print(".");
        }
        else Print(", ");
    }
}

//Descriptors:
std::string GetEdgeDescription(const TNEANet::TEdgeI & edge){
    std::string description = "Edge's id: ";
    description.append(IntToString(edge.GetId()));
    description.append(", ");
    description.append(IntToString(edge.GetSrcNId()));
    description.append(" -> ");
    description.append(IntToString(edge.GetDstNId()));
    description.append(", with weight: ");
    description.append(IntToString(GetInfo(edge)));
    return description;
}
std::string GetEdgeDescription(const int & Id, const TNEANet & graph){
    TNEANet::TEdgeI edge = graph.GetEI(Id);
    return GetEdgeDescription(edge);
}

//Reading input:
std::string ReadWord(const std::string & prompt) {
    if (prompt != "") {
        Print(prompt);
    }
    char input[100];
    scanf("%99s", input);
    std::string retVal(input);
    return retVal;
}
int ReadInt(const std::string & prompt) {
    if (prompt != "") {
        Print(prompt);
    }
    int retVal = 0;
    scanf("%i", &retVal);
    return retVal;
}

//Verifications:
bool IsIntInVector(const int & value, const TIntV & vector){
    for (int i = 0; i < vector.Len(); ++i) {
        if (value == vector[i]) {
            return true;
        }
    }
    return false;
}

//Chronometer actions:
void StartChronometer(){
    begin = time(NULL);
}
std::string ChronometerLap(){
    //    printf ("It took me %d clicks (%f seconds).\n", t, ((float)t)/CLOCKS_PER_SEC);
    //    double num = ((float)t)/CLOCKS_PER_SEC;
    //    char output[50];
    //    snprintf(output,50,"%d",num);
    //    std::string retVal = output;
    end = time(NULL);
    double elapsedTime = difftime(end, begin);
    std::string retVal = DoubleToString(elapsedTime);
    return retVal;
}

//Stack LIFO operations:
void InsertInStack(TIntV & stack, const int value){
    stack.Add(value);
}
int PopFromStack(TIntV & stack){
    int retVal = stack.Last();
    stack.DelLast();
    return retVal;
}

//Prim's Priority Queue operations:
void PrimEnqueue(TIntV & queue, const int & value, const PNEANet & graph){
    if (IsIntInVector(value, queue)) return;
    if (queue.Empty()) {
        queue.Add(value);
    }
    else{
        int index = 0;
        TNEANet::TEdgeI edgeToAdd = graph->GetEI(value);
        while (GetInfo(edgeToAdd) > GetInfo(graph->GetEI(queue[index]))) { ++index; }
        queue.Ins(index, value);
    }
}
int PrimDequeue(TIntV & queue){
    int retVal = queue[0];
    queue.Del(0);
    return retVal;
}

//Graph Insertion & Deletion:
void InsertNode(PNEANet & graph, const int value){
    if (graph->IsNode(value)) Print("That vertex already exists.", true);
    else {
        graph->AddNode(value);
        graph->AddIntAttrDatN(value, value, "");
    }
}
void DeleteNode(PNEANet & graph, const int nodesId){
    if (!graph->IsNode(nodesId)) {
        Print("Node is not in the graph", true);
    }
    else graph->DelNode(nodesId);
}
void InsertEdge(PNEANet & graph, const int originNodesId, const int destinationNodesId, const int weight){
    if (!graph->IsNode(originNodesId) || !graph->IsNode(destinationNodesId)) Print("Origin or destination does not exist", true);
    else {
        int edgesId = graph->AddEdge(originNodesId, destinationNodesId);
        graph->AddIntAttrDatE(edgesId, weight, "");
    }
}
void ForceEdgeInsertion(PNEANet & graph, const int originNodesId, const int destinationNodesId, const int weight){
    if (!graph->IsNode(originNodesId)) InsertNode(graph, originNodesId);
    if (!graph->IsNode(destinationNodesId)) InsertNode(graph, destinationNodesId);
    InsertEdge(graph, originNodesId, destinationNodesId, weight);
}
void DeleteEdge(PNEANet & graph, const int edgesId){
    if (!graph->IsEdge(edgesId)) {
        Print("Edge is not in the graph", true);
    }
    else graph->DelEdge(edgesId);
}

//End of Local Helper

#define LocalHelper_h


#endif /* LocalHelper_h */
