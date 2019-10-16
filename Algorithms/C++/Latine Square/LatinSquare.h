#ifndef LATINSQUARE_H
#define LATINSQUARE_H

class LatinSquare
{
	public:
		LatinSquare(int n);
		void calculate();
	protected:
		int n;
		int **m;
		int c;
		void backTrack(int i, int j);
		bool finalCheck();
		bool finished();
		void showMatrix();
		
};

#endif
