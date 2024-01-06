
#include<iostream>
#include<dos.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<vector>
#include<fstream>
#include <mmsystem.h>
const int MAX_ALARMS = 10;

using namespace std;

const char *d0[7][4] ={  "##","##","##","##",
                         "#","  ","  "," #",
                         "#","  ","  "," #",
                         "#","  ","  "," #",
                         "#","  ","  "," #",
                         "#","  ","  "," #",
                         "##","##","##","##"};

const char *d1[7][4] ={  "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#"};

const char *d2[7][4] ={  "##","##","##","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "##","##","##","#",
                         "# ","  ","  "," ",
                         "# ","  ","  "," ",
                         "##","##","##","#"};

const char *d3[7][4] ={  "##","##","##","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "##","##","##","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "##","##","##","#"};

const char *d4[7][4] ={  "# ","  ","  ","#",
                         "# ","  ","  ","#",
                         "# ","  ","  ","#",
                         "##","##","##","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#"};

const char *d5[7][4] ={  "##","##","##","#",
                         "# ","  ","  "," ",
                         "# ","  ","  "," ",
                         "##","##","##","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "##","##","##","#"};

const char *d6[7][4] ={  "##","##","##","#",
                         "# ","  ","  "," ",
                         "# ","  ","  "," ",
                         "##","##","##","#",
                         "# ","  ","  ","#",
                         "# ","  ","  ","#",
                         "##","##","##","#"};

const char *d7[7][4] ={  "##","##","##","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#"};

const char *d8[7][4] ={  "##","##","##","#",
                         "# ","  ","  ","#",
                         "# ","  ","  ","#",
                         "##","##","##","#",
                         "# ","  ","  ","#",
                         "# ","  ","  ","#",
                         "##","##","##","#"};

const char *d9[7][4] ={  "##","##","##","#",
                         "# ","  ","  ","#",
                         "# ","  ","  ","#",
                         "##","##","##","#",
                         "  ","  ","  ","#",
                         "  ","  ","  ","#",
                         "##","##","##","#"};

const char *sep[7][4] ={ "  ","  ","  "," ",
                         "  ","  ","  "," ",
                         "  ","##","##"," ",
                         "  ","  ","  "," ",
                         "  ","##","##"," ",
                         "  ","  ","  "," ",
                         "  ","  ","  "," "};

                                         //Retrieves a handle to the specified standard device (standard output )

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

       //setting position of cursor

void gotoxy(int x, int y)
{
    //coordinate of row for character cell
     CursorPosition.X =x;
    //coordinate of column for character cell
     CursorPosition.Y =y;
     //inbuilt function used for setting up cursor anywhere we wanted on console
     SetConsoleCursorPosition(console, CursorPosition);

}

 // set bool visible = 0 - invisible, bool visible = 1 - visible
void setcursor (bool visible, DWORD size){
    if(size == 0)
      size =20;                                      // default cursor size Changing to numbers from 1 to 20, decreases cursor width

     //A pointer to a CONSOLE_CURSOR_INFO structure that provides the new specifications for the console screen buffer's cursor.
    CONSOLE_CURSOR_INFO lpCursor;
     //The visibility of the cursor. If the cursor is invisible, this member is false
    lpCursor.bVisible = false;
    //The percentage of the character cell that is filled by the cursor. This value is between 1 and 100.
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);

}

                                                                       /*printing digit as per time*/
void printDigit(int no, int x, int y)
{
  for(int i=0;i<7;i++){
    for(int j=0; j<4;j++){
        switch(no){
          case 0: gotoxy(x+j, y+i); cout<< d0[i][j]; break;
          case 1: gotoxy(x+j, y+i); cout<< d1[i][j]; break;
          case 2: gotoxy(x+j, y+i); cout<< d2[i][j]; break;
          case 3: gotoxy(x+j, y+i); cout<< d3[i][j]; break;
          case 4: gotoxy(x+j, y+i); cout<< d4[i][j]; break;
          case 5: gotoxy(x+j, y+i); cout<< d5[i][j]; break;
          case 6: gotoxy(x+j, y+i); cout<< d6[i][j]; break;
          case 7: gotoxy(x+j, y+i); cout<< d7[i][j]; break;
          case 8: gotoxy(x+j, y+i); cout<< d8[i][j]; break;
          case 9: gotoxy(x+j, y+i); cout<< d9[i][j]; break;
          case 10: gotoxy(x+j, y+i); cout<<sep[i][j]; break;
        }
    }
  }
}
struct Alarm {
    int hour;
    int minute;
    int second;
};
vector<Alarm> alarms;
bool is24HourFormat = false;


void toggleTimeFormat() {
    is24HourFormat = !is24HourFormat;
}


void loadAlarms() {
    ifstream file("alarms.txt");
    if (file.is_open()) {
        Alarm alarm;
        while (file >> alarm.hour >> alarm.minute >> alarm.second) {
            alarms.push_back(alarm);
        }
        file.close();
    }
}

void saveAlarms() {
    ofstream file("alarms.txt");
    if (file.is_open()) {
        for (const auto& alarm : alarms) {
            file << alarm.hour << " " << alarm.minute << " " << alarm.second << endl;
        }
        file.close();
    }
}

                                                   // Function to add a new alarm
void addAlarm(int hour, int minute, int second) {
    Alarm alarm = {hour, minute, second};
    alarms.push_back(alarm);

                                               // Limit the number of alarms to MAX_ALARMS
    if (alarms.size() > MAX_ALARMS) {
        alarms.erase(alarms.begin());
    }

    saveAlarms(); // Save the alarms to file
}

                                                     // Function to delete an alarm
void deleteAlarm(int index) {
    if (index >= 0 && index < alarms.size()) {
        alarms.erase(alarms.begin() + index);
        saveAlarms(); // Save the alarms to file
    }
}
                                                    // Function to display the list of alarms
void displayAlarms() {
    system("cls");
    cout << "List of Alarms:\n";
    for (int i = 0; i < alarms.size(); ++i) {
        cout << i + 1 << ". " << alarms[i].hour << "H " << alarms[i].minute << "M " << alarms[i].second << "S\n";
    }
    cout << "Press 'D' to delete an alarm, 'Esc' to go back.\n";

    char ch = getch();
    if (ch == 27) { // 'Esc' key pressed
        return;
    } else if (ch == 'D' || ch == 'd') {
        cout << "Enter the alarm number to delete: ";
        int alarmNumber;
        cin >> alarmNumber;
        deleteAlarm(alarmNumber - 1);
    }
}

void playAlarmSound() {
    PlaySoundW(L"C:\\Users\\HP\\Downloads\\mixkit-classic-alarm-995.wav", NULL, SND_FILENAME | SND_ASYNC);
}




bool isAlarmSet = false;

void setAlarm(int &alarmHour, int &alarmMin, int &alarmSec) {
    system("cls");

    cout << "Set Alarm Time\n";

    if (is24HourFormat) {
        cout << "Hour (24-hour format): ";
    } else {
        cout << "Hour: ";
    }

    cin >> alarmHour;

    cout << "Minute: ";
    cin >> alarmMin;

    cout << "Second: ";
    cin >> alarmSec;

    isAlarmSet = true;
}


void soundAlarm() {
    cout << "\a";  // Beep sound to indicate alarm
        playAlarmSound();  // Play the alarm sound

}

bool isAlarmTime(int alarmHour, int alarmMin, int alarmSec, int currentHour, int currentMin, int currentSec) {
    if (is24HourFormat) {
        return (alarmHour == currentHour && alarmMin == currentMin && alarmSec == currentSec);
    } else {
        // Convert 12-hour format to 24-hour format for comparison
        int convertedAlarmHour = (alarmHour % 12) + (currentHour >= 12 ? 12 : 0);
        int convertedCurrentHour = (currentHour % 12) + (currentHour >= 12 ? 12 : 0);

        return (convertedAlarmHour == convertedCurrentHour &&
                alarmMin == currentMin && alarmSec == currentSec);
    }
}



int main()
{
    loadAlarms();
    system("cls");
    setcursor(0,0);                      //setting cursor invisible

    srand((unsigned) time (NULL));       //makes use of the computer's internal clock to control the choice of the seed.
                                         //Since time is continually changing, the seed is forever changing.

    time_t now = time(0);                //current date/time based on current system

    char *dt= ctime(&now);               //convert now to string form

    tm *lotm = localtime(&now);          // Convert now to tm struct for local timezone
    dt = asctime(lotm);

    int hour = lotm->tm_hour;            //print various components of tm structure.
    int min = lotm->tm_min;
    int sec = lotm->tm_sec;

                                                              //*DATE PART*//

     int day = lotm->tm_mday;
    int month = lotm->tm_mon + 1;  // Adding 1 as January is represented as 0
    int year = lotm->tm_year + 1900;  // Adding 1900 as tm_year is the number of years since 1900

                                                         //*gap between digits*//

    int gap=10;

                                                        //*cursor position*//
    int posX;
    int posY= 8;
    int alarmHour=0, alarmMin=0, alarmSec=0;
    while(1){
        system("cls");

        gotoxy(41,5);
        cout<<" C U R R E N T  T I M E"<<endl;

        posX= 15;

        if(kbhit()){                     //kbhit function is used to determine if a key has been pressed or not.
            char ch = getch();           //Stores the pressed key in ch
            if(ch==27){                  // Terminates the loop when escape(key) is pressed and ends the program
                break;
            }
            else if (ch == 'S' || ch == 's') {
                setAlarm(alarmHour, alarmMin, alarmSec);
                 addAlarm(alarmHour, alarmMin, alarmSec);

            }
            else if (ch == 'L' || ch == 'l') {
                displayAlarms();
            }
            else if (ch == 'T' || ch == 't') {
                toggleTimeFormat();
            }
        }

         if (isAlarmSet && isAlarmTime(alarmHour, alarmMin, alarmSec, hour, min, sec)) {
            gotoxy(15, 19);
            cout << "ALARM!!!";
            soundAlarm();
            isAlarmSet = false;

        }




          if (is24HourFormat) {
                                                     //*FOR 24h FORMAT*/
                                                       //*printing hour*//

        if(hour< 10){
            printDigit(0,posX,posY);
            printDigit(hour,posX+=gap, posY);
        }
        else{
       printDigit(hour/10,posX,posY);
            printDigit(hour%10,posX+=gap, posY);
        }

          }
          else
          {
                                                                              /*For 12h Formate*/
        int displayHour = hour % 12;
             if (displayHour == 0) {
                 displayHour = 12;
             }

             if(displayHour < 10) {
                 printDigit(0, posX, posY);
                 printDigit(displayHour, posX += gap, posY);
             }
             else {
                 printDigit(displayHour / 10, posX, posY);
                 printDigit(displayHour % 10, posX += gap, posY);
             }
          }
                                                  //*printing the colon symbol between hours and minutes*//

        printDigit(10,posX+=gap,posY);


                                                                //*printing minutes*//
        if(min< 10){
            printDigit(0,posX+=gap,posY);
            printDigit(min,posX+=gap, posY);
        }
        else{
            printDigit(min/10,posX+=gap,posY);
            printDigit(min%10,posX+=gap, posY);
        }
                                                    //*printing the colon symbol between minutes and seconds*//

        printDigit(10,posX+=gap,posY);


                                                               //*printing seconds*//

        if(sec< 10){
            printDigit(0,posX+=gap,posY);
            printDigit(sec,posX+=gap, posY);
        }
        else{
            printDigit(sec/10,posX+=gap,posY);
            printDigit(sec%10,posX+=gap, posY);
        }

                                                            //* Print AM or PM for 12h time format*//

           if (!is24HourFormat) {
            gotoxy(posX + gap, posY);
            cout << (hour < 12 ? " AM" : " PM");
        }

                                                                      //* Print date*//

        gotoxy(15, 17);
        cout << "DATE (Day/Month/Year): " << day << "/" << month << "/" << year;

                                                                     //*Print Alarm Timer*//
      gotoxy(70, 17);
       cout << "Alarm Time : " <<   alarmHour<< "H " << alarmMin<< "M " <<alarmSec<<"S" ;

      gotoxy(70, 18);
       cout << "[To set Alarm press S ]" ;
       gotoxy(15,20);
       cout<<"[Press T or t to change the  time format ]";
       gotoxy(15,21);
       cout<<"[Press L to see the list of alarms]";
                                              //*50 milliseconds processing time is deducted*//
        Sleep(950);
        sec++;
        if(sec>=60){
            sec =0;
            min++;
        }
        if(min>=60){
            min=0;
            hour++;
        }
        if(hour>=24){
            sec=0;
            min=0;
            hour =0;
        }
    }
    return 0;
}
