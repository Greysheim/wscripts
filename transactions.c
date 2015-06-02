#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MON=0,TUE=1,WED=2,THU=3,FRI=4,SAT=5,SUN=6;

int get_weekday(char *s);
void get_nextmonth(char *m, char *nm);

int main() {
	char month[8], weekday_s[8], fstring[255], duemonth[8], nextmonth[8];
	int length, weekday, power, dueday;
	printf("Enter name of month (3 chars): ");
	gets(month);
	month[3] = '\0';
	get_nextmonth(month,nextmonth);
	printf("Enter day of week of 1st of %s (3 chars): ",month);
	gets(weekday_s);
	weekday_s[3] = '\0';
	weekday = get_weekday(weekday_s);
	printf("Enter length of %s in days: ",month);
	scanf("%d",&length);
	system("cls");
	power = 0;
	for(int day=1;day<=length;day++) {
		if(weekday==MON) {
			if((day>7) && (day<=14)) {
				strcpy(fstring,"SlingshotADSL     -59      ~%0.2d %s  ~%0.2d %s  FC\n");
				printf(fstring,day+7,month,day,month);
			}
		}
		if(weekday==TUE) {
			strcpy(duemonth,month);
			dueday = day+1;
			if (dueday > length) {
				dueday-=length;
				strcpy(duemonth,nextmonth);
			}
			strcpy(fstring,"Nathan   Rent     +165      %0.2d %s   %0.2d %s  IN\n");
			printf(fstring,dueday,duemonth,day,month);
			if(day<=7) {
				strcpy(fstring,"Nathan   Power    +??       %0.2d %s   %0.2d %s  IN\n");
				printf(fstring,day+14,month,day,month);
				strcpy(fstring,"Nathan   ADSL     +30       15 %s  ~%0.2d %s  IN\n");
				printf(fstring,month,day,month);
			}
		}
		if(weekday==WED) {
			strcpy(duemonth,month);
			dueday = day+2;
			if (dueday > length) {
				dueday-=length;
				strcpy(duemonth,nextmonth);
			}
			strcpy(fstring,"ChsWlsn  Rent     -360      %0.2d %s   %0.2d %s  AP\n");
			printf(fstring,dueday,duemonth,day,month);
		}
		if(weekday==FRI) {
			if(length-day < 7) {
				// final Friday of month
				power += 35;
				strcpy(duemonth,month);
				dueday = day+2;
				if (dueday > length) {
					dueday-=length;
					strcpy(duemonth,nextmonth);
				}
				strcpy(fstring,"PwrShop  Power    -35       %0.2d %s   %0.2d %s  CC\n");
				printf(fstring,dueday,duemonth,day,month);
				printf("\t(Inc 2 futr pax) (Mth total: %d)\n",power);
			} else {
				// other Fridays
				power += 5;
				strcpy(fstring,"PwrShop  Power    -5        %0.2d %s   %0.2d %s  CC\n");
				printf(fstring,day+2,month,day,month);
			}
		}
		weekday++;
		if(weekday>SUN) weekday=MON;
	}
	printf("==========\n");
}

int get_weekday(char *s) {
	for(unsigned i=0;i<strlen(s);i++) {
		if ((s[i]>='A') && (s[i]<='Z')) {
			s[i] += 'a' - 'A';
		}
	}
	if (strcmp(s,"mon")==0) return MON;
	if (strcmp(s,"tue")==0) return TUE;
	if (strcmp(s,"wed")==0) return WED;
	if (strcmp(s,"thu")==0) return THU;
	if (strcmp(s,"fri")==0) return FRI;
	if (strcmp(s,"sat")==0) return SAT;
	return SUN;
}

void get_nextmonth(char *m, char *nm) {
	if ((m[0]>='a') && (m[0]<='z')) {
		m[0] += 'A' - 'a';
	}
	for(unsigned i=1;i<strlen(m);i++) {
		if ((m[i]>='A') && (m[i]<='Z')) {
			m[i] += 'a' - 'A';
		}
	}
	if (strcmp(m,"Jan")==0) strcpy(nm, "Feb");
	if (strcmp(m,"Feb")==0) strcpy(nm, "Mar");
	if (strcmp(m,"Mar")==0) strcpy(nm, "Apr");
	if (strcmp(m,"Apr")==0) strcpy(nm, "May");
	if (strcmp(m,"May")==0) strcpy(nm, "Jun");
	if (strcmp(m,"Jun")==0) strcpy(nm, "Jul");
	if (strcmp(m,"Jul")==0) strcpy(nm, "Aug");
	if (strcmp(m,"Aug")==0) strcpy(nm, "Sep");
	if (strcmp(m,"Sep")==0) strcpy(nm, "Oct");
	if (strcmp(m,"Oct")==0) strcpy(nm, "Nov");
	if (strcmp(m,"Nov")==0) strcpy(nm, "Dec");
	if (strcmp(m,"Dec")==0) strcpy(nm, "Jan");
}
