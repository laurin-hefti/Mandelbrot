#include <fstream>
#include <complex>
#include <cmath>
#include <math.h>
#include <array>
#include <iostream>
using namespace std;
//const int width = 1920, height = 1080;
const int width = 200, height = 100;
const int it = 20;
const double cx = 0, cy = 0;
const int zom = 1;

array<int, 3> returnfarbe2(int i) {
	if (i >= it-1) {
		return { 0,0,0 };
	}
	if (i <= 5) {
		return { 255,0,0 };
	}
	if (i > 5 && i <=10) {
		return { 250,250,0 };
	}
	if (i > 10 && i <= 15) {
		return { 0,255,0 };
	}
	if (i > 15 && i <= 18) {
		return { 0,255,255 };
	}
	if (i > 18) {
		return { 0,0,255 };
	}

}
array<int,3> returnfarbe(int i){
	if (i >= it) {
		return { 0,0,0 };
	}
	else if (i == 2) {
		return { 255,0,0 };
	}
	else if (i == 1) {
		return { 0,255,0 };
	}
	else if (i == 3) {
		return { 0,0,255 };
	}
	else if (i == 4) {
		return { 255,255,0 };
	}
	else if (i == 5) {
		return { 0,255,255 };
	}
	else if (i == 6) {
		return {255,0,255};
	}
	else if (i == 7) {
		return { 50,50,50 };
	}
	else if (i == 8) {
		return { 100,100,100 };
	}
	else if (i == 9) {
		return { 200,200,200 };
	}
	else {
		return { 255, 255, 255 };
	}
}
int main() {
	//ostream::basic_ostream();
	ofstream img("test5.ppm");
	img << "P3" << endl;
	img << width << " " << height << endl;	
	img << "255" << endl;

	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width; y++) {
			//complex<double> c = complex<double>((2 / (double)(height - 1)) * x - 1, (3 / (double)(width - 1)) * y - 2);
			complex<double> c = complex<double>((3 / (double)(width - 1)) * y - 2, (2 / (double)(height - 1)) * x - 1);

			//complex<double> c = ((double)((double)x / 1000) - 3, (double)((double)y / 1000) - 1);
			complex<double>oldc = c;
			int i = 0;
			int* ii = &i;
			bool drifted = false;
			for(i = 0; i < it; i++) {
				c = pow(c, 2) + oldc;
				if (abs(c) >= 2) {
					img << 255 << " " << 255 << " " << 255 << endl;
					drifted = true;
					break;
				}
				ii = &i;
			}
			if (!drifted)
			{
				img << 0 << " " << 0 << " " << 0 << endl;
			}
			//img << returnfarbe(*ii)[0] << " " << returnfarbe(*ii)[1] << " " << returnfarbe(*ii)[2] << endl;
		}
		//cout << x << endl;
	}
}