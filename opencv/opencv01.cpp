#include <opencv2/opencv.hpp>
int main() {
    cv::Mat img = cv::imread("a.png");
    if (img.empty()) return 1;
    cv::Mat gray, edges;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, edges, 100, 200);
    
    cv::imshow("Edges", edges);
    cv::waitKey();
}

// g++ -std=c++17 opencv01.cpp $(pkg-config --cflags --libs opencv4) 
