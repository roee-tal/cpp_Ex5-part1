#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
// #include "Node.hpp"
namespace ariel{
    class Iterator;
    class OrgChart{
        struct Node{
            std::string data;
            std::vector<Node*>childs;

            Node(const std::string &data) {
                this->data = data;
            }
            ~Node(){}
        };

        public:
            Node *head;
            std::deque<std::string> traverse;
            OrgChart();
            OrgChart& add_root(const std::string &job);
            OrgChart& add_sub(const std::string &bos,const std::string &sub);
            // Node* find_node(const std::string &name);
            friend std::ostream &operator<<(std::ostream &out,  OrgChart &org);
            std::deque<std::string>::iterator begin_level_order();
            std::deque<std::string>::iterator begin_reverse_order();
            std::deque<std::string>::iterator begin_preorder();
            std::deque<std::string>::iterator end_level_order();
            std::deque<std::string>::iterator reverse_order();
            std::deque<std::string>::iterator end_preorder();
            void fill_level_order(Node *head);
            void fill_rev_order(Node *head);
            void fill_preorder(Node *head);
    };
}
