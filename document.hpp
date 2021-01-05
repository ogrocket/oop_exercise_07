#include <vector>
#include <stack>
#include <fstream>

#include "factory.hpp"

class document{
private:
	struct state{ 		//remember one specific state
		std::vector<std::shared_ptr<Figure>> statement;

		state(){}

		state(const std::vector<std::shared_ptr<Figure>> statement){
			this->statement = statement;
		}
	};

	struct states_order{
		std::stack<state> states;

		states_order(){}

		void Save_state(const std::vector<std::shared_ptr<Figure>> &state){
			states.emplace(state);
		}

		std::vector<std::shared_ptr<Figure>> Last_state(){
			if (!states.empty()){
				std::vector<std::shared_ptr<Figure>> last_state = states.top().statement;     //top().state
				states.pop();
				return last_state;
			}
		}
	};

	std::string name;
    std::vector<std::shared_ptr<Figure>> buffer;
    states_order origin;

public:

	document(const std::string &name){
		this->name = name;
	}

	void Add(const std::shared_ptr<Figure> &figure){
		origin.Save_state(buffer);
		buffer.push_back(figure);
	}

	void Erase(const int index){
		if( (index >= 0) && (index <= buffer.size()) ){
			origin.Save_state(buffer);
			buffer.erase(buffer.begin() + index);
		}
		else{
			throw std::runtime_error("Wrong index\n");
		}
	}

	void Undo(){
        buffer = origin.Last_state();
	}

	void Print() const {
		for (int i = 0; i < buffer.size(); i++){
			buffer[i]->Print();
			std::cout << "\tArea = " << buffer[i]->Area() << "\n";
		}
	}

	void Save(){
		std::ofstream out;
        out.open(name, std::ios::out | std::ios::binary | std::ios::trunc);
        if (!out.is_open()) {
            throw std::runtime_error("Can not open file");
          }
         else{
            int size = buffer.size();
         	out.write((char *) &size, sizeof(int));
         	for(int i = 0; i < size; i++){
         		buffer[i]->Save(out);
         	}
         }
         out.close();
	}

	void Read(std::ifstream &in){
		int size;
        in.read((char *) &size, sizeof(int));
        for (int i = 0; i < size; ++i){
        	int id;
        	in.read((char *) &id, sizeof(int));
        	buffer.push_back(Factory::Create(id, in));
        }
        in.close();
	}
};
