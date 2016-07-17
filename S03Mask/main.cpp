
#include <opencv2/opencv.hpp>
using namespace cv;
#if 0
void Sharpen(const Mat& myImage,Mat& Result)
{
    CV_Assert(myImage.depth() == CV_8U);  // 仅接受uchar图像

    Result.create(myImage.size(),myImage.type());
    const int nChannels = myImage.channels();

    for(int j = 1 ; j < myImage.rows-1; ++j)
    {
        const uchar* previous = myImage.ptr<uchar>(j - 1);
        const uchar* current  = myImage.ptr<uchar>(j    );
        const uchar* next     = myImage.ptr<uchar>(j + 1);

        uchar* output = Result.ptr<uchar>(j);

        for(int i= nChannels;i < nChannels*(myImage.cols-1); ++i)
        {
            *output++ = saturate_cast<uchar>(5*current[i]
                         -current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
        }
    }

    Result.row(0).setTo(Scalar(0));
    Result.row(Result.rows-1).setTo(Scalar(0));
    Result.col(0).setTo(Scalar(0));
    Result.col(Result.cols-1).setTo(Scalar(0));
}
#endif

int main()
{
    // 8UC3
    cv::Mat image1 = cv::imread("/Users/xueguoliang/Downloads/1.jpg");

    /*
        0, -1, 0,
        -1, 5, -1,
        0, -1, 0
    */
    cv::Mat mask = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cv::Mat outImage;
  //  Sharpen(image1, outImage);
    cv::filter2D(image1, outImage, image1.depth(), mask);

    cv::imshow("input", image1);
    cv::imshow("output", outImage);

    cv::waitKey(0);
    return 0;
}
