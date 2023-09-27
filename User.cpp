#include "Movie.h"

Movie::Movie(const std::string& title, int duration, const std::string& rating)
    : title(title), duration(duration), rating(rating) {}

const std::string& Movie::getTitle() const {
    return title;
}

int Movie::getDuration() const {
    return duration;
}

const std::string& Movie::getRating() const {
    return rating;
}

const std::vector<std::string>& Movie::getShowtimes() const {
    return showtimes;
}

void Movie::addShowtime(const std::string& showtime) {
    showtimes.push_back(showtime);
}
