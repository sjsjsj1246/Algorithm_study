#include<iostream> 
#include<string> 
using namespace std;

string quard(string::iterator& it)
{ 
  char head = *it; ++it; 
  if (head == 'b' || head == 'w')
	return string(1, head);
  string one = quard(it); 
  string two = quard(it); 
  string three = quard(it); 
  string four = quard(it);
  return string("x") + three + four + one + two; 
} 

int main() 
{ 
  int num; 
  string str; 
  cin >> num;
  while (num--) 
  { 
	cin >> str;
	string::iterator iter = str.begin();
	cout << quard(iter) << endl; 
  }
}