#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <cstdint>
#include "LinkedList.cpp"
#include <string> 
using namespace cv;


void luminance(Vec4b& px) {
    px[3] = (px[2] * 0.2126 + px[1] * 0.7152 + px[0] * .0722);
}

int main()
{

 
    //test.add_node(1, 2);

    Mat img = imread("Resources/card.png");
  
    
    VideoCapture cap(0);
    Mat vid;

    Mat rgba;

    int frame = 0;
    while (true) {
        cap.read(vid);

    cvtColor(vid, rgba, COLOR_BGR2BGRA);
   
    
  //  Rect roi(70,80, 200,200);
  //
  //  Mat imgroi = rgba(roi);
  //
    
        Vec4b* currentRow;
        
      for (int i = 0;i < rgba.rows;i++) {
          MyLinkedList test;
          currentRow = rgba.ptr<Vec4b>(i);
    
          //calculate luminance
          for (int j = 0;j < rgba.cols;j++) {
              luminance(currentRow[j]);
    
              if (currentRow[j][3] > int(0.2 * 255.f)) {
                  test.add_back(int(currentRow[j][3]), currentRow[j]);

    
              }
    
          }
        node* header = quickSort(test.head, test.tail);
       
       
        for (int j = 0;j < rgba.cols;j++) {
            if (currentRow[j][3] < int(0.21 * 255.f)) {
                
                if (header != NULL) {
                    currentRow[j] = header->data.ptr;
                    header = header->next;
                }
                }
        }
        //clear_(header);
         
         
    
    
      }



      // for (int i = 0;i < rgba.rows;i++) {
      //     currentRow = rgba.ptr<Vec4b>(i);
      //
      //     //calculate luminance
      //     for (int j = 0;j < rgba.cols;j++) {
      //         currentRow[j] *= .3;
      //     }
      // }
        
       imshow("image", rgba);
        waitKey(1);
        
      //  frame++;
      //    imwrite("poopa_"+std::to_string(frame)+".png", rgba);
        
    }


    waitKey(0);
    
 //  imshow("pp", rgba);

 //  waitKey(0);
}