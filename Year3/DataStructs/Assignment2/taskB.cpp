#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

struct Variable 
{
    string name;
    int value;

    Variable(string name, int value) 
    {
        this->name = name;
        this->value = value;
    }
};


class Stack 
{
    private: list<Variable> stack;
    public:
        Stack() {}

        bool isEmpty() {return stack.empty();}
        
        Variable& top() {return stack.back();}
        Variable pop() 
        {
            Variable back = top();
            stack.pop_back();
            return back;
        }

        void push(const Variable& var) {stack.push_back(var);}
        void display() 
        {
            for (Variable var : stack) 
            {
                cout << "Name: " << var.name << "    Value: " << var.value;
                cout << endl << endl;
            }
        }
};



class var_processor {
    private:
        ifstream code_file;
        Stack vars_stack;
        int line_counter = 0;

    public:
        var_processor() {code_file = ifstream("code.txt");}


        void process_declaration(const string& line) 
        {
            size_t begg = line.find("int ") + 4;
            size_t end = line.find(";");
            
            string declaration_substr = line.substr(begg, end - begg);
            size_t equal_indx = declaration_substr.find("=");

            if (equal_indx == string::npos) 
            {
                string var_name = declaration_substr;
                Variable new_var(var_name, -1);

                vars_stack.push(new_var);
            } 
            else {
                string var_name = declaration_substr.substr(0, equal_indx);
                int var_value = stoi(declaration_substr.substr(equal_indx + 1));

                Variable new_var(var_name, var_value);
                vars_stack.push(new_var);
            }
            display();
        }


        void process_assignment(const string& line) 
        {
            size_t begg = line.find("=") - 1;
            size_t end = line.find(";");

            string assig_substr = line.substr(begg, end - begg);
            size_t equal_index = assig_substr.find("=");

            string target_var_name = assig_substr.substr(0, equal_index);
            int new_var_value = stoi(assig_substr.substr(equal_index + 1, assig_substr.find(";") - (equal_index + 1)));

            Stack temp;
            while (!vars_stack.isEmpty()) 
            {
                Variable current = vars_stack.pop();
                if (current.name == target_var_name) 
                {
                    Variable updated(target_var_name, new_var_value);
                    temp.push(updated);
                } 
                else 
                {
                    temp.push(current);
                }
            }

            while (!(temp.isEmpty())) {vars_stack.push(temp.pop());}
            display();
            
        }

        
        void process_return0() 
        {
            display();
            while (!(vars_stack.isEmpty())) {vars_stack.pop();}
        }



        void process_line(const string& line) 
        {
            if (line.find("int main()") != string::npos) return;

            if (line.find("int ") != string::npos) 
            {
                process_declaration(line);
                return;
            }

            if (line.find("=") != string::npos) 
            {
                process_assignment(line);
                return;
            }

            if (line.find("return 0;") != string::npos) 
            {
                process_return0();
                return;
            }

        }


        void process() 
        {
            string line;
            while(getline(code_file, line)) 
            {
                process_line(line);
            }

            code_file.close();
        }

        void display() 
        {
            cout << "Line: " << ++line_counter << endl;
            cout << "STACK CONTENT: " << endl;
            vars_stack.display();
            cout << endl;
        }

        ~var_processor() {if (code_file.is_open()) code_file.close();}
};


int main() 
{
    var_processor prcss;
    prcss.process();
}