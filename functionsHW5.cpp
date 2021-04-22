#include<vector>
#include <cmath>
#include "functionsHW5.h"

using namespace std;

int colorPath(const vector<vector<int> >& elevations, vector<vector<int> >& r, vector<vector<int> >& g, vector<vector<int> >& b, int color_r, int color_g,
	int color_b, int start_row) {
	int dist = 0;

	int valueCheckFWD = 0;
	int valueCheckFWDUP = 0;
	int valueCheckFWDDOWN = 0;
	int iVal = start_row;

for (int i = start_row; i < start_row + 1; i++) {
	r.at(i).at(0) = color_r;
	g.at(i).at(0) = color_g;
	b.at(i).at(0) = color_b;
	for (int j = 0; j < elevations.at(i).size() - 1; j++) {

		if (iVal == 0) {
					int valueCheckFWD = abs(elevations.at(iVal).at(j) - elevations.at(iVal).at(j+1));
					int valueCheckFWDDOWN = abs(elevations.at(iVal).at(j) - elevations.at(iVal + 1).at(j + 1));
					int valueCheckFWDUP = valueCheckFWD + valueCheckFWDDOWN;
					if ((valueCheckFWD == valueCheckFWDUP) && (valueCheckFWD == valueCheckFWDDOWN)) {
						r.at(iVal).at(j+1) = color_r;
						g.at(iVal).at(j+1) = color_g;
						b.at(iVal).at(j+1) = color_b;
						dist += valueCheckFWD;
					}
					else if (((valueCheckFWD == valueCheckFWDUP) && (valueCheckFWD < valueCheckFWDDOWN)) || ((valueCheckFWD == valueCheckFWDDOWN) && (valueCheckFWD < valueCheckFWDUP))) {
						r.at(iVal).at(j+1) = color_r;
						g.at(iVal).at(j+1) = color_g;
						b.at(iVal).at(j+1) = color_b;
						dist += valueCheckFWD;
					}
					else if ((valueCheckFWDUP == valueCheckFWDDOWN) && ((valueCheckFWDUP < valueCheckFWD) && (valueCheckFWDDOWN < valueCheckFWD))) {
						r.at(iVal+1).at(j+1) = color_r;
						g.at(iVal+1).at(j+1) = color_g;
						b.at(iVal+1).at(j+1) = color_b;
						iVal += 1;
						dist += valueCheckFWDDOWN;
					}
					else if ((valueCheckFWD < valueCheckFWDUP) && (valueCheckFWD < valueCheckFWDDOWN)) {
							r.at(iVal).at(j+1) = color_r;
							g.at(iVal).at(j+1) = color_g;
							b.at(iVal).at(j+1) = color_b;
							dist += valueCheckFWD;

						}
						else if ((valueCheckFWDUP < valueCheckFWDDOWN) && (valueCheckFWDUP < valueCheckFWD)) {
							r.at(iVal-1).at(j+1) = color_r;
							g.at(iVal-1).at(j+1) = color_g;
							b.at(iVal-1).at(j+1) = color_b;
							iVal -= 1;
							dist += valueCheckFWDUP;
						}
						else if ((valueCheckFWDDOWN < valueCheckFWD) && (valueCheckFWDDOWN < valueCheckFWDUP)) {
							r.at(iVal+1).at(j+1) = color_r;
							g.at(iVal+1).at(j+1) = color_g;
							b.at(iVal+1).at(j+1) = color_b;
							iVal += 1;
							dist += valueCheckFWDDOWN;
						}
				}
				else if (iVal == elevations.size() - 1) {
					int valueCheckFWDUP = abs(elevations.at(iVal).at(j) - elevations.at(iVal - 1).at(j + 1));
					int valueCheckFWD = abs(elevations.at(iVal).at(j) - elevations.at(iVal).at(j+1));
					int valueCheckFWDDOWN = valueCheckFWDUP + valueCheckFWD;
					if ((valueCheckFWD == valueCheckFWDUP) && (valueCheckFWD == valueCheckFWDDOWN)) {
						r.at(iVal).at(j+1) = color_r;
						g.at(iVal).at(j+1) = color_g;
						b.at(iVal).at(j+1) = color_b;
						dist += valueCheckFWD;
					}
					else if (((valueCheckFWD == valueCheckFWDUP) && (valueCheckFWD < valueCheckFWDDOWN)) || ((valueCheckFWD == valueCheckFWDDOWN) && (valueCheckFWD < valueCheckFWDUP))) {
						r.at(iVal).at(j+1) = color_r;
						g.at(iVal).at(j+1) = color_g;
						b.at(iVal).at(j+1) = color_b;
						dist += valueCheckFWD;
					}
					else if ((valueCheckFWDUP == valueCheckFWDDOWN) && ((valueCheckFWDUP < valueCheckFWD) && (valueCheckFWDDOWN < valueCheckFWD))) {
						r.at(iVal+1).at(j+1) = color_r;
						g.at(iVal+1).at(j+1) = color_g;
						b.at(iVal+1).at(j+1) = color_b;
						iVal += 1;
						dist += valueCheckFWDDOWN;
					}
					else if ((valueCheckFWD < valueCheckFWDUP) && (valueCheckFWD < valueCheckFWDDOWN)) {
							r.at(iVal).at(j+1) = color_r;
							g.at(iVal).at(j+1) = color_g;
							b.at(iVal).at(j+1) = color_b;
							dist += valueCheckFWD;

						}
						else if ((valueCheckFWDUP < valueCheckFWDDOWN) && (valueCheckFWDUP < valueCheckFWD)) {
							r.at(iVal-1).at(j+1) = color_r;
							g.at(iVal-1).at(j+1) = color_g;
							b.at(iVal-1).at(j+1) = color_b;
							iVal -= 1;
							dist += valueCheckFWDUP;

						}
						else if ((valueCheckFWDDOWN < valueCheckFWD) && (valueCheckFWDDOWN < valueCheckFWDUP)) {
							r.at(iVal+1).at(j+1) = color_r;
							g.at(iVal+1).at(j+1) = color_g;
							b.at(iVal+1).at(j+1) = color_b;
							iVal += 1;
							dist += valueCheckFWDDOWN;

						}
				}
				else {
					int valueCheckFWDUP = abs(elevations.at(iVal).at(j) - elevations.at(iVal - 1).at(j + 1));
					int valueCheckFWD = abs(elevations.at(iVal).at(j) - elevations.at(iVal).at(j+1));
					int valueCheckFWDDOWN = abs(elevations.at(iVal).at(j) - elevations.at(iVal + 1).at(j + 1));
					if ((valueCheckFWD == valueCheckFWDUP) && (valueCheckFWD == valueCheckFWDDOWN)) {
						r.at(iVal).at(j+1) = color_r;
						g.at(iVal).at(j+1) = color_g;
						b.at(iVal).at(j+1) = color_b;
						dist += valueCheckFWD;
					}
					else if (((valueCheckFWD == valueCheckFWDUP) && (valueCheckFWD < valueCheckFWDDOWN)) || ((valueCheckFWD == valueCheckFWDDOWN) && (valueCheckFWD < valueCheckFWDUP))) {
						r.at(iVal).at(j+1) = color_r;
						g.at(iVal).at(j+1) = color_g;
						b.at(iVal).at(j+1) = color_b;
						dist += valueCheckFWD;
					}
					else if ((valueCheckFWDUP == valueCheckFWDDOWN) && ((valueCheckFWDUP < valueCheckFWD) && (valueCheckFWDDOWN < valueCheckFWD))) {
						r.at(iVal+1).at(j+1) = color_r;
						g.at(iVal+1).at(j+1) = color_g;
						b.at(iVal+1).at(j+1) = color_b;
						iVal += 1;
						dist += valueCheckFWDDOWN;
					}
					else if ((valueCheckFWD < valueCheckFWDUP) && (valueCheckFWD < valueCheckFWDDOWN)) {
							r.at(iVal).at(j+1) = color_r;
							g.at(iVal).at(j+1) = color_g;
							b.at(iVal).at(j+1) = color_b;
							dist += valueCheckFWD;

						}
						else if ((valueCheckFWDUP < valueCheckFWDDOWN) && (valueCheckFWDUP < valueCheckFWD)) {
							r.at(iVal-1).at(j+1) = color_r;
							g.at(iVal-1).at(j+1) = color_g;
							b.at(iVal-1).at(j+1) = color_b;
							iVal -= 1;
							dist += valueCheckFWDUP;

						}
						else if ((valueCheckFWDDOWN < valueCheckFWD) && (valueCheckFWDDOWN < valueCheckFWDUP)) {
							r.at(iVal+1).at(j+1) = color_r;
							g.at(iVal+1).at(j+1) = color_g;
							b.at(iVal+1).at(j+1) = color_b;
							iVal += 1;
							dist += valueCheckFWDDOWN;

						}
				}
	}
}

		return dist;
	}
