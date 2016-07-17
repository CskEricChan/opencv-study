
#include <opencv2/opencv.hpp>

int main()
{
    cv::VideoCapture cap(0);

    if(!cap.isOpened())
    {
        printf("error open camera\n");
        return 0;
    }

    cv::Mat frame;
    float scale = 0.5f;
    while(1)
    {
        cap >> frame;

        cv::Size newSize(frame.cols*scale, frame.rows*scale);
        cv::Mat newFrame(newSize, CV_32S);
        cv::resize(frame, newFrame, newSize);
        cv::imshow("show me", newFrame);

        int ret = cv::waitKey(30);
        if(ret == 27)
        {
            break;
        }
    }
    return 0;
}
