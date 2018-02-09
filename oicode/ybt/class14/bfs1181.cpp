//#define DEBUG
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = 1000;
int *vol = new int[3], based = 0, processing = 0;
struct status {
	int value[3];
	status()
	{
		memset(value, 0, sizeof(value))	;
	}
};

set<int> s;
status *curr = new status[MAXN];
int *tempora = new int[3];

bool eql(const int* a, const int* b)
{
	for(int i = 0; i < 3; ++i)
		if(a[i] != b[i]) return false;

	return true;
}
bool can_exist()
{
	bool exist = true;

	for(int i = 0; i < processing; ++i)
		if(eql(tempora, curr[i].value)) return false;

	return true;
}

int main()
{
	cin >> vol[0] >> vol[1] >> vol[2];
	curr[0].value[0] = 0, curr[0].value[1] = 0, curr[0].value[2] = vol[2];

	while(based <= processing) {
		// tempora[i] -> tempora[j];
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(i == j) continue;

				for(int k = 0; k < 3; ++k) tempora[k] = curr[based].value[k];

				// 总共有两种情况 do
				if(tempora[i] + tempora[j] <= vol[j]) {
					tempora[j] += tempora[i];
					tempora[i] = 0;
				} else {
					tempora[i] -= (vol[j] - tempora[j]);
					tempora[j] = vol[j];
				}

				// end
#ifdef DEBUG
				printf("%c -> %c : ", i + 'a', j + 'a');

				for(int k = 0; k < 3; ++k) printf("%c:%d \\ ", k + 'a', tempora[k]);

				cout << can_exist();
				cout << endl;
#endif

				if(can_exist()) {
					++processing;

					if(tempora[0] == 0) {
						s.insert(tempora[2]);
						//cout<<endl<<tempora[2]<<" "<<endl;break;
					}

					for(int t = 0; t < 3; ++t)
						curr[processing].value[t] = tempora[t];
				}
			}
		}

		++based;
	}

	// output
	for(set<int>::iterator it = s.begin(); it != s.end(); ++it) cout << *it << " ";

	return 0;
}
