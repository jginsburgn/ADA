For snap:
    1. Open Xcode project at: ./Snap-2.4/examples/snap-examples.xcodeproj (relative path to this directory)
    2. Implementations of graph algorithms are under the testgraph group in testgraph.cpp
    3. In that same group there is a helper file called LocalHelper.h which contains aiding functions
    4. Note that there is a file named excerciseGraph.txt in this directory; it is the file describing the graph shown in "Problema Practico 2. Algoritmos de grafos.pdf" and can be loaded using option 13 of the compiled program in question
    5. Compilation can be achieved directly through Xcode
    6. For compilation from console go to ./Snap-2.4/examples/
      
For Boost:
	1. For compilation go to ./Boost and execute g++ -I boost_1_59_0 GraphsAlgorithmsImplementation.cpp
