#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;


const int ROWS = 10;
const int COLS = 20;
vector<vector<int> > world =
{
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
},
nextGen(world);

//IDEA: put this function in a loop that checks each individual element within the 2D vector
int numLiveNghbrs(const vector<vector<int> >& world, int p, int q) { // same thing as detect function
	int numLive = 0;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			//                      numLive += world[p+i][q+j];   // Wrong!!
			numLive += world[(p + i + ROWS) % ROWS][(q + j + COLS) % COLS];

	return numLive - world[p][q];
}
bool aliveNextGen(const vector<vector<int> >& world, int p, int q) {
	int numNghbrs = numLiveNghbrs(world, p, q);

	if (world[p][q])        // if currently alive
		return numNghbrs == 2 || numNghbrs == 3;
	else                    // currently not alive
		return numNghbrs == 3;
}







int main(int argc, char* argv[])
{
	if (argc != 2) {
		return 1;
	}
	int generation = atoi(argv[1]);

	vector<vector<int>> nextGen(world);
	for (int i = 0; i < generation; i++) {
		nextGen = world;
		for (int i = 0; i < world.size(); i++) {
			for (int j = 0; j < world[0].size(); j++) {
				if (aliveNextGen(world, i, j))
					nextGen[i][j] = 1;
				else
					nextGen[i][j] = 0;
			}
		}
		world = nextGen;
	}
	for (int i = 0; i < nextGen.size(); i++) {
		for (int j = 0; j < nextGen[0].size(); j++) {
			if (nextGen[i][j] == 1)
				cout << 'O';
			else
				cout << '.';
		}
		cout << "\n";
	}

	return 0;
}