#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime 
{
    public:
        DateAndTime(int = 0, int = 0, int = 0, int = 1, int = 1, int = 2000);
        void print();
        void nextDay();
    
        void setTime(int, int, int);
	    void setHour(int);
	    void setMinute(int);
	    void setSecond(int);
	    int getHour();
	    int getMinute();
	    int getSecond();
	    void printUniversal();
	    void printStandard();
	    void tick();

    private:
        int month;
        int day;
        int year;
        int hour;
	    int minute;
	    int second;
};

#endif