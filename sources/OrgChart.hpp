#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <fstream>
#include <sstream>
// #include "Node.hpp"
namespace ariel{
    // class Iterator;
    template<class T=std::string>
    class OrgChart{
        struct Node{
            T data;
            std::vector<Node*>childs;

            Node(T &data):data(data) {
                
            }
            // ~Node(){}
        };

		class iterator{
			Node *curr;
			std::deque<Node*> traverse2;
			public:
			iterator(Node* ptr,const char& c)
			{
				this->curr = ptr;
				
				if(c == 'L'){
					if (ptr != nullptr) {
                    	this->traverse2.push_back(ptr);
                }
					fill_level_order(ptr);
				}
				else if(c == 'R'){
					if (ptr != nullptr) {
                    	this->traverse2.push_front(ptr);
                }
					fill_rev_order(ptr);
					curr = traverse2[0];
				}
				else if(c == 'P'){
                    if (ptr != nullptr) {
                    	this->traverse2.push_back(ptr);
                }
					fill_preorder(ptr);
				}
				this->traverse2.push_back(nullptr);
			}

		void fill_level_order(Node *head){
            if(head==nullptr){
                return;
            }
            for(size_t i=0;i<head->childs.size();i++){
                this->traverse2.push_back(head->childs[i]);
            }
            for(size_t i=0;i<head->childs.size();i++){
                fill_level_order(head->childs[i]);
            }
        
        }

		 void fill_rev_order(Node *head){
            if(head!=nullptr){
            for(size_t i=head->childs.size();i>0;i--){
                this->traverse2.push_front(head->childs[i-1]);
            }
            for(size_t i=head->childs.size();i>0;i--){
                fill_rev_order(head->childs[i-1]);
            } 
        }
         }

		 void fill_preorder(Node *head){
             if(head!=nullptr){
             for(size_t i=0;i<head->childs.size();i++){
                this->traverse2.push_back(head->childs[i]);
                fill_preorder(head->childs[i]);
            }
        }
         }
		bool operator==(const iterator&it)const{
			// if (curr == nullptr || it.curr == nullptr) {
            //         return it.curr == curr;
            // }
                return this->curr == it.curr;
            }
        bool operator!=(const iterator&it)const{
                return !(*this==it);
            }
        T& operator*()const{
                return curr->data;
            }

		T* operator->() const {
                return &(curr->data);
            }
		iterator &operator++() {
            if (!traverse2.empty()) {
                traverse2.erase(traverse2.begin());
                curr = traverse2.front();
            }
            return *this;
        }

        iterator operator++(int) {
            iterator t = *this;
            ++*this;
            return t;
            }
		};

        public:
            Node *head;
            // int* x;
            // std::deque<std::string> traverse;
            // OrgChart();
            
            // OrgChart& add_root(T &job);
            // OrgChart& add_sub(T &bos,const T &sub);

                    OrgChart(){ this->head= nullptr;}
        OrgChart& add_root(T job){
            if(head == nullptr){
                this->head = new Node(job);
            }
            else{
                // this->head->data = job;
                Node *newN = new Node(job);
                newN->childs.push_back(head);
                head = newN;
            }
            return *this;

        }
        OrgChart& add_sub(T bos,T sub){
            // Node *dad = find_node(bos);
            // if(dad == nullptr){
            //     throw std::runtime_error("The boss name doesn't exist");
            // }
            // Node *newN = new Node(bos);
            // dad->childs.push_back(newN);
            // return *this;
            if(head == nullptr){
                // return nullptr;
                throw std::runtime_error("The boss name doesn't exist");
            }
            std::deque<Node*> list_to_find;
            list_to_find.push_back(head);
            // bool parent_f = false;
            while(!list_to_find.empty()){
                Node *temp = list_to_find.front();
                if(temp->data == bos){
                    Node* newN = new Node(sub);
                    temp->childs.push_back(newN);
                    // parent_f = true;
                    return *this;
                }
                list_to_find.pop_front();
                for(unsigned long i = 0;i<temp->childs.size();i++){
                    list_to_find.push_back(temp->childs[i]);
                }
            }
            // if(!parent_f){
            throw std::runtime_error("The boss name doesn't exist");
            // }
            // return *this;
        }


        
            // Node* find_node(const std::string &name);
            // friend std::ostream &operator<<(std::ostream &out,  OrgChart &org);

        friend std::ostream &operator<<(std::ostream &out, OrgChart &org)
            {
            for (auto it=org.begin_preorder(); it!=org.end_preorder(); ++it) {
                out << (*it) << " " ;
                }
            return out;
            }

			iterator begin_level_order()const{
				return iterator{head,'L'};
			}
			static iterator end_level_order(){
				return iterator{nullptr,'K'};
			}
			iterator begin_reverse_order()const{
				return iterator{head,'R'};
			}
			static iterator reverse_order(){
				return iterator{nullptr,'K'};
			}
            iterator begin_preorder()const{
				return iterator{head,'P'};
			}
            static iterator end_preorder(){
				return iterator{nullptr,'K'};
			}
			iterator begin()const{
				return begin_level_order();
			}
			static iterator end(){
				return end_level_order();
			}

            // int* begin();
            // int *end();
            // std::deque<std::string>::iterator begin();
            // std::deque<std::string>::iterator end();
            // std::deque<std::string>::iterator begin_level_order();
            // std::deque<std::string>::iterator begin_reverse_order();
            // std::deque<std::string>::iterator begin_preorder();
            // std::deque<std::string>::iterator end_level_order();
            // std::deque<std::string>::iterator reverse_order();
            // std::deque<std::string>::iterator end_preorder();


            // void fill_level_order(Node *head);
            // void fill_rev_order(Node *head);
            // void fill_preorder(Node *head);
    };
}
