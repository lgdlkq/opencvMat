#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//��ʾ����Mat��������ַ���
int main() {

	//����һ��ʹ��Mat()���캯��
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));//CV_8UC3��ʽΪCV_[λ��][���������][���ǰ׺]C[ͨ����]
	cout << "M =" << endl << "" << M << endl << endl;

	//����������C/C++��ͨ�����캯�����г�ʼ��(����һ��������ά�ľ���)
	int sz[3] = { 2,2,2 };
	Mat L(3, sz,CV_8UC3,Scalar::all(0));//ָ��ά��Ȼ�󴫵�һ��ָ��һ�������ָ�룬�������ÿ��γ�ȵĳߴ磬��ͬһ����

	//��������Ϊ�Ѵ��ڵ�IplImageָ�봴����Ϣͷ
	IplImage* img = cvLoadImage("1.jpg", 1);
	Mat mtx = cvarrToMat(img);//ת��IplImage* -> Mat
	imshow("����������",mtx);
	waitKey(2000);

	//�����ģ�����Create()����
	M.create(4, 4, CV_8UC(2));
	cout << "M =" << endl << "" << M << endl << endl;

	//�����壺����Matlabʽ�ĳ�ʼ����ʽ
	Mat E = Mat::eye(4, 4, CV_64F);
	cout << "E =" << endl << "" << E << endl << endl;

	Mat O = Mat::ones(2, 2, CV_64F);
	cout << "O =" << endl << "" << O << endl << endl;

	Mat Z = Mat::zeros(3, 3, CV_64F);
	cout << "Z =" << endl << "" << Z << endl << endl;

	//����������С����ʹ�ö��ŷָ�ʽ��ʼ������
	Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cout << "C =" << endl << "" << C << endl << endl;

	//�����ߣ�Ϊ�Ѵ��ڵĶ��󴴽���Ϣͷ
	Mat RowClone = C.row(1).clone();
	cout << "RowClone =" << endl << "" << RowClone << endl << endl;

	return 0;
}