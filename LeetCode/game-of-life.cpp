class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		// Neighbors array to find 8 neighboring cells for a given cell
		int neighbors[3] = { 0, 1, -1 };

		int rows = board.size();
		int cols = board[0].size();

		// Iterate through board cell by cell.
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {

				// For each cell count the number of live neighbors.
				int liveNeighbors = 0;

				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {

						if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
							int r = (row + neighbors[i]);
							int c = (col + neighbors[j]);

							// Check the validity of the neighboring cell.
							// and whether it was originally a live cell.
							if ((r < rows && r >= 0) && (c < cols && c >= 0) && (abs(board[r][c]) == 1)) {
								liveNeighbors += 1;
							}
						}
					}
				}

				// Rule 1 or Rule 3
				if ((board[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
					// -1 signifies the cell is now dead but originally was live.
					board[row][col] = -1;
				}
				// Rule 4
				if (board[row][col] == 0 && liveNeighbors == 3) {
					// 2 signifies the cell is now live but was originally dead.
					board[row][col] = 2;
				}
			} 
		}

		// Get the final representation for the newly updated board.
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				if (board[row][col] > 0) {
					board[row][col] = 1;
				}
				else {
					board[row][col] = 0;
				}
			}
		}

	}
};