
#include <vector>
#include "boost/graph/floyd_warshall_shortest.hpp" 
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
int N = 14;  //numero de nodos

using namespace boost;
using namespace std;

typedef adjacency_list < vecS, vecS, undirectedS,
    no_property, property < edge_weight_t, int > > Graph;

typedef graph_traits<Graph>::vertex_descriptor MyVertex;
typedef graph_traits <Graph>::edge_descriptor Edge;

//DFS class
class MyVisitor : public default_dfs_visitor
{
public:
  void discover_vertex(MyVertex v, const Graph& g) const
  {
    cerr << v << " ";
    return;
  }
};

//BFS 

template < typename TimeMap > class bfs_time_visitor:public default_bfs_visitor {
  typedef typename property_traits < TimeMap >::value_type T;
public:
  bfs_time_visitor(TimeMap tmap, T & t):m_timemap(tmap), m_time(t) { }
  template < typename Vertex, typename Graph >
    void discover_vertex(Vertex u, const Graph & g) const
  {
    put(m_timemap, u, m_time++);
  }
  TimeMap m_timemap;
  T & m_time;
};


int main(int argc, const char * argv[])
{
	vector<int> registro(10000);
	clock_t t, t_ini, t_fin;
	t=clock();
	t=clock()-t;
  double secs;

Graph g;
  boost::add_edge(1, 3, 8, g);
  boost::add_edge(1, 4, 8, g);
  boost::add_edge(2, 5, 7, g);
  boost::add_edge(3, 2, 7, g);
  boost::add_edge(3, 5, 8, g);
  boost::add_edge(3, 10, 4, g);
  boost::add_edge(4, 5, 1, g);
  boost::add_edge(4, 7, 3, g);
  boost::add_edge(4, 8, 2, g);
  boost::add_edge(5, 6, 9, g);
  boost::add_edge(6, 13, 4 , g);
  boost::add_edge(7, 4, 6, g);
  boost::add_edge(8, 7, 3, g);
  boost::add_edge(8, 9, 3, g);
  boost::add_edge(9, 10, 2, g);
  boost::add_edge(9, 12, 4, g);
  boost::add_edge(10, 3, 10, g);
  boost::add_edge(10, 6, 6, g);  
  boost::add_edge(11, 12, 6, g);
  boost::add_edge(12, 9, 2, g);
  boost::add_edge(12, 11, 8, g);
  boost::add_edge(12, 14, 9, g);
  boost::add_edge(13, 14, 6, g);
  boost::add_edge(14, 13, 2, g);
  for (int i = 1; i < 15;i++){
    registro[i] = 1;
  } 


typedef graph_traits<Graph>::edge_iterator edge_iterator;
 int n;
 int src;
 int trg;
 int a;
 int b;
 int w;
while (1) {
	std::pair<edge_iterator, edge_iterator> ei = edges(g);
		cout<<endl;
		
      cout <<"Grafo: " << endl;  

    for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
        std::cout << "(" << source(*edge_iter, g) << ", " << target(*edge_iter, g) << ") ";
     } 
cout << endl <<"1.Insertar arista o nodo, 2.Eliminar arista, 3. Eliminar nodo, 4. Muestra todos los algoritmos " <<endl;
cin>>n;
   if (n==1){
cout<<"Nodo inicial"<< endl;
cout<<"Si no existe en el grafo se agregara con el siguiente numero" << endl;
cin>> a;
cout<<"Nodo final"<< endl;
cout<<"Si no existe en el grafo se agregara con el siguiente numero" << endl;
cin>> b;
if(a > N){
a = N+1;
N++;
registro[a] = 1;
}
if (b > N){
b = N+1;
N++;
registro[b] = 1;
}
cout<<"Peso"<< endl;
cin>> w;
 boost::add_edge(a, b, w, g);
}//Cierre de 1

else if(n==2){
cout<<"Ingresa el nodo inicial"<< endl;
cin>> a;
cout<<"Ingresa el nodo final"<< endl;
cin>> b;
boost::remove_edge(a,b,g);
}//Cierre de 2

else if(n==3){
  edge_iterator last;
  cout<<"¿Que nodo quieres borrar?"<<endl;
  cin>>a;
  if(!registro[a]){
    cout<<"El nodo no existe"<<endl;
  }else{
        for(edge_iterator edge_iter = ei.first; edge_iter != ei.second; ++edge_iter) {
	if(source(*edge_iter, g) == a){
		src = source(*edge_iter, g);
		trg = target(*edge_iter, g);
		--edge_iter;
		boost::remove_edge(src, trg, g);
	}
	if(target(*edge_iter, g) == a){
		src=source(*edge_iter, g);
		trg=target(*edge_iter, g);
		--edge_iter;
		boost::remove_edge(src, trg,g);
		}
	}
     cout << "Borrado exitosamente" << endl;
     N--;
     }
     registro[a] = 0;
}else{
	break;
}//Cierre de while
}

//Se manda llamar el DFS

    cout<< endl  << "DFS: ";
  t_ini = clock();
  MyVisitor vis;
  boost::depth_first_search(g, boost::visitor(vis));
  t_fin = clock();
  secs = (long double )(t_fin - t_ini) / CLOCKS_PER_SEC;
  cout << endl; 
  printf("Tiempo de ejecucion %.16g milisegundos\n", secs * 1000.0);
  cout << endl;

//Se manda llamar el BFS

    cout << "BFS:";
   t_ini = clock();
  typedef adjacency_list < vecS, vecS, undirectedS > graph_t;
  typedef graph_traits < graph_t >::vertex_descriptor Vertex;
  typedef graph_traits < graph_t >::vertices_size_type Size;
  typedef Size* Iiter;

  std::vector < Size > dtime(num_vertices(g));
  Size time = 0;
  bfs_time_visitor < Size * >visi(&dtime[0], time);
  breadth_first_search(g, vertex(1, g), visitor(visi));

   std::vector<graph_traits<graph_t>::vertices_size_type > discover_order(N);
  integer_range < int >range(0, N);
  std::copy(range.begin(), range.end(), discover_order.begin());
  std::sort(discover_order.begin(), discover_order.end(),
 indirect_cmp < Iiter, std::less < Size > >(&dtime[0]));

  std::cout << "order of discovery: ";
  for (int i = 1; i <= N; ++i)
    cout << discover_order[i] << " ";
    cout << endl;
  t_fin = clock();
  secs = (long double )(t_fin - t_ini) / CLOCKS_PER_SEC;
  printf("Tiempo de ejecucion %.16g milisegundos\n", secs * 1000.0);
  cout << endl;


//Se  utiliza Kruskal
  t_ini = clock();

  property_map < Graph, edge_weight_t >::type weight = get(edge_weight, g);
std::vector < Edge > spanning_tree;
kruskal_minimum_spanning_tree(g, std::back_inserter(spanning_tree));


std::cout<< "KRUSKAL:" << std::endl;
  for (std::vector < Edge >::iterator ei = spanning_tree.begin();
       ei != spanning_tree.end(); ++ei) {
    cout << source(*ei, g) << " <--> " << target(*ei, g)
      << " with weight of " << weight[*ei] << endl;
  }

  t_fin = clock();
  secs = (long double )(t_fin - t_ini) / CLOCKS_PER_SEC; 
  printf("Tiempo de ejecucion %.16g milisegundos\n", secs * 1000.0);
  cout << endl;

//Se utiliza prim
 t_ini = clock();
 cout << "PRIM:" << endl;


  std::vector < graph_traits < Graph >::vertex_descriptor >
  p(num_vertices(g));

#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
  property_map<Graph, vertex_distance_t>::type distance = get(vertex_distance, g);
  property_map<Graph, vertex_index_t>::type indexmap = get(vertex_index, g);
  prim_minimum_spanning_tree
    (g, *vertices(g).first, &p[0], distance, weightmap, indexmap, 
     default_dijkstra_visitor());
#else
  prim_minimum_spanning_tree(g, &p[0]);
#endif

for (std::vector < Edge >::iterator ei = spanning_tree.begin();
       ei != spanning_tree.end(); ++ei) {
    cout << source(*ei, g) << " <--> " << target(*ei, g);
    cout << endl;
  }

  t_fin = clock();
  secs = (long double )(t_fin - t_ini) / CLOCKS_PER_SEC; 
  printf("Tiempo de ejecucion %.16g milisegundos\n", secs * 1000.0);
  cout << endl;


 // Dijkstra
   t_ini = clock();
   cout << "Dijkstra" <<endl ;
  
   typedef graph_traits < graph_t >::vertex_descriptor vertex_descriptor;
   vector<vertex_descriptor> p2(num_vertices(g));
  vector<int> d(num_vertices(g));
  vertex_descriptor s = vertex(1, g);
   dijkstra_shortest_paths(g, s, predecessor_map(boost::make_iterator_property_map(p2.begin(), get(boost::vertex_index, g))).
                           distance_map(boost::make_iterator_property_map(d.begin(), get(boost::vertex_index, g))));
  
  cout << "distances and parents:" << endl;
  graph_traits < graph_t >::vertex_iterator vi, vend;
  for (boost::tie(vi, vend) = vertices(g); vi != vend; ++vi) {
    if(d[*vi] < 99999999){
    cout << "distance(" << *vi << ") = " << d[*vi] << ", ";
    cout << "parent(" << *vi << ") = " << p2[*vi] << endl;
    }
  }

  t_fin = clock();
  secs = (long double )(t_fin - t_ini) / CLOCKS_PER_SEC; 
  printf("Tiempo de ejecucion %.16g milisegundos\n", secs * 1000.0);
  cout << endl;

  return 0;
}
