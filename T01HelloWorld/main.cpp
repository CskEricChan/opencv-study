
#include <opencv2/opencv.hpp>

int main()
{
    // 打开摄像头
    cv::VideoCapture cap(0);

    if(!cap.isOpened())
    {
        printf("error open camera\n");
        return 0;
    }

    // 定义一个矩阵对象，用来保存图像
    cv::Mat frame;
    while(1)
    {
        // 将摄像头的图像放入矩阵中
        cap >> frame;
        // 显示图片
        cv::imshow("show me", frame);
        // 等30毫秒之后再显示下一张
        int ret = cv::waitKey(30);
        // 如果用户按esc键，程序退出
        if(ret == 27)
        {
            break;
        }
    }
    return 0;
}
