#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "Graph.hpp"
#include "Dice.hpp"
#include "DiceSet.hpp"

int* randomIntGenerator() {
	return new int(100 + getRandomInt(900));
}

void demonstrateGraph(Graph<int> *graph, std::string description) {
	Graph<int> *spanningTree = graph->getSpanningTree();

	std::cout << description << ":\n";
	graph->print(std::cout);
	std::cout << "\n";
	std::cout << "It's spanning tree:\n";
	spanningTree->print(std::cout);
	std::cout << "\n\n";

	delete spanningTree;
}

void demonstrateGraphs() {
	Graph<int> *exampleGraph = new Graph<int>;
	Vertex<int> *vertex1 = exampleGraph->addVertex(new int(1));
	Vertex<int> *vertex2 = exampleGraph->addVertex(new int(2));
	Vertex<int> *vertex3 = exampleGraph->addVertex(new int(3));
	Vertex<int> *vertex4 = exampleGraph->addVertex(new int(4));
	exampleGraph->connect(vertex1, vertex2, 3);
	exampleGraph->connect(vertex1, vertex3, 5);
	exampleGraph->connect(vertex1, vertex4, 100);//This edge will not be added to spanning tree
	exampleGraph->connect(vertex2, vertex3, 7);//This edge will not be added to spanning tree
	exampleGraph->connect(vertex3, vertex4, 9);
	demonstrateGraph(exampleGraph, "Example graph");
	delete exampleGraph;

	Graph<int> *randomGraph = new Graph<int>(6, 0.5, 9, randomIntGenerator);
	demonstrateGraph(randomGraph, "Random graph");
	delete randomGraph;
}

void demonstrateDiceSet(const std::vector<Dice*> &vectorOfDice, int setIndex) {
	DiceSet* diceSet = new DiceSet(vectorOfDice);
	int diceIndex = 1;

	std::cout << "Dice set " << setIndex << "\n\n";
	for (Dice* dice : vectorOfDice) {
		std::cout << "Dice " << diceIndex << ":\n";
		dice->print(std::cout);
		std::cout << "\n";
		diceIndex++;
	}
	diceSet->print(std::cout);
	std::cout << "\n\n\n";

	delete diceSet;
}

//Dice are deleted in demonstrateDiceSet() along with created set
void demonstrateDiceSets() {
	std::vector<Dice*> diceForSet1{
		new Dice(std::vector<double>(5, 0.2)),
		new Dice(std::vector<double>(5, 0.2)),
		new Dice(std::vector<double>(5, 0.2))
	};
	std::vector<Dice*> diceForSet2{
		new Dice(4),
		new Dice(6)
	};

	demonstrateDiceSet(diceForSet1, 1);
	demonstrateDiceSet(diceForSet2, 2);
}

int main() {
	srand(time(NULL));
	demonstrateGraphs();
	demonstrateDiceSets();
	std::cin.get();

	return 0;
}
