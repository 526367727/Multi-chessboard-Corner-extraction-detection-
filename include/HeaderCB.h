#pragma once

#include "opencv2\opencv.hpp"
#include <vector>
#include "stdio.h"

#define logd std::printf;

struct Corners
{
	std::vector<cv::Point2f> p;
	std::vector<cv::Vec2f> v1;
	std::vector<cv::Vec2f> v2;
	std::vector<float> score;
} ;

struct ConerInfo
{
	cv::Point2f p;
	int chessidx;
	int row, col;
	int idx;//在当前棋盘格的标号
	float x, y;
	bool vaild;// 0 单目vaild， -1非法,
	int neardiskidx;// 在哪个圆盘附近
	float nearestdiskdistance;

	ConerInfo operator=(ConerInfo& value)
	{
		p = value.p;
		chessidx = value.chessidx;
		row = value.row;
		col = value.col;
		idx = value.idx;
		x = value.x;
		y = value.y;
		vaild = value.vaild;
		neardiskidx = value.neardiskidx;
		nearestdiskdistance = value.nearestdiskdistance;

		return *this;
	}
	ConerInfo()
	{
		vaild = true;
		neardiskidx = -1;
		nearestdiskdistance = -1.0;
	}

};
struct ImageChessesStruct
{
	std::vector<std::vector<cv::Point2f>> flagpostion;
	std::vector<std::vector<std::vector<int>>> idxconersflags;//标识每个棋盘格圆盘标志对应的角点的序号数组
	std::vector<int>choosecorneri;

	cv::Rect rt;
	int cbnum;
	std::vector<std::vector<ConerInfo>> chesscorners;//idx, corner id
	bool flagbeginfromzero;
	ImageChessesStruct& operator=(ImageChessesStruct& value)
	{
		cbnum = value.cbnum;
		chesscorners = value.chesscorners;
		return *this;
	}

};
