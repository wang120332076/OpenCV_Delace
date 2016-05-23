#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

	if (argc < 3){
		cout << "\nUsage: OpenCV_Delace.exe *.mp4 OutputDirectory\nExample: OpenCV_Delace.exe 3D_R0001.mp4 .\\Output\n";
		return -1;
	}
	
	int ii, framenum;
	char sname[50];

	VideoCapture video(argv[1]);
	if (!video.isOpened()){  // check if we succeeded
		cout << "Can't open video file!" << endl;
		return -1;
	}

	framenum = (int)(video.get(CV_CAP_PROP_FRAME_COUNT));
	for (ii=0;ii<framenum;ii++){

		Mat frame;
		video >> frame;

		string Ssname = argv[2];
		//sprintf(sname, "\\%04d.png", ii);
		sprintf(sname, "\\%d.png", ii);			//No leading zeroes; Begin with 1 instead of 0
		Ssname.append(sname);
		//cout << Ssname.c_str() << endl;
		imwrite(Ssname.c_str(), frame);

		if (0==(ii%100)) {
			cout << ".";
		}

	}

	video.release();

	cout << "\nDone!" << endl;
	system("pause");

	return 0;
}