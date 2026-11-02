
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool parseDate(const std::string& dateText, std::tm& birthDate) {
    const std::vector<std::string> formats = {
        "%Y-%m-%d", "%Y/%m/%d", "%Y.%m.%d", "%Y%m%d",
        "%d.%m.%Y", "%d/%m/%Y", "%d-%m-%Y", "%d %m %Y",
        "%m/%d/%Y", 
        "%B %d, %Y", "%b %d, %Y", "%B %d %Y", "%b %d %Y",
        "%d %B %Y", "%d %b %Y"
    };

    for (const std::string& format : formats) {
        std::tm parsed = {};
        std::istringstream input(dateText);
        input >> std::get_time(&parsed, format.c_str());
        if (input.fail()) {
            continue;
        }

        input >> std::ws;
        if (!input.eof()) {
            continue;
        }

        const int year = parsed.tm_year;
        const int month = parsed.tm_mon;
        const int day = parsed.tm_mday;

        parsed.tm_isdst = -1;
        std::tm normalized = parsed;
        const std::time_t seconds = std::mktime(&normalized);

        if (seconds == static_cast<std::time_t>(-1) ||
            normalized.tm_year != year || normalized.tm_mon != month ||
            normalized.tm_mday != day) {
            continue;
        }

        birthDate = parsed;
        return true;
    }

    return false;
}

int main() {
    std::string name;
    std::cout << "What is your name? ";
    std::getline(std::cin, name);

    std::tm birthDate = {};
    std::string dateText;
    while (true) {
        std::cout << "Date of birth : ";
        std::getline(std::cin, dateText);

        if (parseDate(dateText, birthDate)) {
            break;
        }

        std::cout << "I couldn't recognize that date. Please try another "
                     "common date format.\n";
    }

    birthDate.tm_isdst = -1;
    const std::time_t birthSeconds = std::mktime(&birthDate);
    const std::time_t currentSeconds = std::time(nullptr);

    const std::tm today = *std::localtime(&currentSeconds);
    const std::tm birthDay = *std::localtime(&birthSeconds);

    int yearsOld = (today.tm_year + 1900) - (birthDay.tm_year + 1900);
    if (today.tm_mon < birthDay.tm_mon ||
        (today.tm_mon == birthDay.tm_mon && today.tm_mday < birthDay.tm_mday)) {
        --yearsOld;
    }

    std::cout << "Hello " << name << ", you are " << yearsOld
              << " years old.\n";
    return 0;
}
