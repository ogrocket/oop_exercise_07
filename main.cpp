#include "square.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "factory.hpp"
#include "document.hpp"
#include <iostream>
#include <memory>
#include <vector>

void menu();

int main(){
    menu();
    int variant;
    std::shared_ptr<document> doc;
    do{
        std::cin >> variant;
        switch(variant){
            case 1:{
                std::string name;
                std::cout << "Name document : ";
                std::cin >> name;
                doc = std::make_shared<document>(name);
                std::cout << "Created new document\n";
                break;
            }

            case 2:{
                if (doc){
                    doc->Save();
                    std::cout << "Document saved\n";
                }
                else{
                    std::cout << "You need to open document first\n";
                }
                break;
            }

            case 3:{
                std::string file_name;
                std::cout << "Enter name of file : ";
                std::cin >> file_name;
                std::ifstream in;
                in.open(file_name, std::ios::in | std::ios::binary);
                if (!in.is_open()){
                    std::cout << "No file with that name" << std::endl;
                }
                else{
                    doc = std::make_shared<document>(file_name);
                    doc->Read(in);
                    std::cout << "File loaded" << std::endl;
                    in.close();
                }
                break;
            }

            case 4:{
                if(doc){
                    std::cout << "Enter figure id: 1 - triangle, 2 - rectangle, 3 - square \n";
                    int id;
                    std::cin >> id;
                    std::shared_ptr<Figure> fig = Factory::Create(id);
                    doc->Add(fig);
                    std::cout << "Figure added\n";
                }
                else{
                    std::cout << "You need to open document first\n";
                }
                break;
            }

            case  5:{
                if (doc){
                    int index;
                    std::cout << "Enter index: ";
                    std::cin >> index;
                    doc->Erase(index);
                    std::cout << "Figure removed\n";

                }
                else{
                    std::cout << "You need to open document first\n";
                }
                break;
            }

            case 6:{
                if(doc){
                    doc->Print();
                }
                else{
                    std::cout << "You need to open document first\n";
                }
                break;
            }

            case 7:{
                if(doc){
                    doc->Undo();
                }
                else{
                    std::cout << "You need to open document first\n";
                }
                break;
            }
        }

    }while(variant != 0);
    return 0;
}

void menu(){
    std::cout << "1. Create document \n";
    std::cout << "2. Save document \n";
    std::cout << "3. Open document (read file)\n";
    std::cout << "4. Add figure \n";
    std::cout << "5. Delete figure by index\n";
    std::cout << "6. Print all figures \n";
    std::cout << "7. Undo\n";
    std::cout << "0. Exit \n";
}
