#include <string>
#include <cmath>

bool isValidReport(double lat, double lng, int severity) {
    bool validLat = lat >= -90.0 && lat <= 90.0;
    bool validLng = lng >= -180.0 && lng <= 180.0;
    bool validSeverity = severity >= 1 && severity <= 5;
    return validLat && validLng && validSeverity;
}