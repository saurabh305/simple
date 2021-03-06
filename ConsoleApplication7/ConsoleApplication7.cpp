// ConsoleApplication7.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include<iostream>
#include<string>
#include<memory>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int r1,b1,g1;
Mat img;
void threshold(int thres,void* data)
{
	int row = img.rows;
	int col = img.cols;
	Vec3b ch;
	uchar r, g, b;
	Mat binary(img.size(), CV_8UC1,Scalar(0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ch = img.at<Vec3b>(i, j);
			r = ch[2], g = ch[1], b = ch[0];
			if (b<b1 && g<g1 && r>r1)
			{
				uchar replacement=255;
				binary.at<uchar>(i, j) = replacement;
			}
			else
			{
				uchar replacement1=0;
			    binary.at<uchar>(i, j) = replacement1;
			}
		}
		
	}
	imshow("Changed", binary);
}

int main()
{
	Mat orignal;
	namedWindow("Changed");

	createTrackbar("Red", "Changed",&r1,255, threshold);
	createTrackbar("Blue", "Changed", &b1, 255, threshold);
	createTrackbar("Green", "Changed", &g1, 255, threshold);

	orignal= imread("C:\\Users\\saurabh chandra\\Desktop\\minion.jpg");
	img = orignal.clone();
	imshow("img", orignal);
	
	//threshold(binary, 50);


	waitKey(0);
	return 0;
}