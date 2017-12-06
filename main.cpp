/*  Copyright 2017 only(997737609@qq.com). All Rights Reserved.           */
/*                                                                        */
/*  This file is part of ACRC(自动多棋盘格提取).                          */
/*                                                                        */
/*  part of source code come from https://github.com/qibao77/cornerDetect */
/*  Automatic Camera and Range Sensor Calibration using a single Shot     */
/*  this project realize the papar: Automatic Camera and Range Sensor     */
/*  Calibration using a single Shot                                       */
/*  the chess recovery class source code can contact 997737609@qq.com     */

#include "opencv2/opencv.hpp"

#include <algorithm>
#include "CornerDetAC.h "
#include "include\ChessboardRecovery.h"
#include "include\HeaderCB.h"

#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace cv;
using namespace std;
using std::vector;
vector<Point2i> points;

int main(int argc, char* argv[])
{

	Mat src1; 
	cv::Mat src;

	printf("read file...\n");

	string sr = "02";

	string simage, stxt, ssave;
	simage = sr + ".png";
	stxt = sr + ".txt";
	ssave = sr + ".png";

	src1 = imread(simage.c_str(), -1);
	if (src1.channels() == 1)
	{
		src = src1.clone();
	}
	else
	{
		if (src1.channels() == 3)
		{
			cv::cvtColor(src1, src, CV_BGR2GRAY);
		}
		else
		{
			if (src1.channels() == 4)
			{
				cv::cvtColor(src1, src, CV_BGRA2GRAY);
			}
		}
	}

	if (src.empty())//不能读取图像
	{
		printf("Cannot read image file: %s\n", simage.c_str());
		return -1;
	}
	else
	{
		printf("read image file ok\n");
	}

	vector<Point> corners_p;//存储找到的角点
	
	double t = (double)getTickCount();
	
	CornerDetAC corner_detector(src);

	Corners corners_s;
	corner_detector.detectCorners(src, corners_p, corners_s, 0.01);
	//corner_detector.savecorners(corners_s, "corner.txt");
	//corner_detector.readcorners(corners_s, "corner.txt");

	t = ((double)getTickCount() - t) / getTickFrequency();
	std::cout << "time cost :" << t << std::endl;
	ImageChessesStruct ics;
	std::vector<cv::Mat> chessboards;
	ChessboardRecovery cbr;
	cbr.ChessboardRecoveryRun(src1, corners_s, chessboards, ics, true);


	return 0;
}

