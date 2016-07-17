

#include <opencv2/opencv.hpp>

int main()
{
    // 打开摄像头
    cv::VideoCapture cap(0);

    // Mat是矩阵意思，定义了一个矩阵
    // opencv中使用矩阵来保存图片
    cv::Mat frame;

    while(1)
    {
        // 将摄像头的图片，写入frame
        cap >> frame;
        // 显示图片
        cv::imshow("showFrame1", frame);
       // cv::imshow("showFrame2", frame);

        // 等待用户键盘输入，参数表示等待时间，以毫秒为单位
        // 返回值是用户的按键的值
        int ret = cv::waitKey(30);
        if(ret == 27)  // ret ＝27表示用户输入了esc
            break;
    }
    return 0;
}
