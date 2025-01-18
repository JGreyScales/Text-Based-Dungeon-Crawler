#include <string>

class Terrain
{
	char terrainMap[100][100];
public:
	void generateTerrain(Terrain& map) {
	
	};
	Terrain() {
		memset(terrainMap, 'w', sizeof(terrainMap));
	};

};