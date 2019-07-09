//#include <opencv.hpp>
//#include <opencv2/core/core_c.h>
//#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
// #include <opencv2/legacy/legacy.hpp>

//using namespace cv;

#pragma comment(lib,"opencv_core2410d.lib")
#pragma comment(lib,"opencv_highgui2410d.lib")
#pragma comment(lib,"opencv_imgproc2410d.lib")
#pragma comment(lib,"opencv_features2d2410d.lib")
#pragma comment(lib,"opencv_calib3d2410d.lib")
#pragma comment(lib,"opencv_legacy2410d.lib")

//#include <gl/GLU.h>
#include "glut.h"

//#pragma comment(lib,"glaux.lib")
//#pragma comment(lib,"opengl32.lib")
//#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glut32.lib")

#include <atlstr.h> // use STL string instead, although not as convenient...
#include <atltrace.h>
#define TRACE ATLTRACE

#include <iostream>
#include <fstream>
#include <string>
#include<time.h>
using namespace std;

//#include <math.h>




bool LoadPtsPairs( vector<cv::Point2f> &ptsL, vector<cv::Point2f> &ptsR, string &filename );

void SavePtsPairs( vector<cv::Point2f> &ptsL, vector<cv::Point2f> &ptsR, string &filename );


/* cv functions */
void StereoTo3D( vector<cv::Point2f> ptsL, vector<cv::Point2f> ptsR, vector<cv::Point3f> &pts3D, 
				float focalLenInPixel, float baselineInMM, 
				cv::Mat img, cv::Point3f &center3D, cv::Vec3f &size3D);

void TriSubDiv( vector<cv::Point2f> &pts, cv::Mat &img, vector<cv::Vec3i> &tri );

void GetPair( cv::Mat &imgL, cv::Mat &imgR, vector<cv::Point2f> &ptsL, vector<cv::Point2f> &ptsR );

void GetPairBM( cv::Mat &imgL, cv::Mat &imgR, vector<cv::Point2f> &ptsL, vector<cv::Point2f> &ptsR );

void CalcDisparity( cv::Mat &imgL, cv::Mat &imgR, cv::Mat_<float> &disp, int nod );

//void GetPairSegBM( Mat &imgL, Mat &imgR, vector<Point2f> &ptsL, vector<Point2f> &ptsR, vector<int> &ptNum );

//void TriSubDivSeg( vector<Point2f> &ptsL, vector<int> &ptNum, Mat &imgL, vector<Vec3i> &tri );


/* CG functions */
void MapTexTri( cv::Mat & texImg, cv::Point2f pt2D, cv::Point3f pt3D );

GLuint Create3DTexture( cv::Mat &img, vector<cv::Vec3i> &tri, 
					   vector<cv::Point2f> pts2DTex, vector<cv::Point3f> &pts3D, 
					   cv::Point3f center3D, cv::Vec3f size3D );

void Show( GLuint tex, cv::Point3f center3D, cv::Vec3i size3D );

/* OpenGL functions*/
void InitGl();

void Init_lightGl();

void displayGl();

void resizeGl(int w, int h);

void mouseGl(int button, int state, int x, int y);

void mouse_move_Gl(int x,int y);

void keyboard_control_Gl(unsigned char key, int a, int b);

void special_control_Gl(int key, int x, int y);
