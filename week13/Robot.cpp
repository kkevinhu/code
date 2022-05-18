#include <iostream>
using namespace std;

class Robot
{
public:
    Robot()
    {
        position_x = 0;
        position_y = 0;
        direction = 'N';
    }
    void turn(string way)
    {
        char d[4] = {'N', 'E', 'S', 'W'};
        int j;
        for(j = 0;j < 4;j ++)
        if(d[j] == direction)
            break;
        if(way == "RIGHT")
        direction = d[(j + 1) % 4];
        else if(way == "LEFT")
        direction = d[(j - 1 + 4) % 4];
    }
    int getPositionX()
    {
        return position_x;
    }
    int getPositionY()
    {
        return position_y;
    }
    char getDirection()
    {
        return direction;
    }
    void go()
    {
        if(direction == 'N')
        position_y ++;
        else if(direction == 'E')
        position_x ++;
        else if(direction == 'S')
        position_y --;
        else
        position_x --;
    }
    void display()
    {
        cout<<"at("<<position_x<<", "<<position_y<<"), heading "<<direction<<endl;
    };
private:
    int position_x, position_y;
    char direction;
};
//ans

int main() {
    string input;
    Robot robot;
    while (cin>>input) {
        if (input=="GO") {
            int step;
            cin>>step;
            while (step--) 
                robot.go();
            string _step;
            cin>>_step;//STEP
        }
        else if (input=="TURN") {
            string way;
            cin>>way;
            robot.turn(way);
        }
        else if (input=="TURNTO") {
            char direction;
            cin>>direction;
            while (direction!=robot.getDirection())
                robot.turn("RIGHT");
        }
        else if (input=="GOTO") {
            int x, y;
            cin>>x>>y;
            if (x>robot.getPositionX()) {
                while ('E'!=robot.getDirection())
                    robot.turn("RIGHT");
                while (x>robot.getPositionX())
                    robot.go();
            }
            else if (x<robot.getPositionX()) {
                while ('W'!=robot.getDirection())
                    robot.turn("RIGHT");
                while (x<robot.getPositionX())
                    robot.go();
            }
            if (y>robot.getPositionY()) {
                while ('N'!=robot.getDirection())
                    robot.turn("RIGHT");
                while (y>robot.getPositionY())
                    robot.go();
            }
            else if (y<robot.getPositionY()) {
                while ('S'!=robot.getDirection())
                    robot.turn("RIGHT");
                while (y<robot.getPositionY())
                    robot.go();
            }
            while ('N'!=robot.getDirection())
                robot.turn("RIGHT");
        }
        else if (input=="SHOWINFO") {
            robot.display();
        }
        else if (input=="STOP") {
            break;
        }
    } 
}
