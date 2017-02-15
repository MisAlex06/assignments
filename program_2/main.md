```.cpp
/**
* @ProgramName: Program-2
* @Author: Alejandra Brambila
* @Description:  This program reads in images stored as rgb values in a space delimited 
*				 file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 13/02/2017
*/

#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;



//Structure to hold an rgb value
struct rgb {
	int r;
	int g;
	int b;
};

class ImageManip{
	private:
		rgb** image;
		int width;
		int height;
		ifstream infile;
		ofstream ofile;
		string infile_name;
		string ofile_name;

		

	public:
	ImageManip() {
		
	}
	void readFile(string input_file) {
		infile.open(input_file);

		infile >> width >> height;	//Read in width and height from top of input file
										//We need this so we can make the array the right 
										//size. After we get these two values, we can
										//now allocate memory for our 2D array.

		image = new rgb*[height];    //This array points to every row

		for (int i = 0; i < height; i++) {
			image[i] = new rgb[width]; //Now allocate each row of rgb's
		}

		//Read the color data in from our txt file
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				infile >> image[i][j].r >> image[i][j].g >> image[i][j].b;
			}
		}
	}

	void writeFile(string ofile_file) {
		ofile.open(ofile_file);

		ofile << width << " " << height << endl;

		//Displays the color data in to our ofile text
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				ofile << image[i][j].r << image[i][j].g << image[i][j].b;
			}
		ofile << endl;
		}
	}
	/**
	* @FunctionName: flipVert
		* @Description:  Loops through a 2D array and turns every row from top to bottom to bottom to top
		* @Params: rgb** image - 2D array holding rgb values
		*    int width - width of image
		*    int height - height of image
		* @Returns: void
		*/
		void flipVert(string infile_name, string ofile_name) {
			rgb row;
			for (int x = 0; x < (height / 2); x++) {
				for (int y = 0; y < width; y++) {
					row = image[x][y];
					image[x][y] = image[height - 1 - x][y];
					image[height - 1 - x][y] = row;
				}
			}
		}

		/**
		* @FunctionName: flipHorz
		* @Description:  Loops through a 2D array and flips each column from left to right to right to
		* left.
		* @Params: rgb** image - 2D array holding rgb values
		* int width - width of image
		* int height - height of image
		* @Returns: void
		*/
		void flipHorz(string infile_name, string ofile_name) {
			rgb col;
			for (int x = 0; x < height; x++) {
				for (int y = 0; y < (width / 2); y++) {
					col = image[x][y];
					image[x][y] = image[x][width - 1 - y];
					image[x][width - 1 - y] = col;
				}
			}
		}
	
		/**
		* @FunctionName: grayScale
		* @Description:
		* Loops through a 2D array and turns every RGB value into its grayscale equivalent.
		* @Params: rgb** image - 2D array holding rgb values
		* int width - width of image
		* int height - height of image
		* @Returns: void
		*/
		void grayScale(string infile_name, string ofile_name) {
			int gray;
			for (int x = 0; x < width; x++) {
				for (int y = 0; y < height; y++) {
					gray = (image[x][y].r + image[x][y].g + image[x][y].b) / 3;
					image[x][y].r = gray;
					image[x][y].g = gray;
					image[x][y].b = gray;
				}
			}
		}

		/**
		* @FunctionName: printImage
		* @Description: Loops through a 2D array and prints new integers to output.txt
		*				which are the new variables for the changes made to image by
		*				the user.
		* @Params: rgb** image - 2D array holding rgb values
		*		   int width - width of image
		*		   int height - height of image
		*          ofstream outfile - output of new RGB's
		* @Returns: void
		*/
		void printImage(rgb **image, int &width, int &height, ofstream &outfile) {
			cout << height << " " << width << endl;

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					cout << image[i][j].r << " " << image[i][j].g << " "
						<< image[i][j].b << " ";
				}
			cout << endl;
			}
		}
		~ImageManip(){

	}
};

/**
* @FunctionName: main
* @Description: Initialized the read in from input.txt and offers the user a menu to
*				choose which way they would like the manipulate the input.txt
*				then saves results to output.txt.
* @Params: rgb** image - 2D array holding rgb values
*		   int width - width of image
*		   int height - height of image
* @Returns: void
*/
int main(){

	ImageManip run;

	run.readFile("input.txt");
	run.grayScale("input.txt", "output.txt");
	run.writeFile("output.txt");



	system("Pause");
	return 0;
}
```
