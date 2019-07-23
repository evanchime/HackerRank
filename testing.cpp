//#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
	int *y;
	/*if(!y){
		cout << "works" << endl;
	}*/
	int x = 3;
	//y = &x;
	std::cout << x << ' ' << y << endl;
	y = new int();
	//y = (int *)malloc(sizeof(int));
	std::cout << x << ' ' << y << endl;
	delete y;
	//free(y);
	return 0;
}
