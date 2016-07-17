
#include <iostream>
using namespace std;
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat A;
    A = cv::imread("/Users/xueguoliang/Downloads/1.jpg");


    // cv::Rect表示矩形，四个参数分表表示两个坐标点，左下角和右上角，包含左上角，但是不包含右上角
    cv::Mat D(A, cv::Rect(10, 10, 100, 100));

    cv::imshow("show", D);

    cv::Mat T(2, 2, CV_8UC3, cv::Scalar(0, 0, 255));
    cout << "this is T:" << endl << T << endl;

    // waitKey的参数是0表示无限等待
    cv::waitKey(0);

    return 0;
}
