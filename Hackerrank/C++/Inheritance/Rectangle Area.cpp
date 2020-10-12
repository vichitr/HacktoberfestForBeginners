#include <iostream>

using namespace std;

class Rectangle{
    protected:
        int heigth ; 
        int width ;
    public : 
        void display(){
            cout << heigth << " " << width << endl ; 
        }
}; 
class RectangleArea  : public Rectangle {
    public :
        void read_input(){
            cin >> heigth >> width ; 
        }
        void display(){
            cout << heigth * width << endl ;
        }
} ; 


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
