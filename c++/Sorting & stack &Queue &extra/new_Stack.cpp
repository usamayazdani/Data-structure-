#include <iostream> 
#include <stack>  
using namespace std;
void createStack(stack <int> *mystack)
{
	stack <int> ms = mystack;
	while (!ms.empty())
	{
		cout << '\t' << ms.top();
		ms.pop();
	}
	cout << '\n';
}
int main()
{
	stack <int> st;
	st.push(32);
	st.push(21);
	st.push(39);
	st.push(89);
	st.push(25);

	cout << "The stack st is: ";
	createStack(&st);
	cout << "\n st.size() : " << st.size();
	cout << "\n st.top() : " << st.top();
	cout << "\n st.pop() : ";
	st.pop();
	createStack(&st);
	return 0;
}
