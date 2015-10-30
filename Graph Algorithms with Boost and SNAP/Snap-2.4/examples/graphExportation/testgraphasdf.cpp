#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "Snap.h"
#include "Helper.h"

using namespace std::chrono;

//GraphML Node Formatting
std::string GraphMLNodes(const PNGraph & graph){
	std::string nodes;
	for (PNGraph::TObj::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
		nodes.append("\t\t<node id=\"");
		nodes.append(Helper::intToString(NI.GetId()));
		nodes.append("\"/>\n");
	}
	return nodes;
}
//GraphML Edge Formatting
std::string GraphMLEdges(const PNGraph & graph){
	std::string edges;
	int i = 1;
	for (PNGraph::TObj::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++){
		edges.append("<edge id=\"e");
		edges.append(Helper::intToString(i));
		edges.append("\" source=\"");
		edges.append(Helper::intToString(EI.GetSrcNId()));
		edges.append("\" target=\"");
		edges.append(Helper::intToString(EI.GetDstNId()));
		edges.append("\"/>\n");
		++i;
	}
	return edges;
}
//GraphML exportation
void GraphML(const PNGraph & graph, std::string & nameOfFile) {
	std::ofstream file (nameOfFile);
	if (file.is_open()) {
		//XML Headers
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";

		//GraphML Specification
		file << "<graphml xmlns=\"http://graphml.graphdrawing.org/xmlns\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://graphml.graphdrawing.org/xmlns http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd\">\n";
		file << "\t<graph id=\"G\" edgedefault=\"directed\">\n";

		//Nodes and edges
		file << GraphMLNodes(graph).c_str();
		file << GraphMLEdges(graph).c_str();

		//Closings
		file << "\t</graph>\n";
		file << "</graphml>\n";
		file.close();
	}
}

//GEXF Node Formatting
std::string GEXFNodes(const PNGraph & graph){
	std::string nodes;
	for (PNGraph::TObj::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
		nodes.append("<node id=\"");
		nodes.append(Helper::intToString(NI.GetId()));
		nodes.append("\" />\n");
	}
	return nodes;
}
//GEXF Edge Formatting
std::string GEXFEdges(const PNGraph & graph){
	std::string edges;
	int i = 1;
	for (PNGraph::TObj::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++, ++i){
		edges.append("<edge id=\"");
		edges.append(Helper::intToString(i));
		edges.append("\" source=\"");
		edges.append(Helper::intToString(EI.GetSrcNId()));
		edges.append("\" target=\"");
		edges.append(Helper::intToString(EI.GetDstNId()));
		edges.append("\" />\n");
	}
	return edges;
}
//GEXF exportation
void GEXF(const PNGraph & graph, std::string & nameOfFile) {
	std::ofstream file (nameOfFile);
	if (file.is_open()) {
		file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
		file << "<gexf xmlns=\"http://www.gexf.net/1.2draft\" version=\"1.2\">\n";
		file << "<graph mode=\"static\" defaultedgetype=\"directed\">\n";

		file << "<nodes>\n";
		file << GEXFNodes(graph).c_str();
		file << "</nodes>\n";

		file << "<edges>\n";
		file << GEXFEdges(graph).c_str();
		file << "</edges>\n";

		file << "</graph>\n";
		file << "</gexf>\n";
		file.close();
	}
}

//GDF Node Formatting
std::string GDFNodes(const PNGraph & graph){
	std::string nodes;
	for (PNGraph::TObj::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); NI++){
		nodes.append(Helper::intToString(NI.GetId()));
		nodes.append("\n");
	}
	return nodes;
}
//GDF Edge Formatting
std::string GDFEdges(const PNGraph & graph){
	std::string edges;
	for (PNGraph::TObj::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); EI++){
		edges.append(Helper::intToString(EI.GetSrcNId()));
		edges.append(", ");
		edges.append(Helper::intToString(EI.GetDstNId()));
		edges.append("\n");
	}
	return edges;
}
//GDF exportation
void GDF(const PNGraph & graph, std::string & nameOfFile) {
	std::ofstream file (nameOfFile);
	if (file.is_open()) {
		file << "nodedef>id VARCHAR\n";
		file << GDFNodes(graph).c_str();

		file << "edgedef>source VARCHAR, destination VARCHAR\n";
		file << GDFEdges(graph).c_str();

		file.close();
	}
}

//GraphSON Node Formatting
std::string GraphSONNodes(const PNGraph & graph){
	std::string nodes;
	for (PNGraph::TObj::TNodeI NI = graph->BegNI(); NI < graph->EndNI(); ) {
		nodes.append("{ \"id\": \"");
		nodes.append(Helper::intToString(NI.GetId()));
		nodes.append("\" }");
		if (NI++ == graph->EndNI())
			nodes.append(" ],\n");
		else
			nodes.append(",\n");
	}
	return nodes;
}
//GraphSON Edge Formatting
std::string GraphSONEdges(const PNGraph & graph){
	std::string edges;
	for (PNGraph::TObj::TEdgeI EI = graph->BegEI(); EI < graph->EndEI(); ) {
		edges.append("{ \"source\": \"" );
		edges.append(Helper::intToString(EI.GetSrcNId()));
		edges.append("\", \"target\": \"");
		edges.append(Helper::intToString(EI.GetDstNId()));
		edges.append("\" }");
		if (EI++ == graph->EndEI())
			edges.append(" ]\n");
		else
			edges.append(",\n");
	}
	edges.append("} }");
	return edges;
}
//GraphSON exportation
void GraphSON(const PNGraph & graph, std::string & nameOfFile) {
	std::ofstream file (nameOfFile);
	if (file.is_open()) {
		file << "{ \"graph\": {\n";
		file << "\"nodes\": [\n";
		file << GraphSONNodes(graph).c_str();

		file << "\"edges\": [\n";
		file << GraphSONEdges(graph).c_str();

		file.close();
	}
}

int main() {
	PNGraph graph = TSnap::LoadEdgeList<PNGraph>(Helper::readLine("Enter name of data set to read: ").c_str(), 0, 1);
	std::string graphmlfilename = Helper::readLine("Enter name of GraphML file to save: ").append(".graphml");
	std::string gexffilename = Helper::readLine("Enter name of GEXF file to save: ").append(".gexf");
	std::string gdffilename = Helper::readLine("Enter name of GDF file to save: ").append(".gdf");
	std::string graphsonfilename = Helper::readLine("Enter name of GraphSON file to save: ").append(".json");

	high_resolution_clock::time_point begin = high_resolution_clock::now();
	GraphML(graph, graphmlfilename);
	high_resolution_clock::time_point end = high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - begin ).count();
	std::cout << "GraphML: " << duration << std::endl;

	begin = high_resolution_clock::now();
	GEXF(graph, gexffilename);
	end = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - begin ).count();
	std::cout << "GEXF: " << duration << std::endl;

	begin = high_resolution_clock::now();
	GDF(graph, gdffilename);
	end = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - begin ).count();
	std::cout << "GDF: " << duration << std::endl;

	begin = high_resolution_clock::now();
	GraphSON(graph, graphsonfilename);
	end = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - begin ).count();
	std::cout << "GraphSON: " << duration << std::endl;
	return 0;
}
