#include <iostream>
#include <string>
//#include <linked_list.h>
#include <Graph.h>
#include<map>
#include <gtest/gtest.h>
//Name: Erin Stacey
//Assignment: Lab9
//Class: Data Structers
// I did use some sorces in geekforgeeks.com 
int main()
{
   
    ssuds::Graph<std::string, int> w;
    w.add_node("Bob");
    w.add_node("Dave");
    w.add_edge(2, "Dave", "Bob");
    w.add_edge(5, "Bob", "Dave");
    w.add_node("Abby");
    w.remove_node("Abby");
    w.has_edge("Bob", "Dave");
    std::cout << w.has_edge("Bob", "Dave") << std::endl;// 1 for  true 
    w.add_node("Kim");
    w.add_node("Blue");
    w.has_edge("Kim", "Dave");
    std::cout << w.has_edge("Kim", "Dave") << std::endl;// 0 for not true 
   
    w.remove_edge("Bob", "Dave");
    std::cout << w;

    // Making Graph
    ssuds::Graph<std::string, float> w2;
    w2.add_node("A");
    w2.add_node("B");
    w2.add_node("R");
    w2.add_node("G");
    w2.add_node("F");
    w2.add_node("D");
    w2.add_edge(1.3f, "A", "F");
    w2.add_edge(0.6f, "A", "B");
    w2.add_edge(4.0f, "R", "G");
    w2.add_edge(0.1f, "B", "G");
    w2.add_edge(2.5f, "B", "R");
    w2.add_edge(3.7f, "F", "D");
    w2.add_edge(1.3f, "F", "A");
    w2.add_edge(0.1f, "G", "B");

    std::cout << w2;

   
    // Invoke all google test fixtures we've registered
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
}
