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
	int idx;//�ڵ�ǰ���̸�ı��
	float x, y;
	bool vaild;// 0 ��Ŀvaild�� -1�Ƿ�,
	int neardiskidx;// ���ĸ�Բ�̸���
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
	std::vector<std::vector<std::vector<int>>> idxconersflags;//��ʶÿ�����̸�Բ�̱�־��Ӧ�Ľǵ���������
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
