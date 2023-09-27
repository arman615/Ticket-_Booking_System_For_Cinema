#pragma once
#include "Movie.h"

class Ticket {
private:
    Movie movie;
    std::string showtime;
    std::string seatNumber;

public:
    Ticket(const Movie& movie, const std::string& showtime, const std::string& seatNumber);

    const Movie& getMovie() const;
    const std::string& getShowtime() const;
    const std::string& getSeatNumber() const;
};
