#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>  
using namespace cv;  
using namespace std;

// #define block 30

int main(int argc, char** argv) {     //参1传入block值，2传图片名: .png
    Mat image;

    
    if(argc!=3){
    	printf("参数：int block , string imgName\n");
    	return -1;
    }

    string url = "./picture/";
    int block = atoi(argv[1] );
    char pname[30]; strcpy(pname, argv[2]);
    url.append(pname);

    image = imread(url, 1); 


    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY); //颜色通道转换 BGR-->Gray

    namedWindow("Display Image", WINDOW_AUTOSIZE);   //新建窗口
    imshow("Display Image", gray_image);  

    cv::Scalar  mean;    //灰度均值 
    cv::Scalar  dev;     //方差
    cv::meanStdDev ( gray_image, mean, dev );  
    double m = mean.val[0];  
    double s = dev.val[0];  

    double top = m+s, bottle = m-s;
    double interval = (m+2*s)/10;

    int width = gray_image.cols/block;
    int height = gray_image.rows/block;

    for (int i=0;i<height;i++){
    	for (int j=0;j<width;j++){
    		int x=j*block, y=i*block;
    		double gray=0;

    		for(int k=y;k<y+block;k++){
    			for (int q = x; q < x+block; ++q) {
    				gray+= gray_image.at<uchar>(k,q);
    			}
    		}
    		gray = gray/(block*block);

    		if(gray> (top-interval*1)) printf("·");
    		else if(gray> (top-interval*2)) printf("^");
    		else if(gray> (top-interval*3)) printf("/");
    		else if(gray> (top-interval*4)) printf("=");
    		else if(gray> (top-interval*5)) printf("+");
    		else if(gray> (top-interval*6)) printf("*");
    		else if(gray> (top-interval*7)) printf("@");
    		else if(gray> (top-interval*8)) printf("#");
    		else if(gray> (top-interval*9)) printf("$");
    		else printf("W");

    		printf(".");
    	}
    	printf("\n");
    }

    waitKey(0);  //0ms 表示无限等待 知道用户按下按键
    destroyAllWindows(); //关闭所有窗口
    return 0;  
} 