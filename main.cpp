#include <vector>
#include <iostream>

using namespace std;

int main() {
	int cellIdx = 0, brc = 0;
	char cpu[30000] = {0};

	char command;
	vector<unsigned char> commands;
	while(cin >> command && !cin.fail()) {
		commands.push_back(command);
	}

	for(size_t commandIdx{}, size = commands.size(); commandIdx != size; ++commandIdx) {
		if(commands[commandIdx] == '>') {
			++cellIdx;
		} else if(commands[commandIdx] == '<') {
			--cellIdx;
		} else if(commands[commandIdx] == '+') {
			++cpu[cellIdx];
		} else if(commands[commandIdx] == '-') {
			--cpu[cellIdx];
		} else if(commands[commandIdx] == '.') {
			cout << cpu[cellIdx];
		} else if(commands[commandIdx] == ',') {
			cin >> cpu[cellIdx];
		} else if(commands[commandIdx] == '[') {
			if(!cpu[cellIdx]) {
				++brc;
				while(brc) {
					commandIdx += 1;
					if(commands[commandIdx] == '[') {
						++brc;
					} else if(commands[commandIdx] == ']') {
						--brc;
					}
				}
			}
		} else if(commands[commandIdx] == ']') {
			if(cpu[cellIdx]) {
				++brc;
				while(brc) {
					--commandIdx;
					if(commands[commandIdx] == '[') {
						brc--;
					} else if(commands[commandIdx] == ']') {
						brc++;
					}
				}
				--commandIdx;
			}
		}
	}
}