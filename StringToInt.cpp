#include <iostream>
#include <cstring>

using namespace std;



int AtoI(string str){
	string *ptr=NULL;
	ptr = strtok(str, " ");
	cout<<ptr<<"\n";
	return 0;
}

int main(){
	string s="-43";
	cout<<AtoI(s);
}