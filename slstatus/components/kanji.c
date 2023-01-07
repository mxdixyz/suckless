#include <time.h>

const char *
kanji() {
	time_t t=time(NULL);
	struct tm tm=*localtime(&t);
	static int map[]={0,3,2,5,0,3,5,1,4,6,2,4};
	int m=tm.tm_mon+1,y=tm.tm_year+1900;
	y-=m<3;
	int weekDay=(y+y/4-y/100+y/400+map[m-1]+tm.tm_mday)%7;
	if(weekDay==1) {
		return "月";
	} else if(weekDay==2) {
		return "火";
	} else if(weekDay==3) {
		return "水";
	} else if(weekDay==4) {
		return "木";
	} else if(weekDay==5) {
		return "金";
	} else if(weekDay ==6) {
		return "土";
	} else {
		return "日";
	}
}
