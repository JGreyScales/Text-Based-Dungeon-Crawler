//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <vector>
//#include <algorithm>
//
//class Terrain {
//    char terrainMap[100][100];  // The terrain grid
//
//public:
//    Terrain() {
//        srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
//        // Initialize the grid with walls ('W')
//        for (int i = 0; i < 100; ++i) {
//            for (int j = 0; j < 100; ++j) {
//                terrainMap[i][j] = 'W';  // Fill the grid with walls initially
//            }
//        }
//    }
//
//    // Helper function to check if a room fits in the grid
//    bool canPlaceRoom(int x, int y, int roomWidth, int roomHeight) {
//        if (x + roomWidth > 100 || y + roomHeight > 100) return false;
//
//        // Check if the area is empty (all 'W')
//        for (int i = x; i < x + roomWidth; ++i) {
//            for (int j = y; j < y + roomHeight; ++j) {
//                if (terrainMap[i][j] != 'W') return false;  // If any part is not a wall, return false
//            }
//        }
//        return true;
//    }
//
//    // Helper function to place a room in the grid
//    void placeRoom(int x, int y, int roomWidth, int roomHeight) {
//        for (int i = x; i < x + roomWidth; ++i) {
//            for (int j = y; j < y + roomHeight; ++j) {
//                terrainMap[i][j] = 'E';  // Mark as empty space
//            }
//        }
//    }
//
//    // Function to generate a random room (5x5 to 10x10)
//    void generateRandomRoom() {
//        int roomWidth = rand() % 6 + 5;  // Room width: 5-10
//        int roomHeight = rand() % 6 + 5; // Room height: 5-10
//        int x = rand() % 95;  // Random starting x coordinate
//        int y = rand() % 95;  // Random starting y coordinate
//
//        // Ensure the room fits in the grid and doesn't overlap
//        if (canPlaceRoom(x, y, roomWidth, roomHeight)) {
//            placeRoom(x, y, roomWidth, roomHeight);  // Place the room
//            std::cout << "Room placed at: (" << x << ", " << y << ") with size: " << roomWidth << "x" << roomHeight << std::endl;
//        }
//    }
//
//    // Function to create a corridor between two points (e.g., connecting room centers)
//    void createCorridor(int x1, int y1, int x2, int y2) {
//        // Horizontal corridor
//        if (x1 != x2) {
//            for (int i = std::min(x1, x2); i <= std::max(x1, x2); ++i) {
//                terrainMap[i][y1] = 'E';  // Mark corridor as empty space
//            }
//        }
//        // Vertical corridor
//        if (y1 != y2) {
//            for (int i = std::min(y1, y2); i <= std::max(y1, y2); ++i) {
//                terrainMap[x2][i] = 'E';  // Mark corridor as empty space
//            }
//        }
//    }
//
//    // Function to connect rooms with corridors
//    void connectRooms(std::vector<std::pair<int, int>> roomCenters) {
//        for (size_t i = 1; i < roomCenters.size(); ++i) {
//            createCorridor(roomCenters[i - 1].first, roomCenters[i - 1].second, roomCenters[i].first, roomCenters[i].second);
//        }
//    }
//
//    // Function to generate multiple rooms and connect them
//    void generateRoomsAndConnect() {
//        std::vector<std::pair<int, int>> roomCenters;
//
//        // Generate a fixed number of rooms
//        for (int i = 0; i < 5; ++i) {  // Generate 5 rooms (or more)
//            generateRandomRoom();
//            roomCenters.push_back({ rand() % 95, rand() % 95 });  // Store random room center
//        }
//
//        // Connect the rooms
//        connectRooms(roomCenters);
//    }
//
//    // Print the terrain map
//    void printTerrain() const {
//        for (int i = 0; i < 100; ++i) {
//            for (int j = 0; j < 100; ++j) {
//                std::cout << terrainMap[i][j] << ' ';
//            }
//            std::cout << std::endl;
//        }
//    }
//};
//
//int main() {
//    Terrain terrain;
//    terrain.generateRoomsAndConnect();
//    terrain.printTerrain();  // Print the generated map
//    return 0;
//}
