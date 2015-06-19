import java.util.*;


public class Transactions {
	
	public static final String[] MONTH =
			{"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	public static final int[] MONTHLENGTH = {31,28,31,30,31,30,31,31,30,31,30,31};
	public static final String[] WEEKDAY = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		String month = "";
		// Input verification loop
		while(!Arrays.asList(MONTH).contains(month)) {
			System.out.print("Enter name of month (3 chars): ");
			month = sc.nextLine().toUpperCase();
			if(month.length()<3) continue; // Avoid index out of bounds exception
			// Set first char to upper case, rest to lower case; truncate to 3 chars
			month = month.substring(0,1) + month.substring(1,3).toLowerCase();
		}
		// Add one to index of this month to get next month; modulus wraps Dec->Jan
		String nextmonth = MONTH[(Arrays.asList(MONTH).indexOf(month)+1) % MONTH.length];
		// System.out.println("month = " + month + ", nextmonth = " + nextmonth);
		
		
		String weekday = "";
		while(!Arrays.asList(WEEKDAY).contains(weekday)) {
			System.out.print("Enter weekday of 1st of " + month + " (3 chars): ");
			weekday = sc.nextLine().toUpperCase();
			if (weekday.length()<3) continue; // Avoid index out of bounds exception
			weekday = weekday.substring(0,1) + weekday.substring(1,3).toLowerCase();
		}		
		// System.out.println("weekday = " + weekday);
		
		int length = MONTHLENGTH[Arrays.asList(MONTH).indexOf(month)];
		if(length == 28) { // February
			String leapyear = "";
			while(!leapyear.equals("Y") && !leapyear.equals("N")) {
				System.out.print("Leap year? (Y/N): ");
				leapyear = sc.nextLine().toUpperCase();
			}
			if(leapyear.equals("Y")) length = 29;
		}
		// System.out.println("length = " + length);
		
		sc.close();
		clearConsole();
		
		int power = 0;
		for(int day=1;day<=length;day++) {
			String fstring, duemonth;
			int dueday;
			int week = ((day-1)/7)+1;
			if(weekday.equals("Mon") && (week==2)) {
				fstring = "SlingshotADSL     -59      ~%02d %s  ~%02d %s  FC%n";
				System.out.format(fstring,day+7,month,day,month);
			}
			if(weekday.equals("Tue")) {
				duemonth = month;
				dueday = day+1;
				if(dueday>length){
					dueday -= length;
					duemonth = nextmonth; 
				}
				fstring = "Nathan   Rent     +185      %02d %s   %02d %s  IN%n";
				System.out.format(fstring,dueday,duemonth,day,month);
				if(week==1){
					fstring = "Nathan   Power    +??       %02d %s   %02d %s  IN%n";
					System.out.format(fstring,day+14,month,day,month);
					fstring = "Nathan   ADSL     +30       15 %s  ~%02d %s  IN%n";
					System.out.format(fstring,month,day,month);
				}
			}
			if(weekday.equals("Wed")) {
				duemonth = month;
				dueday = day+2;
				if(dueday>length) {
					dueday -= length;
					duemonth = nextmonth;
				}
				fstring = "ChsWlsn  Rent     -400      %02d %s   %02d %s  AP%n";
				System.out.format(fstring,dueday,duemonth,day,month);
			}
			if(weekday.equals("Fri")) {
				if(length-day < 7) {
					// final Friday of month
					power += 35;
					duemonth = month;
					dueday = day+2;
					if(dueday>length) {
						dueday -= length;
						duemonth = nextmonth;
					}
					fstring = "PwrShop  Power    -35       %02d %s   %02d %s  CC%n";
					System.out.format(fstring,dueday,duemonth,day,month);
					System.out.format("        (Inc 2 futr pax) (Mth total: %d)%n",power);
				} else {
					// other Fridays
					power += 5;
					fstring = "PwrShop  Power    -5        %02d %s   %02d %s  CC%n";
					System.out.format(fstring,day+2,month,day,month);
				}
			}
			// increment weekday
			weekday = WEEKDAY[(Arrays.asList(WEEKDAY).indexOf(weekday)+1) % WEEKDAY.length];
		}
	}
	
	public final static void clearConsole() {
	    try {
	        final String os = System.getProperty("os.name");
	        if (os.contains("Windows")) {
	            Runtime.getRuntime().exec("cls");
	        } else {
	            Runtime.getRuntime().exec("clear");
	        }
	    }
	    catch (final Exception e) {}
	}
	
}
