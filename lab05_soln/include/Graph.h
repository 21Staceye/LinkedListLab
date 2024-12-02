#pragma once
#include <map>
#include<vector>
namespace ssuds {
	/// <summary>
	/// A class that graphs nodes and edges. 
	/// </summary>
	/// <typeparam name="N"></typeparam>
	/// <typeparam name="E"></typeparam>
	template<class N, class E>
	class Graph {
	public:
		std::map<N, std::map<N, E>> mData;

		Graph() {
			

		}
		~Graph() {

		}
		/// <summary>
		/// Adds a node to the map.
		/// </summary>
		/// <param name="node_val"></param>
		void add_node(const N& node_val) {
			mData[node_val];
			
		}
		/// <summary>
		/// Adds a edge inbetween nodes. 
		/// </summary>
		/// <param name="edge_val"></param>
		/// <param name="start_node"></param>
		/// <param name="end_node"></param>
		void add_edge(const E& edge_val, const N& start_node, const N& end_node) {
			mData[start_node][end_node] = edge_val;
			
		

		}
		/// <summary>
		/// Checks to see if two nodes have a edge.
		/// </summary>
		/// <param name="start_node"></param>
		/// <param name="end_node"></param>
		/// <returns></returns>
		bool has_edge(const N& start_node, const N& end_node) {
			typename std::map<N, std::map<N, E> >::iterator it = mData.begin();
			it = mData.find(start_node);
			if (it != mData.end()) {
				typename std::map<N, E>::iterator inner_it = it->second.find(end_node);
				if (inner_it != it->second.end()) {
					return true;
				}
				else { return false; }
			}
		
		
		}
		/// <summary>
		/// Removes a Node from the Graph.
		/// </summary>
		/// <param name="node_val"></param>
		void remove_node(const N& node_val) {
			
			typename std::map<N, std::map<N, E> >::iterator it = mData.begin();
			it = mData.find(node_val);
			if (it != mData.end())
				it = mData.erase(it);
			//mData.erase(node_val);
		}
		/// <summary>
		/// Removes a Edge from the map.
		/// </summary>
		/// <param name="start_node"></param>
		/// <param name="end_node"></param>
		void remove_edge(const N& start_node, const N& end_node) {
			//mData[start_node].erase()
			//mData.erase(start_node, end_node);
			typename std::map<N, std::map<N, E> >::iterator it = mData.begin();
			it = mData.find(start_node);
			if (it != mData.end()) {
				typename std::map<N, E>::iterator inner_it = it->second.find(end_node);
				if (inner_it != it->second.end()) {
					E v2 = inner_it->second;
					//mData.erase(v2);
				}
				//else false;
			}
			


		}
		
		/// <summary>
		/// Prints out the nodes and edges in a map.
		/// </summary>
		/// <param name="os"></param>
		/// <param name="G"></param>
		/// <returns></returns>
		friend std::ostream& operator<<(std::ostream& os, const Graph& G)
		{
			typename std::map<N, std::map<N, E>>::const_iterator it = G.mData.begin();
			while (it != G.mData.end()) {
				if (it->first.length() > 3) {
					int num = it->first.length();
					os << it->first;

					os << "||";
				}
				else {
					os << it->first;
					
					os << " ||  ";
				}
			    typename std::map<N, E>::const_iterator inner_it = it->second.begin();
				while (inner_it != it->second.end()) {
					os << "(";
					os << inner_it->first << ": ";
					os << inner_it->second;
					os << ") ";
					
					++inner_it;
				}
				++it;
				os << std::endl;
			}
			
			// ...
			return os;
		}
		
		
	};


}