#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct Bracket {
	char type;
    int position;
    Bracket(char type, int position){
        this->type=type;
        this->position=position;
		}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }
}*ptr=NULL,*newptr=NULL;
//Bracket* create(char ch, int position)
//{
//	ptr=new Bracket(ch,position);
//	return ptr;
//}
int main() {
    string text;
    getline(cin, text);

    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char ch = text[position];

        if (ch == '(' || ch == '[' || ch == '{') {
        	newptr=new Bracket(ch,position);
            opening_brackets_stack.push(*newptr);
        }

        if (ch == ')' || ch == ']' || ch == '}') {
        	if(opening_brackets_stack.empty()){
        	cout<<position+1;
        	return 0;}
        	else{
			if(opening_brackets_stack.top().Matchc(ch))
            opening_brackets_stack.pop();
            else{
            cout<<position+1;
			return 0;	}
			}
        }
    }
	if(opening_brackets_stack.empty())
	cout<<"Success";
	else cout<<opening_brackets_stack.top().position+1;
    return 0;
}
