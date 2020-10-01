//Stack using array
//------------------
#include<iostream>
#define N 5
using namespace std;
int stk[N];
int top=-1;
class stack{
	public:	
		void push(int e){
			if(top==N-1)
			{
			cout<<"Stack is full!\n";
			}
			else
			{
			top++;	
			stk[top]=e;
			cout<<e<<" Successfully entered\n";		
			}
		}
	
			void pop(){
			if(isEmpty()){
				cout<<"The Stack is Empty!\n";
			}
			else{			
			cout<<stk[top]<<" successfully deleted\n";
			top--;
			}
		}
		void seek(){
			cout<<stk[top];
		}
		void display()
		{
			for(int i=top;i>=0;i--)
			{
				cout<<stk[i]<<endl;
			}
		}
		bool isEmpty()
		{
			if(top==-1)
			return 1;
		return 0;
		}
};

int main(){
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.display();
//	s.pop();
//	s.push(10);
//	s.pop();
//	s.pop();

	return 0;
}
