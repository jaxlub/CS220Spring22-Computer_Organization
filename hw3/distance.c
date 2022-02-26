#include "distance.h"
#include <math.h>


double distance (double lati1, double longi1, double lati2, double longi2){
 double rlati1 = lati1 * (M_PI / 180);
 double rlongi1 = longi1 * (M_PI / 180);
 double rlati2 = lati2 * (M_PI / 180);
 double rlongi2 = longi2 * (M_PI / 180);
	
 double x = sin((rlati2 - rlati1)/2)*sin((rlati2 - rlati1)/2) + cos(rlati1)*cos(rlati2)*(sin((rlongi2 - rlongi1)/2)*sin((rlongi2 - rlongi1)/2));
 double y = 2 * atan2(sqrt(x),sqrt(1-x));
 double distanced = y * 6371000; //distance in meters
 // convert from meters to miles
 distanced = distanced * .000621371; //1 mile = .000621371 is the number of miles per 1 meter (found on internet)
return distanced;
}
