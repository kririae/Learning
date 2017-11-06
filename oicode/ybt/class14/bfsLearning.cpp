#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int stringMaxLength = 10;
const int deepMaxn = 1000;

int based = 1, processing = 0;
char input[stringMaxLength], output[stringMaxLength];
char result[deepMaxn][stringMaxLength];
int res[deepMaxn];
bool not_can_exist(char *cache) {
	for(int i = 0; i < processing; ++i) 
		if(strcmp(cache, result[i]) == 0) return false;
	return true;
}

int main() {
	scanf("%s", input);scanf("%s", output);
	// length of input;
	int length = strlen(input);
	// init the root node; 
	strcpy(result[0], input);
	int count = 0;
	char cache[stringMaxLength];
	res[based] = 0;
	while(based <= processing) {
		
		for(int temp, i = 0; i < length; ++i) {	
			strcpy(cache, result[based]);
			// exchange
			temp = cache[i], cache[i] = cache[i + 1], cache[i + 1] = temp;
			if(not_can_exist(cache)){
				strcpy(result[processing], cache);
				++processing;
				res[processing] = res[based] + 1; 
				if(strcmp(cache, output) == 0) {
					// TODO
					cout<<res[processing]<<endl;
					// exit
					based = processing + 1;
					break;
				}
			}
		}
		++based;
	}
	return 0;
}
