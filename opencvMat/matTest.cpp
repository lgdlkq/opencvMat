#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//显示创建Mat对象的七种方法
int main() {

	//方法一：使用Mat()构造函数
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));//CV_8UC3格式为CV_[位数][带符号与否][类的前缀]C[通道数]
	cout << "M =" << endl << "" << M << endl << endl;

	//方法二：在C/C++中通过构造函数进行初始化(创建一个超过二维的矩阵)
	int sz[3] = { 2,2,2 };
	Mat L(3, sz,CV_8UC3,Scalar::all(0));//指定维数然后传递一个指向一个数组的指针，数组包括每个纬度的尺寸，后同一方法

	//方法三：为已存在的IplImage指针创建信息头
	IplImage* img = cvLoadImage("1.jpg", 1);
	Mat mtx = cvarrToMat(img);//转换IplImage* -> Mat
	imshow("方法三测试",mtx);
	waitKey(2000);

	//方法四：利用Create()函数
	M.create(4, 4, CV_8UC(2));
	cout << "M =" << endl << "" << M << endl << endl;

	//方法五：采用Matlab式的初始化方式
	Mat E = Mat::eye(4, 4, CV_64F);
	cout << "E =" << endl << "" << E << endl << endl;

	Mat O = Mat::ones(2, 2, CV_64F);
	cout << "O =" << endl << "" << O << endl << endl;

	Mat Z = Mat::zeros(3, 3, CV_64F);
	cout << "Z =" << endl << "" << Z << endl << endl;

	//方法六：对小矩阵使用逗号分隔式初始化函数
	Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout << "C =" << endl << "" << C << endl << endl;

	//方法七：为已存在的对象创建信息头
	Mat RowClone = C.row(1).clone();
	cout << "RowClone =" << endl << "" << RowClone << endl << endl;

	return 0;
}