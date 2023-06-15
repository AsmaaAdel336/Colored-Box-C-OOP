#include <iostream>
#include<iomanip>
using namespace std;
#ifndef SETCOLORFUN_H_INCLUDED
#define SETCOLORFUN_H_INCLUDED
#include <windows.h>
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

/*
Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15
*/


#endif // SETCOLORFUN_H_INCLUDED
class ColoredBox{
private:
    int length=0,width=0,color_of_the_box,original_color;
    char** box,character='#';
public:

    static int the_biggest_area;

   ColoredBox(int l,int w,int col=15,char box_char='#'){
    length=l;
    width=w;
    character=box_char;
    color_of_the_box=col;
    original_color=col;

       box=new char*[length];
            for(int j=0;j<width;j++){
                box[j]=new char[width];
            }



    for(int i=0;i<length;i++){
       for(int j=0;j<width;j++){
            box[i][j]=character;


        }
            }

    }


    void  display(){

    SetColor(original_color);
     for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            cout<<box[i][j];


        }
        cout<<endl;
            }

    SetColor(15);
    }

    void displayTransposed(){
     SetColor(color_of_the_box);

    for(int i=0;i<width;i++){
       for(int j=0;j<length;j++){
            cout<<box[j][i];


        }
        cout<<endl;
            }
            SetColor(15);
    }

    void displayWider(){
    SetColor(color_of_the_box);

    for(int i=0;i<length;i++){
       for(int j=0;j<width;j++){
            cout<<box[i][j]<<"    ";


        }
        cout<<endl;
        }

    SetColor(15);

    }

    void displayChess(int c){
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){


        if((i+j)%2 == 0){
				color_of_the_box=c;}
			else{
				color_of_the_box=original_color;}
            SetColor(color_of_the_box);
            cout<<box[i][j];
         }
        cout<<endl;
            }
    SetColor(15);

    }
    void setColor(int c){
    color_of_the_box=c;
    }
   void set_character(char ch){
   character=ch;
   }


    int getArea(){
    return length*width;

    }


    int getMaxArea(){
    int x=getArea();

       if(x > the_biggest_area)
          the_biggest_area = x;

    return the_biggest_area;

    }

  ~ColoredBox(){
      for(int i=0;i<length;i++){
        delete[] box[i];
        delete[] box;

      }

  };


};
int ColoredBox::the_biggest_area=0;





int main()
{


    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len;
    cin>>wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb1->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->getArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea();
    delete cb1;

    cout<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    cout<<"Displaying Transposed: "<<endl;
    cb2->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb2->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->display();
    cout<<endl<<"Area="<<cb2->getArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;
    return 0;
}
