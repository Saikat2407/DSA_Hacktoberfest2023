// Java implementation of the approach
import java.util.*;
import java.awt.Point;
public class Main
{
	// Function that returns true if
	// the given pixel is valid
	static boolean isValid(int[][] screen, int m, int n, int x, int y, int prevC, int newC)
	{
		if(x < 0 || x >= m || y < 0 || y >= n || screen[x][y] != prevC
		|| screen[x][y]== newC)
			return false;
		return true;
	}


	// FloodFill function
	static void floodFill(int[][] screen, int m, int n, int x, int y, int prevC, int newC)
	{
		Vector<Point> queue = new Vector<Point>();

		// Append the position of starting
		// pixel of the component
		queue.add(new Point(x, y));

		// Color the pixel with the new color
		screen[x][y] = newC;

		// While the queue is not empty i.e. the
		// whole component having prevC color
		// is not colored with newC color
		while(queue.size() > 0)
		{
			// Dequeue the front node
			Point currPixel = queue.get(queue.size() - 1);
			queue.remove(queue.size() - 1);

			int posX = currPixel.x;
			int posY = currPixel.y;

			// Check if the adjacent
			// pixels are valid
			if(isValid(screen, m, n, posX + 1, posY, prevC, newC))
			{
				// Color with newC
				// if valid and enqueue
				screen[posX + 1][posY] = newC;
				queue.add(new Point(posX + 1, posY));
			}

			if(isValid(screen, m, n, posX-1, posY, prevC, newC))
			{
				screen[posX-1][posY]= newC;
				queue.add(new Point(posX-1, posY));
			}

			if(isValid(screen, m, n, posX, posY + 1, prevC, newC))
			{
				screen[posX][posY + 1]= newC;
				queue.add(new Point(posX, posY + 1));
			}

			if(isValid(screen, m, n, posX, posY-1, prevC, newC))
			{
				screen[posX][posY-1]= newC;
				queue.add(new Point(posX, posY-1));
			}
		}
	}
	
	public static void main(String[] args) {
		int[][] screen ={
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 0, 0},
		{1, 0, 0, 1, 1, 0, 1, 1},
		{1, 2, 2, 2, 2, 0, 1, 0},
		{1, 1, 1, 2, 2, 0, 1, 0},
		{1, 1, 1, 2, 2, 2, 2, 0},
		{1, 1, 1, 1, 1, 2, 1, 1},
		{1, 1, 1, 1, 1, 2, 2, 1}};
	
		// Row of the display
		int m = screen.length;
	
		// Column of the display
		int n = screen.length;
	
		// Co-ordinate provided by the user
		int x = 4;
		int y = 4;
	
		// Current color at that co-ordinate
		int prevC = screen[x][y];
	
		// New color that has to be filled
		int newC = 3;
		floodFill(screen, m, n, x, y, prevC, newC);
	
		// Printing the updated screen
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				System.out.print(screen[i][j] + " ");
			}
			System.out.println();
		}
	}
}

// This code is contributed by mukesh07.
